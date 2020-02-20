--- test/xtest.c.orig	2019-04-30 16:40:02.828913000 -0700
+++ test/xtest.c	2019-04-30 16:40:42.769713000 -0700
@@ -59,10 +59,10 @@
 static void
 xtest_init_devices(void)
 {
-    ScreenRec screen = {0};
-    ClientRec server_client = {0};
-    WindowRec root = {0};
-    WindowOptRec optional = {0};
+    ScreenRec screen = {{0}};
+    ClientRec server_client = {{0}};
+    WindowRec root = {{0}};
+    WindowOptRec optional = {{0}};
 
     /* random stuff that needs initialization */
     root.drawable.id = 0xab;
