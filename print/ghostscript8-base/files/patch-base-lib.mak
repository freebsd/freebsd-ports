--- base/lib.mak.orig	2009-12-30 07:18:01.000000000 +0900
+++ base/lib.mak	2015-08-21 20:39:55.003384000 +0900
@@ -895,7 +895,7 @@
 $(GLOBJ)gsparamx.$(OBJ) : $(GLSRC)gsparamx.c $(string__h)\
  $(gserror_h) $(gserrors_h) $(gsmemory_h) $(gsparam_h) $(gsparamx_h)\
  $(gstypes_h)
-	$(GLCC) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
+	$(GLCCSHARED) $(GLO_)gsparamx.$(OBJ) $(C_) $(GLSRC)gsparamx.c
 
 # Future replacement for gsparams.c
 $(GLOBJ)gsparam2.$(OBJ) : $(GLSRC)gsparam2.c $(GXERR) $(memory__h)\
@@ -2684,12 +2684,12 @@
 # This is used to access compressed, compiled-in support files
 gsiorom_h=$(GLSRC)gsiorom.h
 romfs_=$(GLOBJ)gsiorom.$(OBJ)
-$(GLD)romfs1.dev : $(LIB_MAK) $(ECHO_XE) $(romfs_)
+$(GLD)romfs1.dev : $(LIB_MAK) $(ECHOGS_XE) $(romfs_)
 	$(SETMOD) $(GLD)romfs1 $(romfs_)
 	$(ADDMOD) $(GLD)romfs1 -iodev rom
 
 # A dummy romfs when we aren't using COMPILE_INITS
-$(GLD)romfs0.dev :  $(LIB_MAK) $(ECHO_XE) 
+$(GLD)romfs0.dev :  $(LIB_MAK) $(ECHOGS_XE) 
 	$(SETMOD) $(GLD)romfs0 
 
 $(GLGEN)gsromfs1.c : $(MKROMFS_XE) $(PS_ROMFS_DEPS)
