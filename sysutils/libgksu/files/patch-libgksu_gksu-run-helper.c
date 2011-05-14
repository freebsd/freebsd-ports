--- libgksu/gksu-run-helper.c.o	2011-04-12 16:47:38.000000000 +0000
+++ libgksu/gksu-run-helper.c	2011-04-12 16:49:14.000000000 +0000
@@ -110,6 +110,7 @@
       return 1;
     }
 
+  sleep(2);
   fprintf (stderr, "gksu: waiting\n");
 
   xauth_file = g_strdup_printf ("%s/.Xauthority",
@@ -159,8 +160,8 @@
     /* find out where the xauth binary is located */
     if (g_file_test ("/usr/bin/xauth", G_FILE_TEST_IS_EXECUTABLE))
       xauth_bin = "/usr/bin/xauth";
-    else if (g_file_test ("/usr/X11R6/bin/xauth", G_FILE_TEST_IS_EXECUTABLE))
-      xauth_bin = "/usr/X11R6/bin/xauth";
+    else if (g_file_test ("/usr/local/bin/xauth", G_FILE_TEST_IS_EXECUTABLE))
+      xauth_bin = "/usr/local/bin/xauth";
     else
       {
 	fprintf (stderr,
