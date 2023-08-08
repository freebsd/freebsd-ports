--- browser/app/profile/000-tor-browser.js.orig	2022-11-30 11:37:40 UTC
+++ browser/app/profile/000-tor-browser.js
@@ -123,14 +123,17 @@ pref("extensions.torlauncher.socks_port_flags", "Exten
 // The tor_path is relative to the application directory. On Linux and
 // Windows this is the Browser/ directory that contains the firefox
 // executables, and on Mac OS it is the TorBrowser.app directory.
-pref("extensions.torlauncher.tor_path", "");
+pref("extensions.torlauncher.tor_path", "LOCALBASE/bin/tor");
+pref("extensions.torlauncher.torrc-defaults_path", "LOCALBASE/share/tor-browser/torrc-defaults");
+pref("extensions.torlauncher.geoip_path", "LOCALBASE/share/tor/geoip");
+pref("extensions.torlauncher.geoip6_path", "LOCALBASE/share/tor/geoip6");
 
 // The torrc_path and tordatadir_path are relative to the data directory,
 // which is TorBrowser-Data/ if it exists as a sibling of the application
 // directory. If TorBrowser-Data/ does not exist, these paths are relative
 // to the TorBrowser/ directory within the application directory.
-pref("extensions.torlauncher.torrc_path", "");
-pref("extensions.torlauncher.tordatadir_path", "");
+pref("extensions.torlauncher.torrc_path", "torrc");
+pref("extensions.torlauncher.tordatadir_path", "tor_data");
 
 // BridgeDB-related preferences (used for Moat).
 pref("extensions.torlauncher.bridgedb_front", "cdn.sstatic.net");
