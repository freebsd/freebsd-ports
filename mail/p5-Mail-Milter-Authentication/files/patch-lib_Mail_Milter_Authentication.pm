--- lib/Mail/Milter/Authentication.pm.orig	2024-02-05 02:41:57 UTC
+++ lib/Mail/Milter/Authentication.pm
@@ -32,11 +32,14 @@ use vars qw(@ISA);
         my $MYARGS = {
             'ident' => $Mail::Milter::Authentication::Config::IDENT,
             'to_stderr' => 0, # handled elsewhere
+            'to_stdout' => 0, # handled elsewhere
             'log_pid' => 1,
             'facility' => LOG_MAIL,
         };
         if ( exists $config->{ 'log_dispatchouli' } ) {
-            $MYARGS = $config->{ 'log_dispatchouli' };
+            foreach my $k (keys %{$config->{ 'log_dispatchouli' }}) {
+                $MYARGS->{$k} = $config->{ 'log_dispatchouli' }->{$k};
+            }
         }
 
         $LOGGER = Log::Dispatchouli->new( $MYARGS );
