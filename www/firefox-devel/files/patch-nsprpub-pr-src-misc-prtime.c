--- nsprpub/pr/src/misc/prtime.c.orig	Thu Feb 27 01:01:02 2003
+++ nsprpub/pr/src/misc/prtime.c	Thu May 22 16:46:49 2003
@@ -1666,7 +1666,7 @@
  */
 
 #if defined(SUNOS4) || (__GLIBC__ >= 2) || defined(XP_BEOS) \
-        || defined(NETBSD)
+        || defined(NETBSD) || defined(__FreeBSD__)
     a.tm_zone = NULL;
     a.tm_gmtoff = tm->tm_params.tp_gmt_offset + tm->tm_params.tp_dst_offset;
 #endif
