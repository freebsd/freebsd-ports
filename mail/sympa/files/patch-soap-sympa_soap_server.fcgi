--- soap/sympa_soap_server.fcgi	2003/11/28 18:16:39
+++ soap/sympa_soap_server.fcgi	2004/05/04 21:05:38
@@ -78,7 +78,7 @@
 my $server = SOAP::Transport::HTTP::FCGI::Sympa->new(); 
 
 #$server->dispatch_with({'urn:Sympa' => 'sympasoap'});
-$server->dispatch_to('/home/sympa/bin','sympasoap');
+$server->dispatch_to('--LIBDIR--','sympasoap');
 
 $server->handle($birthday);
 
