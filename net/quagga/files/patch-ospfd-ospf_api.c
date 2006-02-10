--- ospfd/ospf_api.c.orig	Thu Nov 24 21:51:16 2005
+++ ospfd/ospf_api.c	Wed Feb  8 11:49:31 2006
@@ -68,7 +68,7 @@
   struct opaque_lsa
   {
     struct lsa_header header;
-    u_char mydata[];
+    u_char mydata[0];
   };
 
   struct opaque_lsa *olsa;
