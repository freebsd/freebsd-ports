--- js/src/liveconnect/nsISecureLiveconnect.h.orig	2007-10-09 20:03:00.000000000 -0400
+++ js/src/liveconnect/nsISecureLiveconnect.h	2007-10-09 20:03:50.000000000 -0400
@@ -51,7 +51,11 @@
 #include "nsIFactory.h"
 #include "jni.h"
 
+#if JS_BYTES_PER_WORD == 8
+typedef jlong jsobject;
+#else
 typedef jint jsobject;
+#endif
 
 class nsISecureLiveconnect : public nsISupports {
 public:
