--- style/style.pro.orig	2019-07-30 23:03:59 UTC
+++ style/style.pro
@@ -69,7 +69,6 @@ unix {
   isEmpty(PREFIX) {
     PREFIX = /usr
   }
-  COLORSDIR =$$PREFIX/share/kde4/apps/color-schemes
   KF5COLORSDIR =$$PREFIX/share/color-schemes
   DATADIR =$$PREFIX/share
 
