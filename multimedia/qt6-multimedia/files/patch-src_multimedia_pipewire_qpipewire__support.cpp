Fix build on i386.

error: non-constant-expression cannot be narrowed from type 'uint32_t' (aka
'unsigned int') to 'qsizetype' (aka 'int') in initializer list 

--- src/multimedia/pipewire/qpipewire_support.cpp.orig	2025-11-13 22:23:51 UTC
+++ src/multimedia/pipewire/qpipewire_support.cpp
@@ -16,7 +16,7 @@ QDebug operator<<(QDebug dbg, const spa_dict &dict)
 // debug support
 QDebug operator<<(QDebug dbg, const spa_dict &dict)
 {
-    QSpan<const spa_dict_item> items{ dict.items, dict.n_items };
+    QSpan<const spa_dict_item> items{ dict.items, static_cast<qsizetype>(dict.n_items) };
 
     QDebugStateSaver saver(dbg);
     dbg.nospace();
