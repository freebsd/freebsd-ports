--- setup.py.orig	2014-04-13 10:53:47 UTC
+++ setup.py
@@ -22,7 +22,7 @@ import platform
 
 # Version of optimized implementation to use.
 
-if platform.machine() == "x86_64":
+if platform.machine() == "x86_64" or platform.machine() == "amd64":
     # Every x86_64 machine has at least SSE2.
     opt_version = "BLAKE2_COMPRESS_SSE2"
 else:
