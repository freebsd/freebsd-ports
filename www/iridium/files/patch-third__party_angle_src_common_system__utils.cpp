--- third_party/angle/src/common/system_utils.cpp.orig	2025-12-10 15:04:57 UTC
+++ third_party/angle/src/common/system_utils.cpp
@@ -25,7 +25,7 @@ namespace angle
 {
 std::string GetExecutableName()
 {
-#if defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21
+#if (defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21) || defined(ANGLE_PLATFORM_BSD)
     // Support for "getprogname" function in bionic was introduced in L (API level 21)
     const char *executableName = getprogname();
     return (executableName) ? std::string(executableName) : "ANGLE";
