Index: lib/mrt/prefix.c
diff -u -p lib/mrt/prefix.c.orig lib/mrt/prefix.c
--- lib/mrt/prefix.c.orig	Sat Apr 29 04:31:05 2000
+++ lib/mrt/prefix.c	Fri Jun  2 11:23:40 2006
@@ -16,7 +16,8 @@
 #endif /* NT */
 
 
-#ifndef __GLIBC__
+#if !defined(__GLIBC__) && \
+    (!defined(__FreeBSD__) || !defined(HAVE_GETHOSTBYNAME_R))
 #ifdef __osf__
 
 /* apparently, OSF's gethostby{name,addr}_r's are different, broken, and
@@ -51,7 +52,7 @@ struct hostent  *gethostbyaddr_r
       For the time being, this part tries to convert Linux glibc 2.X
       gethostXX_r into Solaris's that we use to code MRT. -- masaki
     */
-#if __GLIBC__ >= 2
+#if __GLIBC__ >= 2 || (defined(__FreeBSD__) && defined(HAVE_GETHOSTBYNAME_R))
    /* Glibc 2.X
 
     int gethostbyname_r (const char *name, struct hostent *result_buf, 
@@ -311,7 +312,7 @@ prefix_toname (prefix_t *prefix)
 
     if (prefix == NULL) return (strdup ("invalid name"));
 
-#ifdef GETHOSTBYADDR_R
+#ifdef HAVE_GETHOSTBYADDR_R
     hostinfo = gethostbyaddr_r((char *) prefix_tochar(prefix),
 		(prefix->bitlen)/8, prefix->family, &result,
 		hostbuf, sizeof hostbuf, &h_errno_r);
