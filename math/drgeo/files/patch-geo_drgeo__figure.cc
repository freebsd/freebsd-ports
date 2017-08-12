Fix the build with GCC >= 6.

drgeo_figure.cc: At global scope:
drgeo_figure.cc:56:1: error: '<anonymous struct> drgeoDialogData', declared using anonymous type, is used but never defined [-fpermissive]
 drgeoDialogData;
  ^~~~~~~~~~~~~~~
--- geo/drgeo_figure.cc.orig	2017-07-25 16:56:59 UTC
+++ geo/drgeo_figure.cc
@@ -48,7 +48,7 @@
 #include "drgeo_dialog.h"
 #include "traite.h"
 
-extern struct
+struct
 {
   drgeoPoint mouse;
   drgeoFigure *figure;
