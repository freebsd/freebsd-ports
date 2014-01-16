--- ./addons/pvr.nextpvr/src/Socket.cpp.orig	2014-01-04 10:22:39.000000000 +0000
+++ ./addons/pvr.nextpvr/src/Socket.cpp	2014-01-13 18:50:01.000000000 +0000
@@ -658,7 +658,7 @@
   }
 }
 
-#elif defined TARGET_LINUX || defined TARGET_DARWIN
+#elif defined TARGET_LINUX || defined TARGET_DARWIN || defined TARGET_FREEBSD
 bool Socket::set_non_blocking ( const bool b )
 {
   int opts;
@@ -767,6 +767,6 @@
 {
   // Not needed for Linux
 }
-#endif //TARGET_WINDOWS || TARGET_LINUX || TARGET_DARWIN
+#endif //TARGET_WINDOWS || TARGET_LINUX || TARGET_DARWIN || TARGET_FREEBSD
 
 } //namespace NextPVR
