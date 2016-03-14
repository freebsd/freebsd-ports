--- cisco-torch.pl.orig	2016-02-15 10:53:28 UTC
+++ cisco-torch.pl
@@ -5,14 +5,14 @@ eval ("use sigtrap;");die "[error] sigtr
 eval ("use Net::hostent;");die "[error] Net::hostent  perl module is not installed \n" if $@;
 eval ("use Getopt::Std;");die "[error] Getopt::Std perl module is not installed \n" if $@;
 eval ("use Net::Telnet;");die "[error] Net::Telnet perl module is not installed \n" if $@;
-eval ("use Net::SSH::Perl;");die "[error] Net::SSH::Perl perl module is not installed \n" if $@;
+eval ("use  Net::SSH2;");die "[error]  Net::SSH2 perl module is not installed \n" if $@;
 eval ("use Net::SSLeay qw(get_https post_https sslcat make_headers make_form);");die "[error] Net::SSLeay perl module is not installed \n" if $@;
 eval ("use MIME::Base64 qw(encode_base64);");die "[error] MIME::Base64 perl module is not installed \n" if $@;
 eval ("use Net::SNMP;");die "[error] Net::SNMP perl module is not installed \n" if $@;
 eval ("use POSIX;");die "[error] POSIX perl  is not suported \n" if $@;
 
 
-eval{require "torch.conf"};
+eval{require "/usr/local/etc/cisco-torch/torch.conf"};
 
 if($@) {
    print "Failed to load config file:torch.conf\n";
@@ -23,11 +23,11 @@ print "Using config file torch.conf...\n
 
 # Plugins
 print "Loading include and plugin ...\n";
-opendir(DIR, "include");
+opendir(DIR, "$datadir/include");
 while($in=readdir(DIR)) {
     next if ($in=~/^[.]{1,2}/);
     next if !($in=~/\.pm$/);
-    require "include/$in";
+    require "$datadir/include/$in";
 }
 closedir(DIR);
 
