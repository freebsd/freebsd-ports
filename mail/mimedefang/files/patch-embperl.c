--- embperl.c.orig	Wed Jun 30 00:57:57 2004
+++ embperl.c	Wed Jun 30 01:01:55 2004
@@ -26,6 +26,9 @@
     char *argv[6];
     int argc;
 
+#ifdef SAFE_EMBED_PERL
+	PL_perl_destruct_level = 1;
+#endif
     if (my_perl != NULL) {
 #ifdef SAFE_EMBED_PERL
 	perl_destruct(my_perl);
@@ -46,7 +49,6 @@
 #ifdef PERL_SET_CONTEXT
     PERL_SET_CONTEXT(my_perl);
 #endif
-    PL_perl_destruct_level = 1;
     perl_construct(my_perl);
     if (subFilter) {
 	argv[0] = "";
