--- src/data_provider/src/extended_sources/wrappers/unix/iutmpx_wrapper.hpp	2025-11-07 08:46:03.000000000 +0000
+++ src/data_provider/src/extended_sources/wrappers/unix/iutmpx_wrapper.hpp	2026-01-12 14:51:47.552260000 +0000
@@ -20,7 +20,9 @@
 
         /// @brief Sets the utmpx file to be used by the library functions.
         /// @param file Path to the utmpx file.
+#if !defined(__FreeBSD__)
         virtual void utmpxname(const char* file) = 0;
+#endif
 
         /// @brief Resets the input stream to the beginning of the utmpx file.
         virtual void setutxent() = 0;
