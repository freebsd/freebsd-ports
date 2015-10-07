--- base/devs.mak.orig	2012-08-08 17:01:36.000000000 +0900
+++ base/devs.mak	2015-08-21 12:18:59.546901000 +0900
@@ -434,10 +434,10 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)lvga256.so : $(lvga256_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)lvga256.so $(lvga256_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)lvga256.so $(lvga256_) -lvga -lvgagl $(XLDFLAGS)
 
 $(GLOBJ)vgalib.so : $(vgalib_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)vgalib.so $(vgalib_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)vgalib.so $(vgalib_) -lvga -lvgagl $(XLDFLAGS)
 
 ### -------------------------- The X11 device -------------------------- ###
 
@@ -479,7 +479,7 @@
 # const/non-const cast required by the X headers that we can't work around.
 $(GLOBJ)gdevxres.$(OBJ) : $(GLSRC)gdevxres.c $(std_h) $(x__h)\
  $(gsmemory_h) $(gstypes_h) $(gxdevice_h) $(gdevx_h)
-	$(CC_NO_WARN) $(GLCCFLAGS) $(XINCLUDE) $(GLO_)gdevxres.$(OBJ) $(C_) $(GLSRC)gdevxres.c
+	$(GLCCSHARED) $(XINCLUDE) $(GLO_)gdevxres.$(OBJ) $(C_) $(GLSRC)gdevxres.c
 
 # Alternate X11-based devices to help debug other drivers.
 # x11alpha pretends to have 4 bits of alpha channel.
@@ -535,7 +535,7 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)X11.so : $(x11alt_) $(x11_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L$(LOCALBASE)/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
