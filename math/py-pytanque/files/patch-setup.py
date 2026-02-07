--- setup.py.orig	2021-09-29 05:21:08 UTC
+++ setup.py
@@ -3,11 +3,11 @@ import glob
 import platform
 import subprocess
 
-if platform.system() in ("Linux","Darwin"):
+if platform.system() in ("Linux","Darwin","FreeBSD"):
     # This will work w/ GCC and clang
     compile_args = ['-std=c++14','-flto','-Dpetanque_STATIC']
     link_args = ['-flto']
-    if platform.system() == "Linux":
+    if platform.system() == "Linux" or platform.system() == "FreeBSD":
         link_args = ["-Wl,--strip-all","-Wl,-gc-sections"]
 elif platform.system() == "Windows":
     compile_args = ['/Dpetanque_STATIC','/TP', '/EHsc']
