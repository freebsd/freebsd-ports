--- lib/Video/DVDRip/GUI/Project/TranscodeTab.pm.orig	Mon Jun  2 15:41:16 2003
+++ lib/Video/DVDRip/GUI/Project/TranscodeTab.pm	Mon Jun  2 16:04:28 2003
@@ -1205,7 +1205,7 @@
 			->set_popdown_strings( "SVCD", "VCD" );
 	} else {
 		$widgets->{tc_video_codec_combo}
-			->set_popdown_strings( "divx4","divx5","xvid","xvidcvs","ffmpeg","fame","af6" );
+			->set_popdown_strings( "xvid","ffmpeg","fame","af6" );
 	}
 
 	$widgets->{tc_video_codec}->set_text($title->tc_video_codec);
