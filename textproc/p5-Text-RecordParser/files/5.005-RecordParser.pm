--- RecordParser.pm~	Tue Dec 16 21:43:05 2003
+++ RecordParser.pm	Thu May  6 11:45:45 2004
@@ -523,8 +523,8 @@
 
     if ( !defined $self->{'fh'} && $self->{'filename'} ) {
         my $file = $self->{'filename'};
-        open my $fh, "<$file" or croak("Cannot read '$file': $!");
-        $self->{'fh'} = $fh;
+        open FH, "<$file" or croak("Cannot read '$file': $!");
+        $self->{'fh'} = \*FH;
     }
 
     return $self->{'fh'};
@@ -727,8 +727,8 @@
             croak( "Cannot use directory '$filename' as input source" );
         } 
         elsif ( -f _ && -r _ ) {
-            if ( my $fh = $self->fh ) {
-                close $fh or croak(
+            if ( $self->fh ) {
+                close $self->fh or croak(
                     "Can't close '", $self->{'filename'}, "': $!\n"
                 );
                 $self->{'fh'} = undef;
