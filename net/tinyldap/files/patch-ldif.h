--- ldif.h.orig	2017-03-19 11:47:19 UTC
+++ ldif.h
@@ -5,7 +5,9 @@
 #include "ldap.h"
 
 /* how many attributes do we allow per record? */
+#ifndef ATTRIBS
 #define ATTRIBS 100
+#endif
 
 struct attribute {
   uint32_t name, value;
