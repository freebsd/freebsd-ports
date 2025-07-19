--- kcms/usbview/usbdb.cpp.orig	2025-07-15 09:51:22 UTC
+++ kcms/usbview/usbdb.cpp
@@ -16,7 +16,7 @@ USBDB::USBDB()
 {
     QString db = QStringLiteral("/usr/share/hwdata/usb.ids"); /* on Fedora and Arch*/
     if (!QFile::exists(db)) {
-        db = QStringLiteral("/usr/share/misc/usb.ids"); /* on Gentoo */
+        db = QStringLiteral("/usr/share/misc/usb_vendors"); /* on FreeBSD */
     }
     if (db.isEmpty())
         return;
