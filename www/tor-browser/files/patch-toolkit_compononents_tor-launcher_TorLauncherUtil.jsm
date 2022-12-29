--- ./toolkit/components/tor-launcher/TorLauncherUtil.jsm.orig	2022-12-12 08:48:18.438560000 +0000
+++ ./toolkit/components/tor-launcher/TorLauncherUtil.jsm	2022-12-12 08:49:39.039184000 +0000
@@ -31,7 +31,7 @@
   checkIPCPathLen = true;
 
   static _isFirstIPCPathRequest = true;
-  static _isUserDataOutsideOfAppDir = undefined;
+  static _isUserDataOutsideOfAppDir = true;
   static _dataDir = null;
   static _appDir = null;
 
@@ -340,7 +340,7 @@
   static get dataDir() {
     if (!this._dataDir) {
       const profDir = Services.dirsvc.get("ProfD", Ci.nsIFile);
-      this._dataDir = profDir.parent.parent;
+      this._dataDir = profDir;
     }
     return this._dataDir;
   }
