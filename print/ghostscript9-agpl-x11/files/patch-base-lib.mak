--- base/lib.mak.orig	2015-08-22 03:38:11.784264000 +0900
+++ base/lib.mak	2015-08-22 03:38:19.947660000 +0900
@@ -1025,7 +1025,7 @@
 $(GLOBJ)gsparamx.$(OBJ) : $(AK) $(GLSRC)gsparamx.c $(string__h)\
  $(gserrors_h) $(gsmemory_h) $(gsparam_h) $(gsparamx_h)\
  $(gstypes_h) $(MAKEDIRS)
-	$(GLCC) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
+	$(GLCCSHARED) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
 
 # Future replacement for gsparams.c
 $(GLOBJ)gsparam2.$(OBJ) : $(GLSRC)gsparam2.c $(AK) $(gx_h)\
