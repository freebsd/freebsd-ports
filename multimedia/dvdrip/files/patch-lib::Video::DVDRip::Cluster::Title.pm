--- lib/Video/DVDRip/Cluster/Title.pm.orig	Sat Apr 10 11:18:03 2004
+++ lib/Video/DVDRip/Cluster/Title.pm		Sun Jan  9 17:41:11 2005
@@ -276,10 +276,10 @@
 	} else {
 		$command .=
 			"dr_exec avimerge".
-			" -i $avi_file".
 			" -p $audio_file".
 			" -a $target_nr".
-			" -o $avi_file.merged &&".
+			" -o $avi_file.merged ".
+			" -i $avi_file &&".
 			" mv $avi_file.merged $target_file &&".
 			" rm $audio_file &&".
 			" echo DVDRIP_SUCCESS";
@@ -312,10 +312,9 @@
 
 	my $command =
 		"mkdir -m 0775 -p '$audio_video_psu_dir' && ".
-		"${nice}dr_exec avimerge -i $avi_chunks_dir/*".
-		" -o $audio_video_psu_file ";
-	
+		"${nice}dr_exec avimerge -o $audio_video_psu_file";
 	$command .= " -p $audio_psu_file " if not $self->is_ogg;
+        $command .= " -i $avi_chunks_dir/*";
 
 	$command .= " && rm $avi_chunks_dir/*"
 			if $self->with_cleanup;
