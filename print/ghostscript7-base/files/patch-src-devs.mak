--- src/devs.mak.orig	2015-08-21 21:59:44.117097000 +0900
+++ src/devs.mak	2015-08-21 22:02:19.960434000 +0900
@@ -405,7 +405,7 @@
 	$(ADDMOD) $(DD)lvga256 -lib vga vgagl
 
 $(GLOBJ)gdevl256.$(OBJ) : $(GLSRC)gdevl256.c $(GDEV) $(memory__h)
-	$(GLCC) $(GLO_)gdevl256.$(OBJ) $(C_) $(GLSRC)gdevl256.c
+	$(GLCCSHARED) $(GLO_)gdevl256.$(OBJ) $(C_) $(GLSRC)gdevl256.c
 
 vgalib_=$(GLOBJ)gdevvglb.$(OBJ) $(GLOBJ)gdevpccm.$(OBJ)
 $(DD)vgalib.dev : $(DEVS_MAK) $(vgalib_)
@@ -413,7 +413,7 @@
 	$(ADDMOD) $(DD)vgalib -lib vga
 
 $(GLOBJ)gdevvglb.$(OBJ) : $(GLSRC)gdevvglb.c $(GDEV) $(gdevpccm_h) $(gsparam_h)
-	$(GLCC) $(GLO_)gdevvglb.$(OBJ) $(C_) $(GLSRC)gdevvglb.c
+	$(GLCCSHARED) $(GLO_)gdevvglb.$(OBJ) $(C_) $(GLSRC)gdevvglb.c
 
 ### -------------------------- The X11 device -------------------------- ###
 
@@ -443,24 +443,24 @@
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
@@ -510,7 +510,13 @@
 
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
 
