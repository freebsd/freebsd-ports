--- ./src/modules/perl/mod_perl.c.orig	2008-11-20 13:12:31.000000000 -0500
+++ ./src/modules/perl/mod_perl.c	2009-06-05 02:07:17.882792245 -0400
@@ -596,6 +596,7 @@
 void perl_startup (server_rec *s, pool *p)
 {
     char *argv[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
+    char **temp_argv=argv;
     char **entries, *dstr;
     int status, i, argc=1;
     dPSRV(s);
@@ -679,7 +680,7 @@
     MP_TRACE_g(fprintf(stderr, "..."));
 
 #ifdef PERL_SYS_INIT
-    PERL_SYS_INIT(&argc,(char***)&argv);
+    PERL_SYS_INIT(&argc,(char***)&temp_argv);
 #endif
 
 #ifndef perl_init_i18nl10n
