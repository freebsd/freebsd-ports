--- include/cmocka.h.orig	2018-01-02 22:14:13.670138000 -0600
+++ include/cmocka.h	2018-01-02 22:35:26.399769000 -0600
@@ -110,7 +110,7 @@
     ((LargestIntegralType)(value))
 
 /* Smallest integral type capable of holding a pointer. */
-#if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED)
+#if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED) && !defined(_UINTPTR_T_DECLARED)
 # if defined(_WIN32)
     /* WIN32 is an ILP32 platform */
     typedef unsigned int uintptr_t;
@@ -136,6 +136,7 @@
 
 # define _UINTPTR_T
 # define _UINTPTR_T_DEFINED
+# define _UINTPTR_T_DECLARED
 #endif /* !defined(_UINTPTR_T) || !defined(_UINTPTR_T_DEFINED) */
 
 /* Perform an unsigned cast to uintptr_t. */
