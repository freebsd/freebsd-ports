--- src/web/config_load.cc.orig	2025-08-15 13:41:10 UTC
+++ src/web/config_load.cc
@@ -150,7 +150,11 @@ void Web::ConfigLoad::setValue(Json::Value& item, cons
 template <typename T>
 void Web::ConfigLoad::setValue(Json::Value& item, const T& value)
 {
+#if FMT_VERSION >= 120000
+    static_assert(fmt::is_formattable<T, fmt::format_context>::value, "T must be formattable");
+#else
     static_assert(fmt::has_formatter<T, fmt::format_context>::value, "T must be formattable");
+#endif
     item[CONFIG_LOAD_VALUE] = fmt::to_string(value);
 }
 
