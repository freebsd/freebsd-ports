deno doesn't provide a precompiled binary for denort on FreeBSD
deno will search a binary in a "target" directory, use "bin" instead
since we install denort in /usr/local/bin/denort

The env variable DENORT_BIN can also be used to point to
another binary

Index: cli/standalone/binary.rs
--- cli/standalone/binary.rs.orig	2025-03-21 06:07:53 UTC
+++ cli/standalone/binary.rs
@@ -911,7 +911,7 @@ fn write_binary_bytes(
   compile_flags: &CompileFlags,
 ) -> Result<(), AnyError> {
   let target = compile_flags.resolve_target();
-  if target.contains("linux") {
+  if target.contains("freebsd") {
     libsui::Elf::new(&original_bin).append(
       "d3n0l4nd",
       &data_section_bytes,
@@ -1078,7 +1078,7 @@ fn get_dev_binary_path() -> Option<OsString> {
     env::current_exe().ok().and_then(|exec_path| {
       if exec_path
         .components()
-        .any(|component| component == Component::Normal("target".as_ref()))
+        .any(|component| component == Component::Normal("bin".as_ref()))
       {
         get_denort_path(exec_path)
       } else {
