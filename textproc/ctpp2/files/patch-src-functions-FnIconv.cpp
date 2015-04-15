--- src/functions/FnIconv.cpp.orig	2012-08-02 07:22:44 UTC
+++ src/functions/FnIconv.cpp
@@ -145,7 +145,7 @@ INT_32 FnIconv::Handler(CDT            *
 		}
 	}
 
-#if (_LIBICONV_VERSION >= 0x0108)
+#if (_LIBICONV_VERSION >= 0x0108) || defined(__FreeBSD__)
 	int iFlag = 1;
 	// Discard illegal characters
 	if (iFlags & C_ICONV_DISCARD_ILSEQ)
@@ -173,7 +173,7 @@ INT_32 FnIconv::Handler(CDT            *
 	size_t iDstLength     = CTPP_ESCAPE_BUFFER_LEN;
 
 	char         aDstData[CTPP_ESCAPE_BUFFER_LEN];
-#if defined(linux) || defined(__APPLE__)
+#if defined(linux) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	char       * aSrcData = (char *)sWhat.data();
 #else
 	const char * aSrcData = (const char *)sWhat.data();
