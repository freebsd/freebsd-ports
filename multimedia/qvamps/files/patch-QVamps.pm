--- QVamps.pm.orig	Mon Jan  2 05:58:27 2006
+++ QVamps.pm	Fri Jan 13 13:20:19 2006
@@ -19,8 +19,8 @@
 # places to look for global settings file
 our @global_settings_paths =
 (
-  "/usr/share/qvamps/etc",
-  "/usr/local/share/qvamps/etc"
+  "%%PREFIX%%/etc/qvamps",
+  "%%DATADIR%%/etc"
 );
 
 # compute program's load prefix
@@ -40,8 +40,8 @@
   "/General/DVD_burner"              => "/dev/dvdrecorder",
   "/General/DVD_burn_speed"          => 4,
 
-  "/Installation/prefix"             => "/usr/local",
-  "/Installation/messages_file"      => "%p/share/qvamps/translations/%l",
+  "/Installation/prefix"             => "%%PREFIX%%",
+  "/Installation/messages_file"      => "%%DATADIR%%/translations/%l",
 
   "/MediaPlayer/play_dvd_title"      => 'mplayer -dvd-device %d %o dvd://%T',
   "/MediaPlayer/play_dvd_cells"      =>
@@ -56,11 +56,12 @@
                     'mplex -v 0 -f 8 -o /dev/stdout %v %a | spumux -P %x > %o',
   "/Dvdauthor/spumux_mpg"            => 'spumux -P %x < %i > %o',
   "/Dvdauthor/burn_cmd"              =>
-    's=`mkisofs -dvd-video -quiet -print-size %i`; ' .
-    'mkisofs -dvd-video -V "%v" %i | ' .
-    'cdrecord dev=%d speed=%s driveropts=burnfree ' .
-             'fs=16M tsize=${s}s -dao -v -',
-
+    'growisofs -dvd-compat -dvd-video ' .
+             '-use-the-force-luke=dao ' .
+             '-use-the-force-luke=notray ' .
+             '-use-the-force-luke=tty ' .
+             '-V "%v" ' .
+             '-speed=%s -Z %d %i ' ,
   "/Vamps/evaporate_cell"            =>
                      'play_cell %d %v %g %c | vamps -E %E -a %a%o -S %S -i %i',
   "/Vamps/select_subtitles"          => '-s %s',
@@ -68,8 +69,8 @@
   "/Vamps/dvdr_spare_sectors"        => 1500,
 
   "/Menu/Preferences/tv_standard"    => "NTSC",
-  "/Menu/Preferences/background"     => "%p/share/qvamps/penguin.jpg",
-  "/Menu/Preferences/audio_es"       => "%p/share/qvamps/silence.mpa",
+  "/Menu/Preferences/background"     => "%%DATADIR%%/penguin.jpg",
+  "/Menu/Preferences/audio_es"       => "%%DATADIR%%/silence.mpa",
   "/Menu/Preferences/audio_language" => "en",
   "/Menu/Preferences/audio_format"   => "Dolby AC-3",
   "/Menu/Preferences/audio_channels" => "5.1",
@@ -101,7 +102,7 @@
 our @settings_paths = @global_settings_paths;
 
 # use settings from program's load prefix
-push @settings_paths, "$load_prefix/share/etc" if ($load_prefix);
+push @settings_paths, "$load_prefix/etc/vamps" if ($load_prefix);
 
 # environment overrides global settings default path
 @settings_paths = ( "$qvamps_home/share/etc" ) if ($qvamps_home);
@@ -287,7 +288,7 @@
 
     if (open $fh, "-|", "ppmtoy4m -S 420_mpeg2 /dev/null 2>&1")
     {
-      if (<$fh> =~ /Unknown subsampling mode option: 420_mpeg2/)
+      if (<$fh> =~ /Unknown subsampling mode option:\s+420_mpeg2/)
       {
 	my $ppm2mpv_ntsc =  read_setting ("/Menu/Preferences/ppm2mpv_ntsc");
 	$ppm2mpv_ntsc    =~ s/420_mpeg2/420mpeg2/;
