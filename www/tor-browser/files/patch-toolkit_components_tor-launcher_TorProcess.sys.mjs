Let geoip/geoip6 file paths be set by prefs like everything else and let
the new getTorFile() deal with it.

Index: toolkit/components/tor-launcher/TorProcess.sys.mjs
--- toolkit/components/tor-launcher/TorProcess.sys.mjs.orig	2024-04-22 21:47:56 UTC
+++ toolkit/components/tor-launcher/TorProcess.sys.mjs
@@ -216,6 +216,7 @@ export class TorProcess {
     }
 
     this.#args = [];
+    this.#args.push("--ignore-missing-torrc");
     this.#args.push("-f", torrcFile.path);
     this.#args.push("DataDirectory", this.#dataDir.path);
     this.#args.push("ClientOnionAuthDir", onionAuthDir.path);
@@ -230,11 +231,15 @@ export class TorProcess {
       // The geoip and geoip6 files are in the same directory as torrc-defaults.
       // TODO: Change TorFile to return the generic path to these files to make
       // them independent from the torrc-defaults.
-      const geoipFile = torrcDefaultsFile.clone();
-      geoipFile.leafName = "geoip";
+      // const geoipFile = torrcDefaultsFile.clone();
+      // geoipFile.leafName = "geoip";
+      // this.#args.push("GeoIPFile", geoipFile.path);
+      // const geoip6File = torrcDefaultsFile.clone();
+      // geoip6File.leafName = "geoip6";
+      // this.#args.push("GeoIPv6File", geoip6File.path);
+      const geoipFile = lazy.TorLauncherUtil.getTorFile("geoip", false);
+      const geoip6File = lazy.TorLauncherUtil.getTorFile("geoip6", false);
       this.#args.push("GeoIPFile", geoipFile.path);
-      const geoip6File = torrcDefaultsFile.clone();
-      geoip6File.leafName = "geoip6";
       this.#args.push("GeoIPv6File", geoip6File.path);
     } else {
       logger.warn(
