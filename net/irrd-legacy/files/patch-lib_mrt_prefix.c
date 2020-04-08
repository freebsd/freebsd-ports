Index: lib/mrt/prefix.c
--- lib/mrt/prefix.c.orig	2015-04-03 11:26:26 UTC
+++ lib/mrt/prefix.c
@@ -5,7 +5,7 @@
 #include <mrt.h>
 #include <netdb.h>
 
-#ifndef __GLIBC__
+#if !defined(__GLIBC__) && !defined(__FreeBSD__)
 #ifdef __osf__
 
 /* apparently, OSF's gethostby{name,addr}_r's are different, broken, and
@@ -29,7 +29,7 @@ struct hostent  *gethostbyaddr_r
       For the time being, this part tries to convert Linux glibc 2.X
       gethostXX_r into Solaris's that we use to code MRT. -- masaki
     */
-#if __GLIBC__ >= 2
+#if __GLIBC__ >= 2 || (defined(__FreeBSD__) && defined(HAVE_GETHOSTBYNAME_R))
    /* Glibc 2.X
 
     int gethostbyname_r (const char *name, struct hostent *result_buf, 
