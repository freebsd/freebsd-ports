--- Radius.pm.orig	Thu Jul  5 14:20:54 2001
+++ Radius.pm	Thu Jul  5 14:30:19 2001
@@ -1038,7 +1038,7 @@
 
 =item * I<sample>
 
- $radius->insert_realm('flintstones.com', 'bedrock.com', 'bedrock', '1812', 'nostrip');
+ $radius->update_realm('flintstones.com', 'bedrock.com', 'bedrock', '1812', 'nostrip');
 
 =item * I<return value>
 
@@ -1778,7 +1778,7 @@
 
 sub fetch_realm_options {
         my $self = shift;
-	my @options = ('nostrip', 'dohints');
+	my @options = ('nostrip', 'dohints', 'loglocal');
 
 	return @options if wantarray;
 	return \@options;
