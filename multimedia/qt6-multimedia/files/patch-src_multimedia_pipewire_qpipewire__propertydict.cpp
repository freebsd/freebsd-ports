Fix build on i386.

error: non-constant-expression cannot be narrowed from type 'uint32_t' (aka
'unsigned int') to 'qsizetype' (aka 'int') in initializer list

--- src/multimedia/pipewire/qpipewire_propertydict.cpp.orig	2025-11-13 22:23:51 UTC
+++ src/multimedia/pipewire/qpipewire_propertydict.cpp
@@ -31,7 +31,7 @@ PwPropertyDict toPropertyDict(const spa_dict &dict)
 
 PwPropertyDict toPropertyDict(const spa_dict &dict)
 {
-    QSpan<const spa_dict_item> items{ dict.items, dict.n_items };
+    QSpan<const spa_dict_item> items{ dict.items, static_cast<qsizetype>(dict.n_items) };
 
     PwPropertyDict map;
     for (const spa_dict_item &item : items)
