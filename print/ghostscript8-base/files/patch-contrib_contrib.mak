--- contrib/contrib.mak.orig	2009-07-27 16:59:50 UTC
+++ contrib/contrib.mak
@@ -956,7 +956,7 @@ $(DD)dmprt.dev : $(dmprt_) $(DD)page.dev
 $(GLOBJ)gdevdmpr.$(OBJ) : $(JAPSRC)gdevdmpr.c $(JAPSRC)dviprlib.h $(PDEVH)
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)gdevdmpr.c
 
-$(GLOBJ)dviprlib.$(OBJ) : $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
+$(GLOBJ)dviprlib.$(OBJ) : $(arch_h) $(stdio__h) $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)dviprlib.c
 
 extra-dmprt-install:
