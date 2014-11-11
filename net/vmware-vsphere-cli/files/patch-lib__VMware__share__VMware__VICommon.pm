--- lib/VMware/share/VMware/VICommon.pm.orig	2014-11-11 21:22:23 UTC
+++ lib/VMware/share/VMware/VICommon.pm
@@ -424,16 +424,6 @@
    my $url = shift;
    my %supportedapiversions;
    if ($url =~ s|http(s?)://(.*)/sdk.*|http$1://$2/sdk/vimService.wsdl|i) {      
-      if ($1 eq "s") {
-         eval {  
-            require Crypt::SSLeay;  
-            Crypt::SSLeay->import();
-         };
-         if ($@) {
-            die "Crypt::SSLeay is required for https connections, but could not be loaded: $@";
-         }
-      }
-
       my $temp_addr = $2;
       if ($temp_addr =~ /:/) {
          if (($temp_addr =~ tr/:/:/) > 1) {
@@ -501,23 +491,11 @@
 
 sub query_server_version {
    BEGIN {
-      #To remove SSL Warning, switching from IO::Socket::SSL to Net::SSL
-      $ENV{PERL_NET_HTTPS_SSL_SOCKET_CLASS} = "Net::SSL";
 	  #To remove host verification
       $ENV{PERL_LWP_SSL_VERIFY_HOSTNAME} = 0;
    }
    my $url = shift;
    if ($url =~ s|http(s?)://(.*)/sdk.*|http$1://$2/sdk/vimService.wsdl|i) {
-      # bug 288336
-      if ($1 eq "s") {
-         eval {  
-            require Crypt::SSLeay;  
-            Crypt::SSLeay->import();
-         };
-         if ($@) { 
-            die "Crypt::SSLeay is required for https connections, but could not be loaded: $@";
-         }
-      }
       # no IPv6 support yet
       my $temp_addr = $2;
       if ($temp_addr =~ /:/) {
