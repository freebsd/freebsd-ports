--- Makefile.PL.orig	2015-05-13 19:26:43 UTC
+++ Makefile.PL
@@ -731,11 +731,11 @@ modperl_lib:
 	cd "$(MODPERL_SRC)" && $(MAKE)
 
 modperl_lib_install:
-	cd "$(MODPERL_SRC)" && $(MAKE) DESTDIR=$(DESTDIR) install
+#	cd "$(MODPERL_SRC)" && $(MAKE) DESTDIR=$(DESTDIR) install
 
 modperl_xs_h_install:
-	@$(MKPATH) $(DESTDIR)$(MODPERL_AP_INCLUDEDIR)
-	$(CP) $(MODPERL_XS_H_FILES) $(DESTDIR)$(MODPERL_AP_INCLUDEDIR)
+#	@$(MKPATH) $(DESTDIR)$(MODPERL_AP_INCLUDEDIR)
+#	$(CP) $(MODPERL_XS_H_FILES) $(DESTDIR)$(MODPERL_AP_INCLUDEDIR)
 
 modperl_src_clean:
 	cd "$(MODPERL_SRC)" && $(MAKE) clean
