--- retroshare-gui/src/RetroShare.pro.orig	2011-08-03 19:45:03.000000000 +0200
+++ retroshare-gui/src/RetroShare.pro	2012-01-15 12:55:12.000000000 +0100
@@ -153,9 +153,12 @@
 
 # ###########################################
 
+INCLUDEPATH += $${PREFIX}/include/gpgme
+LIBS += ../../libretroshare/src/libretroshare.a -lssl -lgpgme -lupnp
+
 bitdht {
-	LIBS += ../../libbitdht/src/lib/libbitdht.a
-	PRE_TARGETDEPS *= ../../libbitdht/src/lib/libbitdht.a
+	LIBS += ../../libbitdht/src/libbitdht.a
+	PRE_TARGETDEPS *= ../../libbitdht/src/libbitdht.a
 }
 
 win32 {
