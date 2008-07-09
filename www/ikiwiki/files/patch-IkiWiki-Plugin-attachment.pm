--- IkiWiki/Plugin/attachment.pm.orig	2008-07-06 23:36:47.000000000 +0200
+++ IkiWiki/Plugin/attachment.pm	2008-07-09 20:55:36.000000000 +0200
@@ -21,6 +21,8 @@ sub formbuilder_setup (@) { #{{{
 	my $q=$params{cgi};
 
 	if (defined $form->field("do") && $form->field("do") eq "edit") {
+		# Add attachment field, set type to multipart.
+		$form->enctype(&CGI::MULTIPART);
 		$form->field(name => 'attachment', type => 'file');
 		# These buttons are not put in the usual place, so
 		# are not added to the normal formbuilder button list.
@@ -34,7 +36,8 @@ sub formbuilder_setup (@) { #{{{
 		# Start with the attachments interface toggled invisible,
 		# but if it was used, keep it open.
 		if ($form->submitted ne "Upload Attachment" &&
-		    ! length $q->param("attachment_select")) {
+		    (! defined $q->param("attachment_select") ||
+		    ! length $q->param("attachment_select"))) {
 			$form->tmpl_param("attachments-class" => "toggleable");
 		}
 		else {
@@ -86,7 +89,19 @@ sub formbuilder (@) { #{{{
 		# This is an (apparently undocumented) way to get the name
 		# of the temp file that CGI writes the upload to.
 		my $tempfile=$q->tmpFileName($filename);
-		
+		if (! defined $tempfile || ! length $tempfile) {
+			# perl 5.8 needs an alternative, awful method
+			if ($q =~ /HASH/ && exists $q->{'.tmpfiles'}) {
+				foreach my $key (keys(%{$q->{'.tmpfiles'}})) {
+					$tempfile=$q->tmpFileName(\$key);
+					last if defined $tempfile && length $tempfile;
+				}
+			}
+			if (! defined $tempfile || ! length $tempfile) {
+				error("CGI::tmpFileName failed to return the uploaded file name");
+			}
+		}
+
 		$filename=IkiWiki::titlepage(
 			IkiWiki::possibly_foolish_untaint(
 				attachment_location($form->field('page')).
@@ -132,7 +147,14 @@ sub formbuilder (@) { #{{{
 		else {
 			my $fh=$q->upload('attachment');
 			if (! defined $fh || ! ref $fh) {
-				error("failed to get filehandle");
+				# needed by old CGI versions
+				$fh=$q->param('attachment');
+				if (! defined $fh || ! ref $fh) {
+					# even that doesn't always work,
+					# fall back to opening the tempfile
+					$fh=undef;
+					open($fh, "<", $tempfile) || error("failed to open \"$tempfile\": $!");
+				}
 			}
 			binmode($fh);
 			writefile($filename, $config{srcdir}, undef, 1, sub {
