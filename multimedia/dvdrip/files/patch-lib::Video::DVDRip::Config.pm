--- lib/Video/DVDRip/Config.pm.orig	Sun Jun  1 18:01:40 2003
+++ lib/Video/DVDRip/Config.pm	Sun Jun  1 18:07:08 2003
@@ -51,14 +51,9 @@
 		value => 4.2,
 	},
 	dvd_device => {
-		label => "DVD device",
-		type => 'file',
-		value => "/dev/dvd",
-	},
-	dvd_mount_point => {
 		label => "DVD mount point",
-		type => 'dir',
+		type => 'file',
		value => "/cdrom",
 	},
 	writer_device => {
 		label => "Writer device file",
@@ -58,7 +58,7 @@
 	writer_device => {
 		label => "Writer device file",
 		type => 'file',
-		value => "/dev/cdrom",
+		value => "/dev/cd0c",
 	},
 	eject_command => {
 		label => "Eject Command",
@@ -91,7 +86,7 @@
 	play_stdin_command => {
 		label => "STDIN player command",
 		type  => 'string',
-		value => 'xine stdin://mpeg2 -g -pq -a %a',
+		value => 'mplayer -aid %(%a+128) -',
 		presets => [
 			'mplayer -aid %(%a+128) -',
 			'xine stdin://mpeg2 -g -pq -a %a',
@@ -147,11 +147,10 @@
 	default_video_codec => {
 		label => "Default video codec",
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
@@ -181,7 +176,7 @@
 	burn_cdrecord_cmd => {
 		label => "cdrecord command",
 		type  => 'string',
-		value => '/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
+		value => 'cdrecord',
 		presets => [
 			'/usr/lib/xcdroast-0.98/bin/xcdrwrap CDRECORD',
 			'cdrecord',
@@ -235,7 +230,7 @@
 
 my @CONFIG_ORDER = (
 	"Filesystem" => [qw(
-		dvd_device         dvd_mount_point
+		dvd_device
 		base_project_dir   dvdrip_files_dir
 		ogg_file_ext
 	)],
@@ -617,8 +617,8 @@
 sub test_play_file_command  	{ _executable (@_) 	}
 sub test_play_stdin_command 	{ _executable (@_) 	}
 sub test_rar_command 		{ _executable (@_) 	}
-sub test_dvd_device		{ _writable (@_)	}
-sub test_writer_device		{ _writable (@_)	}
+sub test_dvd_device		{ _exists (@_)		}
+sub test_writer_device		{ _exists (@_)		}
 sub test_dvd_mount_point	{ _exists (@_)		}
 sub test_base_project_dir	{ _writable (@_)	}
 sub test_dvdrip_files_dir	{ _writable (@_)	}
