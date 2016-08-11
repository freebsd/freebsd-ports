--- src/lib.mak.orig	2003-01-17 00:49:05 UTC
+++ src/lib.mak
@@ -35,6 +35,7 @@ GLICCCC=$(CC_) $(I_)$(GLI_) $(II)$(ICCI_
 GLJCC=$(CC_) $(I_)$(GLI_) $(II)$(JI_)$(_I) $(JCF_) $(GLF_)
 GLZCC=$(CC_) $(I_)$(GLI_) $(II)$(ZI_)$(_I) $(ZCF_) $(GLF_)
 GLCCLEAF=$(CC_LEAF) $(I_)$(GLI_)$(_I) $(GLF_)
+GLCCSHARED=$(CC_SHARED) $(GLCCFLAGS)
 # All top-level makefiles define GLD.
 #GLD=$(GLGEN)
 
@@ -187,22 +188,22 @@ gsnogc_=$(GLOBJ)gsnogc.$(OBJ)
 $(GLD)gsnogc.dev : $(LIB_MAK) $(ECHOGS_XE) $(gsnogc_)
 	$(SETMOD) $(GLD)gsnogc $(gsnogc_)
 
-$(GLOBJ)gsnogc.$(OBJ) : $(GLSRC)gsnogc.c $(GX)\
+$(GLOBJ)gsnogc.$(OBJ) : $(arch_h) $(GLSRC)gsnogc.c $(GX)\
  $(gsmdebug_h) $(gsnogc_h) $(gsstruct_h) $(gxalloc_h)
 	$(GLCC) $(GLO_)gsnogc.$(OBJ) $(C_) $(GLSRC)gsnogc.c
 
 ### Bitmap processing
 
-$(GLOBJ)gsbitcom.$(OBJ) : $(GLSRC)gsbitcom.c $(AK) $(std_h)\
+$(GLOBJ)gsbitcom.$(OBJ) : $(arch_h) $(GLSRC)gsbitcom.c $(AK) $(std_h)\
  $(gdebug_h) $(gsbitops_h) $(gstypes_h)
 	$(GLCC) $(GLO_)gsbitcom.$(OBJ) $(C_) $(GLSRC)gsbitcom.c
 
-$(GLOBJ)gsbitops.$(OBJ) : $(GLSRC)gsbitops.c $(AK) $(memory__h) $(stdio__h)\
+$(GLOBJ)gsbitops.$(OBJ) : $(arch_h) $(GLSRC)gsbitops.c $(AK) $(memory__h) $(stdio__h)\
  $(gdebug_h) $(gsbittab_h) $(gserror_h) $(gserrors_h) $(gstypes_h)\
  $(gxbitops_h)
 	$(GLCC) $(GLO_)gsbitops.$(OBJ) $(C_) $(GLSRC)gsbitops.c
 
-$(GLOBJ)gsbittab.$(OBJ) : $(GLSRC)gsbittab.c $(AK) $(stdpre_h) $(gsbittab_h)
+$(GLOBJ)gsbittab.$(OBJ) : $(arch_h) $(GLSRC)gsbittab.c $(AK) $(stdpre_h) $(gsbittab_h)
 	$(GLCC) $(GLO_)gsbittab.$(OBJ) $(C_) $(GLSRC)gsbittab.c
 
 # gsflip is not part of the standard configuration: it's rather large,
@@ -765,7 +766,7 @@ $(GLOBJ)gsparam.$(OBJ) : $(GLSRC)gsparam
 $(GLOBJ)gsparamx.$(OBJ) : $(GLSRC)gsparamx.c $(string__h)\
  $(gserror_h) $(gserrors_h) $(gsmemory_h) $(gsparam_h) $(gsparamx_h)\
  $(gstypes_h)
-	$(GLCC) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
+	$(GLCCSHARED) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
 
 # Future replacement for gsparams.c
 $(GLOBJ)gsparam2.$(OBJ) : $(GLSRC)gsparam2.c $(GXERR) $(memory__h)\
