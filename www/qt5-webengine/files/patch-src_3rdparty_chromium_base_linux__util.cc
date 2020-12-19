--- src/3rdparty/chromium/base/linux_util.cc.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/base/linux_util.cc
@@ -78,6 +78,9 @@ class DistroNameGetter {
  public:
   DistroNameGetter() {
     static const char* const kFilesToCheck[] = {"/etc/os-release",
+#if defined(OS_BSD)
+	                                        "%%LOCALBASE%%/etc/os-release",
+#endif
                                                 "/usr/lib/os-release"};
     for (const char* file : kFilesToCheck) {
       if (ReadDistroFromOSReleaseFile(file))
