--- programs/Xserver/hw/xfree86/loader/loader.c.orig	Thu May 15 19:50:47 2003
+++ programs/Xserver/hw/xfree86/loader/loader.c	Thu May 15 19:51:35 2003
@@ -88,7 +88,7 @@
 static int refCount[MAX_HANDLE] ;
 #endif
 
-#if defined(__sparc__) && defined(__GNUC__)
+#if defined(__sparc__) && defined(__GNUC__) && !defined(__FreeBSD__)
 # define SYMFUNCDOT(func) { "." #func, (funcptr)&__sparc_dot_ ## func },
 # if !defined(__OpenBSD__)
 # define SYMFUNCDOT89(func) { "." #func, (funcptr)&func ## _sparcv89 },
@@ -298,7 +298,7 @@
     LoaderAddSymbols(-1, -1, dixLookupTab ) ;
     LoaderAddSymbols(-1, -1, fontLookupTab ) ;
     LoaderAddSymbols(-1, -1, extLookupTab );
-#ifdef __sparc__
+#if defined(__sparc__) && !defined(__FreeBSD__)
 #ifdef linux
     if (sparcUseHWMulDiv())
 	LoaderAddSymbols(-1, -1, SparcV89LookupTab ) ;
