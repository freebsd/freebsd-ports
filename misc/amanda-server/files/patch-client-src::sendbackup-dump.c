--- client-src/sendbackup-dump.c.orig	2011-04-24 16:41:40.874642189 +0900
+++ client-src/sendbackup-dump.c	2011-04-24 16:42:28.215501968 +0900
@@ -377,7 +377,7 @@
 #endif
 
 #ifdef __FreeBSD__
-# if defined(__FreeBSD_version) && (__FreeBSD_version >= 500043)
+# if defined(__FreeBSD_version) && (__FreeBSD_version >= 500043) && !defined(FreeBSD_NO_SNAPSHOT_DUMP)
 #  define FREEBSD_EXTRA_KEYS "bL"
 # else
 #  define FREEBSD_EXTRA_KEYS "b"
