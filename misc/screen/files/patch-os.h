--- os.h.orig	Tue Jan  8 07:42:33 2002
+++ os.h	Tue Sep  9 17:39:58 2003
@@ -161,7 +161,7 @@
 # define setregid(rgid, egid) setresgid(rgid, egid, -1)
 #endif
 
-#if defined(HAVE_SETEUID) || defined(HAVE_SETREUID)
+#if (defined(HAVE_SETEUID) || defined(HAVE_SETREUID)) && __FreeBSD_version < 500000
 # define USE_SETEUID
 #endif
 
