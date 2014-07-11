--- config/Makefile.SH.orig	2010-01-09 12:59:48.000000000 -0500
+++ config/Makefile.SH	2014-07-08 04:15:24.000000000 -0400
@@ -208,7 +208,6 @@
 MV = mv -f
 LN = $ln_s
 CP_F = cp -f
-STRIP      = strip
 STRIPFLAGS =
 
 # Change these installation directories to suit your needs.
@@ -221,9 +220,9 @@
 DATADIR   = "\$(DESTDIR)$datadir"
 SYSDATADIR= "\$(DESTDIR)$sysdatadir"
 
-EXDIR     = \$(DATADIR)/examples
+EXDIR     = \$(DESTDIR)/\$(PREFIX)/share/examples/pari
 MISCDIR   = \$(DATADIR)/misc
-DOCDIR    = \$(DATADIR)/doc
+DOCDIR    = \$(DESTDIR)/\$(PREFIX)/share/doc/pari
 
 INSTALL = $cfg/install
 INSTALL_PROGRAM = \$(INSTALL)
@@ -377,7 +376,7 @@
 
 install-doc::
 	-mkdir -p \$(BINDIR) \$(DOCDIR)
-	-cd $doc; \$(MAKE) all
+	#-cd $doc; \$(MAKE) all
 	-\$(INSTALL_PROGRAM) $doc/gphelp    \$(BINDIR)
 	-\$(INSTALL_DATA) $doc/Makefile     \$(DOCDIR)
 	-\$(INSTALL_DATA) $doc/translations \$(DOCDIR)
