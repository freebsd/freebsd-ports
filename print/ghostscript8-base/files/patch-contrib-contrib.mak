--- contrib/contrib.mak.orig	2012-06-13 01:22:12.000000000 +0900
+++ contrib/contrib.mak	2012-06-13 01:22:40.000000000 +0900
@@ -956,7 +956,7 @@
 $(GLOBJ)gdevdmpr.$(OBJ) : $(JAPSRC)gdevdmpr.c $(JAPSRC)dviprlib.h $(PDEVH)
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)gdevdmpr.c
 
-$(GLOBJ)dviprlib.$(OBJ) : $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
+$(GLOBJ)dviprlib.$(OBJ) : $(arch_h) $(stdio__h) $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)dviprlib.c
 
 extra-dmprt-install:
