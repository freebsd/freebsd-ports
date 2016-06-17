--- contrib/lips4/gdevlips.c.orig	2012-08-08 08:01:36 UTC
+++ contrib/lips4/gdevlips.c
@@ -62,7 +62,15 @@ lips_media_selection(int width, int heig
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
