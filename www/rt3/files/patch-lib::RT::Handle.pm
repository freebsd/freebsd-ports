--- lib/RT/Handle.pm	Tue Mar  9 07:54:00 2004
+++ lib/RT/Handle.pm	Wed Sep 22 12:46:41 2004
@@ -78,12 +78,16 @@
 
 =cut
 
+use File::Spec;
 
 sub BuildDSN {
     my $self = shift;
 # Unless the database port is a positive integer, we really don't want to pass it.
 $RT::DatabasePort = undef unless (defined $RT::DatabasePort && $RT::DatabasePort =~ /^(\d+)$/);
 $RT::DatabaseHost = undef unless (defined $RT::DatabaseHost && $RT::DatabaseHost ne '');
+$RT::DatabaseName = File::Spec->catfile($RT::VarPath, $RT::DatabaseName)
+    if ($RT::DatabaseType eq 'SQLite') and
+	not File::Spec->file_name_is_absolute($RT::DatabaseName);
 
 
     $self->SUPER::BuildDSN(Host => $RT::DatabaseHost, 
