--- contrib/contrib.mak.orig	2012-08-08 08:01:36 UTC
+++ contrib/contrib.mak
@@ -943,7 +943,7 @@ $(DD)dmprt.dev : $(dmprt_) $(DD)page.dev
 $(GLOBJ)gdevdmpr.$(OBJ) : $(JAPSRC)gdevdmpr.c $(JAPSRC)dviprlib.h $(PDEVH)
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)gdevdmpr.c
 
-$(GLOBJ)dviprlib.$(OBJ) : $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
+$(GLOBJ)dviprlib.$(OBJ) : $(arch_h) $(stdio__h) $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)dviprlib.c
 
 extra-dmprt-install:
