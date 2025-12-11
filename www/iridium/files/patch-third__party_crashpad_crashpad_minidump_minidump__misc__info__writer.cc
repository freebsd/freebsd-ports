--- third_party/crashpad/crashpad/minidump/minidump_misc_info_writer.cc.orig	2025-12-10 15:04:57 UTC
+++ third_party/crashpad/crashpad/minidump/minidump_misc_info_writer.cc
@@ -159,6 +159,10 @@ std::string MinidumpMiscInfoDebugBuildString() {
   static constexpr char kOS[] = "win";
 #elif BUILDFLAG(IS_FUCHSIA)
   static constexpr char kOS[] = "fuchsia";
+#elif defined(OS_OPENBSD)
+  static constexpr char kOS[] = "openbsd";
+#elif defined(OS_FREEBSD)
+  static constexpr char kOS[] = "freebsd";
 #else
 #error define kOS for this operating system
 #endif
