--- programs/Xserver/hw/xfree86/xorgconf.cpp.orig	Fri Dec 31 14:40:27 2004
+++ programs/Xserver/hw/xfree86/xorgconf.cpp	Fri Dec 31 14:40:28 2004
@@ -624,3 +624,11 @@
     InputDevice "Keyboard1" "CoreKeyboard"
 EndSection
 
+ 
+XCOMM  Two experimental extensions are available -- Composite and XEVIE.  Uncomment
+XCOMM  the section below to enable Composite.  Many extensions can also be disabled
+XCOMM  in this manner.
+
+XCOMM Section "Extensions"
+XCOMM 	Option "Composite" "Enable"
+XCOMM EndSection
