--- src/console.cpp.orig	Mon Nov  4 00:23:20 2002
+++ src/console.cpp	Mon Nov  4 00:23:55 2002
@@ -2157,7 +2157,7 @@
  * CLicqConsole::Input_Line
  *-------------------------------------------------------------------------*/
 char *CLicqConsole::Input_Line(char *sz, unsigned short &n, int cIn,
-  bool bEcho = true)
+  bool bEcho)
 {
   // Now check for keys
   switch (cIn)

