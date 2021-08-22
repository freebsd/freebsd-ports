--- build/linux/strip_binary.py.orig	2021-08-17 16:45:54 UTC
+++ build/linux/strip_binary.py
@@ -19,8 +19,7 @@ def main():
   args = argparser.parse_args()
 
   cmd_line = [
-      args.eu_strip_binary_path, '-o', args.stripped_binary_output, '-f',
-      args.symbol_output, args.binary_input
+      args.eu_strip_binary_path, '-o', args.stripped_binary_output, args.binary_input
   ]
 
   process = subprocess.Popen(cmd_line)
