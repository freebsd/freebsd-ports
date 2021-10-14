--- src/build_theme.sh.cmake.orig	2021-10-07 11:30:17 UTC
+++ src/build_theme.sh.cmake
@@ -110,4 +110,4 @@ fi
 
 render_theme "${COLOR_SCHEME}" "${THEME_NAME}" "${INSTALL_TARGET}" "${COLOR_SCHEME_ROOT}/BreezeLight.colors"
 [ -z "${INSTALL_TARGET}" ] && INSTALL_TARGET="${HOME}/.local/share/themes/${THEME_NAME}"
-cp -r assets/ "${INSTALL_TARGET}"
+cp -r assets "${INSTALL_TARGET}"
