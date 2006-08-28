--- sshdistdefs.h.orig	Wed Dec  3 14:17:34 2003
+++ sshdistdefs.h	Sun Jul 30 15:29:21 2006
@@ -12,7 +12,9 @@
 #ifndef SSHDISTDEFS_H
 #define SSHDISTDEFS_H
 
+#if !defined(__FreeBSD__)
 #define SSHDIST_ZLIB_LEVEL_DETECTION
+#endif
 #define SSHDIST_CRYPT_HMAC
 #define SSHDIST_SESSION_SIA
 #define SSHDIST_SSH2_SOCKS_FILTER
