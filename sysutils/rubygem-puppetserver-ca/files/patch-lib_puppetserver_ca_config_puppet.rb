--- lib/puppetserver/ca/config/puppet.rb.orig	2020-11-06 21:46:06 UTC
+++ lib/puppetserver/ca/config/puppet.rb
@@ -97,7 +97,7 @@ module Puppetserver
           # defaults below
           base_defaults = [
             [:confdir, user_specific_puppet_confdir],
-            [:ssldir,'$confdir/ssl'],
+            [:ssldir, '/var/puppet/ssl'],
             [:certdir, '$ssldir/certs'],
             [:certname, default_certname],
             [:server, 'puppet'],
