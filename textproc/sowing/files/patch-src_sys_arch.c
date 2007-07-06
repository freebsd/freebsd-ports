--- src/sys/arch.c.orig	Wed Sep 20 20:01:15 2000
+++ src/sys/arch.c	Fri Jul  6 23:08:27 2007
@@ -11,7 +11,7 @@
     defined(NeXT)  || defined(WIN32)
 #undef HAS_UNAME
 #endif
-#if defined(dec5000) || defined(rs6000)
+#if defined(dec5000) || defined(rs6000) || defined(__FreeBSD__)
 #undef HAS_UNAME
 #endif
 #if defined(sun4) && defined(sun4Pre41)
@@ -91,6 +91,9 @@
 
 #elif defined(NeXT)
     strncpy( str, "NeXT", slen );
+
+#elif defined(__FreeBSD__)
+    strncpy( str, "FreeBSD", slen );
 
 #else
     strncpy( str, "Unknown", slen );
