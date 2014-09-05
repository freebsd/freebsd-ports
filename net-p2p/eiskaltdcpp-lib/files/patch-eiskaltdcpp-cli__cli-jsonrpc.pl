--- eiskaltdcpp-cli/cli-jsonrpc.pl.orig	2013-08-29 21:25:02.000000000 +0400
+++ eiskaltdcpp-cli/cli-jsonrpc.pl	2014-08-10 16:43:19.942914548 +0400
@@ -35,8 +35,7 @@
     unshift @INC, 
 	 "$XDG_CONFIG_HOME/eiskaltdc++",
 	 "$HOME/.config/eiskaltdc++/",
-	 "/usr/local/share/eiskaltdcpp/cli",
-	 "/usr/share/eiskaltdcpp/cli"
+	 "/usr/local/etc/eiskaltdcpp"
 }
 
 # preparing terminal
@@ -87,15 +86,16 @@
 my $res;
 
 # creating and configuring jsonrpc client
-my $client = eval
+my $client;
+eval
 {
 	require JSON::RPC::Client;
-	JSON::RPC::Client->new();
+	$client = JSON::RPC::Client->new();
 }
 or do
 {
 	require JSON::RPC::Legacy::Client;
-	JSON::RPC::Legacy::Client->new();
+	$client=JSON::RPC::Legacy::Client->new();
 };
 $client->version("2.0");
 $client->ua->timeout(10);
