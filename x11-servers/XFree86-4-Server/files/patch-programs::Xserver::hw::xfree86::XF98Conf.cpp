Index: programs/Xserver/hw/xfree86/XF98Conf.cpp
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/XF98Conf.cpp,v
retrieving revision 1.4
retrieving revision 1.5
diff -u -r1.4 -r1.5
--- programs/Xserver/hw/xfree86/XF98Conf.cpp	13 Feb 2004 23:58:34 -0000	1.4
+++ programs/Xserver/hw/xfree86/XF98Conf.cpp	8 Jun 2004 01:28:55 -0000	1.5
@@ -1,4 +1,4 @@
-XCOMM $XFree86: xc/programs/Xserver/hw/xfree86/XF98Conf.cpp,v 1.4 2004/02/13 23:58:34 dawes Exp $
+XCOMM $XFree86: xc/programs/Xserver/hw/xfree86/XF98Conf.cpp,v 1.5 2004/06/08 01:28:55 dawes Exp $
 XCOMM
 XCOMM Copyright (c) 1994-1998 by The XFree86 Project, Inc.
 XCOMM All rights reserved.
@@ -480,6 +480,20 @@
 
 EndSection
 
+Section "Monitor"
+   Identifier  "Aile TFT LCD"
+   VendorName  "NEC"
+   ModelName   "La13"
+   HorizSync    33.0-82.0  
+   VertRefresh  55.0-90.0
+
+XCOMM fH=46.9,fV=75.0
+   ModeLine "800x600" 49.50 800 836  920 1056 600 601  604  625
+
+XCOMM fH=53.7,fV=85.1
+   ModeLine "800x600H" 56.30 800 836  920 1048 600 601  604  631
+EndSection
+
 XCOMM **********************************************************************
 XCOMM Graphics device section
 XCOMM **********************************************************************
@@ -508,6 +522,16 @@
 XCOMM    VideoRam	2048
 Endsection
 
+Section "Device"
+   Identifier "CLGD7555"
+   VendorName "Cirrus Logic"
+   BoardName  "CLGD 7555"
+   Driver     "cirrus"
+XCOMM  Option     "sw cursor" "on"
+XCOMM  BusID      "PCI:0:3:0"
+XCOMM  VideoRam   2048
+EndSection
+
 XCOMM **********************************************************************
 XCOMM Screen sections.
 XCOMM **********************************************************************
