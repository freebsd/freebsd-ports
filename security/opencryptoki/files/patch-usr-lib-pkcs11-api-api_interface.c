--- usr/lib/pkcs11/api/api_interface.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/api/api_interface.c	2010-10-19 23:52:25.355983620 +0900
@@ -2390,7 +2390,7 @@
 C_GetFunctionList ( CK_FUNCTION_LIST_PTR_PTR ppFunctionList )
 {
 
-   _init();
+   api_init();
    
    LOG("C_GetFunctionList");
    FuncList.version.major = VERSION_MAJOR;
@@ -5168,7 +5168,11 @@
 
 }
 
+#ifdef __sun
+#pragma init(api_init)
+#else
 void api_init(void) __attribute__((constructor));
+#endif
 
 void
 api_init(void)
@@ -5194,7 +5198,11 @@
 
 }
 
+#ifdef __sun
+#pragma fini(api_fini)
+#else
 void api_fini(void) __attribute__((destructor));
+#endif
 
 void
 api_fini()
