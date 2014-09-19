--- src/main.c.orig	Thu Jun 14 01:56:54 2001
+++ src/main.c	Sun Jan  1 17:04:13 2006
@@ -108,7 +108,11 @@
       globalUpdate = 1;
       break;
     case 'v':
+#if DB_VERSION_MAJOR * 10 + DB_VERSION_MINOR == 42
+      fprintf(stderr, "SquidGuard: %s %s\n", VERSION,db_version_4002(NULL,NULL,NULL));
+#else
       fprintf(stderr, "SquidGuard: %s %s\n", VERSION,db_version(NULL,NULL,NULL));
+#endif
       exit(0);
       break;
     case 't':
