--- pty.c.orig	Mon May 30 15:15:43 2005
+++ pty.c	Sat Aug 27 15:47:55 2005
@@ -21,6 +21,7 @@
 #endif
 
 #ifdef __FreeBSD__
+#include <sys/types.h>
 #include <libutil.h>
 #define HAS_OPENPTY 1
 #endif
@@ -40,9 +41,10 @@
 /* c_openpty: unit -> (int * Unix.file_descr) */
 CAMLprim value c_openpty() {
   int master,slave;
+  value pair;
   if (openpty(&master,&slave,NULL,NULL,NULL) < 0)
     uerror("openpty", (value) 0);
-  value pair = alloc_tuple(2);
+  pair = alloc_tuple(2);
   Store_field(pair,0,Val_int(master));
   Store_field(pair,1,Val_int(slave));
   return pair;
