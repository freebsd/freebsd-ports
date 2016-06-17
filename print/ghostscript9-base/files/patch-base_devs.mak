--- base/devs.mak.orig	2012-08-08 08:01:36 UTC
+++ base/devs.mak
@@ -434,10 +434,10 @@ $(GLOBJ)gdevvglb.$(OBJ) : $(GLSRC)gdevvg
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)lvga256.so : $(lvga256_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)lvga256.so $(lvga256_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)lvga256.so $(lvga256_) -lvga -lvgagl $(XLDFLAGS)
 
 $(GLOBJ)vgalib.so : $(vgalib_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)vgalib.so $(vgalib_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)vgalib.so $(vgalib_) -lvga -lvgagl $(XLDFLAGS)
 
 ### -------------------------- The X11 device -------------------------- ###
 
@@ -535,7 +535,7 @@ $(GLOBJ)gdevxalt.$(OBJ) : $(GLSRC)gdevxa
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)X11.so : $(x11alt_) $(x11_)
-	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) $(LDFLAGS) -shared -o $(GLOBJ)X11.so $(x11alt_) $(x11_) -L$(LOCALBASE)/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
