--- kaffeine/src/input/dvb/dvbsection.cpp.orig	2007-07-28 18:45:37.000000000 +0200
+++ kaffeine/src/input/dvb/dvbsection.cpp	2007-07-29 15:30:30.000000000 +0200
@@ -157,7 +157,8 @@
 	int i;
 	char buffer[1000];
 	size_t inSize, outSize=sizeof(buffer);
-	char *inBuf, *outBuf;
+	const char *inBuf;
+	char *outBuf;
 	iconv_t cd;
 	QCString table=defaultCharset;
 
@@ -232,7 +233,8 @@
 	char c[4];
 	QString s;
 
-	memset( mempcpy( c, buf+2, 3 ), 0, 1 );
+	memcpy(c,buf+2,3);
+	c[3] = 0;
 	s = c;
 	return s;
 }
