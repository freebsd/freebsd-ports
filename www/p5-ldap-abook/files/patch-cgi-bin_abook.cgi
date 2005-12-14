
$FreeBSD$

--- cgi-bin/abook.cgi.orig
+++ cgi-bin/abook.cgi
@@ -39,7 +39,7 @@
 
 my $config_file='/usr/local/etc/AddressBook.conf';
 my $query = CGI::new();
-my $myURL=$query->url;
+my $myURL=$query->url(-absolute=>1);
 my $op = $query->param(op);
 my $entry;
 my $error_msg = "";
