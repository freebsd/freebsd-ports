--- ui/gtk/ime_compat_check.cc.orig	2025-07-02 06:08:04 UTC
+++ ui/gtk/ime_compat_check.cc
@@ -35,6 +35,10 @@ struct InputMethod {
 
 std::vector<base::FilePath> GetLibrarySearchPaths() {
   std::vector<base::FilePath> search_path;
+#if BUILDFLAG(IS_BSD)
+  // We really only care about this search path.
+  search_path.emplace_back("/usr/local/lib");
+#else
   void* handle = dlopen("libc.so.6", RTLD_GLOBAL | RTLD_LAZY | RTLD_NOLOAD);
   if (!handle) {
     return search_path;
@@ -60,6 +64,7 @@ std::vector<base::FilePath> GetLibrarySearchPaths() {
     // SAFETY: The range is bound by `serinfo.dls_cnt`.
     search_path.emplace_back(UNSAFE_BUFFERS(sip->dls_serpath[j].dls_name));
   }
+#endif
 
   return search_path;
 }
