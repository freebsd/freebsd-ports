Index: lib/mrt/prefix.c
diff -u -p lib/mrt/prefix.c.orig lib/mrt/prefix.c
--- lib/mrt/prefix.c.orig	Fri Aug 31 03:10:31 2001
+++ lib/mrt/prefix.c	Mon May  1 12:05:11 2006
@@ -15,7 +15,7 @@
 #include <ws2tcpip.h>
 #endif /* NT */
 
-#ifndef __GLIBC__
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 #ifdef __osf__
 
 /* apparently, OSF's gethostby{name,addr}_r's are different, broken, and
@@ -50,7 +50,7 @@ struct hostent  *gethostbyaddr_r
       For the time being, this part tries to convert Linux glibc 2.X
       gethostXX_r into Solaris's that we use to code MRT. -- masaki
     */
-#if __GLIBC__ >= 2
+#if __GLIBC__ >= 2 || (defined(__FreeBSD__) && defined(HAVE_GETHOSTBYNAME_R))
    /* Glibc 2.X
 
     int gethostbyname_r (const char *name, struct hostent *result_buf, 
