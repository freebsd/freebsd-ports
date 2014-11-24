--- src/lib.mak.orig	2013-04-30 02:52:53.000000000 +0900
+++ src/lib.mak	2013-04-30 02:53:40.000000000 +0900
@@ -187,22 +187,22 @@
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
