--- WebServer.m.orig	2011-04-01 06:15:13.000000000 +0200
+++ WebServer.m	2011-04-16 11:24:04.000000000 +0200
@@ -46,6 +46,10 @@
 
 #define	Alloc(X)	[(X) allocWithZone: defaultMallocZone]
 
+#if (MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4)
+#define object_getClass(object) (object->class_pointer)
+#endif
+
 @implementation	WebServer
 
 + (void) initialize
