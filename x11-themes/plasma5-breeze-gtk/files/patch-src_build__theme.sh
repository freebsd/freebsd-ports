--- src/build_theme.sh.orig	2020-03-10 12:54:51 UTC
+++ src/build_theme.sh
@@ -109,4 +109,4 @@ fi
 
 render_theme "${COLOR_SCHEME}" "${THEME_NAME}" "${INSTALL_TARGET}" "${COLOR_SCHEME_ROOT}/Breeze.colors"
 [ -z "${INSTALL_TARGET}" ] && INSTALL_TARGET="${HOME}/.local/share/themes/${THEME_NAME}"
-cp -r assets/ "${INSTALL_TARGET}"
+cp -r assets "${INSTALL_TARGET}"
