--- toolkit/mozapps/installer/packager.mk.orig	2008-04-28 22:30:07.000000000 +0200
+++ toolkit/mozapps/installer/packager.mk	2009-05-02 13:33:13.000000000 +0200
@@ -418,7 +418,7 @@
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	ln -s $(installdir)/$(MOZ_APP_NAME)-browser $(DESTDIR)$(bindir)
 ifdef INSTALL_SDK # Here comes the hard part
 # include directory is stable (dist/sdk/include) and unstable (dist/include)
 	$(NSINSTALL) -D $(DESTDIR)$(includedir)/stable
@@ -426,7 +426,7 @@
 	(cd $(DIST)/sdk/include && tar $(TAR_CREATE_FLAGS) - .) | \
 	  (cd $(DESTDIR)$(includedir)/stable && tar -xf -)
 # The dist/include has module subdirectories that we need to flatten
-	find $(DIST)/include -xtype f -exec $(SYSINSTALL) $(IFLAGS1) {} $(DESTDIR)$(includedir)/unstable \;
+	find $(DIST)/include -type f -o -type l -exec $(SYSINSTALL) $(IFLAGS1) {} $(DESTDIR)$(includedir)/unstable \;
 # IDL directory is stable (dist/sdk/idl) and unstable (dist/idl)
 	$(NSINSTALL) -D $(DESTDIR)$(idldir)/stable 
 	$(NSINSTALL) -D $(DESTDIR)$(idldir)/unstable
