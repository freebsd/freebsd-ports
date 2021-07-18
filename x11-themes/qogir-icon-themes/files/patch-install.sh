--- install.sh.orig	2020-11-22 14:20:00 UTC
+++ install.sh
@@ -37,34 +37,34 @@ install() {
     echo "Installing '${THEME_DIR}'..."
     
     mkdir -p "${THEME_DIR}"
-    cp -r "${SRC_DIR}/COPYING" "${THEME_DIR}"
-    cp -r "${SRC_DIR}/AUTHORS" "${THEME_DIR}"
-    cp -r "${SRC_DIR}/src/index.theme" "${THEME_DIR}"
-    cp -r "${SRC_DIR}/src/cursors/dist${theme}${color}/cursors" "${THEME_DIR}"
+    cp -R "${SRC_DIR}/COPYING" "${THEME_DIR}"
+    cp -R "${SRC_DIR}/AUTHORS" "${THEME_DIR}"
+    cp -R "${SRC_DIR}/src/index.theme" "${THEME_DIR}"
+    cp -R "${SRC_DIR}/src/cursors/dist${theme}${color}/cursors" "${THEME_DIR}"
     
     cd "${THEME_DIR}" || exit 1
-    sed -i "s/${name}/${name}${theme}${color}/g" index.theme
+    gsed -i "s/${name}/${name}${theme}${color}/g" index.theme
     
     if [[ ${color} == '' ]]; then
-        cp -r "${SRC_DIR}"/src/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
-        cp -r "${SRC_DIR}"/links/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
+        cp -R "${SRC_DIR}"/src/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
+        cp -R "${SRC_DIR}"/links/{16,22,24,32,48,96,128,scalable,symbolic} "${THEME_DIR}"
         [[ ${theme} != '' ]] && \
-        cp -r "${SRC_DIR}"/src/theme"${theme}"/* "${THEME_DIR}"
+        cp -R "${SRC_DIR}"/src/theme"${theme}"/* "${THEME_DIR}"
     else
         mkdir -p "${THEME_DIR}/16"
         mkdir -p "${THEME_DIR}/22"
         mkdir -p "${THEME_DIR}/24"
-        cp -r "${SRC_DIR}"/src/16/{actions,places,devices} "${THEME_DIR}/16"
-        cp -r "${SRC_DIR}"/src/22/{actions,places,devices} "${THEME_DIR}/22"
-        cp -r "${SRC_DIR}"/src/24/{actions,places,devices} "${THEME_DIR}/24"
+        cp -R "${SRC_DIR}"/src/16/{actions,places,devices} "${THEME_DIR}/16"
+        cp -R "${SRC_DIR}"/src/22/{actions,places,devices} "${THEME_DIR}/22"
+        cp -R "${SRC_DIR}"/src/24/{actions,places,devices} "${THEME_DIR}/24"
         
-        sed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/actions/*
-        sed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/places/*
-        sed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/devices/*
+        gsed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/actions/*
+        gsed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/places/*
+        gsed -i "s/#5d656b/#d3dae3/g" "${THEME_DIR}"/{16,22,24}/devices/*
         
-        cp -r "${SRC_DIR}"/links/16/{actions,places,devices} "${THEME_DIR}/16"
-        cp -r "${SRC_DIR}"/links/22/{actions,places,devices} "${THEME_DIR}/22"
-        cp -r "${SRC_DIR}"/links/24/{actions,places,devices} "${THEME_DIR}/24"
+        cp -R "${SRC_DIR}"/links/16/{actions,places,devices} "${THEME_DIR}/16"
+        cp -R "${SRC_DIR}"/links/22/{actions,places,devices} "${THEME_DIR}/22"
+        cp -R "${SRC_DIR}"/links/24/{actions,places,devices} "${THEME_DIR}/24"
         
         cd "${dest}" || exit 1
         ln -sf "../${name}${theme}/scalable" "${name}${theme}-dark/scalable"
