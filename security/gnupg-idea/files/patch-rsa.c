--- rsa.c.orig	Tue May  9 08:21:33 2000
+++ rsa.c	Tue May  9 08:22:16 2000
@@ -64,6 +64,9 @@
 /* end configurable stuff */
 
 
+#ifndef IS_MODULE
+static
+#endif
 const char * const gnupgext_version = "RSA ($Revision: 1.10 $)";
 
 #ifndef DIM
@@ -500,6 +503,9 @@
  *			   31 = integer with available pubkey algorithms
  *		  version = interface version of the function/pointer
  */
+#ifndef IS_MODULE
+static
+#endif
 void *
 gnupgext_enum_func( int what, int *sequence, int *class, int *vers )
 {
@@ -529,4 +535,17 @@
     return ret;
 }
 
+
+#ifndef IS_MODULE
+
+void register_internal_cipher_extension( const char *module_id,
+			      void * (*enumfunc)(int, int*, int*, int*) );
+
+void
+rsa_constructor(void)
+{
+    register_internal_cipher_extension( gnupgext_version,
+					gnupgext_enum_func );
+}
+#endif
 
