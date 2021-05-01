--- lib/Video/DVDRip/Config.pm.orig	Sun Aug 20 07:56:01 2006
+++ lib/Video/DVDRip/Config.pm	Sat Sep 23 13:58:03 2006
@@ -193,16 +193,16 @@
     dvd_device => {
         label => __ "Default DVD device",
         type  => 'file',
-        value => "",
+        value => "/cdrom",
         dvd_button => 1,
     },
     selected_dvd_device => {
-        value   => "/dev/dvd",
+        value   => "/cdrom",
     },
     eject_command => {
         label => __ "Eject Command",
         type  => 'string',
-        value => "eject",
+        value => "cdcontrol",
         rules => "executable-command",
     },
     play_dvd_command => {
@@ -226,7 +226,7 @@
     play_stdin_command => {
         label   => __ "STDIN player command",
         type    => 'string',
-        value   => 'xine stdin://mpeg2 -g -pq -a %a',
+        value   => 'mplayer -aid %(%a+128) -',
         presets => [
             'mplayer -aid %(%a+128) -', 'xine stdin://mpeg2 -g -pq -a %a',
         ],
@@ -274,7 +274,7 @@
     default_video_codec => {
         label   => __ "Default video codec",
         type    => 'string',
-        value   => 'xvid',
+        value   => 'xvid4',
         presets => [
             "SVCD",   "VCD",  "XSVCD",   "XVCD",  "CVD",   "divx4",
             "divx5",  "xvid", "xvidcvs", "xvid2", "xvid3", "xvid4",
