--- idea.c.orig	Wed Oct  9 02:32:12 2002
+++ idea.c	Wed Oct  9 21:39:05 2002
@@ -420,6 +420,9 @@
 
 
 
+#ifndef IS_MODULE
+static
+#endif
 const char * const gnupgext_version = "IDEA ($Revision: 1.11 $)";
 
 static struct {
@@ -449,6 +452,9 @@
  *		  version = interface version of the function/pointer
  *			    (currently this is 1 for all functions)
  */
+#ifndef IS_MODULE
+static
+#endif
 void *
 gnupgext_enum_func( int what, int *sequence, int *class, int *vers )
 {
@@ -477,3 +483,17 @@
     *sequence = i;
     return ret;
 }
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
+
