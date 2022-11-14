diff --git a/src/libserver/hyperscan_tools.cxx b/src/libserver/hyperscan_tools.cxx
index 6187208a9..96366067d 100644
--- src/libserver/hyperscan_tools.cxx
+++ src/libserver/hyperscan_tools.cxx
@@ -306,7 +306,15 @@ auto load_cached_hs_file(const char *fname, std::int64_t offset = 0) -> tl::expe
 						msg_debug_hyperscan_lambda("multipattern: create new database in %s; %Hz size",
 							tmpfile_pattern.data(), unserialized_size);
 						void *buf;
-						posix_memalign(&buf, 16, unserialized_size);
+#ifdef HAVE_GETPAGESIZE
+						auto page_size = getpagesize();
+#else
+						auto page_size = sysconf(_SC_PAGESIZE);
+#endif
+						if (page_size == -1) {
+							page_size = 4096;
+						}
+						posix_memalign(&buf, page_size, unserialized_size);
 						if (buf == nullptr) {
 							return tl::make_unexpected(error {"Cannot allocate memory", errno, error_category::CRITICAL });
 						}
