--- ldif.h.orig	2008-04-25 13:09:34.000000000 +0200
+++ ldif.h	2008-04-25 21:36:30.000000000 +0200
@@ -4,7 +4,9 @@
 #include <ldap.h>
 
 /* how many attributes do we allow per record? */
+#ifndef ATTRIBS
 #define ATTRIBS 100
+#endif
 
 struct attribute {
   uint32_t name, value;
