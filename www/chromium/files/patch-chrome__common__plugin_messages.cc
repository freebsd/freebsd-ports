--- chrome/common/plugin_messages.cc.orig	2011-01-19 12:12:15.000000000 +0100
+++ chrome/common/plugin_messages.cc	2011-01-21 20:46:41.000000000 +0100
@@ -56,7 +56,7 @@
 
 PluginMsg_UpdateGeometry_Param::PluginMsg_UpdateGeometry_Param()
     : transparent(false),
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD)
       windowless_buffer(TransportDIB::DefaultHandleValue()),
       background_buffer(TransportDIB::DefaultHandleValue())
 #else
@@ -271,7 +271,7 @@
   WriteParam(m, p.windowless_buffer);
   WriteParam(m, p.background_buffer);
   WriteParam(m, p.transparent);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   WriteParam(m, p.ack_key);
 #endif
 }
@@ -285,7 +285,7 @@
       ReadParam(m, iter, &r->windowless_buffer) &&
       ReadParam(m, iter, &r->background_buffer) &&
       ReadParam(m, iter, &r->transparent)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
       &&
       ReadParam(m, iter, &r->ack_key)
 #endif
@@ -304,7 +304,7 @@
   LogParam(p.background_buffer, l);
   l->append(", ");
   LogParam(p.transparent, l);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   l->append(", ");
   LogParam(p.ack_key, l);
 #endif
