--- src/prot.c.orig	2018-03-05 09:31:55 UTC
+++ src/prot.c
@@ -3,7 +3,7 @@
 #include "hasshsgr.h"
 #include "prot.h"
 
-int prot_gid(int gid)
+int prot_gid(gid_t gid)
 {
 #ifdef HASSHORTSETGROUPS
   short x[2];
@@ -15,7 +15,7 @@ int prot_gid(int gid)
   return setgid(gid); /* _should_ be redundant, but on some systems it isn't */
 }
 
-int prot_uid(int uid)
+int prot_uid(uid_t uid)
 {
   return setuid(uid);
 }
