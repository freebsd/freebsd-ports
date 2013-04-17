--- base/lib.mak.orig	2013-04-18 04:24:52.000000000 +0900
+++ base/lib.mak	2013-04-18 04:25:13.000000000 +0900
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
