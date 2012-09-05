--- include/vlc_common.h.orig
+++ include/vlc_common.h
@@ -642,7 +642,7 @@ static inline unsigned popcount (unsigne
 #endif
 }
 
-#ifdef __OS2__
+#if defined(__OS2__) || defined(__FreeBSD__)
 #   undef bswap16
 #   undef bswap32
 #   undef bswap64
