--- base/lib.mak.orig	2015-08-21 12:20:36.687050000 +0900
+++ base/lib.mak	2015-08-21 12:20:57.497755000 +0900
@@ -990,7 +990,7 @@
 $(GLOBJ)gsparamx.$(OBJ) : $(AK) $(GLSRC)gsparamx.c $(string__h)\
  $(gserrors_h) $(gsmemory_h) $(gsparam_h) $(gsparamx_h)\
  $(gstypes_h) $(MAKEDIRS)
-	$(GLCC) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
+	$(GLCCSHARED) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
 
 # Future replacement for gsparams.c
 $(GLOBJ)gsparam2.$(OBJ) : $(GLSRC)gsparam2.c $(AK) $(gx_h)\
