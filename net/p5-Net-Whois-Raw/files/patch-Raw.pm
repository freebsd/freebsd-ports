--- Raw.pm.orig	Fri Mar 22 01:36:28 2002
+++ Raw.pm	Sun Apr 21 16:29:50 2002
@@ -23,6 +23,8 @@
          MIL whois.nic.mil
 	 COOP whois.nic.coop
 	 MUSEUM whois.museum
+	 INFO whois.afilias.net
+	 BIZ  whois.neulevel.biz
          AD  whois.ripe.net
          AL  whois.ripe.net
          AM  whois.ripe.net
@@ -130,6 +132,8 @@
 #         ZA  apies.frd.ac.za
 
 %notfound = (
+	  'whois.neulevel.biz.error' => '^Not found:',
+	  'whois.afilias.net.error' => '^NOT FOUND',
           'whois.nic.cc.error' => '^No match for',
           'whois.arin.net.error' => '^No match for',
           'whois.nic.br.error' => 'No match for',
@@ -180,7 +184,7 @@
           'ns.litnet.lt.error' => 'No matches found',
           'whois.adamsnames.tc.error' => 'is not a domain controlled by',
           'whois.nic.la.error' => '^NO MATCH for',
-          'whois.networksolutions.com.error' => '^No match for',
+          'whois.networksolutions.com.error' => '^NO MATCH:',
           'whois.thnic.net.error' => 'No entries found');
 
 %strip = (
@@ -421,6 +425,9 @@
                             ]
         );
 
+$OMIT_MSG = 0;
+$CHECK_FAIL = 0;
+
 sub whois {
     my ($dom, $srv) = @_;
     my $res;
@@ -480,12 +487,12 @@
 
 sub finish {
     my ($text, $srv) = @_;
-    my $notfound = $notfound{lc($srv)};
+    my $notfound = $notfound{lc("$srv.error")};
     my @strip = $strip{lc($srv)} ? @{$strip{lc($srv)}} : ();
     return $text unless $CHECK_FAIL || $OMIT_MSG;
     my @lines;
     MAIN: foreach (split(/\n/, $text)) {
-        return undef if $CHECK_FAIL && /$notfound/;
+        return undef if $CHECK_FAIL && defined ($notfound) && /$notfound/;
         if ($OMIT_MSG) {
             foreach my $re (@strip) {
                 next MAIN if (/$re/);
