--- install.sh.orig	2023-02-27 08:02:22 UTC
+++ install.sh
@@ -637,18 +637,13 @@ tweaks_temp() {
   cp -rf ${SRC_DIR}/src/_sass/_tweaks.scss ${SRC_DIR}/src/_sass/_tweaks-temp.scss
 }
 
-install_image() {
-  sed -i "/\$background:/s/default/image/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
-  echo -e "Install Nautilus with background image version ..."
-}
-
 install_win_titlebutton() {
-  sed -i "/\$titlebutton:/s/circle/square/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+  sed -i "" -e "s/titlebutton: 'circle/titlebutton: 'square/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   echo -e "Install Square titlebutton version ..."
 }
 
 install_round_window() {
-  sed -i "/\$window:/s/default/round/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+  sed -i "" -e "s/window: 'default/window: 'round/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   echo -e "Install Round window version ..."
 }
 
@@ -662,7 +657,7 @@ install_theme_color() {
         theme_color='ubuntu'
         ;;
     esac
-    sed -i "/\$theme:/s/default/${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+    sed -i "" -e "s/theme: 'default/theme: '${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   fi
 }
 
@@ -672,10 +667,6 @@ theme_tweaks() {
     install_css_deps; tweaks_temp
   fi
 
-  if [[ "$image" == "true" ]] ; then
-    install_image
-  fi
-
   if [[ "$square" == "true" ]] ; then
     install_win_titlebutton
   fi
@@ -716,8 +707,6 @@ uninstall_theme() {
     done
   done
 }
-
-./clean-old-theme.sh
 
 if [[ "${gdm:-}" != 'true' && "${remove:-}" != 'true' ]]; then
   install_theme
