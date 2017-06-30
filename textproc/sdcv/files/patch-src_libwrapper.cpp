--- src/libwrapper.cpp.orig	2013-07-07 14:34:44 UTC
+++ src/libwrapper.cpp
@@ -285,7 +285,7 @@ namespace {
         sdcv_pager& operator=(const sdcv_pager&) = delete;
         ~sdcv_pager() {
             if (output != stdout)
-                fclose(output);
+                pclose(output);
         }
         FILE *get_stream() { return output; }
     private:
