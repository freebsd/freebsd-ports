--- ./components/gatherer/standard/pstext/pstext/defs.h.orig	Fri Aug  1 13:51:49 2003
+++ ./components/gatherer/standard/pstext/pstext/defs.h	Fri Aug  1 13:58:59 2003
@@ -43,7 +43,12 @@
 	TOK_STRING, TOK_NUMBER, TOK_OTHER, TOK_CMD
 } token_e;
 
+#ifdef __STRICT_ANSI__
+void error (char *fmt, ...);
+#else
 void error();
+#endif
+
 void printout();
 
 extern int line_count;
