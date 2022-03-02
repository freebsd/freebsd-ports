--- chrome/updater/lib_util.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/updater/lib_util.cc
@@ -11,7 +11,7 @@
 
 namespace updater {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 std::string UnescapeURLComponent(base::StringPiece escaped_text) {
   return base::UnescapeURLComponent(
