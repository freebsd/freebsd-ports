--- src/webrtc/src/third_party/perfetto/src/base/string_utils.cc.orig	2023-12-10 06:10:27 UTC
+++ src/webrtc/src/third_party/perfetto/src/base/string_utils.cc
@@ -39,7 +39,8 @@ namespace base { 
 // Locale-independant as possible version of strtod.
 double StrToD(const char* nptr, char** endptr) {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   static auto c_locale = newlocale(LC_ALL, "C", nullptr);
   return strtod_l(nptr, endptr, c_locale);
