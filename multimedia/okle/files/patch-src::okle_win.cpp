--- src/okle_win.cpp.orig	Sun Nov 23 09:26:07 2003
+++ src/okle_win.cpp	Thu Mar 11 22:41:26 2004
@@ -37,6 +37,7 @@
 #include <kstandarddirs.h>
 #include <qtooltip.h>
 #include <dcopclient.h>
+#include <kfileitem.h>
 
 extern "C" {
 #include <X11/Xlib.h>
@@ -737,14 +738,14 @@
     return;
   }
 
- QFileInfo fi(dvdp);
- if(!fi.exists())
+ KFileItem fi(KFileItem::Unknown, KFileItem::Unknown, dvdp);
+ if(!QFile::exists(dvdp))
   {
    KMessageBox::error(0,QString(i18n("%1 does not exist.\n\nEither set the correct DVD path in File -> Settings or create a symlink from your DVD device to %2.")).arg(dvdp).arg(dvdp),i18n("DVD device file not found"));
    return;
   }
 
- if(!fi.isFile() && !fi.isSymLink())
+ if(!fi.isFile() && !fi.isLink())
   {
    KMessageBox::error(0,QString(i18n("%1 exists but is not a file or symlink.\n\nMake sure that %2 really refers to your DVD device or change the DVD device path in File -> Settings.")).arg(dvdp).arg(dvdp),i18n("DVD device file not usable"));
    return;
