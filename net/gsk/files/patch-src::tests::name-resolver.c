--- src/tests/name-resolver.c.orig	Sat Dec 11 00:55:44 2004
+++ src/tests/name-resolver.c	Mon Jan 31 00:49:15 2005
@@ -38,8 +38,8 @@
 {
   GskNameResolverFamily family;
   GskNameResolverTask *task;
-  gsk_init (&argc, &argv, NULL);
   guint i;
+  gsk_init (&argc, &argv, NULL);
 
   if (argc != 3)
     g_error ("%s requires exactly 2 arguments, family and name", argv[0]);
