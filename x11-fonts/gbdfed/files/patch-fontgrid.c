--- fontgrid.c~	2010-04-16 09:39:02.000000000 -0500
+++ fontgrid.c	2012-06-05 12:50:41.558078595 -0500
@@ -4711,10 +4711,7 @@ fontgrid_select_next_glyph(Fontgrid *fw,
         return FALSE;
     }
 
-    if (fw->orientation == GTK_ORIENTATION_VERTICAL)
-      code += (fw->cell_rows * count);
-    else
-      code += count;
+    code += count;
 
     if (fw->unencoded && code > gp->encoding)
       code = gp->encoding;
@@ -4794,10 +4791,7 @@ fontgrid_select_previous_glyph(Fontgrid 
         return FALSE;
     }
 
-    if (fw->orientation == GTK_ORIENTATION_VERTICAL)
-      code -= (fw->cell_rows * count);
-    else
-      code -= count;
+    code -= count;
 
     if (code < 0)
       code = 0;
