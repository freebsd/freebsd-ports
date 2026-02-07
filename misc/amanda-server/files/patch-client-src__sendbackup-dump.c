--- client-src/sendbackup-dump.c.orig	2017-12-01 13:26:32 UTC
+++ client-src/sendbackup-dump.c
@@ -428,7 +428,7 @@ char *progname;
 #endif
 
 #ifdef __FreeBSD__
-# if defined(__FreeBSD_version) && (__FreeBSD_version >= 500043)
+# if defined(__FreeBSD_version) && (__FreeBSD_version >= 500043) && !defined(FreeBSD_NO_SNAPSHOT_DUMP)
 #  define FREEBSD_EXTRA_KEYS "bL"
 # else
 #  define FREEBSD_EXTRA_KEYS "b"
