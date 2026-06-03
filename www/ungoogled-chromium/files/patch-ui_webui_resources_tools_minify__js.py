--- ui/webui/resources/tools/minify_js.py.orig	2026-05-09 18:09:27 UTC
+++ ui/webui/resources/tools/minify_js.py
@@ -32,7 +32,7 @@ def main(argv):
   # Spawn a NodeJS script to use the programmatic Terser API, since the CLI API
   # does not allow compressing multiple files at once. This is done to avoid
   # launching NodeJS once for every input file.
-  node.RunNode([
+  node.RunNode(['--jitless',
       os.path.join(_HERE_PATH, 'minify_js.js'), '--in_folder', in_path,
       '--out_folder', out_path
   ] + args.in_files)
