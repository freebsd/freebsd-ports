--- modules/gui/qt4/qt4.hpp.orig
+++ modules/gui/qt4/qt4.hpp
@@ -34,7 +34,7 @@
 #include <vlc_playlist.h>  /* playlist_t */
 
 #define QT_NO_CAST_TO_ASCII
-#include <QString>
+#include <qt4/QtCore/QString>
 
 #if ( QT_VERSION < 0x040600 )
 # error Update your Qt version to at least 4.6.0
