--- base/openjpeg.mak.orig	2012-08-08 08:01:36 UTC
+++ base/openjpeg.mak
@@ -102,7 +102,7 @@ $(OPEN_JPEG_GEN)openjpeg_0.dev : $(TOP_M
 	$(SETMOD) $(OPEN_JPEG_GEN)openjpeg_0 $(open_jpeg_OBJS)
 
 # define our specific compiler
-OPEN_JPEG_CC=$(CC) $(CFLAGS) $(D_)OPJ_STATIC$(_D) $(I_)$(OPEN_JPEG_GEN)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(D)..$(_I) $(JPXCF_)
+OPEN_JPEG_CC=$(CC) $(JPX_CFLAGS) $(I_)$(JPX_OPENJPEG_I_)$(_I)  $(I_)$(JPX_OPENJPEG_I_)$(D)..$(_I) $(CFLAGS) $(D_)OPJ_STATIC$(_D) $(I_)$(OPEN_JPEG_GEN)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(_I) $(I_)$(JPX_OPENJPEG_I_)$(D)..$(_I) $(JPXCF_)
 OPEN_JPEG_O=$(O_)$(OPEN_JPEG_OBJ)$(OPEN_JPEG_PREFIX)
 
 OPEN_JPEG_DEP=$(AK) $(OPEN_JPEG_MAK)
