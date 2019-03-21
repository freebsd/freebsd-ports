--- themes/themes.pro.orig	2019-03-19 23:10:32 UTC
+++ themes/themes.pro
@@ -6,7 +6,6 @@ unix {
     PREFIX = /usr
   }
   KVDIR = $$PREFIX/share/Kvantum
-  COLORSDIR = $$PREFIX/share/kde4/apps/color-schemes
   KF5COLORSDIR = $$PREFIX/share/color-schemes
   OBDIR = $$PREFIX/share/themes
 
@@ -14,7 +13,6 @@ unix {
   QMAKE_INSTALL_DIR = cp -f -R --no-preserve=mode
   kv.path = $$KVDIR
   kv.files += ./kvthemes/*
-  colors.path = $$COLORSDIR
   colors.files += ./colors/*.colors
   kf5colors.path = $$KF5COLORSDIR
   kf5colors.files += ./colors/*.colors
