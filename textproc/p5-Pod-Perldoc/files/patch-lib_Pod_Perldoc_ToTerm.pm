--- lib/Pod/Perldoc/ToTerm.pm.orig	2015-02-12 03:08:32 UTC
+++ lib/Pod/Perldoc/ToTerm.pm
@@ -41,6 +41,8 @@ sub _get_columns_from_manwidth {
 
 	return 0 unless defined $ENV{MANWIDTH};
 
+	if ($ENV{MANWIDTH} eq 'tty') { return 0; }
+
 	unless( $ENV{MANWIDTH} =~ m/\A\d+\z/ ) {
 		$self->warn( "Ignoring non-numeric MANWIDTH ($ENV{MANWIDTH})\n" );
 		return 0;
