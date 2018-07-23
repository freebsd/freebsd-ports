--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2018-07-19 16:36:31.131399000 +0200
+++ third_party/blink/renderer/core/editing/editing_behavior.cc	2018-07-19 16:36:56.793922000 +0200
@@ -270,7 +270,7 @@
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
