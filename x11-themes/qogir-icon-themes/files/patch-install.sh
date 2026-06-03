--- install.sh.orig	2025-02-15 14:25:54 UTC
+++ install.sh
@@ -42,39 +42,39 @@ install() {
   echo "Installing '${THEME_DIR}'..."
 
   mkdir -p "${THEME_DIR}"
-  cp -r "${SRC_DIR}/COPYING" "${THEME_DIR}"
-  cp -r "${SRC_DIR}/AUTHORS" "${THEME_DIR}"
+  cp "${SRC_DIR}/COPYING" "${THEME_DIR}"
+  cp "${SRC_DIR}/AUTHORS" "${THEME_DIR}"
 
   if [[ "${noapp:-}" == 'true' ]]; then
-    cp -r "${SRC_DIR}/src/index-noapp.theme" "${THEME_DIR}/index.theme"
+    cp "${SRC_DIR}/src/index-noapp.theme" "${THEME_DIR}/index.theme"
   else
-    cp -r "${SRC_DIR}/src/index.theme" "${THEME_DIR}"
+    cp "${SRC_DIR}/src/index.theme" "${THEME_DIR}"
   fi
 
   if [[ ${color} != '-Light' ]]; then
-    cp -r "${SRC_DIR}/src/cursors/dist${theme}${color}/cursors" "${THEME_DIR}"
+    cp -R "${SRC_DIR}/src/cursors/dist${theme}${color}/cursors" "${THEME_DIR}"
   fi
 
   cd "${THEME_DIR}" || exit 1
-  sed -i "s/${name}/${name}${theme}${color}/g" index.theme
+  sed -i "" -e "s/${name}/${name}${theme}${color}/g" index.theme
 
   if [[ ${color} == '' ]]; then
-    cp -r "${SRC_DIR}"/src/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
-    cp -r "${SRC_DIR}"/links/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
+    cp -R "${SRC_DIR}"/src/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
+    cp -R "${SRC_DIR}"/links/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
     [[ ${theme} != '' ]] && \
-    cp -r "${SRC_DIR}"/src/theme"${theme}"/* "${THEME_DIR}"
+    cp -R "${SRC_DIR}"/src/theme"${theme}"/* "${THEME_DIR}"
   elif [[ ${color} == '-Light' ]]; then
     mkdir -p "${THEME_DIR}"/{16,22,24}
 
-    cp -r "${SRC_DIR}"/src/16/panel "${THEME_DIR}/16"
-    cp -r "${SRC_DIR}"/src/22/panel "${THEME_DIR}/22"
-    cp -r "${SRC_DIR}"/src/24/panel "${THEME_DIR}/24"
+    cp -R "${SRC_DIR}"/src/16/panel "${THEME_DIR}/16"
+    cp -R "${SRC_DIR}"/src/22/panel "${THEME_DIR}/22"
+    cp -R "${SRC_DIR}"/src/24/panel "${THEME_DIR}/24"
 
-    sed -i "s/#d3dae3/#5d656b/g" "${THEME_DIR}"/{16,22,24}/panel/*.svg
+    sed -i "" -e "s/#d3dae3/#5d656b/g" "${THEME_DIR}"/{16,22,24}/panel/*.svg
 
-    cp -r "${SRC_DIR}"/links/16/panel "${THEME_DIR}/16"
-    cp -r "${SRC_DIR}"/links/22/panel "${THEME_DIR}/22"
-    cp -r "${SRC_DIR}"/links/24/panel "${THEME_DIR}/24"
+    cp -R "${SRC_DIR}"/links/16/panel "${THEME_DIR}/16"
+    cp -R "${SRC_DIR}"/links/22/panel "${THEME_DIR}/22"
+    cp -R "${SRC_DIR}"/links/24/panel "${THEME_DIR}/24"
 
     cd "${dest}" || exit 1
     ln -sf "../${name}${theme}/cursors" "${name}${theme}-Light/cursors"
@@ -104,19 +104,19 @@ install() {
   else
     mkdir -p "${THEME_DIR}"/{16,22,24,32}
 
-    cp -r "${SRC_DIR}"/src/16/{actions,places,devices} "${THEME_DIR}/16"
-    cp -r "${SRC_DIR}"/src/22/{actions,places,devices} "${THEME_DIR}/22"
-    cp -r "${SRC_DIR}"/src/24/{actions,places,devices} "${THEME_DIR}/24"
-    cp -r "${SRC_DIR}"/src/32/actions "${THEME_DIR}/32"
+    cp -R "${SRC_DIR}"/src/16/{actions,places,devices} "${THEME_DIR}/16"
+    cp -R "${SRC_DIR}"/src/22/{actions,places,devices} "${THEME_DIR}/22"
+    cp -R "${SRC_DIR}"/src/24/{actions,places,devices} "${THEME_DIR}/24"
+    cp -R "${SRC_DIR}"/src/32/actions "${THEME_DIR}/32"
 
-    sed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24,32}/actions/*.svg
-    sed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/places/*.svg
-    sed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/devices/*.svg
+    sed -i "" -e "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24,32}/actions/*.svg
+    sed -i "" -e "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/places/*.svg
+    sed -i "" -e "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/devices/*.svg
 
-    cp -r "${SRC_DIR}"/links/16/{actions,places,devices} "${THEME_DIR}/16"
-    cp -r "${SRC_DIR}"/links/22/{actions,places,devices} "${THEME_DIR}/22"
-    cp -r "${SRC_DIR}"/links/24/{actions,places,devices} "${THEME_DIR}/24"
-    cp -r "${SRC_DIR}"/links/32/actions "${THEME_DIR}/32"
+    cp -R "${SRC_DIR}"/links/16/{actions,places,devices} "${THEME_DIR}/16"
+    cp -R "${SRC_DIR}"/links/22/{actions,places,devices} "${THEME_DIR}/22"
+    cp -R "${SRC_DIR}"/links/24/{actions,places,devices} "${THEME_DIR}/24"
+    cp -R "${SRC_DIR}"/links/32/actions "${THEME_DIR}/32"
 
     cd "${dest}" || exit 1
     ln -sf "../${name}${theme}/scalable" "${name}${theme}-Dark/scalable"
@@ -174,21 +174,21 @@ install_cursors_scalable() {
   local THEME_DIR="${dest}/${name}${theme}${color}"
 
   if [[ ${color} != '-Light' ]]; then
-    cp -rf "$CURSORS_SRC_DIR"/scalable "${THEME_DIR}"/cursors_scalable
-    cp -rf "$CURSORS_SRC_DIR/svg${theme}${color}/${svgid}.svg" "${THEME_DIR}/cursors_scalable/${svgid}"
+    cp -R "$CURSORS_SRC_DIR"/scalable "${THEME_DIR}"/cursors_scalable
+    cp "$CURSORS_SRC_DIR/svg${theme}${color}/${svgid}.svg" "${THEME_DIR}/cursors_scalable/${svgid}"
   fi
 }
 
 make_cursors_svg() {
   rm -rf "$CURSORS_SRC_DIR"/{svg-Ubuntu,svg-Manjaro,svg-Ubuntu-Dark,svg-Manjaro-Dark}
-  cp -r "$CURSORS_SRC_DIR"/svg "$CURSORS_SRC_DIR"/svg-Ubuntu
-  cp -r "$CURSORS_SRC_DIR"/svg "$CURSORS_SRC_DIR"/svg-Manjaro
-  cp -r "$CURSORS_SRC_DIR"/svg-Dark "$CURSORS_SRC_DIR"/svg-Ubuntu-Dark
-  cp -r "$CURSORS_SRC_DIR"/svg-Dark "$CURSORS_SRC_DIR"/svg-Manjaro-Dark
-  sed -i "s/#5294e2/#fb8441/g" "$CURSORS_SRC_DIR"/svg-Ubuntu/*.svg
-  sed -i "s/#5294e2/#2eb398/g" "$CURSORS_SRC_DIR"/svg-Manjaro/*.svg
-  sed -i "s/#5294e2/#fb8441/g" "$CURSORS_SRC_DIR"/svg-Ubuntu-Dark/*.svg
-  sed -i "s/#5294e2/#2eb398/g" "$CURSORS_SRC_DIR"/svg-Manjaro-Dark/*.svg
+  cp -R "$CURSORS_SRC_DIR"/svg "$CURSORS_SRC_DIR"/svg-Ubuntu
+  cp -R "$CURSORS_SRC_DIR"/svg "$CURSORS_SRC_DIR"/svg-Manjaro
+  cp -R "$CURSORS_SRC_DIR"/svg-Dark "$CURSORS_SRC_DIR"/svg-Ubuntu-Dark
+  cp -R "$CURSORS_SRC_DIR"/svg-Dark "$CURSORS_SRC_DIR"/svg-Manjaro-Dark
+  sed -i "" -e "s/#5294e2/#fb8441/g" "$CURSORS_SRC_DIR"/svg-Ubuntu/*.svg
+  sed -i "" -e "s/#5294e2/#2eb398/g" "$CURSORS_SRC_DIR"/svg-Manjaro/*.svg
+  sed -i "" -e "s/#5294e2/#fb8441/g" "$CURSORS_SRC_DIR"/svg-Ubuntu-Dark/*.svg
+  sed -i "" -e "s/#5294e2/#2eb398/g" "$CURSORS_SRC_DIR"/svg-Manjaro-Dark/*.svg
 }
 
 while [[ $# -gt 0 ]]; do
