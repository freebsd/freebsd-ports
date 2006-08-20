--- servers/slapd/back-perl/bind.c.orig	Fri Aug 18 16:04:41 2006
+++ servers/slapd/back-perl/bind.c	Fri Aug 18 16:05:14 2006
@@ -32,7 +32,7 @@
 
 	PerlBackend *perl_back = (PerlBackend *) op->o_bd->be_private;
 
-#ifdef HAVE_WIN32_ASPERL
+#if defined(HAVE_WIN32_ASPERL) || defined(USE_ITHREADS)
 	PERL_SET_CONTEXT( PERL_INTERPRETER );
 #endif
 
