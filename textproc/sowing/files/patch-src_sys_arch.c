--- src/sys/arch.c.orig	2009-12-29 16:53:02 UTC
+++ src/sys/arch.c
@@ -11,7 +11,7 @@
     defined(NeXT)  || defined(WIN32)
 #undef HAS_UNAME
 #endif
-#if defined(dec5000) || defined(rs6000)
+#if defined(dec5000) || defined(rs6000) || defined(__FreeBSD__)
 #undef HAS_UNAME
 #endif
 #if defined(sun4) && defined(sun4Pre41)
@@ -96,6 +96,9 @@ void SYGetArchType( char *str, int slen 
 #elif defined(NeXT)
     strncpy( str, "NeXT", slen );
 
+#elif defined(__FreeBSD__)
+    strncpy( str, "FreeBSD", slen );
+
 #else
     strncpy( str, "Unknown", slen );
 #endif
