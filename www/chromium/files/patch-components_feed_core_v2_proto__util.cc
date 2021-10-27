--- components/feed/core/v2/proto_util.cc.orig	2021-09-24 04:26:03 UTC
+++ components/feed/core/v2/proto_util.cc
@@ -85,8 +85,8 @@ feedwire::Version GetPlatformVersionMessage() {
 
   int32_t major, minor, revision;
   base::SysInfo::OperatingSystemVersionNumbers(&major, &minor, &revision);
-  result.set_major(major);
-  result.set_minor(minor);
+  result.set_gmajor(major);
+  result.set_gminor(minor);
   result.set_revision(revision);
 #if defined(OS_ANDROID)
   result.set_api_version(base::android::BuildInfo::GetInstance()->sdk_int());
@@ -101,8 +101,8 @@ feedwire::Version GetAppVersionMessage(const ChromeInf
   // Chrome's version is in the format: MAJOR,MINOR,BUILD,PATCH.
   const std::vector<uint32_t>& numbers = chrome_info.version.components();
   if (numbers.size() > 3) {
-    result.set_major(static_cast<int32_t>(numbers[0]));
-    result.set_minor(static_cast<int32_t>(numbers[1]));
+    result.set_gmajor(static_cast<int32_t>(numbers[0]));
+    result.set_gminor(static_cast<int32_t>(numbers[1]));
     result.set_build(static_cast<int32_t>(numbers[2]));
     result.set_revision(static_cast<int32_t>(numbers[3]));
   }
