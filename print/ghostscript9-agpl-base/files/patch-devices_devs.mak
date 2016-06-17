--- devices/devs.mak.orig	2015-03-30 08:21:24 UTC
+++ devices/devs.mak
@@ -546,7 +546,7 @@ $(DEVOBJ)gdevxalt.$(OBJ) : $(DEVSRC)gdev
 ### NON PORTABLE, ONLY UNIX WITH GCC SUPPORT
 
 $(DEVOBJ)X11.so : $(x11alt_) $(x11_) $(MAKEDIRS)
-	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)X11.so $(x11alt_) $(x11_) -L/usr/X11R6/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
+	$(CCLD) $(LDFLAGS) -shared -o $(DEVOBJ)X11.so $(x11alt_) $(x11_) -L$(LOCALBASE)/lib -lXt -lSM -lICE -lXext -lX11 $(XLIBDIRS)
 
 ###### --------------- Memory-buffered printer devices --------------- ######
 
