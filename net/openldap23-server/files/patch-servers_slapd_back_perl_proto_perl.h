--- servers/slapd/back-perl/proto-perl.h.orig	Fri Aug 18 16:05:27 2006
+++ servers/slapd/back-perl/proto-perl.h	Fri Aug 18 16:05:40 2006
@@ -22,7 +22,6 @@
 
 extern BI_init		perl_back_initialize;
 
-extern BI_open		perl_back_open;
 extern BI_close		perl_back_close;
 
 extern BI_db_init	perl_back_db_init;
