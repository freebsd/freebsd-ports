--- include/cmocka.h.orig	2018-09-06 06:15:11 UTC
+++ include/cmocka.h
@@ -111,7 +111,7 @@ typedef uintmax_t LargestIntegralType;
     ((LargestIntegralType)(value))
 
 /* Smallest integral type capable of holding a pointer. */
-#if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED)
+#if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED) && !defined(_UINTPTR_T_DECLARED)
 # if defined(_WIN32)
     /* WIN32 is an ILP32 platform */
     typedef unsigned int uintptr_t;
@@ -137,6 +137,7 @@ typedef uintmax_t LargestIntegralType;
 
 # define _UINTPTR_T
 # define _UINTPTR_T_DEFINED
+# define _UINTPTR_T_DECLARED
 #endif /* !defined(_UINTPTR_T) || !defined(_UINTPTR_T_DEFINED) */
 
 /* Perform an unsigned cast to uintptr_t. */
