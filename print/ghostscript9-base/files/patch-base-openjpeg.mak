--- base/openjpeg.mak.orig	2012-02-08 17:48:48.000000000 +0900
+++ base/openjpeg.mak	2012-02-14 06:40:56.000000000 +0900
@@ -101,7 +101,7 @@
 	$(SETMOD) $(OPEN_JPEG_GEN)openjpeg_0 $(open_jpeg_OBJS)
 
 # define our specific compiler
-OPEN_JPEG_CC=$(CC) $(CFLAGS) $(D_)OPJ_STATIC$(_D) $(I_)$(OPEN_JPEG_GEN)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(D)..$(_I) $(JPXCF_)
+OPEN_JPEG_CC=$(CC) $(JPX_CFLAGS) $(I_)$(JPX_OPENJPEG_I_)$(_I)  $(I_)$(JPX_OPENJPEG_I_)$(D)..$(_I) $(CFLAGS) $(D_)OPJ_STATIC$(_D) $(I_)$(OPEN_JPEG_GEN)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(D)..$(_I) $(JPXCF_)
 OPEN_JPEG_O=$(O_)$(OPEN_JPEG_OBJ)$(OPEN_JPEG_PREFIX)
 
 OPEN_JPEG_DEP=$(AK) $(OPEN_JPEG_MAK)
