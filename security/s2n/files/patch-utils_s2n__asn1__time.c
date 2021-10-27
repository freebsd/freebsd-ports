--- utils/s2n_asn1_time.c.orig	2021-10-21 18:40:29 UTC
+++ utils/s2n_asn1_time.c
@@ -47,7 +47,7 @@ typedef enum parser_state {
 
 static inline long get_gmt_offset(struct tm *t) {
     /* See: https://sourceware.org/git/?p=glibc.git;a=blob;f=include/features.h;h=ba272078cf2263ec88e039fda7524c136a4a7953;hb=HEAD */
-#if defined(__USE_MISC) || defined(__ANDROID__) || defined(ANDROID) || (defined(__APPLE__) && defined(__MACH__))
+#if defined(__USE_MISC) || defined(__ANDROID__) || defined(ANDROID) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
     return t->tm_gmtoff;
 #else
     return t->__tm_gmtoff;
