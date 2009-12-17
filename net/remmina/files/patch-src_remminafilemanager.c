--- src/remminafilemanager.c	2009/12/12 13:47:56	43
+++ src/remminafilemanager.c	2009/12/16 15:01:20	44
@@ -56,6 +56,7 @@
         remmina_file_free (remminafile);
         n++;
     }
+    g_dir_close (dir);
     return n;
 }
 
