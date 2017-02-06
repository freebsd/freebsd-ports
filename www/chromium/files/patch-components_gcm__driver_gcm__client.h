--- components/gcm_driver/gcm_client.h.orig	2017-01-26 00:49:11 UTC
+++ components/gcm_driver/gcm_client.h
@@ -80,6 +80,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNKNOWN
   };
 
