--- lib/Net/XWhois.pm.orig	Sun Oct  6 05:37:55 2002
+++ lib/Net/XWhois.pm	Tue Apr 29 19:01:59 2003
@@ -16,6 +16,7 @@
 # 
 # Changes:
 #
+#  03/08/2003  jmiller     Added new .org PIR registy and parser
 #  08/05/2002  rwoodard    Merged in changes from XWhois discussion forum on
 #                          sourceforge.net; made additional changes as needed
 #                          to implement reverse lookups of IP addresses
@@ -157,6 +158,26 @@
    net_handle           => '\((NETBLK\S+)\)',
    country              => '\n\s+(\S+)\n\n',
  },
+
+ PIR => {
+  name            => 'Domain Name:(\S+)',
+  status          => 'Status:(.*?)\s*\n',
+  registrant      => 'Registrant (?:Name|Street1|Street2|City|Postal Code|Country|Email):(.*?)\s*\n',
+  nameservers     => 'Name Server:(\S+)',
+  contact_admin   => 'Admin (?:Name|Street1|Street2|City|Postal Code|Country|Email):(.*?)\s*\n',
+  contact_tech    => 'Tech (?:Name|Street1|Street2|City|Postal Code|Country|Email):(.*?)\s*\n',
+  contact_zone    => 'Admin (?:Name|Street1|Street2|City|Postal Code|Country|Email):(.*?)\s*\n',
+  contact_billing => 'Billing (?:Name|Street1|Street2|City|Postal Code|Country|Email):(.*?)\s*\n',
+  contact_emails  => '(?:Registrant|Admin|Billing|Tech) Email:(\S+\@\S+)',
+  contact_handles => '\(([^\W\d]+\d+)\)',
+  domain_handles  => '\((\S*?-DOM)\)',
+  org_handles     => '\((\S*?-ORG)\)',
+  not_registered  => 'NOT FOUND',
+#  forwardwhois    => 'Whois Server:(.*?)\s*\n',
+  registrar       => 'Referral URL:(.*?)\s*\n',
+  reg_date        => 'Created On:(.*?)\s*\n',
+  exp_date        => 'Expiration Date:(.*?)\s*\n',
+ },
  
  INTERNIC => {
   name            => '[\n\r\f]+\s*[Dd]omain [Nn]ame[:\.]*\s+(\S+)', 
@@ -241,6 +262,22 @@
   nameservers     => 'Name servers:[\s\n]+(\S+)[\s\n]+(\S+)',
  },
 
+ RIPN => {
+  name            => 'domain:\s+(\S+)\n',
+  registrant      => 'descr:\s+(.+?)\n',
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
@@ -276,7 +313,7 @@
 
  DENIC => { 
   name            => 'domain:\s+(\S+)\n',
-  registrants     => 'descr:\s+(.+?)\n',
+  registrant      => 'descr:\s+(.+?)\n',
   contact_admin   => 'admin-c:\s+(.*?)\s*\n',
   contact_tech    => 'tech-c:\s+(.*?)\s*\n',
   contact_zone    => 'zone-c:\s+(.*?)\s*\n',
@@ -339,7 +376,9 @@
 );
 
 my %WHOIS_PARSER = (
+    'whois.publicinterestregistry.net' => 'PIR',
     'whois.ripe.net'            => 'RPSL',
+    'whois.ripn.net'            => 'RIPN',
     'whois.nic.mil'             => 'INTERNIC',
     'whois.nic.ad.jp'           => 'JAPAN',
     'whois.domainz.net.nz'      => 'GENERIC',
@@ -397,12 +436,12 @@
     'mt'  => 'whois.ripe.net',      'mx'  => 'whois.nic.mx',
     'net' => 'whois.internic.net',  'nl'  => 'whois.ripe.net',
     'no'  => 'whois.norid.no',      'nz'  => 'whois.domainz.net.nz',
-    'org' => 'whois.internic.net',
+    'org' => 'whois.publicinterestregistry.net',
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
@@ -557,6 +596,7 @@
     $self->{ Domain }=~s/^www\.//; #trim leading www. if present; internic doesn't like it
     print "looking up ", $self->{ Domain }, " on ", $self->{ Server }, "\n" if ($self->{ Verbose });
     
+    my $domain = $self->{ Domain };
     #see if we already have a response in the cache, unless told not to
     unless ( $self->{ Nocache } ) {
       READCACHE: {
