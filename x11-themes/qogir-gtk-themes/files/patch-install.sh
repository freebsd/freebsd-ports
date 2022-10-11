--- install.sh.orig	2022-07-07 08:30:28 UTC
+++ install.sh
@@ -562,18 +562,13 @@ tweaks_temp() {
   cp -rf ${SRC_DIR}/src/_sass/_tweaks.scss ${SRC_DIR}/src/_sass/_tweaks-temp.scss
 }
 
-install_image() {
-  sed -i "/\$background:/s/default/image/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
-  echo -e "Install Nautilus with background image version ..."
-}
-
 install_win_titlebutton() {
-  sed -i "/\$titlebutton:/s/circle/square/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+  sed -i "" -e "s|titlebutton: 'circle|titlebutton: 'square|" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   echo -e "Install Square titlebutton version ..."
 }
 
 install_round_window() {
-  sed -i "/\$window:/s/default/round/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+  sed -i "" -e "s|window: 'default|window: 'round|" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   echo -e "Install Round window version ..."
 }
 
@@ -587,18 +582,14 @@ install_theme_color() {
         theme_color='ubuntu'
         ;;
     esac
-    sed -i "/\$theme:/s/default/${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+    sed -i "" -e "s|theme: 'default|theme: '${theme_color}|" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   fi
 }
 
 theme_tweaks() {
-  if [[ "$image" == "true" || "$square" == "true" || "$accent" == 'true' || "$window" == 'round' ]]; then
+  if [[ "$square" == "true" || "$accent" == 'true' || "$window" == 'round' ]]; then
     tweaks='true'
     install_package; tweaks_temp
-  fi
-
-  if [[ "$image" == "true" ]] ; then
-    install_image
   fi
 
   if [[ "$square" == "true" ]] ; then
