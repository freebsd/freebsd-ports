--- utils/show.cc.orig	2025-10-15 08:54:46 UTC
+++ utils/show.cc
@@ -160,7 +160,7 @@ int parseCommandLine(app_opts& opts, int argc, char co
 
 [[nodiscard]] auto toString(time_t now)
 {
-    return now == 0 ? "Unknown" : fmt::format("{:%a %b %d %T %Y}", fmt::localtime(now));
+    return now == 0 ? "Unknown" : fmt::format("{:%a %b %d %T %Y}", *std::localtime(&now));
 }
 
 bool compareSecondField(std::string_view l, std::string_view r)
