--- src/setargs.c.orig	Mon Nov  9 20:15:56 1998
+++ src/setargs.c	Fri Nov  3 02:41:25 2000
@@ -89,6 +89,8 @@
 		LastArgv = argv[argc-1] + strlen(argv[argc-1]);
 }
 
+#ifndef HAVE_SETPROCTITLE
+
 /*
  * Set process title
  */
@@ -165,5 +167,7 @@
 	_setproctitle(buf);
 }
 #endif	/* !ARG_TYPE */
+
+#endif /* !HAVE_SETPROCTITLE */
 
 #endif 	/* SETARGS */
