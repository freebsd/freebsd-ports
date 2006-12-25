--- lib/Net/XWhois.pm.orig	Sun Oct  6 01:37:55 2002
+++ lib/Net/XWhois.pm	Mon Dec 25 15:32:36 2006
@@ -16,6 +16,9 @@
 # 
 # Changes:
 #
+#  07/16/2006  koma2       Update whois server for JAPAN
+#  09/26/2005  lioux       Update parser for BRNIC
+#  03/08/2003  jmiller     Added new .org PIR registy and parser
 #  08/05/2002  rwoodard    Merged in changes from XWhois discussion forum on
 #                          sourceforge.net; made additional changes as needed
 #                          to implement reverse lookups of IP addresses
@@ -122,11 +125,18 @@
    status          => 'status:\s+([^\n]*)\n',
    contact_admin   => '(?:admin|owner)-c:\s+([^\n]*)\n',
    contact_tech    => 'tech-c:\s+([^\n]*)\n',
-   contact_emails  => 'email:\s+(\S+\@\S+)',
+   contact_emails  => 'e-mail:\s+(\S+\@\S+)',
    contact_handles => 'nic-hdl(?:-\S*):\s+([^\n]*)\n',
    remarks        => 'remarks:\s+([^\n]*)\n',
    notify         => 'notify:\s+([^\n]*)\n',
    forwardwhois   => 'remarks:\s+[^\n]*(whois.\w+.\w+)',
+   address        => 'address:\s+(.+?)\n',
+   phone          => 'phone:\s+(.+?)\n',
+   contact_billing => 'billing-c:\s+([^\n]*)\n',
+   nameservers    => 'nserver:\s+(\S+)',
+   person         => 'person:\s+(.*?)\s*\n',
+   creation_time  => 'created:\s+(.*?)\s*\n',
+   record_update  => 'changed:\s+(.*?)\s*\n',
  },
  
  KRNIC => { #added by rwoodard 08/06/2002
@@ -157,6 +167,26 @@
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
@@ -241,6 +271,22 @@
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
@@ -276,7 +322,7 @@
 
  DENIC => { 
   name            => 'domain:\s+(\S+)\n',
-  registrants     => 'descr:\s+(.+?)\n',
+  registrant      => 'descr:\s+(.+?)\n',
   contact_admin   => 'admin-c:\s+(.*?)\s*\n',
   contact_tech    => 'tech-c:\s+(.*?)\s*\n',
   contact_zone    => 'zone-c:\s+(.*?)\s*\n',
@@ -339,9 +385,11 @@
 );
 
 my %WHOIS_PARSER = (
+    'whois.publicinterestregistry.net' => 'PIR',
     'whois.ripe.net'            => 'RPSL',
+    'whois.ripn.net'            => 'RIPN',
     'whois.nic.mil'             => 'INTERNIC',
-    'whois.nic.ad.jp'           => 'JAPAN',
+    'whois.jp'           	=> 'JAPAN',
     'whois.domainz.net.nz'      => 'GENERIC',
     'whois.nic.gov'             => 'INTERNIC',
     'whois.nic.ch'              => 'RIPE_CH',
@@ -388,7 +436,7 @@
     'hr'  => 'whois.ripe.net',      'hu'  => 'whois.ripe.net',
     'ie'  => 'whois.ripe.net',      'il'  => 'whois.ripe.net',
     'is'  => 'whois.ripe.net',      'it'  => 'whois.ripe.net',
-    'jp'  => 'whois.nic.ad.jp',
+    'jp'  => 'whois.jp',
     'kr'  => 'whois.krnic.net',
     'li'  => 'whois.ripe.net',      'lt'  => 'whois.ripe.net',
     'lu'  => 'whois.ripe.net',      'lv'  => 'whois.ripe.net',
@@ -397,12 +445,12 @@
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
@@ -423,9 +471,10 @@
 );
 
 my %ARGS = (
-    'whois.nic.ad.jp'            => { 'S' => '/e' },
+    'whois.jp'            => { 'S' => '/e' },
     'whois.internic.net'         => { 'P' => '=' },
     'whois.networksolutions.com' => { 'P' => '=' },
+    'whois.denic.de'             => { 'P' => '-T dn ' },
 );
 
 sub register_parser {
@@ -532,8 +581,8 @@
     }
 
     #if there is already a Parser defined for this server, use it
-    if ( $self->{ _PARSERS }->{ $self->{ Server }}) {
-        $self->{ Parser } = $self->{ _PARSERS }->{ $self->{ Server }};
+    if ( $self->{ _PARSERS }->{ $self->{ _WHOIS_PARSER }->{ $self->{ Server } }  }) {
+        $self->{ Parser } = $self->{ _PARSERS }->{ $self->{ _WHOIS_PARSER }->{ $self->{ Server } }  };
     }
 
     #if we still don't have a Parser to use, guess based on the Domain (or IP)
@@ -557,6 +606,7 @@
     $self->{ Domain }=~s/^www\.//; #trim leading www. if present; internic doesn't like it
     print "looking up ", $self->{ Domain }, " on ", $self->{ Server }, "\n" if ($self->{ Verbose });
     
+    my $domain = $self->{ Domain };
     #see if we already have a response in the cache, unless told not to
     unless ( $self->{ Nocache } ) {
       READCACHE: {
@@ -608,7 +658,7 @@
           $fw="whois.twnic.net" if ($self->{ Response }=~/Allocated to TWNIC/misg );
        }
        else { #original code
-          @fwa = $self->{ Response } =~ m/\s+$self->{ Domain }\n.*?\n*?\s*?.*?Whois Server: (.*?)(?=\n)/isg;
+          @fwa = $self->{ Response } =~ m/$self->forwardwhois/isg;
           $fw = shift @fwa;
           return undef unless (defined($fw) && length($fw) > 0); # pattern not found
        }
@@ -872,7 +922,7 @@
     my %WHOIS_PARSER = (
     'whois.ripe.net'       => 'RPSL',
     'whois.nic.mil'        => 'INTERNIC',
-    'whois.nic.ad.jp'      => 'JAPAN',
+    'whois.jp'             => 'JAPAN',
     'whois.domainz.net.nz' => 'GENERIC',
     'whois.nic.gov'        => 'INTERNIC',
     'whois.nic.ch'         => 'RIPE_CH',
