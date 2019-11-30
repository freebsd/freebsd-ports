--- btsixad/vuhid.c.orig	2014-07-27 15:28:06 UTC
+++ btsixad/vuhid.c
@@ -14,7 +14,7 @@
 #include <unistd.h>
 #include <dev/usb/usb_ioctl.h>
 
-#include <cuse4bsd.h>
+#include <cuse.h>
 
 #ifndef CUSE_ID_BTSIXAD
 #define CUSE_ID_BTSIXAD(what) CUSE_MAKE_ID('6', 'A', what, 0)
@@ -188,10 +188,10 @@ vuhid_init()
         const char* error;
         switch (r) {
         case CUSE_ERR_NOT_LOADED:
-            error = "kldload cuse4bsd";
+            error = "kldload cuse";
             break;
         case CUSE_ERR_INVALID:
-            error = "cuse4bsd not accessible";
+            error = "cuse not accessible";
             break;
         default:
             error = "cuse_init() failed";
