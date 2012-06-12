--- contrib/contrib.mak.orig	2012-04-08 01:05:18.000000000 +0900
+++ contrib/contrib.mak	2012-04-08 01:05:44.000000000 +0900
@@ -943,7 +943,7 @@
 $(GLOBJ)gdevdmpr.$(OBJ) : $(JAPSRC)gdevdmpr.c $(JAPSRC)dviprlib.h $(PDEVH)
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)gdevdmpr.c
 
-$(GLOBJ)dviprlib.$(OBJ) : $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
+$(GLOBJ)dviprlib.$(OBJ) : $(arch_h) $(stdio__h) $(JAPSRC)dviprlib.c $(JAPSRC)dviprlib.h
 	$(GLCC) $(O_)$@ $(C_) $(JAPSRC)dviprlib.c
 
 extra-dmprt-install:
