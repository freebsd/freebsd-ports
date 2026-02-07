--- exilog_cgi_messages.pm.orig	2005-07-26 11:34:47 UTC
+++ exilog_cgi_messages.pm
@@ -145,8 +145,8 @@ sub _select_host {
   }
 
   my @queries;
-  if ($param->{'qs'} =~ /^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$/) {
-    # IPv4 address
+  if ($param->{'qs'} =~ /^[0-9A-Fa-f.:]+$/) {
+    # IPv4 or IPv6 address
     push @queries, { 'table' => 'messages',
                      'criteria' => { 'host_addr' => $param->{'qs'} } },
                    { 'table' => 'rejects',
@@ -352,7 +352,7 @@ sub messages {
     delete $message->{timestamp};
 
     # Check the message ID.
-    if ($message->{message_id} !~ /^.{6}\-.{6}\-.{2}$/) {
+    if ($message->{message_id} !~ /^.{6}\-.{6,11}\-.{2,4}$/) {
       # This is a pre-DATA reject/warning.
       # Render it as a reject.
       my $complete = @{ sql_select( 'rejects', ['*'], $message ) }[0];
