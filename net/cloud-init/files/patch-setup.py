--- setup.py.orig	2025-08-12 19:00:58 UTC
+++ setup.py
@@ -176,7 +176,7 @@ USR = "usr"
 # Install everything in the right location and take care of Linux (default) and
 # FreeBSD systems.
 USR = "usr"
-ETC = "etc"
+ETC = "%%PREFIX%%/etc"
 USR_LIB_EXEC = "usr/lib"
 LIB = "lib"
 if os.uname()[0] in ["FreeBSD", "DragonFly", "OpenBSD"]:
