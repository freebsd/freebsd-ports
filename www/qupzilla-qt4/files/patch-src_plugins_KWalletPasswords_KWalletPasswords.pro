--- src/plugins/KWalletPasswords/KWalletPasswords.pro.orig	2016-11-15 12:42:46 UTC
+++ src/plugins/KWalletPasswords/KWalletPasswords.pro
@@ -55,6 +55,7 @@ isEqual(QT_MAJOR_VERSION, 5) {
     QT += KWallet
 } else {
     LIBS += -lkdeui
+    INCPATH += %%KDE4_INC%%
 }
 
 PLUGIN_DIR = $$PWD
