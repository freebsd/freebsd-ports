--- components/gcm_driver/gcm_client_impl.cc.orig	2018-06-13 00:10:13.000000000 +0200
+++ components/gcm_driver/gcm_client_impl.cc	2018-07-18 23:56:44.202609000 +0200
@@ -152,6 +152,9 @@
     case GCMClient::PLATFORM_CROS:
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_CROS;
       break;
+    case GCMClient::PLATFORM_BSD:
+      platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
+      break;
     case GCMClient::PLATFORM_UNSPECIFIED:
       // For unknown platform, return as LINUX.
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
