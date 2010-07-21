--- toolkit/mozapps/installer/packager.mk.orig	2007-09-26 13:45:01.000000000 -0400
+++ toolkit/mozapps/installer/packager.mk	2007-09-26 13:47:29.000000000 -0400
@@ -409,7 +409,7 @@
 	(cd $(DIST)/sdk/include && tar $(TAR_CREATE_FLAGS) - .) | \
 	  (cd $(DESTDIR)$(includedir)/stable && tar -xf -)
 # The dist/include has module subdirectories that we need to flatten
-	find $(DIST)/include -xtype f -exec $(SYSINSTALL) $(IFLAGS1) {} $(DESTDIR)$(includedir)/unstable \;
+	find -L $(DIST)/include -name system_wrappers\* -prune -or -type f -exec $(SYSINSTALL) $(IFLAGS1) {} $(DESTDIR)$(includedir)/unstable \;
 # IDL directory is stable (dist/sdk/idl) and unstable (dist/idl)
 	$(NSINSTALL) -D $(DESTDIR)$(idldir)/stable 
 	$(NSINSTALL) -D $(DESTDIR)$(idldir)/unstable
