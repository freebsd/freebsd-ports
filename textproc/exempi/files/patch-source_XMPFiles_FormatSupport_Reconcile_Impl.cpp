--- source/XMPFiles/FormatSupport/Reconcile_Impl.cpp.orig	2008-02-26 11:56:56.000000000 -0500
+++ source/XMPFiles/FormatSupport/Reconcile_Impl.cpp	2008-02-26 12:04:09.000000000 -0500
@@ -249,7 +249,7 @@
 	
 		iconv_t cd = iconv_open( "ISO8859-1", "UTF-8" );
 
-		char * in = (char *)utf8Ptr;
+		const char * in = (char *)utf8Ptr;
 		size_t inLen = utf8Len;
 		size_t outLen = utf8Len * 4;
 		char * buf = (char *)calloc( outLen, 1 );
@@ -406,7 +406,7 @@
 	
 		iconv_t cd = iconv_open( "UTF-8", "ISO8859-1" );
 
-		char * in = (char *)_latin1Ptr;
+		const char * in = (char *)_latin1Ptr;
 		size_t inLen = latin1Len;
 		size_t outLen = latin1Len * 4;
 		char * buf = (char *)calloc( outLen, 1 );
