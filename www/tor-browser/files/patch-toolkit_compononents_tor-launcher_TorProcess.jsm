--- ./toolkit/components/tor-launcher/TorProcess.jsm.orig	2022-12-12 13:13:52.306244000 +0100
+++ ./toolkit/components/tor-launcher/TorProcess.jsm	2022-12-12 13:14:59.887641000 +0100
@@ -254,6 +254,8 @@
     this._dataDir = TorLauncherUtil.getTorFile("tordatadir", true);
     const onionAuthDir = TorLauncherUtil.getTorFile("toronionauthdir", true);
     const hashedPassword = TorProtocolService.torGetPassword(true);
+    const geoipFile = TorLauncherUtil.getTorFile("geoip", false);
+    const geoip6File = TorLauncherUtil.getTorFile("geoip6", false);
     let detailsKey;
     if (!this._exeFile) {
       detailsKey = "tor_missing";
@@ -282,10 +284,6 @@
       false
     );
     // The geoip and geoip6 files are in the same directory as torrc-defaults.
-    const geoipFile = torrcDefaultsFile.clone();
-    geoipFile.leafName = "geoip";
-    const geoip6File = torrcDefaultsFile.clone();
-    geoip6File.leafName = "geoip6";
 
     this._args = [];
     if (torrcDefaultsFile) {
