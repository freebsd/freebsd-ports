
$FreeBSD$

--- main/bfilter.cpp.orig	Sat Jul 17 12:25:27 2004
+++ main/bfilter.cpp	Sat Jul 17 12:25:51 2004
@@ -118,7 +118,7 @@
 	int idle_timer = 0;
 	uint8_t recv_buf[8192];
 	enum { IOV_ELEMENTS = 4 };
-	Network::iovec iov[IOV_ELEMENTS];
+	Network::IoVec iov[IOV_ELEMENTS];
 	
 	while (true) {
 		FD_ZERO(&rfds);
