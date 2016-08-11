--- src/misc.h.orig	2007-11-16 13:21:46 UTC
+++ src/misc.h
@@ -114,14 +114,6 @@ void dump_cert (const char *text, ksba_c
 char *host_and_port_from_url (const char *url, int *port);
 
 
-#ifdef HAVE_FOPENCOOKIE
-/* We have to implement funopen in terms of glibc's fopencookie. */
-FILE *funopen(void *cookie,
-              int (*readfn)(void *, char *, int),
-              int (*writefn)(void *, const char *, int),
-              fpos_t (*seekfn)(void *, fpos_t, int),
-              int (*closefn)(void *));
-#endif /*HAVE_FOPENCOOKIE*/
 
 
 #endif /* MISC_H */
