--- libgksu/gksu-run-helper.c.o	2011-04-12 16:47:38.000000000 +0000
+++ libgksu/gksu-run-helper.c	2011-04-12 16:49:14.000000000 +0000
@@ -110,6 +110,7 @@
       return 1;
     }
 
+  sleep(2);
   fprintf (stderr, "gksu: waiting\n");
 
   xauth_file = g_strdup_printf ("%s/.Xauthority",
