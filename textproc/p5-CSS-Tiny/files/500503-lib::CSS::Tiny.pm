--- lib/CSS/Tiny.pm.orig	Thu Mar 24 00:29:48 2005
+++ lib/CSS/Tiny.pm	Thu Mar 24 00:29:59 2005
@@ -209,7 +209,7 @@
 	my $file = shift or return $self->_error( 'No file name provided' );
 
 	# Write the file
-	open( CSS, '>', $file ) or return $self->_error( "Failed to open file '$file' for writing: $!" );
+	open( CSS, '>'. $file ) or return $self->_error( "Failed to open file '$file' for writing: $!" );
 	print CSS $self->write_string;
 	close( CSS );
 
