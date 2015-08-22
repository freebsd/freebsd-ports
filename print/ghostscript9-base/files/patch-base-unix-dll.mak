--- base/unix-dll.mak.orig	2012-08-08 02:01:36.000000000 -0600
+++ base/unix-dll.mak	2014-04-18 12:12:34.000000000 -0600
@@ -162,8 +162,8 @@
 	-mkdir -p $(DESTDIR)$(bindir)
 	-mkdir -p $(DESTDIR)$(libdir)
 	-mkdir -p $(DESTDIR)$(gsincludedir)
-	$(INSTALL_PROGRAM) $(GSSOC) $(DESTDIR)$(bindir)/$(GSSOC_XENAME)
-	$(INSTALL_PROGRAM) $(GSSOX) $(DESTDIR)$(bindir)/$(GSSOX_XENAME)
+	$(INSTALL_PROGRAM) -s $(GSSOC) $(DESTDIR)$(bindir)/$(GSSOC_XENAME)
+	$(INSTALL_PROGRAM) -s $(GSSOX) $(DESTDIR)$(bindir)/$(GSSOX_XENAME)
 	$(INSTALL_PROGRAM) $(BINDIR)/$(GS_SONAME_MAJOR_MINOR) $(DESTDIR)$(libdir)/$(GS_SONAME_MAJOR_MINOR)
 	$(RM_) $(DESTDIR)$(libdir)/$(GS_SONAME)
 	ln -s $(GS_SONAME_MAJOR_MINOR) $(DESTDIR)$(libdir)/$(GS_SONAME)
