--- src/setargs.c.orig	1998-11-10 04:15:56 UTC
+++ src/setargs.c
@@ -89,6 +89,8 @@ setargs_settup(argc, argv, envp)
 		LastArgv = argv[argc-1] + strlen(argv[argc-1]);
 }
 
+#ifndef HAVE_SETPROCTITLE
+
 /*
  * Set process title
  */
@@ -165,5 +167,7 @@ extern void setproctitle(fmt, a1, a2, a3, a4, a5, a6)
 	_setproctitle(buf);
 }
 #endif	/* !ARG_TYPE */
+
+#endif /* !HAVE_SETPROCTITLE */
 
 #endif 	/* SETARGS */
