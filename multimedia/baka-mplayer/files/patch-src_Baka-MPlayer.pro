commit 12cacc9
Author: Daniel Clarke <u8sand@gmail.com>
Date:   Sun Dec 28 23:00:42 2014 -0500

    .pro adjustment to deal with INSTROOT
---
 src/Baka-MPlayer.pro | 30 +++++++++++++++---------------
 1 file changed, 15 insertions(+), 15 deletions(-)

diff --git src/Baka-MPlayer.pro src/Baka-MPlayer.pro
index 22c5901..8508447 100644
--- src/Baka-MPlayer.pro
+++ src/Baka-MPlayer.pro
@@ -38,21 +38,21 @@ win32 {
 }
 
 # INSTROOT is the installation root directory, leave empty if not using a package management system
-isEmpty(BINDIR):BINDIR=$$INSTROOT/usr/bin
-isEmpty(MEDIADIR):MEDIADIR=$$INSTROOT/usr/share/pixmaps
-isEmpty(APPDIR):APPDIR=$$INSTROOT/usr/share/applications
-isEmpty(DOCDIR):DOCDIR=$$INSTROOT/usr/share/doc
-isEmpty(MANDIR):MANDIR=$$INSTROOT/usr/share/man
-isEmpty(LICENSEDIR):LICENSEDIR=$$INSTROOT/usr/share/licenses
-isEmpty(BAKADIR):BAKADIR=$$INSTROOT/usr/share/baka-mplayer
-
-target.path = $$BINDIR
-logo.path = $$MEDIADIR
-desktop.path = $$APPDIR
-manual.path = $$DOCDIR/baka-mplayer
-man.path = $$MANDIR/man1
-license.path = $$LICENSEDIR/baka-mplayer
-translations.path = $$BAKADIR/translations
+isEmpty(BINDIR):BINDIR=/usr/bin
+isEmpty(MEDIADIR):MEDIADIR=/usr/share/pixmaps
+isEmpty(APPDIR):APPDIR=/usr/share/applications
+isEmpty(DOCDIR):DOCDIR=/usr/share/doc
+isEmpty(MANDIR):MANDIR=/usr/share/man
+isEmpty(LICENSEDIR):LICENSEDIR=/usr/share/licenses
+isEmpty(BAKADIR):BAKADIR=/usr/share/baka-mplayer
+
+target.path = $$INSTROOT$$BINDIR
+logo.path = $$INSTROOT$$MEDIADIR
+desktop.path = $$INSTROOT$$APPDIR
+manual.path = $$INSTROOT$$DOCDIR/baka-mplayer
+man.path = $$INSTROOT$$MANDIR/man1
+license.path = $$INSTROOT$$LICENSEDIR/baka-mplayer
+translations.path = $$INSTROOT$$BAKADIR/translations
 
 logo.files = ../etc/logo/baka-mplayer.svg
 desktop.files = ../etc/baka-mplayer.desktop
