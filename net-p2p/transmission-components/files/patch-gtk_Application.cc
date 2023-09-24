--- gtk/Application.cc.orig	2023-09-19 12:12:08 UTC
+++ gtk/Application.cc
@@ -395,7 +395,7 @@ void register_magnet_link_handler()
             _("Couldn't register Transmission as a {content_type} handler: {error} ({error_code})"),
             fmt::arg("content_type", content_type),
             fmt::arg("error", e.what()),
-            fmt::arg("error_code", e.code())));
+            fmt::arg("error_code", static_cast<int>(e.code()))));
     }
 }
 
