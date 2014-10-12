Make plugin ready for met.no locationforecast-1.2 API (bug #10916).

--- panel-plugin/weather-translate.h.orig	2013-01-24 14:45:10 UTC
+++ panel-plugin/weather-translate.h
@@ -24,6 +24,8 @@
 
 G_BEGIN_DECLS
 
+const gchar *get_symbol_for_id(gint id);
+
 const gchar *translate_desc(const gchar *desc,
                             gboolean nighttime);
 
