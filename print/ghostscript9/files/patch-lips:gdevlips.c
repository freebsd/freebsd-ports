--- contrib/lips4/gdevlips.c.orig	2011-08-05 20:12:20.000000000 +0900
+++ contrib/lips4/gdevlips.c	2011-12-06 15:31:38.000000000 +0900
@@ -62,7 +62,15 @@
         height = tmp;
     }
     for (pt = lips_paper_table; pt->num_unit < 80; pt++)
+/* add by shige 11/06 2003 */
+#ifdef USE_LIPS_SIZE_ERROR
+	if(pt->width+LIPS_SIZE_ERROR_VALUE>=width 
+	  && pt->width-LIPS_SIZE_ERROR_VALUE<=width 
+	  && pt->height+LIPS_SIZE_ERROR_VALUE>=height 
+	  && pt->height-LIPS_SIZE_ERROR_VALUE<=height) 
+#else
         if (pt->width == width && pt->height == height)
+#endif
             break;
 
     return pt->num_unit + landscape;
