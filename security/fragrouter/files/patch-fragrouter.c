--- fragrouter.c.orig	2022-11-08 17:15:14 UTC
+++ fragrouter.c
@@ -104,8 +104,8 @@ usage(void)
 int
 main(int argc, char *argv[])
 {
-  char c, ebuf[BUFSIZ], hops[BUFSIZ], *dev = NULL;
-  int num = 0, type = -1, hopptr = 4;
+  char ebuf[BUFSIZ], hops[BUFSIZ], *dev = NULL;
+  int c, num = 0, type = -1, hopptr = 4;
   attack_handler attack;
 
   hops[0] = '\0';
