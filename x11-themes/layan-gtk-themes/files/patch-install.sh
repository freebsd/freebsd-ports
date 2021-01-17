--- install.sh.orig	2021-02-13 19:28:54 UTC
+++ install.sh
@@ -42,8 +42,8 @@ install() {
   echo "Installing '${THEME_DIR}'..."
 
   mkdir -p                                                                           ${THEME_DIR}
-  cp -ur ${SRC_DIR}/COPYING                                                          ${THEME_DIR}
-  cp -ur ${SRC_DIR}/AUTHORS                                                          ${THEME_DIR}
+  cp -pr ${SRC_DIR}/COPYING                                                          ${THEME_DIR}
+  cp -pr ${SRC_DIR}/AUTHORS                                                          ${THEME_DIR}
 
   echo "[Desktop Entry]" >> ${THEME_DIR}/index.theme
   echo "Type=X-GNOME-Metatheme" >> ${THEME_DIR}/index.theme
@@ -59,30 +59,30 @@ install() {
   echo "ButtonLayout=menu:minimize,maximize,close" >> ${THEME_DIR}/index.theme
 
   mkdir -p                                                                           ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/src/gnome-shell/{*.svg,extensions,noise-texture.png,pad-osd.css} ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/src/gnome-shell/gnome-shell-theme.gresource.xml                  ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/src/gnome-shell/assets${ELSE_DARK}                               ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/src/gnome-shell/common-assets/{*.svg,dash}                       ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/src/gnome-shell/gnome-shell${ELSE_DARK}.css                      ${THEME_DIR}/gnome-shell/gnome-shell.css
+  cp -pr ${SRC_DIR}/src/gnome-shell/{*.svg,extensions,noise-texture.png,pad-osd.css} ${THEME_DIR}/gnome-shell
+  cp -pr ${SRC_DIR}/src/gnome-shell/gnome-shell-theme.gresource.xml                  ${THEME_DIR}/gnome-shell
+  cp -pr ${SRC_DIR}/src/gnome-shell/assets${ELSE_DARK}                               ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/src/gnome-shell/common-assets/{*.svg,dash}                       ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/src/gnome-shell/gnome-shell${ELSE_DARK}.css                      ${THEME_DIR}/gnome-shell/gnome-shell.css
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-2.0
-  cp -ur ${SRC_DIR}/src/gtk-2.0/{apps.rc,hacks.rc,main.rc,panel.rc}                  ${THEME_DIR}/gtk-2.0
-  cp -ur ${SRC_DIR}/src/gtk-2.0/assets${ELSE_DARK}                                   ${THEME_DIR}/gtk-2.0/assets
-  cp -ur ${SRC_DIR}/src/gtk-2.0/gtkrc${color}                                        ${THEME_DIR}/gtk-2.0/gtkrc
+  cp -pr ${SRC_DIR}/src/gtk-2.0/{apps.rc,hacks.rc,main.rc,panel.rc}                  ${THEME_DIR}/gtk-2.0
+  cp -pr ${SRC_DIR}/src/gtk-2.0/assets${ELSE_DARK}                                   ${THEME_DIR}/gtk-2.0/assets
+  cp -pr ${SRC_DIR}/src/gtk-2.0/gtkrc${color}                                        ${THEME_DIR}/gtk-2.0/gtkrc
 
-  cp -ur ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-assets
+  cp -pr ${SRC_DIR}/src/gtk/assets                                                   ${THEME_DIR}/gtk-assets
 
   mkdir -p                                                                           ${THEME_DIR}/gtk-3.0
   ln -sf ../gtk-assets                                                               ${THEME_DIR}/gtk-3.0/assets
-  cp -ur ${SRC_DIR}/src/gtk/gtk${color}${solid}.css                                  ${THEME_DIR}/gtk-3.0/gtk.css
+  cp -pr ${SRC_DIR}/src/gtk/gtk${color}${solid}.css                                  ${THEME_DIR}/gtk-3.0/gtk.css
   [[ ${color} != '-dark' ]] && \
-  cp -ur ${SRC_DIR}/src/gtk/gtk-dark${solid}.css                                     ${THEME_DIR}/gtk-3.0/gtk-dark.css
+  cp -pr ${SRC_DIR}/src/gtk/gtk-dark${solid}.css                                     ${THEME_DIR}/gtk-3.0/gtk-dark.css
 
   mkdir -p                                                                           ${THEME_DIR}/xfwm4
-  cp -ur ${SRC_DIR}/src/xfwm4/assets${ELSE_LIGHT}/*.png                              ${THEME_DIR}/xfwm4
-  cp -ur ${SRC_DIR}/src/xfwm4/themerc${ELSE_LIGHT}                                   ${THEME_DIR}/xfwm4/themerc
+  cp -pr ${SRC_DIR}/src/xfwm4/assets${ELSE_LIGHT}/*.png                              ${THEME_DIR}/xfwm4
+  cp -pr ${SRC_DIR}/src/xfwm4/themerc${ELSE_LIGHT}                                   ${THEME_DIR}/xfwm4/themerc
 
-  cp -ur ${SRC_DIR}/src/plank                                                        ${THEME_DIR}
+  cp -pr ${SRC_DIR}/src/plank                                                        ${THEME_DIR}
 }
 
 while [[ $# -gt 0 ]]; do
