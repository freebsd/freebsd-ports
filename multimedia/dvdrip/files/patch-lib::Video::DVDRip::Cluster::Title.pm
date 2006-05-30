--- lib/Video/DVDRip/Cluster/Title.pm.orig	Sun Aug 14 18:22:29 2005
+++ lib/Video/DVDRip/Cluster/Title.pm	Sun Apr 16 04:44:24 2006
@@ -313,10 +313,10 @@
 
 	my $command =
 		"mkdir -m 0775 -p '$audio_video_psu_dir' && ".
-		"${nice}dr_exec avimerge -i $avi_chunks_dir/*".
-		" -o $audio_video_psu_file ";
+		"${nice}dr_exec avimerge -o $audio_video_psu_file";
 	
 	$command .= " -p $audio_psu_file " if not $self->is_ogg;
+	$command .= " -i $avi_chunks_dir/*";
 
 	$command .= " && rm $avi_chunks_dir/*"
 			if $self->with_cleanup;
