--- components/gcm_driver/gcm_client.h.orig	2019-10-21 19:06:29 UTC
+++ components/gcm_driver/gcm_client.h
@@ -86,6 +86,7 @@ class GCMClient {
     PLATFORM_CROS,
     PLATFORM_IOS,
     PLATFORM_ANDROID,
+    PLATFORM_BSD,
     PLATFORM_UNSPECIFIED
   };
 
