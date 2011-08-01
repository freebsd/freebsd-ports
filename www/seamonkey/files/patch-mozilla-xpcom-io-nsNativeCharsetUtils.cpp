--- mozilla/xpcom/io/nsNativeCharsetUtils.cpp.orig	2011-06-16 15:45:54.000000000 +0200
+++ mozilla/xpcom/io/nsNativeCharsetUtils.cpp	2011-06-16 15:46:49.000000000 +0200
@@ -96,11 +96,11 @@
 // iconv for all platforms where nltypes.h and nllanginfo.h are present 
 // along with iconv.
 //
-#if defined(HAVE_ICONV) && defined(HAVE_NL_TYPES_H) && defined(HAVE_LANGINFO_CODESET)
-#define USE_ICONV 1
-#else
+//#if defined(HAVE_ICONV) && defined(HAVE_NL_TYPES_H) && defined(HAVE_LANGINFO_CODESET)
+//#define USE_ICONV 1
+//#else
 #define USE_STDCONV 1
-#endif
+//#endif
 
 static void
 isolatin1_to_utf16(const char **input, PRUint32 *inputLeft, PRUnichar **output, PRUint32 *outputLeft)
