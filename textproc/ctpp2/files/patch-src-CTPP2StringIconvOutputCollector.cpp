--- src/CTPP2StringIconvOutputCollector.cpp.orig	2012-08-02 07:22:44 UTC
+++ src/CTPP2StringIconvOutputCollector.cpp
@@ -56,7 +56,7 @@ StringIconvOutputCollector::StringIconvO
 		throw CTPPCharsetRecodeException(sSrcEnc.c_str(), sDstEnc.c_str());
 	}
 
-#if (_LIBICONV_VERSION >= 0x0108)
+#if (_LIBICONV_VERSION >= 0x0108) || defined(__FreeBSD__)
 	int iFlag = 1;
 	// Discard illegal characters
 	if (iFlags & C_ICONV_DISCARD_ILSEQ) { iconvctl(oIconv, ICONV_SET_DISCARD_ILSEQ, &iFlag); }
@@ -85,7 +85,7 @@ INT_32 StringIconvOutputCollector::Colle
 	size_t iDstLength     = CTPP_ESCAPE_BUFFER_LEN;
 
 	char         aDstData[CTPP_ESCAPE_BUFFER_LEN];
-#if defined(linux) || defined(__APPLE__)
+#if defined(linux) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 	char       * aSrcData = (char *)vData;
 #else
 	const char * aSrcData = (const char *)vData;
