--- lib/Pod/Perldoc/ToMan.pm.orig	2015-02-12 03:08:10 UTC
+++ lib/Pod/Perldoc/ToMan.pm
@@ -63,7 +63,7 @@ sub init {
 sub _roffer_candidates {
 	my( $self ) = @_;
 
-	if( $self->is_openbsd || $self->is_bitrig ) { qw( mandoc groff nroff ) }
+	if( $self->is_openbsd || $self->is_freebsd || $self->is_bitrig ) { qw( mandoc groff nroff ) }
 	else                    { qw( groff nroff mandoc ) }
 	}
 
@@ -108,6 +108,8 @@ sub _get_columns_from_manwidth {
 
 	return 0 unless defined $ENV{MANWIDTH};
 
+	if ($ENV{MANWIDTH} eq 'tty') { return 0; }
+
 	unless( $ENV{MANWIDTH} =~ m/\A\d+\z/ ) {
 		$self->warn( "Ignoring non-numeric MANWIDTH ($ENV{MANWIDTH})\n" );
 		return 0;
