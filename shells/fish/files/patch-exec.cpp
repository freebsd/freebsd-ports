--- exec.cpp.orig
+++ exec.cpp
@@ -343,7 +343,11 @@
 */
 static int has_fd(const io_chain_t &d, int fd)
 {
+#if defined(_LIBCPP_VERSION)
+    return io_chain_get(d, fd) != nullptr;
+#else
     return io_chain_get(d, fd) != NULL;
+#endif
 }
 
 /**
@@ -606,7 +610,11 @@
         j->io.insert(j->io.begin(), parser.block_io.begin(), parser.block_io.end());
     }
 
+#if defined(LIBCPP_VERSION)
+    const io_buffer_t *input_redirect = nullptr;
+#else
     const io_buffer_t *input_redirect = NULL;
+#endif
     for (size_t idx = 0; idx < j->io.size(); idx++)
     {
         const shared_ptr<io_data_t> &io = j->io.at(idx);
