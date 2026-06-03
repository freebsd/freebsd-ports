--- install.sh.orig	2025-08-21 16:29:23 UTC
+++ install.sh
@@ -1,11 +1,11 @@
 #!/usr/local/bin/bash
 
-. config.sh
-export SCALE_FACTORS=$( seq -s' ' 2 $MAX_SCALE_FACTOR )
-
 REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
 SRC_DIR="${REPO_DIR}/src"
 
+. ${REPO_DIR}/config.sh
+export SCALE_FACTORS=$( seq -s' ' 2 $MAX_SCALE_FACTOR )
+
 ROOT_UID=0
 DEST_DIR=
 
@@ -193,9 +193,6 @@ install() {
   mkdir -p                                                                                   "${THEME_DIR}/xfwm4"
   cp -r "${SRC_DIR}/assets/xfwm4/assets${color}${small}/"*'.png'                             "${THEME_DIR}/xfwm4"
   cp -r "${SRC_DIR}/main/xfwm4/themerc${color}"                                              "${THEME_DIR}/xfwm4/themerc"
-  
-  mkdir -p                                                                                   "${THEME_DIR}/unity"
-  cp -r "${SRC_DIR}/assets/unity/assets/"*'.png'                                             "${THEME_DIR}/unity"
 
   mkdir -p                                                                                   "${THEME_DIR}/cinnamon"
   sassc $SASSC_OPT "${SRC_DIR}/main/cinnamon/cinnamon${color}${opacity}.scss"                "${THEME_DIR}/cinnamon/cinnamon.css"
@@ -288,7 +285,7 @@ install_gdm() {
     cp -an "$UBUNTU_YARU_THEME_FILE" "$UBUNTU_YARU_THEME_FILE.bak"
     rm -rf "$UBUNTU_YARU_THEME_FILE"
 
-    sed -i "s|assets|resource:///org/gnome/shell/theme/assets|" "$GDM_THEME_DIR"/gnome-shell/gnome-shell.css
+    sed -i "" "s|assets|resource:///org/gnome/shell/theme/assets|" "$GDM_THEME_DIR"/gnome-shell/gnome-shell.css
 
     glib-compile-resources \
       --sourcedir="$GDM_THEME_DIR"/gnome-shell \
@@ -647,7 +644,7 @@ theme_color() {
         theme_color='grey'
         ;;
     esac
-    sed -i "/\$theme:/s/default/${theme_color}/" "${SRC_DIR}/sass/_theme-variant-temp.scss"
+    sed -i "" "/\$theme:/s/default/${theme_color}/" "${SRC_DIR}/sass/_theme-variant-temp.scss"
   fi
 }
 
