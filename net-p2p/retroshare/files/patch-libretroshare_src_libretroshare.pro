--- libretroshare/src/libretroshare.pro.orig	2018-03-13 19:25:38 UTC
+++ libretroshare/src/libretroshare.pro
@@ -341,13 +341,15 @@ mac {
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
-	INCLUDEPATH *= /usr/local/include/glib-2.0
+	INCLUDEPATH += $$system(pkg-config --cflags glib-2.0 | sed -e "s/-I//g")
 
 	QMAKE_CXXFLAGS *= -Dfseeko64=fseeko -Dftello64=ftello -Dstat64=stat -Dstatvfs64=statvfs -Dfopen64=fopen
 
 	# linux/bsd can use either - libupnp is more complete and packaged.
 	#CONFIG += upnp_miniupnpc 
     CONFIG += upnp_libupnp
+	DEFINES *= PLUGIN_DIR=\"\\\"$${PLUGIN_DIR}\\\"\"
+	DEFINES *= DATA_DIR=\"\\\"$${DATA_DIR}\\\"\"
 }
 
 ################################# OpenBSD ##########################################
