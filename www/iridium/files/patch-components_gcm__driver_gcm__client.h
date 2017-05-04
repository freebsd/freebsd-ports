--- components/gcm_driver/gcm_client.h.orig	2017-04-19 19:06:32 UTC
+++ components/gcm_driver/gcm_client.h
@@ -82,6 +82,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNKNOWN
   };
 
