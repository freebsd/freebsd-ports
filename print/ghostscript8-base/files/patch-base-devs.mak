--- base/devs.mak.orig	2009-11-12 00:50:28.000000000 +0900
+++ base/devs.mak	2015-08-21 20:37:24.364436000 +0900
@@ -421,10 +421,10 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)lvga256.so : $(lvga256_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)lvga256.so $(lvga256_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)lvga256.so $(lvga256_) -lvga -lvgagl $(XLDFLAGS)
 
 $(GLOBJ)vgalib.so : $(vgalib_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)vgalib.so $(vgalib_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)vgalib.so $(vgalib_) -lvga -lvgagl $(XLDFLAGS)
 
 ### -------------------------- The X11 device -------------------------- ###
 
@@ -457,7 +457,7 @@
 	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevx.$(OBJ) $(C_) $(GLSRC)gdevx.c
 
 $(GLOBJ)gdevxcmp.$(OBJ) : $(GLSRC)gdevxcmp.c $(GDEVX) $(math__h)
-	$(GLCC) $(XINCLUDE) $(GLO_)gdevxcmp.$(OBJ) $(C_) $(GLSRC)gdevxcmp.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxcmp.$(OBJ) $(C_) $(GLSRC)gdevxcmp.c
 
 $(GLOBJ)gdevxini.$(OBJ) : $(GLSRC)gdevxini.c $(GDEVX) $(memory__h)\
  $(gserrors_h) $(gsparamx_h) $(gxdevmem_h) $(gdevbbox_h)
@@ -467,7 +467,7 @@
 # const/non-const cast required by the X headers that we can't work around.
 $(GLOBJ)gdevxres.$(OBJ) : $(GLSRC)gdevxres.c $(std_h) $(x__h)\
  $(gsmemory_h) $(gstypes_h) $(gxdevice_h) $(gdevx_h)
-	$(CC_NO_WARN) $(GLCCFLAGS) $(XINCLUDE) $(GLO_)gdevxres.$(OBJ) $(C_) $(GLSRC)gdevxres.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxres.$(OBJ) $(C_) $(GLSRC)gdevxres.c
 
 $(GLOBJ)gdevxxf.$(OBJ) : $(GLSRC)gdevxxf.c $(GDEVX) $(math__h) $(memory__h)\
  $(gsstruct_h) $(gsutil_h) $(gxxfont_h)
@@ -527,7 +527,7 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)X11.so : $(x11alt_) $(x11_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L$(LOCALBASE)/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
