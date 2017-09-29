--- third_party/WebKit/Source/core/editing/EditingBehavior.cpp.orig	2017-09-10 01:26:55.763466000 +0200
+++ third_party/WebKit/Source/core/editing/EditingBehavior.cpp	2017-09-10 01:27:25.592044000 +0200
@@ -268,7 +268,7 @@
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
