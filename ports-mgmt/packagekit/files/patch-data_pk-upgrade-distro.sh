--- data/pk-upgrade-distro.sh.orig	2013-06-06 16:50:58.000000000 +0000
+++ data/pk-upgrade-distro.sh	2013-06-06 16:51:06.000000000 +0000
@@ -37,7 +37,7 @@
 	xdg-su -c /usr/sbin/wagon
 else
 	TITLE="System is not recognised"
-	TEXT="Your distribution was not recognised by the upgrade script.\nPlease file a but in your distribution bug tracker under the component PackageKit."
+	TEXT="Your distribution was not recognised by the upgrade script.\nPlease file a but in your distribution bug tracker under the component GNOME and subcomponent PackageKit."
 	if [ "$DESKTOP" = "kde" ]; then
 		PATH=`kde4-config --path exe` kdialog --title "$TITLE" --sorry "$TEXT"
 	# do not dep on zenity in build scripts
