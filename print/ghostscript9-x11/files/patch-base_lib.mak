--- base/lib.mak.orig	2012-08-08 08:01:36 UTC
+++ base/lib.mak
@@ -990,7 +990,7 @@ $(GLOBJ)gsparam.$(OBJ) : $(GLSRC)gsparam
 $(GLOBJ)gsparamx.$(OBJ) : $(AK) $(GLSRC)gsparamx.c $(string__h)\
  $(gserrors_h) $(gsmemory_h) $(gsparam_h) $(gsparamx_h)\
  $(gstypes_h) $(MAKEDIRS)
-	$(GLCC) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
+	$(GLCCSHARED) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
 
 # Future replacement for gsparams.c
 $(GLOBJ)gsparam2.$(OBJ) : $(GLSRC)gsparam2.c $(AK) $(gx_h)\
