--- ldif.h.orig	Mon Jul  8 22:57:42 2002
+++ ldif.h	Mon Mar  1 12:19:54 2004
@@ -2,7 +2,9 @@
 #include <ldap.h>
 
 /* how many attributes do we allow per record? */
+#ifndef ATTRIBS
 #define ATTRIBS 32
+#endif
 
 struct attribute {
   long name, value;
