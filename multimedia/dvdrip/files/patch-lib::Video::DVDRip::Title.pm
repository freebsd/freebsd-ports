--- lib/Video/DVDRip/Title.pm.orig	Wed Dec 29 20:15:48 2004
+++ lib/Video/DVDRip/Title.pm	Wed Dec 29 20:16:44 2004
@@ -2152,10 +2152,10 @@
 
 		$command .=
 			"dr_exec avimerge".
-			" -i $avi_file".
 			" -p $audio_file".
 			" -a $target_nr".
-			" -o $avi_file.merged &&".
+			" -o $avi_file.merged".
+			" -i $avi_file &&".
 			" mv $avi_file.merged $avi_file &&".
 			" rm $audio_file &&".
 			" echo DVDRIP_SUCCESS";
@@ -2540,7 +2540,7 @@
 	my $target_file = $self->preview_filename( type => $type );
 	
 	my $catch = $self->system (
-		command => "identify -ping $source_file"
+		command => "identify $source_file"
 	);
 	my ($width, $height);
 	($width, $height) = ( $catch =~ /(\d+)x(\d+)/ );
@@ -2598,7 +2598,7 @@
 	}
 	
 	my $catch = $self->system (
-		command => "identify -ping $source_file"
+		command => "identify $source_file"
 	);
 	my ($width, $height);
 	($width, $height) = ( $catch =~ /(\d+)x(\d+)/ );
