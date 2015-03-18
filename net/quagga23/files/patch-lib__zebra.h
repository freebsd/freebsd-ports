--- lib/zebra.h.orig	2014-08-25 16:56:53 UTC
+++ lib/zebra.h
@@ -358,7 +358,8 @@
  * OpenBSD: network byte order, apart from older versions which are as per 
  *          *BSD
  */
-#if defined(__NetBSD__) || defined(__FreeBSD__) \
+#if defined(__NetBSD__) \
+   || (defined(__FreeBSD__) && (__FreeBSD_version < 1100030)) \
    || (defined(__OpenBSD__) && (OpenBSD < 200311)) \
    || (defined(__APPLE__)) \
    || (defined(SUNOS_5) && defined(WORDS_BIGENDIAN))
