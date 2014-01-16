--- ./addons/pvr.wmc/src/Socket.cpp.orig	2014-01-04 10:22:39.000000000 +0000
+++ ./addons/pvr.wmc/src/Socket.cpp	2014-01-13 18:50:49.000000000 +0000
@@ -442,7 +442,7 @@
 	}
 }
 
-#elif defined TARGET_LINUX || defined TARGET_DARWIN
+#elif defined TARGET_LINUX || defined TARGET_DARWIN || defined TARGET_FREEBSD
 bool Socket::set_non_blocking ( const bool b )
 {
 	int opts;
@@ -554,7 +554,7 @@
 {
 	// Not needed for Linux
 }
-#endif //TARGET_WINDOWS || TARGET_LINUX || TARGET_DARWIN
+#endif //TARGET_WINDOWS || TARGET_LINUX || TARGET_DARWIN || TARGET_FREEBSD
 
 
 void Socket::SetServerName(CStdString strServerName)
