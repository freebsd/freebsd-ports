--- lib/Video/DVDRip/Cluster/Title.pm.orig	Fri Sep 22 15:35:37 2006
+++ lib/Video/DVDRip/Cluster/Title.pm	Fri Sep 22 15:38:24 2006
@@ -300,10 +300,10 @@
         if $self->tc_nice =~ /\S/;
 
     my $command = "mkdir -m 0775 -p '$audio_video_psu_dir' && "
-        . "${nice}execflow avimerge -i $avi_chunks_dir/*"
-        . " -o $audio_video_psu_file ";
+        . "${nice}execflow avimerge -o $audio_video_psu_file";
 
     $command .= " -p $audio_psu_file " if !$self->is_ogg;
+    $command .= " -i $avi_chunks_dir/*";
 
     $command .= " && rm $avi_chunks_dir/*"
         if $self->with_cleanup;
