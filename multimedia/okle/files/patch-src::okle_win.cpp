--- src/okle_win.cpp.orig	Tue Feb 25 11:19:50 2003
+++ src/okle_win.cpp	Sun Apr  6 01:50:55 2003
@@ -34,6 +34,7 @@
 #include <kstandarddirs.h>
 #include <qtooltip.h>
 #include <dcopclient.h>
+#include <kfileitem.h>
 
 extern "C" {
 #include <X11/Xlib.h>
@@ -519,16 +520,16 @@
 void OkleWin::slotFileOpenDisc()
 {
  conf->setGroup("DVD");
- QString dvdp = conf->readEntry("dvdpath","/dev/dvd");
+ QString dvdp = conf->readEntry("dvdpath","/dev/acd0c");
 
- QFileInfo fi(dvdp);
- if(!fi.exists())
+ KFileItem fi(KFileItem::Unknown, KFileItem::Unknown, dvdp);
+ if(!QFile::exists(dvdp))
   {
    KMessageBox::error(0,QString(i18n("%1 does not exist!")).arg(dvdp),i18n("Error"));
    return;
   }
 
- if(!fi.isFile() && !fi.isSymLink())
+ if(!fi.isFile() && !fi.isLink())
   {
    KMessageBox::error(0,QString(i18n("%1 exists but is not a file or symlink!")).arg(dvdp),i18n("Error"));
    return;
@@ -714,7 +715,7 @@
 {
  PrefsWin* prefs = new PrefsWin(this);
  conf->setGroup("DVD");
- prefs->setDVDPath(conf->readEntry("dvdpath","/dev/dvd"));
+ prefs->setDVDPath(conf->readEntry("dvdpath","/dev/acd0c"));
  prefs->setRegion(conf->readNumEntry("region",1));
  if(prefs->exec())
   {
