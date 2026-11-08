Add support for FreeBSD equivalent of /proc/self/fd through a special
fdescfs mount with option "nodup". This filesystem should be mounted
either to the private $PIDDIR/fd/ directory or to /dev/fd in order to
provide security and performance characteristics similar to Linux.

Without this, fsp->fsp_flags.have_proc_fds is always false on FreeBSD,
which silently degrades the pathref/ACL fd-resolution logic in
vfs_zfsacl.c and vfs_freebsd.c to a less secure, non-race-free
path-based fallback (see also patch-source3_modules_vfs__zfsacl.c and
patch-source3_modules_vfs__freebsd.c, both of which branch on
fsp->fsp_flags.have_proc_fds).

Adapted for the struct sys_proc_fd_path_buf-based sys_proc_fd_path()
signature introduced upstream in Samba 4.24 (see
source3/include/proto.h: "struct sys_proc_fd_path_buf { char buf[35]; }").

Originally-based-on: 0028-s3-lib-system-add-FreeBSD-proc_fd_pattern.patch
(Timur I. Bakeyev, adapted for Samba 4.20 by Andrea Venturoli, carried
in net/samba419, net/samba420, net/samba422, net/samba423).

--- source3/lib/system.c.orig	2026-01-20 15:42:54 UTC
+++ source3/lib/system.c
@@ -970,6 +970,71 @@ char *sys_realpath(const char *path)
 	return result;
 }

+#if defined(FREEBSD)
+static bool freebsd_fdesc_check(const char *pattern)
+{
+	char fdesc_path[PATH_MAX];
+	int fd, fd2;
+
+	fd = open(lp_pid_directory(), O_DIRECTORY);
+	if (fd == -1) {
+		DBG_ERR("%s: failed to open pid directory: %s\n",
+			lp_pid_directory(), strerror(errno));
+		return false;
+	}
+
+	snprintf(fdesc_path, sizeof(fdesc_path), pattern, fd);
+
+	fd2 = open(fdesc_path, O_DIRECTORY);
+	if (fd2 == -1) {
+		/*
+		 * Setting O_DIRECTORY on open of fdescfs mount
+		 * without 'nodup' option will fail with ENOTDIR.
+		 */
+		if (errno == ENOTDIR) {
+			DBG_ERR("%s: fdescfs filesystem is not mounted with "
+				"'nodup' option. This specific mount option is "
+				"required in order to enable race-free handling "
+				"of paths.\n"
+				"See documentation for Samba's New VFS "
+				"for more details. The 'nodup' mount option was "
+				"introduced in FreeBSD 13.\n", fdesc_path);
+			close(fd);
+			return false;
+		}
+		DBG_ERR("%s: failed to open fdescfs path: %s\n",
+			fdesc_path, strerror(errno));
+		close(fd);
+		return false;
+	}
+	close(fd);
+	close(fd2);
+
+	return true;
+}
+
+static char *freebsd_pattern(char *buf, size_t bufsize)
+{
+	const char *base_dir[] = {
+		lp_pid_directory(), /* This is a preferred location */
+		"/dev",
+		NULL
+	};
+	const char **base;
+
+	for (base = &base_dir[0]; *base != NULL; base++) {
+		snprintf(buf, bufsize, "%s/fd/%%d", *base);
+		if (freebsd_fdesc_check(buf)) {
+			return buf;
+		}
+	}
+	return NULL;
+}
+
+static char proc_fd_pattern_buf[PATH_MAX];
+static const char *proc_fd_pattern = NULL;
+#endif /* defined(FREEBSD) */
+
 bool sys_have_proc_fds(void)
 {
 	static bool checked = false;
@@ -981,8 +1046,17 @@ bool sys_have_proc_fds(void)
 		return have_proc_fds;
 	}

+#if defined(FREEBSD)
+	if (freebsd_pattern(proc_fd_pattern_buf, sizeof(proc_fd_pattern_buf)) != NULL) {
+		have_proc_fds = true;
+		proc_fd_pattern = proc_fd_pattern_buf;
+	} else {
+		have_proc_fds = false;
+	}
+#else
 	ret = stat("/proc/self/fd/0", &sb);
 	have_proc_fds = (ret == 0);
+#endif
 	checked = true;

 	return have_proc_fds;
@@ -990,10 +1064,38 @@ bool sys_have_proc_fds(void)

 char *sys_proc_fd_path(int fd, struct sys_proc_fd_path_buf *buf)
 {
+#if defined(FREEBSD)
+	bool have_proc_fds = sys_have_proc_fds();
+	int written;
+
+	SMB_ASSERT(have_proc_fds);
+
+#if defined(__clang__)
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
+	written = snprintf(buf->buf, sizeof(buf->buf), proc_fd_pattern, fd);
+#if defined(__clang__)
+#pragma clang diagnostic pop
+#endif
+
+	/*
+	 * struct sys_proc_fd_path_buf is sized tightly for the fixed-length
+	 * Linux "/proc/self/fd/<fd>" string. Our FreeBSD pattern is based on
+	 * lp_pid_directory() or "/dev", which can in principle be longer
+	 * under an unusual install prefix. snprintf() never overflows the
+	 * buffer, but a truncated path would silently resolve to the wrong
+	 * file, so fail loudly instead of returning a truncated path.
+	 */
+	SMB_ASSERT(written >= 0 && (size_t)written < sizeof(buf->buf));
+
+	return buf->buf;
+#else
 	int written =
 		snprintf(buf->buf, sizeof(buf->buf), "/proc/self/fd/%d", fd);

 	SMB_ASSERT(sys_have_proc_fds() && (written >= 0));

 	return buf->buf;
+#endif
 }
