--- components/gcm_driver/gcm_client.h.orig	2017-03-09 20:04:31 UTC
+++ components/gcm_driver/gcm_client.h
@@ -78,6 +78,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNKNOWN
   };
 
