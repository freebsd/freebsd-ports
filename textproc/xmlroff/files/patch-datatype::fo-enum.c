--- datatype/fo-enum.c.orig	Mon Jan 10 13:55:20 2005
+++ datatype/fo-enum.c	Mon Jan 10 13:56:26 2005
@@ -400,6 +400,8 @@
 void
 fo_enum_class_init (FoEnumClass *klass)
 {
+  int i;
+
   GObjectClass *object_class = G_OBJECT_CLASS (klass);
   
   parent_class = g_type_class_peek_parent (klass);
@@ -413,7 +415,6 @@
 
   FO_DATATYPE_CLASS (klass)->copy = fo_enum_copy;
 
-  int i;
   for (i = 0; i < FO_ENUM_ENUM_LIMIT; i++)
     {
       enums[i] = NULL;
@@ -708,10 +709,12 @@
 FoDatatype *
 fo_enum_get_enum_by_value (FoEnumEnum enum_value)
 {
+  GEnumValue *enum_ptr;
+
   g_return_val_if_fail (enum_value > FO_ENUM_ENUM_UNSPECIFIED, NULL);
   g_return_val_if_fail (enum_value < FO_ENUM_ENUM_LIMIT, NULL);
 
-  GEnumValue *enum_ptr =
+  enum_ptr =
     g_enum_get_value (g_type_class_ref (FO_TYPE_ENUM_ENUM),
 		      enum_value);
 
@@ -748,10 +751,12 @@
 FoDatatype *
 fo_enum_get_enum_by_nick (const gchar *name)
 {
+  GEnumValue *enum_ptr;
+
   g_return_val_if_fail (name != NULL, NULL);
   g_return_val_if_fail (*name != '\0', NULL);
 
-  GEnumValue *enum_ptr =
+  enum_ptr =
     g_enum_get_value_by_nick (g_type_class_ref (FO_TYPE_ENUM_ENUM),
 			      name);
 
