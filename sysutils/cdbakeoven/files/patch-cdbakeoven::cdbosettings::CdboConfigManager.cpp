--- cdbakeoven/cdbosettings/CdboConfigManager.cpp.orig	Thu Sep 19 21:58:21 2002
+++ cdbakeoven/cdbosettings/CdboConfigManager.cpp	Thu Sep 19 22:00:06 2002
@@ -19,7 +19,7 @@
 #include "CdboConfigManager.moc"
 
 //===========================================
-CdboConfigManager::CdboConfigManager(QObject* parent = 0, const char* name = 0)
+CdboConfigManager::CdboConfigManager(QObject* parent, const char* name)
 		: QObject (parent, name){
 ////////
 }
