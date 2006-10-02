--- lib/Mail/SpamAssassin/ArchiveIterator.pm.orig	Tue Aug 29 23:16:47 2006
+++ lib/Mail/SpamAssassin/ArchiveIterator.pm	Fri Sep 29 10:49:46 2006
@@ -1141,7 +1141,7 @@
 	  }
 
           $self->bump_scan_progress();
-	  $info->{"$file.$offset"} = Mail::SpamAssassin::Util::receive_date($header);
+	  $info->{$offset} = Mail::SpamAssassin::Util::receive_date($header);
 
 	  # go onto the next message
 	  seek(INPUT, $offset + $size, 0);
