--- settings.pro.orig	2008-02-05 12:18:34.000000000 +0100
+++ settings.pro	2008-09-17 14:29:22.000000000 +0200
@@ -50,8 +50,8 @@
 # and we do that in their Makefiles if CONFIG has mac_bundle
 macx: CONFIG += console
 
-INCLUDEPATH += $${PREFIX}/include
-INCLUDEPATH += $$CONFIG_INCLUDEPATH
+#INCLUDEPATH += $${PREFIX}/include
+#INCLUDEPATH += $$CONFIG_INCLUDEPATH
 
 # remove warn_{on|off} from CONFIG since we set it in our CFLAGS
 CONFIG -= warn_on warn_off
