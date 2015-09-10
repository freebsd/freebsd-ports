--- src/smartgdi-contrib.mak.orig	Wed Jun 19 21:43:43 2002
+++ src/smartgdi-contrib.mak	Mon Jul 21 13:59:00 2003
@@ -3,10 +3,12 @@
 ### Note : this driver is used by Samsung SmartGDI compatible printers.   ###
 ###
 
+gdi_opts=-DGS_VERSION_MAJOR=$(GS_VERSION_MAJOR)
+
 GDIMONO=$(GLOBJ)gdevgdi.$(OBJ) $(HPPCL)
 
 $(DD)gdi.dev: $(GDIMONO) $(DD)page.dev
 	$(SETPDEV) $(DD)gdi $(GDIMONO)
 
 $(GLOBJ)gdevgdi.$(OBJ): $(GLSRC)gdevgdi.c $(PDEVH) $(gdevpcl_h)
-	$(GLCC) $(GLO_)gdevgdi.$(OBJ) $(C_) $(GLSRC)gdevgdi.c
+	$(GLCC) $(GLO_)gdevgdi.$(OBJ) $(C_) $(gdi_opts) $(GLSRC)gdevgdi.c
