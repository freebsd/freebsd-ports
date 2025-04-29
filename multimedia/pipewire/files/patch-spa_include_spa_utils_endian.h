--- spa/include/spa/utils/endian.h.orig	2025-03-14 10:07:06 UTC
+++ spa/include/spa/utils/endian.h
@@ -5,7 +5,7 @@
 #ifndef SPA_ENDIAN_H
 #define SPA_ENDIAN_H
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if defined(__MidnightBSD__)
 #include <sys/endian.h>
 #define bswap_16 bswap16
 #define bswap_32 bswap32
