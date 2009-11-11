--- xpcom/reflect/xptcall/src/xptcprivate.h.orig	2009-11-09 21:43:49.000000000 -0800
+++ xpcom/reflect/xptcall/src/xptcprivate.h	2009-11-09 21:44:05.000000000 -0800
@@ -45,7 +45,7 @@
 
 class xptiInterfaceEntry;
 
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__))
+#if !defined(__ia64)
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n() = 0;
 #else
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n(PRUint64,PRUint64,PRUint64,PRUint64,PRUint64,PRUint64,PRUint64,PRUint64) = 0;
@@ -62,7 +62,7 @@
 #undef STUB_ENTRY
 #undef SENTINEL_ENTRY
 
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__))
+#if !defined(__ia64)
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n();
 #else
 #define STUB_ENTRY(n) NS_IMETHOD Stub##n(PRUint64,PRUint64,PRUint64,PRUint64,PRUint64,PRUint64,PRUint64,PRUint64);
