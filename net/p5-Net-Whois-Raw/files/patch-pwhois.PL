--- pwhois.PL.orig	Fri Mar 22 01:35:53 2002
+++ pwhois.PL	Mon Mar 25 14:20:16 2002
@@ -59,23 +59,27 @@
 
 =head1 SYNOPSIS
 
-pwhois perl.com
-pwhois gnu.org
-pwhois -s police.co.il
-pwhois -c there.is.no.tld.called.foobar
-pwhois yahoo.com whois.networksolutions.com
-pwhois -T 10 funet.fi
+  pwhois perl.com
+  pwhois gnu.org
+  pwhois -s police.co.il
+  pwhois -c there.is.no.tld.called.foobar
+  pwhois yahoo.com whois.networksolutions.com
+  pwhois -T 10 funet.fi
 
 etc etc.....
 
 =head1 DESCRIPTION
 
 Just invoke with a domain name, optionally with a whois server name.
-The -s switch attempts to strip the copyright message or disclaimer.
-The -c switch attempts to return an empty answer for failed searches.
-The -T switch takes a parameter that is used for the timeout for
+
+The B<-s> switch attempts to strip the copyright message or disclaimer.
+
+The B<-c> switch attempts to return an empty answer for failed searches.
+
+The B<-T> switch takes a parameter that is used for the timeout for
 connection attempts.
  
+
 =head1 AUTHOR
 
 Ariel Brosh, B<schop@cpan.org>

