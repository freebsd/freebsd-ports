--- install.sh.orig	2021-12-17 21:36:35 UTC
+++ install.sh
@@ -84,8 +84,8 @@ install() {
   theme_tweaks
 
   mkdir -p                                                                           ${THEME_DIR}
-  cp -rf ${SRC_DIR}/COPYING                                                          ${THEME_DIR}
-  cp -rf ${SRC_DIR}/AUTHORS                                                          ${THEME_DIR}
+  gcp -rf ${SRC_DIR}/COPYING                                                          ${THEME_DIR}
+  gcp -rf ${SRC_DIR}/AUTHORS                                                          ${THEME_DIR}
 
   echo "[Desktop Entry]" >> ${THEME_DIR}/index.theme
   echo "Type=X-GNOME-Metatheme" >> ${THEME_DIR}/index.theme
@@ -101,10 +101,10 @@ install() {
   echo "ButtonLayout=menu:minimize,maximize,close" >> ${THEME_DIR}/index.theme
 
   mkdir -p                                                                           ${THEME_DIR}/gnome-shell
-  cp -rf ${SRC_DIR}/src/gnome-shell/{*.svg,extensions,noise-texture.png,pad-osd.css} ${THEME_DIR}/gnome-shell
-  cp -rf ${SRC_DIR}/src/gnome-shell/gnome-shell-theme.gresource.xml                  ${THEME_DIR}/gnome-shell
-  cp -rf ${SRC_DIR}/src/gnome-shell/assets${ELSE_DARK}                               ${THEME_DIR}/gnome-shell/assets
-  cp -rf ${SRC_DIR}/src/gnome-shell/common-assets/*.svg                              ${THEME_DIR}/gnome-shell/assets
+  gcp -rf ${SRC_DIR}/src/gnome-shell/{*.svg,extensions,noise-texture.png,pad-osd.css} ${THEME_DIR}/gnome-shell
+  gcp -rf ${SRC_DIR}/src/gnome-shell/gnome-shell-theme.gresource.xml                  ${THEME_DIR}/gnome-shell
+  gcp -rf ${SRC_DIR}/src/gnome-shell/assets${ELSE_DARK}                               ${THEME_DIR}/gnome-shell/assets
+  gcp -rf ${SRC_DIR}/src/gnome-shell/common-assets/*.svg                              ${THEME_DIR}/gnome-shell/assets
 
   if [[ "$tweaks" == 'true' ]]; then
     if [[ "${GS_VERSION:-}" == 'new' ]]; then
@@ -114,76 +114,76 @@ install() {
     fi
   else
     if [[ "${GS_VERSION:-}" == 'new' ]]; then
-      cp -rf ${SRC_DIR}/src/gnome-shell/shell-40-0/gnome-shell${color}${size}.css    ${THEME_DIR}/gnome-shell/gnome-shell.css
+      gcp -rf ${SRC_DIR}/src/gnome-shell/shell-40-0/gnome-shell${color}${size}.css    ${THEME_DIR}/gnome-shell/gnome-shell.css
     else
-      cp -rf ${SRC_DIR}/src/gnome-shell/shell-3-36/gnome-shell${color}${size}.css    ${THEME_DIR}/gnome-shell/gnome-shell.css
+      gcp -rf ${SRC_DIR}/src/gnome-shell/shell-3-36/gnome-shell${color}${size}.css    ${THEME_DIR}/gnome-shell/gnome-shell.css
     fi
   fi
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-2.0
-  cp -rf ${SRC_DIR}/src/gtk-2.0/{apps.rc,hacks.rc,panel.rc}                          ${THEME_DIR}/gtk-2.0
-  cp -rf ${SRC_DIR}/src/gtk-2.0/main.rc${theme}                                      ${THEME_DIR}/gtk-2.0/main.rc
-  cp -rf ${SRC_DIR}/src/gtk-2.0/assets${ELSE_DARK}                                   ${THEME_DIR}/gtk-2.0/assets
+  gcp -rf ${SRC_DIR}/src/gtk-2.0/{apps.rc,hacks.rc,panel.rc}                          ${THEME_DIR}/gtk-2.0
+  gcp -rf ${SRC_DIR}/src/gtk-2.0/main.rc${theme}                                      ${THEME_DIR}/gtk-2.0/main.rc
+  gcp -rf ${SRC_DIR}/src/gtk-2.0/assets${ELSE_DARK}                                   ${THEME_DIR}/gtk-2.0/assets
   [[ ${theme} != '' && ${color} == '-dark' ]] && \
-  cp -rf ${SRC_DIR}/src/gtk-2.0/assets-theme-dark/*.png                              ${THEME_DIR}/gtk-2.0/assets
-  cp -rf ${SRC_DIR}/src/gtk-2.0/gtkrc${theme}${color}                                ${THEME_DIR}/gtk-2.0/gtkrc
+  gcp -rf ${SRC_DIR}/src/gtk-2.0/assets-theme-dark/*.png                              ${THEME_DIR}/gtk-2.0/assets
+  gcp -rf ${SRC_DIR}/src/gtk-2.0/gtkrc${theme}${color}                                ${THEME_DIR}/gtk-2.0/gtkrc
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-3.0
-  cp -rf ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-3.0
-  cp -rf ${SRC_DIR}/src/gtk/common-assets                                            ${THEME_DIR}/gtk-3.0
+  gcp -rf ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-3.0
+  gcp -rf ${SRC_DIR}/src/gtk/common-assets                                            ${THEME_DIR}/gtk-3.0
 
   if [[ "$tweaks" == 'true' ]]; then
     sassc $SASSC_OPT ${SRC_DIR}/src/gtk/3.0/gtk${color}${size}.scss                  ${THEME_DIR}/gtk-3.0/gtk.css
     [[ ${color} != '-dark' ]] && \
     sassc $SASSC_OPT ${SRC_DIR}/src/gtk/3.0/gtk-dark${size}.scss                     ${THEME_DIR}/gtk-3.0/gtk-dark.css
   else
-    cp -rf ${SRC_DIR}/src/gtk/3.0/gtk${color}${size}.css                             ${THEME_DIR}/gtk-3.0/gtk.css
+    gcp -rf ${SRC_DIR}/src/gtk/3.0/gtk${color}${size}.css                             ${THEME_DIR}/gtk-3.0/gtk.css
     [[ ${color} != '-dark' ]] && \
-    cp -rf ${SRC_DIR}/src/gtk/3.0/gtk-dark${size}.css                                ${THEME_DIR}/gtk-3.0/gtk-dark.css
+    gcp -rf ${SRC_DIR}/src/gtk/3.0/gtk-dark${size}.css                                ${THEME_DIR}/gtk-3.0/gtk-dark.css
   fi
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-4.0
-  cp -rf ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-4.0
-  cp -rf ${SRC_DIR}/src/gtk/common-assets                                            ${THEME_DIR}/gtk-4.0
+  gcp -rf ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-4.0
+  gcp -rf ${SRC_DIR}/src/gtk/common-assets                                            ${THEME_DIR}/gtk-4.0
 
   if [[ "$tweaks" == 'true' ]]; then
     sassc $SASSC_OPT ${SRC_DIR}/src/gtk/4.0/gtk${color}${size}.scss                  ${THEME_DIR}/gtk-4.0/gtk.css
     [[ ${color} != '-dark' ]] && \
     sassc $SASSC_OPT ${SRC_DIR}/src/gtk/4.0/gtk-dark${size}.scss                     ${THEME_DIR}/gtk-4.0/gtk-dark.css
   else
-    cp -rf ${SRC_DIR}/src/gtk/4.0/gtk${color}${size}.css                             ${THEME_DIR}/gtk-4.0/gtk.css
+    gcp -rf ${SRC_DIR}/src/gtk/4.0/gtk${color}${size}.css                             ${THEME_DIR}/gtk-4.0/gtk.css
     [[ ${color} != '-dark' ]] && \
-    cp -rf ${SRC_DIR}/src/gtk/4.0/gtk-dark${size}.css                                ${THEME_DIR}/gtk-4.0/gtk-dark.css
+    gcp -rf ${SRC_DIR}/src/gtk/4.0/gtk-dark${size}.css                                ${THEME_DIR}/gtk-4.0/gtk-dark.css
   fi
 
   mkdir -p                                                                           ${THEME_DIR}/metacity-1
-  cp -rf ${SRC_DIR}/src/metacity-1/assets/*.png                                      ${THEME_DIR}/metacity-1
-  cp -rf ${SRC_DIR}/src/metacity-1/metacity-theme-1${color}.xml                      ${THEME_DIR}/metacity-1/metacity-theme-1.xml
+  gcp -rf ${SRC_DIR}/src/metacity-1/assets/*.png                                      ${THEME_DIR}/metacity-1
+  gcp -rf ${SRC_DIR}/src/metacity-1/metacity-theme-1${color}.xml                      ${THEME_DIR}/metacity-1/metacity-theme-1.xml
   cd ${THEME_DIR}/metacity-1
   ln -s metacity-theme-1.xml metacity-theme-2.xml
   ln -s metacity-theme-1.xml metacity-theme-3.xml
 
   mkdir -p                                                                           ${THEME_DIR}/unity
-  cp -rf ${SRC_DIR}/src/unity/{*.svg,*.png,dash-widgets.json}                        ${THEME_DIR}/unity
-  cp -rf ${SRC_DIR}/src/unity/assets${ELSE_LIGHT}                                    ${THEME_DIR}/unity/assets
+  gcp -rf ${SRC_DIR}/src/unity/{*.svg,*.png,dash-widgets.json}                        ${THEME_DIR}/unity
+  gcp -rf ${SRC_DIR}/src/unity/assets${ELSE_LIGHT}                                    ${THEME_DIR}/unity/assets
 
   mkdir -p                                                                           ${THEME_DIR}/xfwm4
-  cp -rf ${SRC_DIR}/src/xfwm4/{*.svg,themerc}                                        ${THEME_DIR}/xfwm4
-  cp -rf ${SRC_DIR}/src/xfwm4/assets${ELSE_LIGHT}                                    ${THEME_DIR}/xfwm4/assets
+  gcp -rf ${SRC_DIR}/src/xfwm4/{*.svg,themerc}                                        ${THEME_DIR}/xfwm4
+  gcp -rf ${SRC_DIR}/src/xfwm4/assets${ELSE_LIGHT}                                    ${THEME_DIR}/xfwm4/assets
 
   if [[ "${theme}" == '' ]]; then
     mkdir -p                                                                         ${THEME_DIR}/cinnamon
-    cp -rf ${SRC_DIR}/src/cinnamon/cinnamon${ELSE_DARK}.css                          ${THEME_DIR}/cinnamon/cinnamon.css
-    cp -rf ${SRC_DIR}/src/cinnamon/assets/common-assets                              ${THEME_DIR}/cinnamon/assets
-    cp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/checkbox/*.svg          ${THEME_DIR}/cinnamon/assets/checkbox
-    cp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/menu/*.svg              ${THEME_DIR}/cinnamon/assets/menu
-    cp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/misc/*.svg              ${THEME_DIR}/cinnamon/assets/misc
-    cp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/switch/*.svg            ${THEME_DIR}/cinnamon/assets/switch
-    cp -rf ${SRC_DIR}/src/cinnamon/thumbnail${ELSE_DARK}.png                         ${THEME_DIR}/cinnamon/thumbnail.png
+    gcp -rf ${SRC_DIR}/src/cinnamon/cinnamon${ELSE_DARK}.css                          ${THEME_DIR}/cinnamon/cinnamon.css
+    gcp -rf ${SRC_DIR}/src/cinnamon/assets/common-assets                              ${THEME_DIR}/cinnamon/assets
+    gcp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/checkbox/*.svg          ${THEME_DIR}/cinnamon/assets/checkbox
+    gcp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/menu/*.svg              ${THEME_DIR}/cinnamon/assets/menu
+    gcp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/misc/*.svg              ${THEME_DIR}/cinnamon/assets/misc
+    gcp -rf ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/switch/*.svg            ${THEME_DIR}/cinnamon/assets/switch
+    gcp -rf ${SRC_DIR}/src/cinnamon/thumbnail${ELSE_DARK}.png                         ${THEME_DIR}/cinnamon/thumbnail.png
   fi
 
   mkdir -p                                                                           ${THEME_DIR}/plank
-  cp -rf ${SRC_DIR}/src/plank/dock${ELSE_LIGHT}.theme                                ${THEME_DIR}/plank/dock.theme
+  gcp -rf ${SRC_DIR}/src/plank/dock${ELSE_LIGHT}.theme                                ${THEME_DIR}/plank/dock.theme
 }
 
 install_gdm() {
@@ -193,7 +193,7 @@ install_gdm() {
 
   if [[ -f "$GS_THEME_FILE" ]] && [[ "$(which glib-compile-resources 2> /dev/null)" ]]; then
     echo "Installing '$GS_THEME_FILE'..."
-    cp -an "$GS_THEME_FILE" "$GS_THEME_FILE.bak"
+    gcp -an "$GS_THEME_FILE" "$GS_THEME_FILE.bak"
     glib-compile-resources \
       --sourcedir="$THEME_DIR/gnome-shell" \
       --target="$GS_THEME_FILE" \
@@ -206,8 +206,8 @@ install_gdm() {
 
   if [[ -f "$UBUNTU_THEME_FILE" ]]; then
     echo "Installing '$UBUNTU_THEME_FILE'..."
-    cp -an "$UBUNTU_THEME_FILE" "$UBUNTU_THEME_FILE.bak"
-    cp -af "$THEME_DIR/gnome-shell/gnome-shell.css" "$UBUNTU_THEME_FILE"
+    gcp -an "$UBUNTU_THEME_FILE" "$UBUNTU_THEME_FILE.bak"
+    gcp -af "$THEME_DIR/gnome-shell/gnome-shell.css" "$UBUNTU_THEME_FILE"
   fi
 }
 
@@ -215,7 +215,7 @@ install_icon() {
   echo -e "\nInstalling Canta icon theme..."
 
   # Copying files
-  cp -rf ${SRC_DIR}/icons/Canta ${ICON_DEST_DIR}
+  gcp -rf ${SRC_DIR}/icons/Canta ${ICON_DEST_DIR}
 
   # update icon caches
   gtk-update-icon-cache ${ICON_DEST_DIR}/Canta
@@ -390,7 +390,7 @@ install_theme() {
 }
 
 tweaks_temp() {
-  cp -rf ${SRC_DIR}/src/_sass/_tweaks.scss ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+  gcp -rf ${SRC_DIR}/src/_sass/_tweaks.scss ${SRC_DIR}/src/_sass/_tweaks-temp.scss
 }
 
 theme_colors() {
@@ -403,7 +403,7 @@ theme_colors() {
         theme_color='indigo'
         ;;
     esac
-    sed -i "/\$color:/s/default/${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+    gsed -i "/\$color:/s/default/${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   fi
 }
 
