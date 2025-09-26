--- node/build_node_bridge.py.orig	2025-09-26 09:35:20 UTC
+++ node/build_node_bridge.py
@@ -132,7 +132,7 @@ def main(args: Optional[List[str]] = None) -> int:
     else:
         features.append('log/release_max_level_info')
 
-    cmdline = ['cargo', 'build', '--target', cargo_target, '-p', 'libsignal-node', '--features', ','.join(features)]
+    cmdline = ['cargo', 'build', '-p', 'libsignal-node', '--features', ','.join(features)]
     if configuration_name == 'Release':
         cmdline.append('--release')
     else:
@@ -227,7 +227,6 @@ def main(args: Optional[List[str]] = None) -> int:
     subprocess.check_call(cmdline, env=cargo_env)
 
     libs_in = os.path.join(cargo_env['CARGO_BUILD_TARGET_DIR'],
-                           cargo_target,
                            configuration_name.lower())
 
     src_path = os.path.join(libs_in, lib_format.format('signal_node'))
