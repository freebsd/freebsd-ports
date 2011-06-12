
$FreeBSD$

--- src/Libraries/MusicBrainz/MusicBrainz/LocalDisc.cs.orig
+++ src/Libraries/MusicBrainz/MusicBrainz/LocalDisc.cs
@@ -133,11 +133,11 @@
                 switch (Environment.OSVersion.Platform){
                 case PlatformID.Unix:
                     // TODO can we actually detect the environment?
-                    //try {
+                    try {
                         return new DiscLinux (device);
-                    //} catch {
-                    //    return new DiscFreeBSD (device);
-                    //}
+                    } catch {
+                        return new DiscFreeBSD (device);
+                    }
                 //case PlatformID.Win32NT:
                     //return new DiscWin32NT (device);
                 default:
