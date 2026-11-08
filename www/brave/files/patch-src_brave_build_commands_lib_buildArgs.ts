--- src/brave/build/commands/lib/buildArgs.ts.orig	2026-06-01 00:00:00 UTC
+++ src/brave/build/commands/lib/buildArgs.ts
@@ -36,6 +36,13 @@
   'is_brave_origin_branded',
 ]
 
+// FreeBSD is built with the Chromium Linux configuration: the FreeBSD Chromium
+// port patches build/config/BUILDCONFIG.gn so that target_os="freebsd" turns on
+// is_linux (and is_bsd) in GN.
+function isLinuxLike(targetOS: string | undefined) {
+  return targetOS === 'linux' || targetOS === 'freebsd'
+}
+
 export function getBuildArgs(config: Config) {
   let args: Record<string, any> = {
     'import("//brave/build/args/brave_defaults.gni")': null,
@@ -178,7 +185,7 @@
   // 3. On Android Release x64/arm64, debug sections exceed 4GiB causing
   //    "relocation R_X86_64_32 out of range" linker errors.
   if (
-    (config.targetOS === 'linux'
+    (isLinuxLike(config.targetOS)
       && (config.targetArch === 'x86'
         || (!config.isDebug()
           && !config.isComponentBuild()
@@ -199,7 +206,7 @@
   // For Linux Release builds, upstream doesn't want to use symbol_level = 2
   // unless use_debug_fission is set. However, they don't set it when a
   // cc_wrapper is used. Since we use cc_wrapper we need to set it manually.
-  if (config.targetOS === 'linux' && config.isReleaseBuild()) {
+  if (isLinuxLike(config.targetOS) && config.isReleaseBuild()) {
     // use_debug_fission requires symbol_level >= 1
     args.symbol_level = 1
     args.use_debug_fission = true
@@ -231,6 +238,21 @@
     }
   }
 
+  if (config.targetOS === 'freebsd') {
+    // Nothing is downloaded on FreeBSD: there is no hermetic toolchain, no
+    // sysroot, no PGO profile and no depot_tools, so the build has to rely on
+    // the compiler and the libraries installed from ports.
+    args.use_sysroot = false
+    args.clang_use_chrome_plugins = false
+    args.enable_nacl = false
+    args.chrome_pgo_phase = 0
+    args.use_remoteexec = false
+    args.use_reclient = false
+    args.use_siso = false
+    args.treat_warnings_as_errors = false
+    args.fatal_linker_warnings = false
+  }
+
   // Devtools: Now we patch devtools frontend, so it is useful to see
   // if something goes wrong on CI builds.
   if (config.targetOS !== 'android' && config.targetOS !== 'ios' && isCI) {
