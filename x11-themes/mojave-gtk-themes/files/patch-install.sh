--- install.sh.orig	2021-02-13 19:46:41 UTC
+++ install.sh
@@ -56,7 +56,7 @@ install() {
   echo "Installing '${THEME_DIR}'..."
 
   mkdir -p                                                                              ${THEME_DIR}
-  cp -ur ${REPO_DIR}/COPYING                                                            ${THEME_DIR}
+  cp -pr ${REPO_DIR}/COPYING                                                            ${THEME_DIR}
 
   echo "[Desktop Entry]" >>                                                             ${THEME_DIR}/index.theme
   echo "Type=X-GNOME-Metatheme" >>                                                      ${THEME_DIR}/index.theme
@@ -72,32 +72,32 @@ install() {
   echo "ButtonLayout=close,minimize,maximize:menu" >>                                   ${THEME_DIR}/index.theme
 
   mkdir -p                                                                              ${THEME_DIR}/gnome-shell
-  cp -ur ${SRC_DIR}/main/gnome-shell/gnome-shell${color}${opacity}.css                  ${THEME_DIR}/gnome-shell/gnome-shell.css
-  cp -ur ${SRC_DIR}/assets/gnome-shell/common-assets                                    ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/assets/gnome-shell/assets${color}/*.svg                             ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/assets/gnome-shell/assets${color}/background.png                    ${THEME_DIR}/gnome-shell/assets
-  cp -ur ${SRC_DIR}/assets/gnome-shell/assets${color}/activities/activities${icon}.svg  ${THEME_DIR}/gnome-shell/assets/activities.svg
+  cp -pr ${SRC_DIR}/main/gnome-shell/gnome-shell${color}${opacity}.css                  ${THEME_DIR}/gnome-shell/gnome-shell.css
+  cp -pr ${SRC_DIR}/assets/gnome-shell/common-assets                                    ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/assets/gnome-shell/assets${color}/*.svg                             ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/assets/gnome-shell/assets${color}/background.png                    ${THEME_DIR}/gnome-shell/assets
+  cp -pr ${SRC_DIR}/assets/gnome-shell/assets${color}/activities/activities${icon}.svg  ${THEME_DIR}/gnome-shell/assets/activities.svg
   cd ${THEME_DIR}/gnome-shell
   ln -s assets/no-events.svg no-events.svg
   ln -s assets/process-working.svg process-working.svg
   ln -s assets/no-notifications.svg no-notifications.svg
 
   mkdir -p                                                                              ${THEME_DIR}/gtk-2.0
-  cp -ur ${SRC_DIR}/main/gtk-2.0/gtkrc${color}                                          ${THEME_DIR}/gtk-2.0/gtkrc
-  cp -ur ${SRC_DIR}/main/gtk-2.0/menubar-toolbar${color}.rc                             ${THEME_DIR}/gtk-2.0/menubar-toolbar.rc
-  cp -ur ${SRC_DIR}/main/gtk-2.0/common/*.rc                                            ${THEME_DIR}/gtk-2.0
-  cp -ur ${SRC_DIR}/assets/gtk-2.0/assets${color}                                       ${THEME_DIR}/gtk-2.0/assets
+  cp -pr ${SRC_DIR}/main/gtk-2.0/gtkrc${color}                                          ${THEME_DIR}/gtk-2.0/gtkrc
+  cp -pr ${SRC_DIR}/main/gtk-2.0/menubar-toolbar${color}.rc                             ${THEME_DIR}/gtk-2.0/menubar-toolbar.rc
+  cp -pr ${SRC_DIR}/main/gtk-2.0/common/*.rc                                            ${THEME_DIR}/gtk-2.0
+  cp -pr ${SRC_DIR}/assets/gtk-2.0/assets${color}                                       ${THEME_DIR}/gtk-2.0/assets
 
   mkdir -p                                                                              ${THEME_DIR}/gtk-3.0
-  cp -ur ${SRC_DIR}/assets/gtk-3.0/common-assets/assets                                 ${THEME_DIR}/gtk-3.0
-  cp -ur ${SRC_DIR}/assets/gtk-3.0/windows-assets/titlebutton${alt}${small}             ${THEME_DIR}/gtk-3.0/windows-assets
-  cp -ur ${SRC_DIR}/assets/gtk-3.0/thumbnail${color}.png                                ${THEME_DIR}/gtk-3.0/thumbnail.png
-  cp -ur ${SRC_DIR}/main/gtk-3.0/gtk-dark${opacity}.css                                 ${THEME_DIR}/gtk-3.0/gtk-dark.css
+  cp -pr ${SRC_DIR}/assets/gtk-3.0/common-assets/assets                                 ${THEME_DIR}/gtk-3.0
+  cp -pr ${SRC_DIR}/assets/gtk-3.0/windows-assets/titlebutton${alt}${small}             ${THEME_DIR}/gtk-3.0/windows-assets
+  cp -pr ${SRC_DIR}/assets/gtk-3.0/thumbnail${color}.png                                ${THEME_DIR}/gtk-3.0/thumbnail.png
+  cp -pr ${SRC_DIR}/main/gtk-3.0/gtk-dark${opacity}.css                                 ${THEME_DIR}/gtk-3.0/gtk-dark.css
 
   if [[ ${color} == '-light' ]]; then
-    cp -ur ${SRC_DIR}/main/gtk-3.0/gtk-light${opacity}.css                              ${THEME_DIR}/gtk-3.0/gtk.css
+    cp -pr ${SRC_DIR}/main/gtk-3.0/gtk-light${opacity}.css                              ${THEME_DIR}/gtk-3.0/gtk.css
   else
-    cp -ur ${SRC_DIR}/main/gtk-3.0/gtk-dark${opacity}.css                               ${THEME_DIR}/gtk-3.0/gtk.css
+    cp -pr ${SRC_DIR}/main/gtk-3.0/gtk-dark${opacity}.css                               ${THEME_DIR}/gtk-3.0/gtk.css
   fi
 
   glib-compile-resources --sourcedir=${THEME_DIR}/gtk-3.0 --target=${THEME_DIR}/gtk-3.0/gtk.gresource ${SRC_DIR}/main/gtk-3.0/gtk.gresource.xml
@@ -106,24 +106,24 @@ install() {
   echo '@import url("resource:///org/gnome/Mojave-theme/gtk-dark.css");' >>             ${THEME_DIR}/gtk-3.0/gtk-dark.css
 
   mkdir -p                                                                              ${THEME_DIR}/metacity-1
-  cp -ur ${SRC_DIR}/main/metacity-1/metacity-theme${color}.xml                          ${THEME_DIR}/metacity-1/metacity-theme-1.xml
-  cp -ur ${SRC_DIR}/main/metacity-1/metacity-theme-3.xml                                ${THEME_DIR}/metacity-1
-  cp -ur ${SRC_DIR}/assets/metacity-1/assets/*.png                                      ${THEME_DIR}/metacity-1
-  cp -ur ${SRC_DIR}/assets/metacity-1/thumbnail${color}.png                             ${THEME_DIR}/metacity-1/thumbnail.png
+  cp -pr ${SRC_DIR}/main/metacity-1/metacity-theme${color}.xml                          ${THEME_DIR}/metacity-1/metacity-theme-1.xml
+  cp -pr ${SRC_DIR}/main/metacity-1/metacity-theme-3.xml                                ${THEME_DIR}/metacity-1
+  cp -pr ${SRC_DIR}/assets/metacity-1/assets/*.png                                      ${THEME_DIR}/metacity-1
+  cp -pr ${SRC_DIR}/assets/metacity-1/thumbnail${color}.png                             ${THEME_DIR}/metacity-1/thumbnail.png
   cd ${THEME_DIR}/metacity-1 && ln -s metacity-theme-1.xml metacity-theme-2.xml
 
   mkdir -p                                                                              ${THEME_DIR}/xfwm4
-  cp -ur ${SRC_DIR}/assets/xfwm4/assets${color}/*.png                                   ${THEME_DIR}/xfwm4
-  cp -ur ${SRC_DIR}/main/xfwm4/themerc${color}                                          ${THEME_DIR}/xfwm4/themerc
+  cp -pr ${SRC_DIR}/assets/xfwm4/assets${color}/*.png                                   ${THEME_DIR}/xfwm4
+  cp -pr ${SRC_DIR}/main/xfwm4/themerc${color}                                          ${THEME_DIR}/xfwm4/themerc
 
   mkdir -p                                                                              ${THEME_DIR}/cinnamon
-  cp -ur ${SRC_DIR}/main/cinnamon/cinnamon${color}${opacity}.css                        ${THEME_DIR}/cinnamon/cinnamon.css
-  cp -ur ${SRC_DIR}/assets/cinnamon/common-assets                                       ${THEME_DIR}/cinnamon/assets
-  cp -ur ${SRC_DIR}/assets/cinnamon/assets${color}/*.svg                                ${THEME_DIR}/cinnamon/assets
-  cp -ur ${SRC_DIR}/assets/cinnamon/thumbnail${color}.png                               ${THEME_DIR}/cinnamon/thumbnail.png
+  cp -pr ${SRC_DIR}/main/cinnamon/cinnamon${color}${opacity}.css                        ${THEME_DIR}/cinnamon/cinnamon.css
+  cp -pr ${SRC_DIR}/assets/cinnamon/common-assets                                       ${THEME_DIR}/cinnamon/assets
+  cp -pr ${SRC_DIR}/assets/cinnamon/assets${color}/*.svg                                ${THEME_DIR}/cinnamon/assets
+  cp -pr ${SRC_DIR}/assets/cinnamon/thumbnail${color}.png                               ${THEME_DIR}/cinnamon/thumbnail.png
 
   mkdir -p                                                                              ${THEME_DIR}/plank
-  cp -ur ${SRC_DIR}/other/plank/${name}${color}/*.theme                                 ${THEME_DIR}/plank
+  cp -pr ${SRC_DIR}/other/plank/${name}${color}/*.theme                                 ${THEME_DIR}/plank
 }
 
 # Backup and install files related to GDM theme
@@ -170,7 +170,7 @@ install_gdm() {
     # rm -rf "$ETC_THEME_FILE" "$GS_THEME_FILE"
     # mv "$GS_THEME_FILE.bak" "$GS_THEME_FILE"
     [[ -d $SHELL_THEME_FOLDER/Mojave ]] && rm -rf $SHELL_THEME_FOLDER/Mojave
-    cp -ur "$GDM_THEME_DIR/gnome-shell" "$SHELL_THEME_FOLDER/Mojave"
+    cp -pr "$GDM_THEME_DIR/gnome-shell" "$SHELL_THEME_FOLDER/Mojave"
     cd "$ETC_THEME_FOLDER"
     ln -s "$SHELL_THEME_FOLDER/Mojave/gnome-shell.css" gdm3.css
   fi
