--- third_party/blink/renderer/build/scripts/run_with_pythonpath.py.orig	2026-11-11 14:44:17 UTC
+++ third_party/blink/renderer/build/scripts/run_with_pythonpath.py
@@ -23,6 +23,7 @@ def main():
             (os.pathsep + env['PYTHONPATH']) if 'PYTHONPATH' in env else ''
         )
         env['PYTHONPATH'] = os.pathsep.join(python_paths) + existing_pp
+    env['LD_LIBRARY_PATH'] = "${WRKSRC}/out/Release"
     sys.exit(subprocess.call([sys.executable] + args, env=env))
 
 
