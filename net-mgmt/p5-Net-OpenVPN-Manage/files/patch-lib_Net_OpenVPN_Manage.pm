--- lib/Net/OpenVPN/Manage.pm.orig	2006-07-10 18:21:19 UTC
+++ lib/Net/OpenVPN/Manage.pm
@@ -1,3 +1,5 @@
+# -*- mode: cperl; mode: follow; -*-
+
 package Net::OpenVPN::Manage;
 
 use strict;
@@ -217,6 +219,84 @@ sub status_ref() {
   return $ref;
 }
 
+# $hash_ref = $vpn->status_hash();
+sub status_hash() {
+  my $ref;
+  my $self = shift;
+  my $arg  = 2;
+  my $telnet = $self->{objects}{_telnet_};
+  my @output = $telnet->cmd(String => 'status '.$arg, Prompt => '/(SUCCESS:.*\n|ERROR:.*\n|END.*\n)/');
+  unless ($telnet->last_prompt =~ /(SUCCESS:.*|END.*\n)/){
+    $self->{error_msg} = $telnet->last_prompt();
+    return 0;
+  }
+  unless ($telnet->last_prompt =~ /END.*\n/){
+    return $telnet->last_prompt();
+  }
+  my ( $i, @arr );
+  foreach my $ln ( @output ){
+      chomp $ln;
+      if (( $ln eq '' ) || ( $ln =~ /^\s*$/ )){ 
+      next;
+    } elsif ( $ln =~ s/^(CLIENT_LIST),// ) {
+	@arr = split ',', $ln;
+	chomp @arr;
+	$ref->{$1}->{$arr[0]} = {
+ 	    ip_real => $arr[1],
+ 	    ip_virt => $arr[2],
+ 	    b_recv => $arr[3],
+ 	    b_sent => $arr[4],
+ 	    ts => $arr[5],
+ 	    ts_s => $arr[6],
+ 	    name => $arr[7],
+ 	};
+	undef @arr;
+    } elsif ( $ln =~ s/^(ROUTING_TABLE),// ) {
+	@arr = split ',', $ln;
+	chomp @arr;
+	$ref->{$1}->{$arr[1]} = {
+	    ip_virt => $arr[0],
+	    ip_real => $arr[2],
+	    ts => $arr[3],
+	    ts_s => $arr[4],
+	};
+	undef @arr;
+    } elsif ( $ln =~ /^HEADER,ROUTING_TABLE/ ) {
+	@arr = split ',', $ln;
+	chomp @arr;
+	$ref->{HEADER}->{$arr[1]} = {
+	    ip_virt => 'Virtual Address',
+	    cn => 'Common Name',
+	    ip_real => 'Real Address',
+	    ts => 'Last Ref',
+	    ts_s => 'Last Ref (time_t)',
+	};
+	undef @arr;
+    } elsif ( $ln =~ /^HEADER,CLIENT_LIST/ ) {
+	@arr = split ',', $ln;
+	chomp @arr;
+	$ref->{HEADER}->{$arr[1]} = {
+	    cn => 'Common Name',
+	    ip_real => 'Real Address',
+	    ip_virt => 'Virtual Address',
+	    b_recv => 'Bytes Received',
+	    b_sent => 'Bytes Sent',
+	    ts => 'Connected Since',
+	    ts_s => 'Connected Since (time_t)',
+	    name => 'Username',
+	};
+	undef @arr;
+    } elsif ( $ln =~ s/^(TITLE),// ){
+      $ref->{$1}=$ln;
+    } elsif ( $ln =~ s/^(TIME),// ){
+      $ref->{$1}=$ln;
+    } elsif ( $ln =~ s/^(GLOBAL_STATS),// ){
+      $ref->{$1}=$ln;
+    } 
+  }
+  return $ref;
+}
+
 # Not implemented
 sub test {
   my $self = shift;
@@ -478,6 +558,10 @@ If called without an argument, it will r
 	# Print the connection status page using the version 2 format.
 	print $vpn->status(2); 
 
+=item $vpn->status_hash( );
+
+Returns the active connections status information as a hash to hashes.
+
 =item $vpn->status_ref( );
 
 Returns the active connections status information as a reference to a hash of arrays.
