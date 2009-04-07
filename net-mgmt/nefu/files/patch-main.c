--- main.c	2006-11-10 20:32:33.000000000 +0100
+++ main.c	2008-06-23 20:26:45.000000000 +0200
@@ -409,6 +409,10 @@
 	}
     }

+    /* fix the html_dir */
+    if(no_html == 1)
+        nefu_html_dir = NULL;
+
     /* initalize html pages */
     html_init( &s );

