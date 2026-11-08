--- src/bulk_extractor_restarter.h.orig	2026-08-18 16:51:54 UTC
+++ src/bulk_extractor_restarter.h
@@ -28,8 +28,8 @@ class bulk_extractor_restarter { (private)
     std::stringstream       cdata {};
     std::string             thisElement {};
     std::string             provided_filename {};
-    scanner_config          &sc;
-    Phase1::Config          &cfg;
+    [[maybe_unused]] scanner_config          &sc;
+    [[maybe_unused]] Phase1::Config          &cfg;
 
 public:
     bulk_extractor_restarter(scanner_config &sc_,
@@ -100,7 +100,7 @@ class bulk_extractor_restarter { (private)
         return {report_path_bak, cfg.seen_page_ids.size()};
     }
 #else
-    restart_summary restart() {
+    [[noreturn]] restart_summary restart() {
         throw std::runtime_error("Compiled without libexpat; cannot restart.");
     }
 #endif
