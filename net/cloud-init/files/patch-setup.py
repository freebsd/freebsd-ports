--- setup.py.orig	2021-03-17 15:40:30 UTC
+++ setup.py
@@ -153,7 +153,7 @@ INITSYS_TYPES = sorted([f.partition(".")[0] for f in I
 # Install everything in the right location and take care of Linux (default) and
 # FreeBSD systems.
 USR = "usr"
-ETC = "etc"
+ETC = "%%PREFIX%%/etc"
 USR_LIB_EXEC = "usr/lib"
 LIB = "lib"
 if os.uname()[0] == 'FreeBSD':
