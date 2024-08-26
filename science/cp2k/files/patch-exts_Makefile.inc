--- exts/Makefile.inc.orig	2024-08-06 12:33:49 UTC
+++ exts/Makefile.inc
@@ -36,7 +36,7 @@ dbcsr:
 
 dbcsr:
 	+$(MAKE) -C $(EXTSHOME)/$@ -f $(EXTSHOME)/build_$@/Makefile \
-	   ARCHFILE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   ARCHFILE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   LIBDIR=$(LIBEXTSDIR)/$@ \
 	   OBJDIR=$(OBJEXTSDIR)/$@ \
 	   USE_ACCEL="$(DBCSR_USE_ACCEL)" \
@@ -45,7 +45,7 @@ dbcsrversion:
 
 dbcsrversion:
 	@$(MAKE) -C $(EXTSHOME)/dbcsr -f $(EXTSHOME)/build_dbcsr/Makefile \
-	   ARCHFILE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   ARCHFILE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   USE_ACCEL="$(DBCSR_USE_ACCEL)" \
 	   ACC="$(DBCSR_ACC)" \
 	   ACCFLAGS="$(strip $(DBCSR_ACCFLAGS))" \
@@ -54,7 +54,7 @@ dbcsrclean:
 dbcsrclean:
 	@echo "Clean DBCSR"
 	@$(MAKE) -C $(EXTSHOME)/dbcsr -f $(EXTSHOME)/build_dbcsr/Makefile \
-	   ARCHFILE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   ARCHFILE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   LIBDIR=$(LIBEXTSDIR)/$@ \
 	   OBJDIR=$(OBJEXTSDIR)/$@ \
 	   USE_ACCEL="$(DBCSR_USE_ACCEL)" \
