--- base/devs.mak.orig	2008-11-08 03:49:34.000000000 +0900
+++ base/devs.mak	2009-03-29 03:39:04.000000000 +0900
@@ -418,11 +418,11 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)lvga256.so : $(lvga256_)
-	$(CCLD) -shared -Wl,'-solvga256.so' $(lvga256_) -lvga -lvgagl
+	$(CCLD) -shared -Wl,'-solvga256.so' $(lvga256_) -lvga -lvgagl $(XLDFLAGS)
 	mv lvga256.so $(GLOBJ)lvga256.so
 
 $(GLOBJ)vgalib.so : $(vgalib_)
-	$(CCLD) -shared -Wl,'-sovgalib.so' $(vgalib_) -lvga -lvgagl
+	$(CCLD) -shared -Wl,'-sovgalib.so' $(vgalib_) -lvga -lvgagl $(XLDFLAGS)
 	mv vgalib.so $(GLOBJ)vgalib.so
 
 ### -------------------------- The X11 device -------------------------- ###
@@ -526,7 +526,7 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(GLOBJ)X11.so : $(x11alt_) $(x11_)
-	$(CCLD) -shared -Wl,'-soX11.so' $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) -shared -Wl,'-soX11.so' $(x11alt_) $(x11_) -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 	mv X11.so $(GLOBJ)X11.so
 
 ###### --------------- Memory-buffered printer devices --------------- ######
