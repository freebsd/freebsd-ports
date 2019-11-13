--- components/gcm_driver/gcm_client_impl.cc.orig	2019-09-09 21:55:14 UTC
+++ components/gcm_driver/gcm_client_impl.cc
@@ -134,6 +134,9 @@ void ToCheckinProtoVersion(
     case GCMClient::PLATFORM_CROS:
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_CROS;
       break;
+    case GCMClient::PLATFORM_BSD:
+      platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
+      break;
     case GCMClient::PLATFORM_UNSPECIFIED:
       // For unknown platform, return as LINUX.
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
