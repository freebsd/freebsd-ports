--- install.sh.orig	2021-02-13 18:45:42 UTC
+++ install.sh
@@ -74,8 +74,8 @@ install() {
   echo "Installing '${THEME_DIR}'..."
 
   mkdir -p                                                                           ${THEME_DIR}
-  cp -ur ${SRC_DIR}/COPYING                                                          ${THEME_DIR}
-  cp -ur ${SRC_DIR}/AUTHORS                                                          ${THEME_DIR}
+  cp -pr ${SRC_DIR}/COPYING                                                          ${THEME_DIR}
+  cp -pr ${SRC_DIR}/AUTHORS                                                          ${THEME_DIR}
 
   echo "[Desktop Entry]" >> ${THEME_DIR}/index.theme
   echo "Type=X-GNOME-Metatheme" >> ${THEME_DIR}/index.theme
@@ -91,53 +91,53 @@ install() {
   echo "ButtonLayout=menu:minimize,maximize,close" >> ${THEME_DIR}/index.theme
 
   mkdir -p                                                                           ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/src/gnome-shell/{*.svg,extensions,noise-texture.png,pad-osd.css} ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/src/gnome-shell/gnome-shell-theme.gresource.xml                  ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/src/gnome-shell/assets${ELSE_DARK}                               ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/src/gnome-shell/common-assets/{*.svg,dash}                       ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/src/gnome-shell/gnome-shell${theme}${color}${size}.css           ${THEME_DIR}/gnome-shell/gnome-shell.css
+  cp -pr ${SRC_DIR}/src/gnome-shell/{*.svg,extensions,noise-texture.png,pad-osd.css} ${THEME_DIR}/gnome-shell
+  cp -pr ${SRC_DIR}/src/gnome-shell/gnome-shell-theme.gresource.xml                  ${THEME_DIR}/gnome-shell
+  cp -pr ${SRC_DIR}/src/gnome-shell/assets${ELSE_DARK}                               ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/src/gnome-shell/common-assets/{*.svg,dash}                       ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/src/gnome-shell/gnome-shell${theme}${color}${size}.css           ${THEME_DIR}/gnome-shell/gnome-shell.css
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-2.0
-  cp -ur ${SRC_DIR}/src/gtk-2.0/{apps.rc,hacks.rc,panel.rc}                          ${THEME_DIR}/gtk-2.0
-  cp -ur ${SRC_DIR}/src/gtk-2.0/main.rc${theme}                                      ${THEME_DIR}/gtk-2.0/main.rc
-  cp -ur ${SRC_DIR}/src/gtk-2.0/assets${ELSE_DARK}                                   ${THEME_DIR}/gtk-2.0/assets
+  cp -pr ${SRC_DIR}/src/gtk-2.0/{apps.rc,hacks.rc,panel.rc}                          ${THEME_DIR}/gtk-2.0
+  cp -pr ${SRC_DIR}/src/gtk-2.0/main.rc${theme}                                      ${THEME_DIR}/gtk-2.0/main.rc
+  cp -pr ${SRC_DIR}/src/gtk-2.0/assets${ELSE_DARK}                                   ${THEME_DIR}/gtk-2.0/assets
   [[ ${theme} != '' && ${color} == '-dark' ]] && \
   cp -r ${SRC_DIR}/src/gtk-2.0/assets-theme-dark/*.png                               ${THEME_DIR}/gtk-2.0/assets
-  cp -ur ${SRC_DIR}/src/gtk-2.0/gtkrc${theme}${color}                                ${THEME_DIR}/gtk-2.0/gtkrc
+  cp -pr ${SRC_DIR}/src/gtk-2.0/gtkrc${theme}${color}                                ${THEME_DIR}/gtk-2.0/gtkrc
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-3.0
-  cp -ur ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-3.0
-  cp -ur ${SRC_DIR}/src/gtk/common-assets                                            ${THEME_DIR}/gtk-3.0
-  cp -ur ${SRC_DIR}/src/gtk/gtk${theme}${color}${size}.css                           ${THEME_DIR}/gtk-3.0/gtk.css
+  cp -pr ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-3.0
+  cp -pr ${SRC_DIR}/src/gtk/common-assets                                            ${THEME_DIR}/gtk-3.0
+  cp -pr ${SRC_DIR}/src/gtk/gtk${theme}${color}${size}.css                           ${THEME_DIR}/gtk-3.0/gtk.css
   [[ ${color} != '-dark' ]] && \
-  cp -ur ${SRC_DIR}/src/gtk/gtk${theme}-dark${size}.css                              ${THEME_DIR}/gtk-3.0/gtk-dark.css
+  cp -pr ${SRC_DIR}/src/gtk/gtk${theme}-dark${size}.css                              ${THEME_DIR}/gtk-3.0/gtk-dark.css
 
   mkdir -p                                                                           ${THEME_DIR}/metacity-1
-  cp -ur ${SRC_DIR}/src/metacity-1/assets/*.png                                      ${THEME_DIR}/metacity-1
-  cp -ur ${SRC_DIR}/src/metacity-1/metacity-theme-1${color}.xml                      ${THEME_DIR}/metacity-1/metacity-theme-1.xml
+  cp -pr ${SRC_DIR}/src/metacity-1/assets/*.png                                      ${THEME_DIR}/metacity-1
+  cp -pr ${SRC_DIR}/src/metacity-1/metacity-theme-1${color}.xml                      ${THEME_DIR}/metacity-1/metacity-theme-1.xml
   cd ${THEME_DIR}/metacity-1
   ln -s metacity-theme-1.xml metacity-theme-2.xml
   ln -s metacity-theme-1.xml metacity-theme-3.xml
 
   mkdir -p                                                                           ${THEME_DIR}/unity
-  cp -ur ${SRC_DIR}/src/unity/{*.svg,*.png,dash-widgets.json}                        ${THEME_DIR}/unity
-  cp -ur ${SRC_DIR}/src/unity/assets${ELSE_LIGHT}                                    ${THEME_DIR}/unity/assets
+  cp -pr ${SRC_DIR}/src/unity/{*.svg,*.png,dash-widgets.json}                        ${THEME_DIR}/unity
+  cp -pr ${SRC_DIR}/src/unity/assets${ELSE_LIGHT}                                    ${THEME_DIR}/unity/assets
 
   mkdir -p                                                                           ${THEME_DIR}/xfwm4
-  cp -ur ${SRC_DIR}/src/xfwm4/{*.svg,themerc}                                        ${THEME_DIR}/xfwm4
-  cp -ur ${SRC_DIR}/src/xfwm4/assets${ELSE_LIGHT}                                    ${THEME_DIR}/xfwm4/assets
+  cp -pr ${SRC_DIR}/src/xfwm4/{*.svg,themerc}                                        ${THEME_DIR}/xfwm4
+  cp -pr ${SRC_DIR}/src/xfwm4/assets${ELSE_LIGHT}                                    ${THEME_DIR}/xfwm4/assets
 
   mkdir -p                                                                           ${THEME_DIR}/cinnamon
-  cp -ur ${SRC_DIR}/src/cinnamon/cinnamon${ELSE_DARK}.css                            ${THEME_DIR}/cinnamon/cinnamon.css
-  cp -ur ${SRC_DIR}/src/cinnamon/assets/common-assets                                ${THEME_DIR}/cinnamon/assets
-  cp -ur ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/checkbox/*.svg            ${THEME_DIR}/cinnamon/assets/checkbox
-  cp -ur ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/menu/*.svg                ${THEME_DIR}/cinnamon/assets/menu
-  cp -ur ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/misc/*.svg                ${THEME_DIR}/cinnamon/assets/misc
-  cp -ur ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/switch/*.svg              ${THEME_DIR}/cinnamon/assets/switch
-  cp -ur ${SRC_DIR}/src/cinnamon/thumbnail${ELSE_DARK}.png                           ${THEME_DIR}/cinnamon/thumbnail.png
+  cp -pr ${SRC_DIR}/src/cinnamon/cinnamon${ELSE_DARK}.css                            ${THEME_DIR}/cinnamon/cinnamon.css
+  cp -pr ${SRC_DIR}/src/cinnamon/assets/common-assets                                ${THEME_DIR}/cinnamon/assets
+  cp -pr ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/checkbox/*.svg            ${THEME_DIR}/cinnamon/assets/checkbox
+  cp -pr ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/menu/*.svg                ${THEME_DIR}/cinnamon/assets/menu
+  cp -pr ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/misc/*.svg                ${THEME_DIR}/cinnamon/assets/misc
+  cp -pr ${SRC_DIR}/src/cinnamon/assets/assets${ELSE_DARK}/switch/*.svg              ${THEME_DIR}/cinnamon/assets/switch
+  cp -pr ${SRC_DIR}/src/cinnamon/thumbnail${ELSE_DARK}.png                           ${THEME_DIR}/cinnamon/thumbnail.png
 
   mkdir -p                                                                           ${THEME_DIR}/plank
-  cp -ur ${SRC_DIR}/src/plank/dock${ELSE_LIGHT}.theme                                ${THEME_DIR}/plank/dock.theme
+  cp -pr ${SRC_DIR}/src/plank/dock${ELSE_LIGHT}.theme                                ${THEME_DIR}/plank/dock.theme
 }
 
 install_gdm() {
@@ -169,7 +169,7 @@ install_icon() {
   echo -e "\nInstalling Canta icon theme..."
 
   # Copying files
-  cp -ur ${SRC_DIR}/icons/Canta ${ICON_DEST_DIR}
+  cp -pr ${SRC_DIR}/icons/Canta ${ICON_DEST_DIR}
 
   # update icon caches
   gtk-update-icon-cache ${ICON_DEST_DIR}/Canta
