--- components/gcm_driver/gcm_client_impl.cc.orig	2016-10-06 04:02:16.000000000 +0300
+++ components/gcm_driver/gcm_client_impl.cc	2016-10-13 13:07:14.340338000 +0300
@@ -137,6 +137,9 @@
     case GCMClient::PLATFORM_CROS:
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_CROS;
       break;
+    case GCMClient::PLATFORM_BSD: // TODO what the hell are those?
+      platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
+      break;
     case GCMClient::PLATFORM_UNKNOWN:
       // For unknown platform, return as LINUX.
       platform = checkin_proto::ChromeBuildProto_Platform_PLATFORM_LINUX;
