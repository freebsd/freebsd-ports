
$FreeBSD$

--- src/Libraries/MusicBrainz/MusicBrainz/LocalDisc.cs.orig
+++ src/Libraries/MusicBrainz/MusicBrainz/LocalDisc.cs
@@ -131,7 +131,11 @@
             try {
                 switch (Environment.OSVersion.Platform){
                 case PlatformID.Unix:
-                    return new DiscLinux (device);
+                        try {
+                            return new DiscLinux (device);
+                        } catch {
+                            return new DiscFreeBSD (device);
+                        }
                 //case PlatformID.Win32NT:
                     //return new DiscWin32NT (device);
                 default:
