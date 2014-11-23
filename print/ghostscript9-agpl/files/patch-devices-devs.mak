--- devices/devs.mak.orig	2014-03-26 21:53:48.000000000 +0900
+++ devices/devs.mak	2014-08-25 00:38:44.000000000 +0900
@@ -438,10 +438,10 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(DEVOBJ)lvga256.so : $(lvga256_)
-	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)lvga256.so $(lvga256_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)lvga256.so $(lvga256_) -lvga -lvgagl $(XLDFLAGS)
 
 $(DEVOBJ)vgalib.so : $(vgalib_)
-	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)vgalib.so $(vgalib_) -lvga -lvgagl
+	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)vgalib.so $(vgalib_) -lvga -lvgagl $(XLDFLAGS)
 
 ### -------------------------- The X11 device -------------------------- ###
 
@@ -538,7 +538,7 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(DEVOBJ)X11.so : $(x11alt_) $(x11_)
-	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)X11.so $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)X11.so $(x11alt_) $(x11_) -L$(LOCALBASE)/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
