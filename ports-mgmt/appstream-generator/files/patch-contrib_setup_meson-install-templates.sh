--- contrib/setup/meson-install-templates.sh.orig	2023-04-20 11:44:26 UTC
+++ contrib/setup/meson-install-templates.sh
@@ -3,6 +3,8 @@ cd "$MESON_SOURCE_ROOT"
 
 cd "$MESON_SOURCE_ROOT"
 
-echo "Installing templates..."
-install -d "${DESTDIR}/${MESON_INSTALL_PREFIX}/share/appstream/templates"
-cp -dpru --no-preserve=ownership data/templates/* -t "${DESTDIR}/${MESON_INSTALL_PREFIX}/share/appstream/templates"
+# FreeBSD: We do this ourselves in the port
+
+#echo "Installing templates..."
+#install -d "${DESTDIR}/${MESON_INSTALL_PREFIX}/share/appstream/templates"
+#cp -dpru --no-preserve=ownership data/templates/* -t "${DESTDIR}/${MESON_INSTALL_PREFIX}/share/appstream/templates"
