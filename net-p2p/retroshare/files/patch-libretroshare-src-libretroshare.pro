--- libretroshare/src/libretroshare.pro~	2011-08-03 19:43:26.000000000 +0200
+++ libretroshare/src/libretroshare.pro	2012-01-15 04:20:41.000000000 +0100
@@ -104,6 +104,7 @@
 	INCLUDEPATH += . $${BITDHT_DIR}
 	# The next line if for compliance with debian packages. Keep it!
 	INCLUDEPATH += ../libbitdht
+	INCLUDEPATH += $${PREFIX}/include/gpgme
 	DEFINES *= RS_USE_BITDHT
 }
 
