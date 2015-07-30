--- Makefile.PL.orig	2010-04-24 12:37:38 UTC
+++ Makefile.PL
@@ -12,8 +12,7 @@ my @whichcand = qw(/bin/which /usr/bin/w
 
 my @KRB5_CONFIG_TRIES = (
 
-    '/usr/kerberos/bin/krb5-config',   # for use with CentOS,  as suggested by Mark Hedges in https://rt.cpan.org/Ticket/Display.html?id=48732
-    '/usr/bin/krb5-config',            # always worth a try ;-)
+    '%%KRB5CONF%%',      # for use with FreeBSD
 
 );
 
