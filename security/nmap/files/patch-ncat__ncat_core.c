Index: ncat/ncat_core.c
diff -u -p ncat/ncat_core.c.orig ncat/ncat_core.c
--- ncat/ncat_core.c.orig	2009-04-02 11:57:42.000000000 +0900
+++ ncat/ncat_core.c	2009-04-22 00:58:48.839927966 +0900
@@ -89,6 +89,7 @@ int resolve(char *hostname, unsigned sho
 
   memset(&hints, 0, sizeof(hints));
   hints.ai_family = o.af;
+  hints.ai_socktype = SOCK_DGRAM;
   if (o.nodns)
      hints.ai_flags |= AI_NUMERICHOST;
 
