--- configure.pl.orig	Sat Jun  9 09:40:22 2001
+++ configure.pl	Sun Jun 10 19:23:51 2001
@@ -1312,7 +1312,7 @@
 DOCDIR        = \$(INSTALLROOT)/share/doc/\$(NAME)-\$(VERSION)
 
 OWNER         = root
-GROUP         = root
+GROUP         = wheel
 DATA_MODE     = 644
 EXEC_MODE     = 755
 
@@ -1341,7 +1341,7 @@
 # FIXME: Hardcoded
 USER_DOCS     = readme.txt doc/license.txt doc/log.txt doc/thanks.txt \\
                 doc/pgpkeys.asc
-DEVEL_DOCS    = doc/doc.ps doc/relnotes.txt
+DEVEL_DOCS    = doc/opencl.ps doc/relnotes.txt
 
 HEADERS       = $headers
 
