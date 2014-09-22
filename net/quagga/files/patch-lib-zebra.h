--- lib/zebra.h.orig	2014-03-16 09:54:05.510349508 +0100
+++ lib/zebra.h	2014-03-16 10:57:36.640087484 +0100
@@ -355,7 +355,8 @@
  * OpenBSD: network byte order, apart from older versions which are as per 
  *          *BSD
  */
-#if defined(__NetBSD__) || defined(__FreeBSD__) \
+#if defined(__NetBSD__) \
+   || (defined(__FreeBSD__) && (__FreeBSD_version < 1100030)) \
    || (defined(__OpenBSD__) && (OpenBSD < 200311)) \
    || (defined(SUNOS_5) && defined(WORDS_BIGENDIAN))
 #define HAVE_IP_HDRINCL_BSD_ORDER
