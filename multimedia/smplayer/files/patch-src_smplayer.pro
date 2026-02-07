--- src/smplayer.pro.orig	2016-12-26 22:19:34 UTC
+++ src/smplayer.pro
@@ -97,6 +97,8 @@ isEqual(QT_MAJOR_VERSION, 5) {
 	}
 }
 
+DEFINES -= $${DEFINES_DISABLED}
+
 contains(QT_VERSION, ^4\\.[0-3]\\..*) {
 	message("Some features requires Qt > 4.3.")
 
