--- components/gcm_driver/gcm_client_impl.cc.orig	2017-04-19 19:06:32 UTC
+++ components/gcm_driver/gcm_client_impl.cc
@@ -136,6 +136,9 @@ void ToCheckinProtoVersion(
     case GCMClient::PLATFORM_CROS:
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_CROS;
       break;
+    case GCMClient::PLATFORM_BSD: // TODO what the hell are those?
+      platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
+      break;
     case GCMClient::PLATFORM_UNKNOWN:
       // For unknown platform, return as LINUX.
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
