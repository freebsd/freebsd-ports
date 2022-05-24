--- exts/Makefile.inc.orig	2021-12-31 09:29:59 UTC
+++ exts/Makefile.inc
@@ -36,7 +36,7 @@ extclean: dbcsrclean
 
 dbcsr:
 	+$(MAKE) -C $(EXTSHOME)/$@ -f $(EXTSHOME)/build_$@/Makefile \
-	   ARCHFILE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   ARCHFILE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   LIBDIR=$(LIBEXTSDIR)/$@ \
 	   OBJDIR=$(OBJEXTSDIR)/$@ \
 	   USE_ACCEL="$(DBCSR_USE_ACCEL)" \
@@ -45,7 +45,7 @@ dbcsr:
 
 dbcsrversion:
 	@$(MAKE) -C $(EXTSHOME)/dbcsr -f $(EXTSHOME)/build_dbcsr/Makefile \
-	   ARCHFILE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   ARCHFILE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   USE_ACCEL="$(DBCSR_USE_ACCEL)" \
 	   ACC="$(DBCSR_ACC)" \
 	   ACCFLAGS="$(DBCSR_ACCFLAGS)" \
@@ -54,7 +54,7 @@ dbcsrversion:
 dbcsrclean:
 	@echo "Clean DBCSR"
 	@$(MAKE) -C $(EXTSHOME)/dbcsr -f $(EXTSHOME)/build_dbcsr/Makefile \
-	   ARCHFILE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   ARCHFILE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   LIBDIR=$(LIBEXTSDIR)/$@ \
 	   OBJDIR=$(OBJEXTSDIR)/$@ \
 	   USE_ACCEL="$(DBCSR_USE_ACCEL)" \
