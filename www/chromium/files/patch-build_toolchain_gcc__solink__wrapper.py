--- build/toolchain/gcc_solink_wrapper.py.orig	2026-09-25 15:26:43 UTC
+++ build/toolchain/gcc_solink_wrapper.py
@@ -41,7 +41,7 @@ def CollectDynSym(args):
     toc = ''
     nm = subprocess.Popen(
         wrapper_utils.CommandToRun(
-            [args.nm, '--format=posix', '-g', '-D', '-p', args.output]
+            [args.nm, '-g', '-D', '-p', args.output]
         ),
         stdout=subprocess.PIPE,
         bufsize=-1,
