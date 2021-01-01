--- components/gcm_driver/gcm_client.h.orig	2020-02-03 21:53:30 UTC
+++ components/gcm_driver/gcm_client.h
@@ -87,6 +87,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
