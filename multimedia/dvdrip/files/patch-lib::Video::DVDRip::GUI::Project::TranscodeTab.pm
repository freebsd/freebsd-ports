--- lib/Video/DVDRip/GUI/Project/TranscodeTab.pm.orig	Mon Jun  2 15:41:16 2003
+++ lib/Video/DVDRip/GUI/Project/TranscodeTab.pm	Mon Jun  2 16:04:28 2003
@@ -1269,14 +1269,14 @@
 		if ( $self->version ("transcode") < 609 ) {
 			$widgets->{tc_video_codec_combo}
 				->set_popdown_strings(
-					"divx4","divx5","xvid",
-					"xvidcvs","ffmpeg","fame","af6"
+					"xvid",
+					"ffmpeg","fame","af6"
 				);
 		} else {
 			$widgets->{tc_video_codec_combo}
 				->set_popdown_strings(
-					"divx4","divx5","xvid","xvid2","xvid3",
-					"xvid4","ffmpeg","fame","af6"
+					"xvid4",
+					"ffmpeg","fame","af6"
 				);
 		}
 	}
