--- ui/webui/resources/tools/minify_js.py.orig	2026-09-25 15:26:43 UTC
+++ ui/webui/resources/tools/minify_js.py
@@ -36,6 +36,7 @@ def main(argv):
   # launching NodeJS once for every input file.
   node.RunNode(
     [
+      '--jitless',
       os.path.join(_HERE_PATH, 'minify_js.js'),
       '--in_folder',
       in_path,
