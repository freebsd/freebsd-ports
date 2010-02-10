--- lib/Mail/SpamAssassin/Plugin/Bayes.pm	2010/01/26 12:13:41	903191
+++ lib/Mail/SpamAssassin/Plugin/Bayes.pm	2010/02/03 16:44:07	906120
@@ -832,7 +832,7 @@
             });
 
   $permsgstatus->set_tag ('TOKENSUMMARY', sub {
-              if( defined $self->{tag_data}{BAYESTC} )
+              if ( defined $permsgstatus->{tag_data}{BAYESTC} )
                 {
                   my $tcount_neutral = $permsgstatus->{tag_data}{BAYESTCLEARNED}
                                     - $permsgstatus->{tag_data}{BAYESTCSPAMMY}
 
