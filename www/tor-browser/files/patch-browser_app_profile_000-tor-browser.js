Set all path-related prefs to minimize patching of tl-util.jsm/tl-process.js

Index: browser/app/profile/000-tor-browser.js
--- browser/app/profile/000-tor-browser.js.orig
+++ browser/app/profile/000-tor-browser.js
@@ -100,7 +100,10 @@ pref("extensions.torlauncher.socks_port_flags", "Exten
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
