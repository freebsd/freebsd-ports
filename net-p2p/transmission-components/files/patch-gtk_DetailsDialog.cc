--- gtk/DetailsDialog.cc.orig	2025-10-15 08:45:18 UTC
+++ gtk/DetailsDialog.cc
@@ -49,10 +49,12 @@
 
 #include <fmt/chrono.h>
 #include <fmt/core.h>
+#include <fmt/ranges.h>
 #include <fmt/format.h>
 
 #include <algorithm>
 #include <array>
+#include <chrono>
 #include <cstddef>
 #include <cstdlib> // abort()
 #include <limits>
@@ -606,12 +608,12 @@ void gtr_text_buffer_set_text(Glib::RefPtr<Gtk::TextBu
 
 [[nodiscard]] std::string get_date_string(time_t t)
 {
-    return t == 0 ? _("N/A") : fmt::format(FMT_STRING("{:%x}"), fmt::localtime(t));
+    return t == 0 ? _("N/A") : fmt::format("{:%x}", *std::localtime(&t));
 }
 
 [[nodiscard]] std::string get_date_time_string(time_t t)
 {
-    return t == 0 ? _("N/A") : fmt::format(FMT_STRING("{:%c}"), fmt::localtime(t));
+    return t == 0 ? _("N/A") : fmt::format("{:%c}", *std::localtime(&t));
 }
 
 } // namespace
