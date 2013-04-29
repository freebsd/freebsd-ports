--- src/contrib.mak.orig	2008-06-21 01:20:36.000000000 +0900
+++ src/contrib.mak	2008-06-21 01:21:28.000000000 +0900
@@ -878,3 +878,4 @@
 $(GLOBJ)gdevsunr.$(OBJ) : $(GLSRC)gdevsunr.c $(PDEVH)
 	$(GLCC) $(GLO_)gdevsunr.$(OBJ) $(C_) $(GLSRC)gdevsunr.c
 
+include $(GLSRCDIR)/contrib_extra.mak
