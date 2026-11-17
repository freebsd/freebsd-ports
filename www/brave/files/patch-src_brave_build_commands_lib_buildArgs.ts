--- src/brave/build/commands/lib/buildArgs.ts.orig	2026-10-18 18:43:23 UTC
+++ src/brave/build/commands/lib/buildArgs.ts
@@ -35,6 +35,13 @@ const FORWARD_ENV_CONFIG_VARS_TO_GN_ARGS
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
@@ -167,7 +174,7 @@ export function getBuildArgs(config: Con
   // 3. On Android Release x64/arm64, debug sections exceed 4GiB causing
   //    "relocation R_X86_64_32 out of range" linker errors.
   if (
-    (config.targetOS === 'linux'
+    (isLinuxLike(config.targetOS)
       && (config.targetArch === 'x86'
         || (!config.isDebug()
           && !config.isComponentBuild()
@@ -187,7 +194,7 @@ export function getBuildArgs(config: Con
 
   // For Linux Release builds, upstream doesn't want to use symbol_level = 2
   // unless use_debug_fission is set.
-  if (config.targetOS === 'linux' && config.isReleaseBuild()) {
+  if (isLinuxLike(config.targetOS) && config.isReleaseBuild()) {
     // use_debug_fission requires symbol_level >= 1
     args.symbol_level = 1
     args.use_debug_fission = true
@@ -209,6 +216,21 @@ export function getBuildArgs(config: Con
     args.use_system_xcode = false
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
   if (config.targetOS === 'linux') {
     if (config.targetArch !== 'x86') {
       // Include vaapi support
