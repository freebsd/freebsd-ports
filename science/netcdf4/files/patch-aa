--- rules.make.orig	Sat Dec 18 05:34:48 2004
+++ rules.make	Thu Jan  6 15:12:59 2005
@@ -145,14 +145,8 @@
 	$(INSTALL) $(MANUAL) $@
 $(MANDIR)/man3/$(MANUAL):	$(MANDIR)/man3 $(MANUAL)
 	$(INSTALL) $(MANUAL) $@
-$(MANDIR)/man3f/$(MANUAL):	$(MANDIR)/man3 $(MANDIR)/man3/$(MANUAL) \
-				$(MANDIR)/man3f
-	rm -f $@
-	ln -s $(MANDIR)/man3/$(MANUAL) $@
-$(MANDIR)/man3f90/$(MANUAL):	$(MANDIR)/man3 $(MANDIR)/man3/$(MANUAL) \
-				$(MANDIR)/man3f90
-	rm -f $@
-	ln -s $(MANDIR)/man3/$(MANUAL) $@
+$(MANDIR)/man3f/$(MANUAL):	$(MANDIR)/man3 $(MANDIR)/man3/$(MANUAL)
+$(MANDIR)/man3f90/$(MANUAL):	$(MANDIR)/man3 $(MANDIR)/man3/$(MANUAL)
 
 ################################################################################
 # Cleanup:
