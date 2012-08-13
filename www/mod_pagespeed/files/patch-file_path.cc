Index: third_party/chromium/src/base/sys_string_conversions_linux.cc
===================================================================
--- third_party/chromium/src/base/sys_string_conversions_linux.cc	(revision 90205)
+++ third_party/chromium/src/base/sys_string_conversions_linux.cc	(working copy)
@@ -97,6 +97,7 @@
   return out;
 }
 
+#if 0
 std::wstring SysNativeMBToWide(const StringPiece& native_mb) {
   mbstate_t ps;
 
@@ -153,6 +154,7 @@
 
   return out;
 }
+#endif
 
 #endif  // OS_CHROMEOS
 
Index: third_party/chromium/src/base/file_path.cc
===================================================================
--- third_party/chromium/src/base/file_path.cc	(revision 90205)
+++ third_party/chromium/src/base/file_path.cc	(working copy)
@@ -517,9 +517,11 @@
 // See file_path.h for a discussion of the encoding of paths on POSIX
 // platforms.  These encoding conversion functions are not quite correct.
 
+#if 0
 string16 FilePath::LossyDisplayName() const {
   return WideToUTF16(base::SysNativeMBToWide(path_));
 }
+#endif
 
 std::string FilePath::MaybeAsASCII() const {
   if (IsStringASCII(path_))
@@ -530,10 +532,13 @@
 // The *Hack functions are temporary while we fix the remainder of the code.
 // Remember to remove the #includes at the top when you remove these.
 
+#if 0
 // static
 FilePath FilePath::FromWStringHack(const std::wstring& wstring) {
   return FilePath(base::SysWideToNativeMB(wstring));
 }
+#endif
+
 #elif defined(OS_WIN)
 string16 FilePath::LossyDisplayName() const {
   return path_;
