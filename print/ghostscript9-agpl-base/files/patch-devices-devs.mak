--- devices/devs.mak.orig	2015-03-30 17:21:24.000000000 +0900
+++ devices/devs.mak	2015-07-14 08:48:48.795797000 +0900
@@ -546,7 +546,7 @@
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(DEVOBJ)X11.so : $(x11alt_) $(x11_) $(MAKEDIRS)
-	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)X11.so $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)X11.so $(x11alt_) $(x11_) -L$(LOCALBASE)/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
