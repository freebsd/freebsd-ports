--- Makefile.PL.orig	Fri Jun 18 06:18:30 2004
+++ Makefile.PL	Thu Sep 30 10:39:29 2004
@@ -240,19 +240,6 @@
 	@pod2html --outfile=$(SITEPREFIX)/doc/html/Todo.html --infile=Docs/Todo.pod --title="NSP Todo"
 	@pod2html --outfile=$(SITEPREFIX)/doc/html/Usage.html --infile=Docs/Usage.pod --title="NSP Usage"
 
-# general documentation to man/man3
-
-	@$(MKPATH) $(SITEPREFIX)/man/man3
-
-	@echo "Installing man page documentation in $(SITEPREFIX)/man/man3"
-
-	@pod2man Docs/FAQ.pod $(SITEPREFIX)/man/man3/FAQ.$(MAN3EXT) 
-	@pod2man Docs/NewStats.pod $(SITEPREFIX)/man/man3/NewStats.$(MAN3EXT) 
-	@pod2man Docs/Measures.pod $(SITEPREFIX)/man/man3/Measures.$(MAN3EXT) 
-	@pod2man Docs/README.pod $(SITEPREFIX)/man/man3/README.$(MAN3EXT) 
-	@pod2man Docs/Todo.pod $(SITEPREFIX)/man/man3/Todo.$(MAN3EXT) 
-	@pod2man Docs/Usage.pod $(SITEPREFIX)/man/man3/Usage.$(MAN3EXT) 
-
 # general documentation to doc/pod
 
 	@echo "Installing pod documentation in $(SITEPREFIX)/doc/pod"
