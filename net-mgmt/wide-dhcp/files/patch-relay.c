--- relay/relay.c.orig	1999-01-01 19:28:04.000000000 +0900
+++ relay/relay.c	2012-10-25 18:05:55.000000000 +0900
@@ -123,7 +123,7 @@
 static void forwarding();
 int open_if();
 
-void
+int
 main(argc, argv)
   int argc;
   char **argv;
