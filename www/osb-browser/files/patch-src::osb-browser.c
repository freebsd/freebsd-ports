--- src/osb-browser.c.orig	Tue Feb  1 11:50:56 2005
+++ src/osb-browser.c	Tue Feb  1 11:51:33 2005
@@ -127,7 +127,7 @@
 static void
 _weak_notify(gpointer data, GObject *was)
 {
-  g_warning("Destroyed: %s at %x\n", (const char*) data, (int) was);
+  g_warning("Destroyed: %s at %p\n", (const char*) data, was);
 }
 
 
