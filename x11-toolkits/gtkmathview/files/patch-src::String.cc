--- src/String.cc.orig	Mon Jul 14 08:01:23 2003
+++ src/String.cc	Mon Jul 14 08:05:56 2003
@@ -34,6 +34,12 @@
 #include "String.hh"
 #include "Globals.hh"
 
+#ifdef __FreeBSD__
+#if (__FreeBSD_version < 500000)
+#define iswspace(c) ((c) == ' ' || (c) == '\t' || (c) == '\n')
+#endif
+#endif
+
 #ifdef DEBUG
 int String::counter = 0;
 #endif
