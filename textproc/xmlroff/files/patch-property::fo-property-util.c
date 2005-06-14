--- property/fo-property-util.c.orig	Tue Apr 26 04:09:35 2005
+++ property/fo-property-util.c	Tue Jun 14 22:22:38 2005
@@ -1866,6 +1866,8 @@
 			       FoContext  *context,
 			       GError    **error)
 {
+  FoDatatype *new_style;
+  FoDatatype *new_color;
   g_return_val_if_fail (datatype != NULL, NULL);
   g_return_val_if_fail (FO_IS_DATATYPE (datatype), NULL);
   g_return_val_if_fail (context != NULL, NULL);
@@ -1886,7 +1888,7 @@
 	  return NULL;
 	}
 
-      FoDatatype *new_style =
+      new_style =
 	fo_property_util_validate_style (fo_wsc_get_style (datatype),
 					 context,
 					 &tmp_error);
@@ -1897,7 +1899,7 @@
 	  return NULL;
 	}
 
-      FoDatatype *new_color =
+      new_color =
 	  fo_property_util_validate_color_transparent (fo_wsc_get_color (datatype),
 						       context,
 						       &tmp_error);
