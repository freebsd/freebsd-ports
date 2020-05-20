--- exts/Makefile.inc.orig	2020-05-20 01:23:28 UTC
+++ exts/Makefile.inc
@@ -14,7 +14,7 @@ extclean: dbcsrclean
 
 dbcsr:
 	+$(MAKE) -C $(EXTSHOME)/$@ -f .cp2k/Makefile \
-	   INCLUDEMAKE=$(ARCHDIR)/$(ARCH).$(ONEVERSION) \
+	   INCLUDEMAKE=$(ARCHDIR)/$(XARCH).$(ONEVERSION) \
 	   LIBDIR=$(LIBEXTSDIR)/$@ \
 	   OBJDIR=$(OBJEXTSDIR)/$@ \
 	   ACC="$(NVCC)" \
