--- src/devs.mak.orig	2003-03-11 11:59:10 UTC
+++ src/devs.mak
@@ -405,7 +405,7 @@ $(DD)lvga256.dev : $(DEVS_MAK) $(lvga256
 	$(ADDMOD) $(DD)lvga256 -lib vga vgagl
 
 $(GLOBJ)gdevl256.$(OBJ) : $(GLSRC)gdevl256.c $(GDEV) $(memory__h)
-	$(GLCC) $(GLO_)gdevl256.$(OBJ) $(C_) $(GLSRC)gdevl256.c
+	$(GLCCSHARED) $(GLO_)gdevl256.$(OBJ) $(C_) $(GLSRC)gdevl256.c
 
 vgalib_=$(GLOBJ)gdevvglb.$(OBJ) $(GLOBJ)gdevpccm.$(OBJ)
 $(DD)vgalib.dev : $(DEVS_MAK) $(vgalib_)
@@ -413,7 +413,7 @@ $(DD)vgalib.dev : $(DEVS_MAK) $(vgalib_)
 	$(ADDMOD) $(DD)vgalib -lib vga
 
 $(GLOBJ)gdevvglb.$(OBJ) : $(GLSRC)gdevvglb.c $(GDEV) $(gdevpccm_h) $(gsparam_h)
-	$(GLCC) $(GLO_)gdevvglb.$(OBJ) $(C_) $(GLSRC)gdevvglb.c
+	$(GLCCSHARED) $(GLO_)gdevvglb.$(OBJ) $(C_) $(GLSRC)gdevvglb.c
 
 ### -------------------------- The X11 device -------------------------- ###
 
@@ -443,24 +443,24 @@ GDEVX=$(GDEV) $(x__h) $(gdevx_h) $(TOP_M
 $(GLOBJ)gdevx.$(OBJ) : $(GLSRC)gdevx.c $(GDEVX) $(math__h) $(memory__h)\
  $(gscoord_h) $(gsdevice_h) $(gsiparm2_h) $(gsmatrix_h) $(gsparam_h)\
  $(gxdevmem_h) $(gxgetbit_h) $(gxiparam_h) $(gxpath_h)
-	$(GLCC) $(XINCLUDE) $(GLO_)gdevx.$(OBJ) $(C_) $(GLSRC)gdevx.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevx.$(OBJ) $(C_) $(GLSRC)gdevx.c
 
 $(GLOBJ)gdevxcmp.$(OBJ) : $(GLSRC)gdevxcmp.c $(GDEVX) $(math__h)
-	$(GLCC) $(XINCLUDE) $(GLO_)gdevxcmp.$(OBJ) $(C_) $(GLSRC)gdevxcmp.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxcmp.$(OBJ) $(C_) $(GLSRC)gdevxcmp.c
 
 $(GLOBJ)gdevxini.$(OBJ) : $(GLSRC)gdevxini.c $(GDEVX) $(memory__h)\
  $(gserrors_h) $(gsparamx_h) $(gxdevmem_h) $(gdevbbox_h)
-	$(GLCC) $(XINCLUDE) $(GLO_)gdevxini.$(OBJ) $(C_) $(GLSRC)gdevxini.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxini.$(OBJ) $(C_) $(GLSRC)gdevxini.c
 
 # We have to compile gdevxres without warnings, because there is a
 # const/non-const cast required by the X headers that we can't work around.
 $(GLOBJ)gdevxres.$(OBJ) : $(GLSRC)gdevxres.c $(std_h) $(x__h)\
  $(gsmemory_h) $(gstypes_h) $(gxdevice_h) $(gdevx_h)
-	$(CC_NO_WARN) $(GLCCFLAGS) $(XINCLUDE) $(GLO_)gdevxres.$(OBJ) $(C_) $(GLSRC)gdevxres.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxres.$(OBJ) $(C_) $(GLSRC)gdevxres.c
 
 $(GLOBJ)gdevxxf.$(OBJ) : $(GLSRC)gdevxxf.c $(GDEVX) $(math__h) $(memory__h)\
  $(gsstruct_h) $(gsutil_h) $(gxxfont_h)
-	$(GLCC) $(XINCLUDE) $(GLO_)gdevxxf.$(OBJ) $(C_) $(GLSRC)gdevxxf.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxxf.$(OBJ) $(C_) $(GLSRC)gdevxxf.c
 
 # Alternate X11-based devices to help debug other drivers.
 # x11alpha pretends to have 4 bits of alpha channel.
@@ -510,7 +510,13 @@ $(DD)x11rg32x.dev : $(DEVS_MAK) $(DD)x11
 
 $(GLOBJ)gdevxalt.$(OBJ) : $(GLSRC)gdevxalt.c $(GDEVX) $(math__h) $(memory__h)\
  $(gsdevice_h) $(gsparam_h) $(gsstruct_h)
-	$(GLCC) $(XINCLUDE) $(GLO_)gdevxalt.$(OBJ) $(C_) $(GLSRC)gdevxalt.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxalt.$(OBJ) $(C_) $(GLSRC)gdevxalt.c
+
+### Shared library object supporting X11.
+### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
+
+$(GLOBJ)X11.so : $(x11alt_) $(x11_)
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L${LOCALBASE}/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
