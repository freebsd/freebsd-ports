--- components/gcm_driver/gcm_client.h.orig	2021-03-12 23:57:22 UTC
+++ components/gcm_driver/gcm_client.h
@@ -87,6 +87,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
