--- ./src/main.cpp.orig	2010-07-06 01:13:01.000000000 +0400
+++ ./src/main.cpp	2010-07-06 22:29:53.933972524 +0400
@@ -23,8 +23,6 @@
 *
 * ============================================================ */
 
-// workaround for recent flashplugins
-#include <gtk/gtk.h>
 
 // version include
 #include "../version.h"
@@ -45,8 +43,6 @@
 
 extern "C" KDE_EXPORT int kdemain(int argc, char **argv)
 {
-    // just a hackisch workaround for recent flashplugins
-    gtk_init(&argc, &argv);
 
     KAboutData about("rekonq",
                      0,
