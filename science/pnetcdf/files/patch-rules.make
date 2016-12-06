--- rules.make.orig	2013-10-26 16:53:18 UTC
+++ rules.make
@@ -125,21 +125,21 @@
 # $(INSTALL)ation:
 
 $(INCDIR)/$(HEADER):	$(INCDIR) $(HEADER)
-	$(INSTALL) $(srcdir)/$(HEADER) $@
+	$(INSTALL) $(srcdir)/$(HEADER) $(DESTDIR)$@
 $(INCDIR)/$(HEADER1):	$(INCDIR) $(HEADER1)
-	$(INSTALL) $(srcdir)/$(HEADER1) $@
+	$(INSTALL) $(srcdir)/$(HEADER1) $(DESTDIR)$@
 $(INCDIR)/$(HEADER2):	$(INCDIR) $(HEADER2)
-	$(INSTALL) $(srcdir)/$(HEADER2) $@
+	$(INSTALL) $(srcdir)/$(HEADER2) $(DESTDIR)$@
 $(INCDIR)/$(HEADER3):	$(INCDIR) $(HEADER3)
-	$(INSTALL) $(srcdir)/$(HEADER3) $@
+	$(INSTALL) $(srcdir)/$(HEADER3) $(DESTDIR)$@
 
 $(LIBDIR)/$(LIBRARY):	$(LIBDIR) $(LIBRARY)
-	$(INSTALL) -d -m 755 $(LIBDIR)
-	$(INSTALL) -m 644  $(LIBRARY) $@
+	$(INSTALL) -d -m 755 $(DESTDIR)$(LIBDIR)
+	$(INSTALL) -m 644  $(LIBRARY) $(DESTDIR)$@
 
 $(BINDIR)/$(PROGRAM):	$(BINDIR) $(PROGRAM)
-	$(INSTALL) -d -m 755 $(BINDIR)
-	$(INSTALL) -m 755  $(PROGRAM) $@
+	$(INSTALL) -d -m 755 $(DESTDIR)$(BINDIR)
+	$(INSTALL) -m 755  $(PROGRAM) $(DESTDIR)$@
 
 #$(BINDIR) \
 #$(INCDIR) \
