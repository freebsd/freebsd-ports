--- idea.c.orig	Tue May  9 08:18:54 2000
+++ idea.c	Tue May  9 08:20:49 2000
@@ -474,7 +474,9 @@
 }
 
 
-
+#ifndef IS_MODULE
+static
+#endif
 const char * const gnupgext_version = "IDEA ($Revision: 1.11 $)";
 
 static struct {
@@ -504,6 +506,9 @@
  *		  version = interface version of the function/pointer
  *			    (currently this is 1 for all functions)
  */
+#ifndef IS_MODULE
+static
+#endif
 void *
 gnupgext_enum_func( int what, int *sequence, int *class, int *vers )
 {
@@ -533,4 +538,18 @@
     return ret;
 }
 
+
+
+#ifndef IS_MODULE
+
+void register_internal_cipher_extension( const char *module_id,
+			      void * (*enumfunc)(int, int*, int*, int*) );
+
+void
+idea_constructor(void)
+{
+    register_internal_cipher_extension( gnupgext_version,
+					gnupgext_enum_func );
+}
+#endif
 
