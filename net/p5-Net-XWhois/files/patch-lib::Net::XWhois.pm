--- lib/Net/XWhois.pm.orig	Sat Jul 14 11:30:30 2001
+++ lib/Net/XWhois.pm	Tue Mar  5 15:18:05 2002
@@ -124,6 +124,22 @@
   nameservers     => 'Name servers:[\s\n]+(\S+)[\s\n]+(\S+)',
  },
 
+ RIPN => {
+  name            => 'domain:\s+(\S+)\n',
+  registrants     => 'descr:\s+(.+?)\n',
+  contact_admin   => 'admin-o:\s+(.*?)\s*\n',
+  contact_tech    => 'tech-c:\s+(.*?)\s*\n',
+  nameservers     => 'nserver:\s+(\S+)',
+  status          => 'state:\s+(.*?)\s*\n',
+  changed         => 'changed:\s+(.*?)\s*\n',
+  source          => 'source:\s+(.*?)\s*\n',
+  person          => 'person:\s+(.*?)\s*\n',
+  address         => 'address:\s+(.+?)\n',
+  phone           => 'phone:\s+(.+?)\n',
+  fax_no          => 'fax-no:\s+(.+?)\n',
+  contact_emails  => 'e-mail:\s+(.+?)\n',
+ },
+
  NOMINET => { 
   name                => 'omain Name:\s+(\S+)',
   registrant          => 'egistered For:\s*(.*?)\n',
@@ -202,6 +218,7 @@
 
 my %WHOIS_PARSER = (
     'whois.ripe.net'            => 'RPSL',
+    'whois.ripn.net'            => 'RIPN',
     'whois.nic.mil'             => 'INTERNIC',
     'whois.nic.ad.jp'           => 'JAPAN',
     'whois.domainz.net.nz'      => 'GENERIC',
@@ -254,10 +271,10 @@
     'no'  => 'whois.norid.no',      'nz'  => 'whois.domainz.net.nz',
     'org' => 'whois.internic.net',
     'pl'  => 'whois.ripe.net',      'pt'  => 'whois.ripe.net',
-    'ro'  => 'whois.ripe.net',      'ru'  => 'whois.ripe.net',
+    'ro'  => 'whois.ripe.net',      'ru'  => 'whois.ripn.net',
     'se'  => 'whois.ripe.net',      'sg'  => 'whois.nic.net.sg',
     'si'  => 'whois.ripe.net',      'sk'  => 'whois.ripe.net',
-    'sm'  => 'whois.ripe.net',      'su'  => 'whois.ripe.net',
+    'sm'  => 'whois.ripe.net',      'su'  => 'whois.ripn.net',
     'tn'  => 'whois.ripe.net',      'tr'  => 'whois.ripe.net',
     'tw'  => 'whois.twnic.net',
     'ua'  => 'whois.ripe.net',      
