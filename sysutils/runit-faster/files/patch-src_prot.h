--- src/prot.h.orig	2018-03-05 09:38:43 UTC
+++ src/prot.h
@@ -3,7 +3,10 @@
 #ifndef PROT_H
 #define PROT_H
 
-extern int prot_gid(int);
-extern int prot_uid(int);
+#include <sys/param.h>
+#include <unistd.h>
+
+extern int prot_gid(gid_t);
+extern int prot_uid(uid_t);
 
 #endif
