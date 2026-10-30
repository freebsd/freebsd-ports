--- toolkit/components/tor-launcher/TorProcess.sys.mjs.orig	2026-10-29 19:45:00 UTC
+++ toolkit/components/tor-launcher/TorProcess.sys.mjs
@@ -254,6 +254,7 @@ export class TorProcess {
     }
 
     this.#args = [];
+    this.#args.push("--ignore-missing-torrc");
     this.#args.push("-f", torrcFile.path);
     this.#args.push("DataDirectory", this.#dataDir.path);
     this.#args.push("ClientOnionAuthDir", onionAuthDir.path);
@@ -271,34 +272,10 @@ export class TorProcess {
       );
     }
 
-    const torAppDataDir = lazy.TorLauncherUtil.getTorFile(
-      "torappdatadir",
-      false
-    );
-    if (torAppDataDir) {
-      const geoipFile = torAppDataDir.clone();
-      geoipFile.append("geoip");
-      if (geoipFile.exists()) {
-        this.#args.push("GeoIPFile", geoipFile.path);
-      } else {
-        logger.warn(
-          "GeoIP file not found, the circuit display will not show locations."
-        );
-      }
-      const geoip6File = torAppDataDir.clone();
-      geoip6File.append("geoip6");
-      if (geoip6File.exists()) {
-        this.#args.push("GeoIPv6File", geoip6File.path);
-      } else {
-        logger.warn(
-          "GeoIP6 file not found, the circuit display will not show locations for IPv6-only relays."
-        );
-      }
-    } else {
-      logger.warn(
-        "App data directory not found, the circuit display will not show locations."
-      );
-    }
+    const geoipFile = lazy.TorLauncherUtil.getTorFile("geoip", false);
+	const geoip6File = lazy.TorLauncherUtil.getTorFile("geoip6", false);
+    this.#args.push("GeoIPFile", geoipFile.path);
+    this.#args.push("GeoIPv6File", geoip6File.path);
   }
 
   /**
