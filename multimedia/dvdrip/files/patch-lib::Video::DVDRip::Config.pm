--- lib/Video/DVDRip/Config.pm.orig	Sat Mar 18 08:26:51 2006
+++ lib/Video/DVDRip/Config.pm	Sun Apr 16 04:52:57 2006
@@ -57,7 +57,7 @@
 	dvd_device => {
 		label => __"DVD device",
 		type => 'file',
-		value => "/dev/dvd",
+		value => "/dev/cd0",
 	},
 	dvd_mount_point => {
 		label => __"DVD mount point",
@@ -67,12 +67,12 @@
 	writer_device => {
 		label => __"Writer device file",
 		type => 'file',
-		value => "/dev/cdrom",
+		value => "/dev/cd0",
 	},
 	eject_command => {
 		label => __"Eject Command",
 		type => 'string',
-		value => "eject",
+		value => "cdcontrol",
 	},
 	play_dvd_command => {
 		label => __"DVD player command",
@@ -95,7 +95,7 @@
 	play_stdin_command => {
 		label => __"STDIN player command",
 		type  => 'string',
-		value => 'xine stdin://mpeg2 -g -pq -a %a',
+		value => 'mplayer -aid %(%a+128) -',
 		presets => [
 			'mplayer -aid %(%a+128) -',
 			'xine stdin://mpeg2 -g -pq -a %a',
@@ -151,7 +151,7 @@
 	default_video_codec => {
 		label => __"Default video codec",
 		type  => 'string',
-		value => 'divx4',
+		value => 'xvid4',
 		presets => [
 			"SVCD","VCD","XSVCD","XVCD","CVD",
 			"divx4","divx5",
@@ -198,7 +198,7 @@
 	burn_cdrecord_cmd => {
 		label => __"cdrecord command",
 		type  => 'string',
-		value => '/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
+		value => 'cdrecord',
 		presets => [
 			'/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
 			'cdrecord',
