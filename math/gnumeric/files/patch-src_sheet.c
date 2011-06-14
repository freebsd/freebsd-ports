--- src/sheet.c.orig	2011-06-11 15:07:26.380716192 -0500
+++ src/sheet.c	2011-06-11 15:07:10.273212703 -0500
@@ -701,7 +701,8 @@ gnm_sheet_constructed (GObject *obj)
 
 	sheet_scale_changed (sheet, TRUE, TRUE);
 
-	parent_class->constructed (obj);
+	if (parent_class->constructed)
+			parent_class->constructed (obj);
 }
 
 static guint
