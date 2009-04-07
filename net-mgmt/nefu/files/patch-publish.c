--- publish.c	2005-08-01 16:08:43.000000000 +0200
+++ publish.c	2008-06-24 14:11:41.000000000 +0200
@@ -750,7 +750,11 @@
 	return( 1 );
     }

-    return( html_plan( s ));
+    if ( nefu_html_dir != NULL ) {
+        return( html_plan( s ));
+    }
+
+    return ( 0 );
 }


