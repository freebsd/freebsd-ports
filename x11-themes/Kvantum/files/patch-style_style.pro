--- style/style.pro.orig	2019-03-19 23:11:41 UTC
+++ style/style.pro
@@ -62,7 +62,6 @@ unix {
   isEmpty(PREFIX) {
     PREFIX = /usr
   }
-  COLORSDIR =$$PREFIX/share/kde4/apps/color-schemes
   KF5COLORSDIR =$$PREFIX/share/color-schemes
   DATADIR =$$PREFIX/share
 
