--- install.sh.orig	2023-10-29 16:16:30 UTC
+++ install.sh
@@ -62,8 +62,7 @@ install() {
   echo "[X-GNOME-Metatheme]"                                                       >> "${themedir}/index.theme"
   echo "GtkTheme=${name}${color}${theme}"                                          >> "${themedir}/index.theme"
   echo "MetacityTheme=${name}${color}${theme}"                                     >> "${themedir}/index.theme"
-  echo "IconTheme=Qogir-manjaro"                                                   >> "${themedir}/index.theme"
-  echo "CursorTheme=Qogir-manjaro"                                                 >> "${themedir}/index.theme"
+  echo "CursorTheme=Adwaita"                                                 >> "${themedir}/index.theme"
   echo "ButtonLayout=menu:minimize,maximize,close"                                 >> "${themedir}/index.theme"
 
   # Install GNOME Shell Theme
