--- dao/ScsiIf-lib.cc.orig	Tue Oct 29 19:40:39 2002
+++ dao/ScsiIf-lib.cc	Tue Oct 29 20:14:24 2002
@@ -430,7 +430,7 @@
 #include "ScsiIf-common.cc"
 //<<<<<<< ScsiIf-lib.cc
 
-#ifndef linux
+#ifdef linux
 
 /* Function for mapping any SCSI device to the corresponding SG device.
  * Taken from D. Gilbert's example code.
