--- src/casyncconn.cpp.orig	2009-07-10 20:23:05.000000000 +0200
+++ src/casyncconn.cpp	2014-09-08 18:37:50.000000000 +0200
@@ -90,7 +90,6 @@
 cAsyncConn::cAsyncConn(int desc, cAsyncSocketServer *s, tConnType ct):
 	cObj("cAsyncConn"),
 	mSockDesc(desc),
-	mIterator(0),
 	ok(desc>0),
 	mWritable(true),
 	mExtraPoll(0),
@@ -147,7 +146,6 @@
 	mBufReadPos(0),
 	mRegFlag(0),
 	mCloseAfter(0,0),
-	mIterator(0),
 	ok(false),
 	mWritable(true),
 	mExtraPoll(0),
