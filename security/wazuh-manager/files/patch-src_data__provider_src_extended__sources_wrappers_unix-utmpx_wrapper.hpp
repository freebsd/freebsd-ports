--- src/data_provider/src/extended_sources/wrappers/unix/utmpx_wrapper.hpp	2025-11-07 08:46:03.000000000 +0000
+++ src/data_provider/src/extended_sources/wrappers/unix/utmpx_wrapper.hpp	2026-01-12 14:51:47.552488000 +0000
@@ -18,11 +18,12 @@
     public:
         /// @brief Sets the utmpx file to be used by the library functions.
         /// @param file Path to the utmpx file.
+#if !defined(__FreeBSD__)
         void utmpxname(const char* file) override
         {
             ::utmpxname(file);
         }
-
+#endif
         /// @brief Resets the input stream to the beginning of the utmpx file.
         void setutxent() override
         {
