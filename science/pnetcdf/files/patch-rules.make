--- rules.make.orig	2013-10-27 00:53:18.000000000 +0800
+++ rules.make	2014-03-09 22:42:45.290481492 +0800
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
