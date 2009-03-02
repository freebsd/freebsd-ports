--- kaffeine/src/input/dvb/plugins/epg/kaffeinedvbsection.cpp.orig	2008-01-30 22:22:36.000000000 +0100
+++ kaffeine/src/input/dvb/plugins/epg/kaffeinedvbsection.cpp	2008-01-30 22:26:23.000000000 +0100
@@ -134,13 +134,14 @@
 bool KaffeineDVBsection::doIconv( QCString &s, QCString table, char *buffer, int buflen )
 {
 	size_t inSize, outSize=buflen;
-	char *inBuf, *outBuf;
+	const char *inBuf;
+	char *outBuf;
 	iconv_t cd;
 
 	inSize = s.length();
 	if ( inSize<1 )
 		return false;
-	cd = iconv_open( "UTF8", table );
+	cd = iconv_open( "UTF-8", table );
 	inBuf = s.data();
 	outBuf = buffer;
 	outBuf[0] = 0;
@@ -230,7 +231,8 @@
 	char c[4];
 	QString s;
 
-	memset( mempcpy( c, buf+2, 3 ), 0, 1 );
+	memcpy(c,buf+2,3);
+	c[3] = 0;
 	s = c;
 	return s;
 }
