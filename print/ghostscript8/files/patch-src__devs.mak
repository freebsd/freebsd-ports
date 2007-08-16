--- src/devs.mak.orig	Thu Jun  7 07:03:27 2007
+++ src/devs.mak	Wed Aug  8 23:26:52 2007
@@ -426,11 +426,11 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)lvga256.so: $(lvga256_)
-	$(CCLD) -shared -Wl,'-solvga256.so' $(lvga256_) -lvga -lvgagl
+	$(CCLD) -shared -Wl,'-solvga256.so' $(lvga256_) -lvga -lvgagl $(XLDFLAGS)
 	mv lvga256.so $(GLOBJ)lvga256.so
 
 $(GLOBJ)vgalib.so: $(vgalib_)
-	$(CCLD) -shared -Wl,'-sovgalib.so' $(vgalib_) -lvga -lvgagl
+	$(CCLD) -shared -Wl,'-sovgalib.so' $(vgalib_) -lvga -lvgagl $(XLDFLAGS)
 	mv vgalib.so $(GLOBJ)vgalib.so
 
 ### -------------------------- The X11 device -------------------------- ###
@@ -534,7 +534,7 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)X11.so: $(x11alt_) $(x11_)
-	$(CCLD) -shared -Wl,'-soX11.so' $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) -shared -Wl,'-soX11.so' $(x11alt_) $(x11_) -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 	mv X11.so $(GLOBJ)X11.so
 
 ###### --------------- Memory-buffered printer devices --------------- ######
