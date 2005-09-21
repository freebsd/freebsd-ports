--- lib/Video/DVDRip/Config.pm.orig	Sun Aug 14 17:34:52 2005
+++ lib/Video/DVDRip/Config.pm	Sun Aug 14 17:39:55 2005
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
@@ -151,11 +151,10 @@
 	default_video_codec => {
 		label => __"Default video codec",
 		type  => 'string',
-		value => 'divx4',
+		value => 'xvid4',
 		presets => [
 			"SVCD","VCD","XSVCD","XVCD","CVD",
-			"divx4","divx5",
-			"xvid","xvidcvs","xvid2","xvid3","xvid4",
+			"xvid4",
 			"ffmpeg","fame","af6"
 		],
 	},
@@ -198,7 +197,7 @@
 	burn_cdrecord_cmd => {
 		label => __"cdrecord command",
 		type  => 'string',
-		value => '/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
+		value => 'cdrecord',
 		presets => [
 			'/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
 			'cdrecord',
@@ -791,8 +790,8 @@
 sub test_play_file_command  	{ _executable (@_) 	}
 sub test_play_stdin_command 	{ _executable (@_) 	}
 sub test_rar_command 		{ _executable (@_) 	}
-sub test_dvd_device		{ _writable (@_)	}
-sub test_writer_device		{ _writable (@_)	}
+sub test_dvd_device		{ _exists (@_)	}
+sub test_writer_device		{ _exists (@_)	}
 sub test_dvd_mount_point	{ _exists (@_)		}
 sub test_base_project_dir	{ _writable (@_)	}
 sub test_dvdrip_files_dir	{ _writable (@_)	}
