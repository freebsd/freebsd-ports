--- src/platform/freebsd.rs.orig	1970-01-01 00:00:00 UTC
+++ src/platform/freebsd.rs
@@ -0,0 +1,812 @@
+//! FreeBSD platform support.
+//!
+//! Mirrors the Linux backend (clipboard, notifications, and shell helpers are
+//! shared behaviour), but reads process state through sysctl(3) `kern.proc`
+//! rather than procfs, which FreeBSD does not mount by default, and copies
+//! POSIX.1e/NFSv4 ACLs instead of Linux ACL xattrs.
+
+use std::{
+    io::Write,
+    os::fd::RawFd,
+    path::PathBuf,
+    process::{Command, Stdio},
+};
+
+pub(super) const REMOTE_BRIDGE_CLOCK: libc::clockid_t = libc::CLOCK_MONOTONIC;
+
+use super::{
+    read_limited_reader, ClipboardCommand, ClipboardImage, ForegroundJob, ForegroundProcess,
+    LimitedRead, Signal,
+};
+
+pub(crate) use super::unix_common::{
+    configure_status_command, create_remote_private_dir, create_remote_ssh_config_dir,
+    create_remote_ssh_config_file, hostname, local_datetime, remote_bridge_endpoint_path,
+    remote_private_temp_base, remote_reattach_argument, remote_reattach_program,
+    remote_ssh_config_paths, set_default_plugin_pane_pwd, shutdown_client_stream,
+    status_commands_supported, wait_client_stream_readable, write_client_stream,
+    ClientStreamReader, StatusCommandGuard,
+};
+
+/// Upper bound on the processes reported for one foreground process group, so a
+/// pathological group cannot grow the per-tick detection work without limit.
+const FOREGROUND_TREE_SCAN_LIMIT: usize = 512;
+
+
+pub(crate) fn config_file_link_count(path: &std::path::Path) -> std::io::Result<u64> {
+    use std::os::unix::fs::MetadataExt;
+    Ok(std::fs::metadata(path)?.nlink())
+}
+
+pub(crate) fn check_config_write_target(_target: &std::path::Path) -> std::io::Result<()> {
+    Ok(())
+}
+
+pub(crate) fn write_existing_config(
+    _target: &std::path::Path,
+    _contents: &[u8],
+) -> std::io::Result<bool> {
+    // Unix keeps atomic replacement for existing files too.
+    Ok(false)
+}
+
+pub(crate) fn create_config_temporary(
+    path: &std::path::Path,
+    private: bool,
+) -> std::io::Result<std::fs::File> {
+    use std::os::unix::fs::OpenOptionsExt;
+    std::fs::OpenOptions::new()
+        .write(true)
+        .create_new(true)
+        .mode(if private { 0o600 } else { 0o666 })
+        .open(path)
+}
+
+pub(crate) fn write_config_temporary(
+    source: Option<&std::path::Path>,
+    temporary: &std::path::Path,
+    contents: &[u8],
+) -> std::io::Result<()> {
+    use std::os::{fd::AsRawFd, unix::fs::MetadataExt};
+    let mut output = std::fs::OpenOptions::new()
+        .write(true)
+        .truncate(true)
+        .open(temporary)?;
+    if let Some(source) = source {
+        let input = std::fs::File::open(source)?;
+        let metadata = input.metadata()?;
+        let current = output.metadata()?;
+        if (metadata.uid(), metadata.gid()) != (current.uid(), current.gid()) {
+            // Keep ownership before restoring mode/ACLs; chown can clear mode bits.
+            if unsafe { libc::fchown(output.as_raw_fd(), metadata.uid(), metadata.gid()) } != 0 {
+                return Err(std::io::Error::last_os_error());
+            }
+        }
+        // Replace inherited ACLs before enabling the original mode. Prepare all
+        // access controls while the temporary is empty, before writing secrets.
+        copy_config_acl(input.as_raw_fd(), output.as_raw_fd())?;
+        output.set_permissions(metadata.permissions())?;
+    }
+    output.write_all(contents)?;
+    output.sync_all()
+}
+
+
+// FreeBSD keeps ACLs in the filesystem's native ACL store rather than in
+// extended attributes. Copy the source's NFSv4 ACL (ZFS, UFS with nfsv4acls) or
+// POSIX.1e access ACL (UFS with acls) so mode bits alone cannot silently broaden
+// access, for example through an inherited ACL on the parent directory.
+fn copy_config_acl(source: RawFd, destination: RawFd) -> std::io::Result<()> {
+    unsafe extern "C" {
+        fn acl_get_fd_np(fd: libc::c_int, kind: libc::c_int) -> *mut libc::c_void;
+        fn acl_set_fd_np(fd: libc::c_int, acl: *mut libc::c_void, kind: libc::c_int)
+            -> libc::c_int;
+        fn acl_free(object: *mut libc::c_void) -> libc::c_int;
+    }
+    const ACL_TYPE_ACCESS: libc::c_int = 0x0000_0002;
+    const ACL_TYPE_NFS4: libc::c_int = 0x0000_0004;
+    for kind in [ACL_TYPE_NFS4, ACL_TYPE_ACCESS] {
+        let acl = unsafe { acl_get_fd_np(source, kind) };
+        if acl.is_null() {
+            let error = std::io::Error::last_os_error();
+            // The filesystem does not support this ACL flavour (or any ACLs).
+            if matches!(error.raw_os_error(), Some(libc::EINVAL | libc::EOPNOTSUPP)) {
+                continue;
+            }
+            return Err(error);
+        }
+        let result = unsafe { acl_set_fd_np(destination, acl, kind) };
+        let error = std::io::Error::last_os_error();
+        unsafe {
+            acl_free(acl);
+        }
+        return if result == 0 { Ok(()) } else { Err(error) };
+    }
+    Ok(())
+}
+
+pub fn raise_server_nofile_limit() {}
+
+pub(crate) fn should_draw_host_cursor_by_default() -> bool {
+    false
+}
+
+pub(crate) fn should_query_host_terminal_palette() -> bool {
+    true
+}
+
+
+fn raw_command_argv(command: &str, flag: &str) -> Vec<std::ffi::OsString> {
+    vec!["/bin/sh".into(), flag.into(), command.into()]
+}
+
+pub(crate) fn detached_custom_command_process_platform(command: &str) -> std::process::Command {
+    let argv = raw_command_argv(command, "-lc");
+    let mut command = std::process::Command::new(&argv[0]);
+    command.args(&argv[1..]);
+    command
+}
+
+pub(crate) fn pane_custom_command_pty_builder_platform(
+    command: &str,
+) -> portable_pty::CommandBuilder {
+    portable_pty::CommandBuilder::from_argv(raw_command_argv(command, "-c"))
+}
+
+pub(crate) fn scrollback_editor_argv(path: &std::path::Path) -> std::io::Result<Vec<String>> {
+    let quoted_path = shell_quote(&path.display().to_string());
+    let command = format!(
+        r#"scrollback_file={quoted_path}; eval "${{EDITOR:-vi}} \"\$scrollback_file\""; status=$?; rm -f "$scrollback_file"; exit $status"#
+    );
+    Ok(vec!["/bin/sh".to_string(), "-c".to_string(), command])
+}
+
+pub(crate) fn interactive_shell_command(argv: &[String], shell_name: &str) -> Option<String> {
+    super::interactive_unix_shell_command(argv, shell_name, shell_quote)
+}
+
+fn shell_quote(value: &str) -> String {
+    if !value.is_empty()
+        && value.chars().all(|ch| {
+            ch.is_ascii_alphanumeric()
+                || matches!(
+                    ch,
+                    '@' | '%' | '_' | '+' | '=' | ':' | ',' | '.' | '/' | '-'
+                )
+        })
+    {
+        return value.to_string();
+    }
+
+    format!("'{}'", value.replace('\'', "'\\''"))
+}
+
+/// Collect the foreground terminal job for a given child PID.
+pub(crate) fn available_pane_shell(child_pid: u32) -> Option<String> {
+    super::available_pane_shell_from_job(child_pid, foreground_job(child_pid)?)
+}
+
+/// A `kern.proc` process table entry.
+#[derive(Debug, Clone, PartialEq, Eq)]
+struct ProcEntry {
+    pid: u32,
+    pgid: i32,
+    sid: i32,
+    tpgid: i32,
+    comm: String,
+    stat: libc::c_char,
+}
+
+/// Read a sysctl(3) node, retrying while the value grows between the size
+/// probe and the read (the process table is not a snapshot).
+fn sysctl_bytes(mib: &[libc::c_int]) -> Option<Vec<u8>> {
+    for _ in 0..4 {
+        let mut len: libc::size_t = 0;
+        if unsafe {
+            libc::sysctl(
+                mib.as_ptr(),
+                mib.len() as libc::c_uint,
+                std::ptr::null_mut(),
+                &mut len,
+                std::ptr::null(),
+                0,
+            )
+        } != 0
+        {
+            return None;
+        }
+        len += len / 8 + 64;
+        let mut buffer = vec![0_u8; len];
+        let result = unsafe {
+            libc::sysctl(
+                mib.as_ptr(),
+                mib.len() as libc::c_uint,
+                buffer.as_mut_ptr().cast(),
+                &mut len,
+                std::ptr::null(),
+                0,
+            )
+        };
+        if result == 0 {
+            buffer.truncate(len);
+            return Some(buffer);
+        }
+        if std::io::Error::last_os_error().raw_os_error() != Some(libc::ENOMEM) {
+            return None;
+        }
+    }
+    None
+}
+
+fn c_chars_to_bytes(chars: &[libc::c_char]) -> Vec<u8> {
+    chars
+        .iter()
+        .take_while(|&&ch| ch != 0)
+        .map(|&ch| ch as u8)
+        .collect()
+}
+
+fn proc_entries(mib: &[libc::c_int]) -> Vec<ProcEntry> {
+    let Some(buffer) = sysctl_bytes(mib) else {
+        return Vec::new();
+    };
+    let size = std::mem::size_of::<libc::kinfo_proc>();
+    buffer
+        .chunks_exact(size)
+        .filter_map(|chunk| {
+            // The kernel packs whole structures; read each one without assuming
+            // the Vec<u8> allocation is suitably aligned.
+            let info: libc::kinfo_proc =
+                unsafe { std::ptr::read_unaligned(chunk.as_ptr().cast()) };
+            if info.ki_structsize as usize != size || info.ki_pid <= 0 {
+                return None;
+            }
+            Some(ProcEntry {
+                pid: info.ki_pid as u32,
+                pgid: info.ki_pgid,
+                sid: info.ki_sid,
+                tpgid: info.ki_tpgid,
+                comm: String::from_utf8_lossy(&c_chars_to_bytes(&info.ki_comm)).into_owned(),
+                stat: info.ki_stat,
+            })
+        })
+        .collect()
+}
+
+fn pid_mib_arg(pid: u32) -> Option<libc::c_int> {
+    libc::c_int::try_from(pid).ok().filter(|pid| *pid > 0)
+}
+
+fn proc_entry(pid: u32) -> Option<ProcEntry> {
+    let pid = pid_mib_arg(pid)?;
+    proc_entries(&[libc::CTL_KERN, libc::KERN_PROC, libc::KERN_PROC_PID, pid])
+        .into_iter()
+        .next()
+}
+
+/// Zombies have no arguments or environment left, and embryonic processes do
+/// not have them yet.
+fn process_allows_argument_read(stat: libc::c_char) -> bool {
+    !matches!(stat, libc::SZOMB | libc::SIDL)
+}
+
+pub fn foreground_job(child_pid: u32) -> Option<ForegroundJob> {
+    let process_group_id = foreground_process_group_id(child_pid)?;
+    foreground_job_for_group(child_pid, process_group_id)
+}
+
+fn foreground_job_for_group(child_pid: u32, process_group_id: u32) -> Option<ForegroundJob> {
+    let session_id = proc_entry(child_pid)?.sid;
+    let group = pid_mib_arg(process_group_id)?;
+    // kern.proc.pgrp returns just the group's members, so unlike procfs there
+    // is no process tree to walk; the session check keeps the job on the pane's
+    // terminal.
+    let mut members =
+        proc_entries(&[libc::CTL_KERN, libc::KERN_PROC, libc::KERN_PROC_PGRP, group])
+            .into_iter()
+            .filter(|entry| entry.pgid == group && entry.sid == session_id)
+            .collect::<Vec<_>>();
+    members.sort_unstable_by_key(|entry| entry.pid);
+    members.truncate(FOREGROUND_TREE_SCAN_LIMIT);
+
+    let processes = members
+        .into_iter()
+        .map(|member| {
+            let argv = process_allows_argument_read(member.stat)
+                .then(|| process_argv(member.pid))
+                .flatten();
+            ForegroundProcess {
+                pid: member.pid,
+                name: member.comm,
+                argv0: None,
+                cmdline: argv.as_ref().map(|parts| parts.join(" ")),
+                argv,
+            }
+        })
+        .collect::<Vec<_>>();
+
+    if processes.is_empty() {
+        return None;
+    }
+
+    Some(ForegroundJob {
+        process_group_id,
+        processes,
+    })
+}
+
+pub fn foreground_group_leader_job(process_group_id: u32) -> Option<ForegroundJob> {
+    let entry = proc_entry(process_group_id)?;
+    if entry.pgid < 0 || entry.pgid as u32 != process_group_id {
+        return None;
+    }
+
+    let argv = process_allows_argument_read(entry.stat)
+        .then(|| process_argv(process_group_id))
+        .flatten();
+    Some(ForegroundJob {
+        process_group_id,
+        processes: vec![ForegroundProcess {
+            pid: process_group_id,
+            name: entry.comm,
+            argv0: None,
+            cmdline: argv.as_ref().map(|parts| parts.join(" ")),
+            argv,
+        }],
+    })
+}
+
+pub fn foreground_process_group_id(child_pid: u32) -> Option<u32> {
+    let tpgid = proc_entry(child_pid)?.tpgid;
+    (tpgid > 0).then_some(tpgid as u32)
+}
+
+pub fn foreground_process_group_id_for_tty_fd(fd: RawFd) -> Option<u32> {
+    let pgid = unsafe { libc::tcgetpgrp(fd) };
+    (pgid > 0).then_some(pgid as u32)
+}
+
+fn process_argv(pid: u32) -> Option<Vec<String>> {
+    let bytes = sysctl_bytes(&[
+        libc::CTL_KERN,
+        libc::KERN_PROC,
+        libc::KERN_PROC_ARGS,
+        pid_mib_arg(pid)?,
+    ])?;
+    if bytes.is_empty() {
+        return None;
+    }
+    let parts: Vec<String> = bytes
+        .split(|&b| b == 0)
+        .filter(|part| !part.is_empty())
+        .map(|part| String::from_utf8_lossy(part).into_owned())
+        .collect();
+    (!parts.is_empty()).then_some(parts)
+}
+
+/// Get the current working directory of a process through `kern.proc.cwd`.
+pub fn process_cwd(pid: u32) -> Option<PathBuf> {
+    use std::os::unix::ffi::OsStrExt;
+
+    let bytes = sysctl_bytes(&[
+        libc::CTL_KERN,
+        libc::KERN_PROC,
+        libc::KERN_PROC_CWD,
+        pid_mib_arg(pid)?,
+    ])?;
+    if bytes.len() < std::mem::size_of::<libc::kinfo_file>() {
+        return None;
+    }
+    let info: libc::kinfo_file = unsafe { std::ptr::read_unaligned(bytes.as_ptr().cast()) };
+    let path = c_chars_to_bytes(&info.kf_path);
+    (!path.is_empty()).then(|| PathBuf::from(std::ffi::OsStr::from_bytes(&path)))
+}
+
+/// Read a Herdr agent identity hint from a process environment.
+pub fn process_agent_hint(pid: u32) -> Option<crate::detect::Agent> {
+    let entry = proc_entry(pid)?;
+    if !process_allows_argument_read(entry.stat) {
+        return None;
+    }
+    let environ = sysctl_bytes(&[
+        libc::CTL_KERN,
+        libc::KERN_PROC,
+        libc::KERN_PROC_ENV,
+        pid_mib_arg(pid)?,
+    ])?;
+    super::parse_agent_env_hint(&environ)
+}
+
+pub fn session_processes(child_pid: u32) -> Vec<u32> {
+    let Some(session_id) = process_session_id(child_pid) else {
+        return Vec::new();
+    };
+
+    proc_entries(&[libc::CTL_KERN, libc::KERN_PROC, libc::KERN_PROC_PROC])
+        .into_iter()
+        .filter(|entry| entry.sid == session_id)
+        .map(|entry| entry.pid)
+        .collect()
+}
+
+
+pub fn signal_processes(pids: &[u32], signal: Signal) {
+    let sig = match signal {
+        Signal::Hangup => libc::SIGHUP,
+        Signal::Terminate => libc::SIGTERM,
+        Signal::Kill => libc::SIGKILL,
+    };
+
+    for &pid in pids {
+        if pid == 0 {
+            continue;
+        }
+        unsafe {
+            libc::kill(pid as i32, sig);
+        }
+    }
+}
+
+pub fn process_exists(pid: u32) -> bool {
+    if pid == 0 {
+        return false;
+    }
+    let result = unsafe { libc::kill(pid as i32, 0) };
+    if result == 0 {
+        true
+    } else {
+        std::io::Error::last_os_error().raw_os_error() == Some(libc::EPERM)
+    }
+}
+
+pub fn write_clipboard(bytes: &[u8]) -> bool {
+    for command in clipboard_commands() {
+        if run_clipboard_command(&command, bytes) {
+            return true;
+        }
+    }
+    false
+}
+
+pub fn read_clipboard_text() -> Option<String> {
+    for command in read_clipboard_text_commands() {
+        if let Some(text) = read_clipboard_text_with_command(&command) {
+            return Some(text);
+        }
+    }
+    None
+}
+
+pub fn open_url(url: &str) -> std::io::Result<Option<std::process::Child>> {
+    Command::new("xdg-open")
+        .arg(url)
+        .stdin(Stdio::null())
+        .stdout(Stdio::null())
+        .stderr(Stdio::null())
+        .spawn()
+        .map(Some)
+}
+
+pub fn read_clipboard_image() -> Option<ClipboardImage> {
+    for (mime, extension) in [
+        ("image/png", "png"),
+        ("image/jpeg", "jpg"),
+        ("image/jpg", "jpg"),
+        ("image/gif", "gif"),
+        ("image/webp", "webp"),
+        ("image/bmp", "bmp"),
+    ] {
+        if std::env::var_os("WAYLAND_DISPLAY").is_some() {
+            if let Some(image) =
+                read_validated_clipboard_image("wl-paste", &["--type", mime], extension)
+            {
+                return Some(image);
+            }
+        }
+
+        if std::env::var_os("DISPLAY").is_some() {
+            if let Some(image) = read_validated_clipboard_image(
+                "xclip",
+                &["-selection", "clipboard", "-t", mime, "-o"],
+                extension,
+            ) {
+                return Some(image);
+            }
+        }
+    }
+
+    None
+}
+
+fn read_validated_clipboard_image(
+    program: &str,
+    args: &[&str],
+    extension: &'static str,
+) -> Option<ClipboardImage> {
+    let bytes = read_clipboard_image_with_command(program, args)?;
+    if !bytes_match_image_signature(extension, &bytes) {
+        return None;
+    }
+    Some(ClipboardImage { bytes, extension })
+}
+
+fn bytes_match_image_signature(extension: &str, bytes: &[u8]) -> bool {
+    match extension {
+        "png" => bytes.starts_with(b"\x89PNG\r\n\x1a\n"),
+        "jpg" => bytes.starts_with(&[0xFF, 0xD8, 0xFF]),
+        "gif" => bytes.starts_with(b"GIF87a") || bytes.starts_with(b"GIF89a"),
+        "webp" => bytes.len() >= 12 && bytes.starts_with(b"RIFF") && bytes[8..12] == *b"WEBP",
+        "bmp" => {
+            if bytes.len() < 26 || !bytes.starts_with(b"BM") {
+                return false;
+            }
+            let offset = u32::from_le_bytes([bytes[10], bytes[11], bytes[12], bytes[13]]) as usize;
+            (26..=bytes.len()).contains(&offset)
+        }
+        _ => false,
+    }
+}
+
+/// Show a native desktop notification through libnotify's command-line helper.
+pub fn show_desktop_notification(title: &str, body: Option<&str>) -> std::io::Result<bool> {
+    show_desktop_notification_with_command(title, body, |program| Command::new(program))
+}
+
+fn show_desktop_notification_with_command(
+    title: &str,
+    body: Option<&str>,
+    mut command: impl FnMut(&str) -> Command,
+) -> std::io::Result<bool> {
+    if std::env::var_os("DISPLAY").is_none() && std::env::var_os("WAYLAND_DISPLAY").is_none() {
+        return Ok(false);
+    }
+
+    let mut cmd = command("notify-send");
+    cmd.arg("--app-name").arg("Herdr").arg("--").arg(title);
+    if let Some(body) = body.filter(|body| !body.is_empty()) {
+        cmd.arg(body);
+    }
+    run_notification_command(cmd)
+}
+
+fn run_notification_command(mut command: Command) -> std::io::Result<bool> {
+    let status = match command
+        .stdin(Stdio::null())
+        .stdout(Stdio::null())
+        .stderr(Stdio::null())
+        .status()
+    {
+        Ok(status) => status,
+        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(false),
+        Err(err) => return Err(err),
+    };
+
+    Ok(status.success())
+}
+
+fn read_clipboard_image_with_command(program: &str, args: &[&str]) -> Option<Vec<u8>> {
+    let mut command = Command::new(program);
+    command.args(args);
+    read_clipboard_image_with_spawned_command(command)
+}
+
+fn read_clipboard_image_with_spawned_command(command: Command) -> Option<Vec<u8>> {
+    read_clipboard_image_with_spawned_command_max(
+        command,
+        crate::protocol::MAX_CLIPBOARD_IMAGE_PAYLOAD,
+    )
+}
+
+fn read_clipboard_image_with_spawned_command_max(
+    mut command: Command,
+    max_bytes: usize,
+) -> Option<Vec<u8>> {
+    let mut child = command
+        .stdin(Stdio::null())
+        .stdout(Stdio::piped())
+        .stderr(Stdio::null())
+        .spawn()
+        .ok()?;
+    let stdout = child.stdout.take()?;
+
+    let read = match read_limited_reader(stdout, max_bytes) {
+        Ok(read) => read,
+        Err(_) => {
+            let _ = child.kill();
+            let _ = child.wait();
+            return None;
+        }
+    };
+
+    if read == LimitedRead::Oversized {
+        let _ = child.kill();
+        let _ = child.wait();
+        return None;
+    }
+
+    let status = child.wait().ok()?;
+    if !status.success() {
+        return None;
+    }
+
+    match read {
+        LimitedRead::Complete(bytes) => Some(bytes),
+        LimitedRead::Empty | LimitedRead::Oversized => None,
+    }
+}
+
+fn clipboard_commands() -> Vec<ClipboardCommand> {
+    let mut commands = Vec::new();
+
+    if std::env::var_os("WAYLAND_DISPLAY").is_some() {
+        commands.push(ClipboardCommand {
+            program: "wl-copy",
+            args: &["--type", "text/plain;charset=utf-8"],
+        });
+    }
+
+    if std::env::var_os("DISPLAY").is_some() {
+        commands.push(ClipboardCommand {
+            program: "xclip",
+            args: &["-selection", "clipboard", "-in"],
+        });
+        commands.push(ClipboardCommand {
+            program: "xsel",
+            args: &["--clipboard", "--input"],
+        });
+    }
+
+    commands
+}
+
+fn read_clipboard_text_commands() -> Vec<ClipboardCommand> {
+    let mut commands = Vec::new();
+
+    if std::env::var_os("WAYLAND_DISPLAY").is_some() {
+        commands.push(ClipboardCommand {
+            program: "wl-paste",
+            args: &["--type", "text/plain;charset=utf-8"],
+        });
+        commands.push(ClipboardCommand {
+            program: "wl-paste",
+            args: &["--type", "text/plain"],
+        });
+    }
+
+    if std::env::var_os("DISPLAY").is_some() {
+        commands.push(ClipboardCommand {
+            program: "xclip",
+            args: &["-selection", "clipboard", "-out"],
+        });
+        commands.push(ClipboardCommand {
+            program: "xsel",
+            args: &["--clipboard", "--output"],
+        });
+    }
+
+    commands
+}
+
+fn read_clipboard_text_with_command(command: &ClipboardCommand) -> Option<String> {
+    const MAX_CLIPBOARD_TEXT_BYTES: usize = 1024 * 1024;
+
+    let mut child = Command::new(command.program)
+        .args(command.args)
+        .stdin(Stdio::null())
+        .stdout(Stdio::piped())
+        .stderr(Stdio::null())
+        .spawn()
+        .ok()?;
+
+    let stdout = child.stdout.take()?;
+    let read = match read_limited_reader(stdout, MAX_CLIPBOARD_TEXT_BYTES) {
+        Ok(LimitedRead::Oversized) => {
+            let _ = child.kill();
+            let _ = child.wait();
+            return None;
+        }
+        Ok(read) => read,
+        Err(_) => {
+            let _ = child.kill();
+            let _ = child.wait();
+            return None;
+        }
+    };
+
+    let status = child.wait().ok()?;
+    if !status.success() {
+        return None;
+    }
+
+    match read {
+        LimitedRead::Complete(bytes) => String::from_utf8(bytes).ok(),
+        LimitedRead::Empty => None,
+        LimitedRead::Oversized => unreachable!("oversized clipboard text is handled before wait"),
+    }
+}
+
+fn run_clipboard_command(command: &ClipboardCommand, bytes: &[u8]) -> bool {
+    let mut child = match Command::new(command.program)
+        .args(command.args)
+        .stdin(Stdio::piped())
+        .stdout(Stdio::null())
+        .stderr(Stdio::null())
+        .spawn()
+    {
+        Ok(child) => child,
+        Err(_) => return false,
+    };
+
+    let Some(mut stdin) = child.stdin.take() else {
+        let _ = child.kill();
+        let _ = child.wait();
+        return false;
+    };
+
+    if stdin.write_all(bytes).is_err() {
+        let _ = child.kill();
+        let _ = child.wait();
+        return false;
+    }
+    drop(stdin);
+
+    if command.program == "wl-copy" {
+        return wait_for_wl_copy_startup(child);
+    }
+
+    child.wait().map(|status| status.success()).unwrap_or(false)
+}
+
+fn wait_for_wl_copy_startup(mut child: std::process::Child) -> bool {
+    const STARTUP_WAIT: std::time::Duration = std::time::Duration::from_millis(100);
+    const POLL_INTERVAL: std::time::Duration = std::time::Duration::from_millis(5);
+
+    let deadline = std::time::Instant::now() + STARTUP_WAIT;
+    loop {
+        match child.try_wait() {
+            Ok(Some(status)) => return status.success(),
+            Ok(None) if std::time::Instant::now() < deadline => {
+                std::thread::sleep(POLL_INTERVAL);
+            }
+            Ok(None) => return detach_clipboard_owner(child),
+            Err(_) => {
+                let _ = child.kill();
+                let _ = child.wait();
+                return false;
+            }
+        }
+    }
+}
+
+fn detach_clipboard_owner(child: std::process::Child) -> bool {
+    let pid = child.id();
+    let child = std::sync::Arc::new(std::sync::Mutex::new(child));
+    let reaper_child = std::sync::Arc::clone(&child);
+    let reaper = std::thread::Builder::new()
+        .name("herdr-wl-copy-reaper".to_string())
+        .spawn(move || {
+            let wait_result = match reaper_child.lock() {
+                Ok(mut child) => child.wait(),
+                Err(poisoned) => poisoned.into_inner().wait(),
+            };
+            if let Err(err) = wait_result {
+                tracing::warn!(pid, %err, "failed to reap wl-copy clipboard owner");
+            }
+        });
+
+    if let Err(err) = reaper {
+        tracing::warn!(pid, %err, "failed to start wl-copy clipboard owner reaper");
+        let mut child = match child.lock() {
+            Ok(child) => child,
+            Err(poisoned) => poisoned.into_inner(),
+        };
+        let _ = child.kill();
+        let _ = child.wait();
+        return false;
+    }
+
+    true
+}
+fn process_session_id(pid: u32) -> Option<i32> {
+    proc_entry(pid).map(|entry| entry.sid)
+}
