--- src/contrib.mak.orig	2003-01-17 09:49:00.000000000 +0900
+++ src/contrib.mak	2015-08-21 22:44:22.155516000 +0900
@@ -598,9 +598,6 @@
 $(DD)lbp8.dev : $(lbp8_) $(DD)page.dev
 	$(SETPDEV) $(DD)lbp8 $(lbp8_)
 
-$(DD)lips3.dev : $(lbp8_) $(DD)page.dev
-	$(SETPDEV) $(DD)lips3 $(lbp8_)
-
 $(GLOBJ)gdevlbp8.$(OBJ) : $(GLSRC)gdevlbp8.c $(PDEVH)
 	$(GLCC) $(GLO_)gdevlbp8.$(OBJ) $(C_) $(GLSRC)gdevlbp8.c
 
@@ -878,3 +875,4 @@
 $(GLOBJ)gdevsunr.$(OBJ) : $(GLSRC)gdevsunr.c $(PDEVH)
 	$(GLCC) $(GLO_)gdevsunr.$(OBJ) $(C_) $(GLSRC)gdevsunr.c
 
+include $(GLSRCDIR)/contrib_extra.mak
