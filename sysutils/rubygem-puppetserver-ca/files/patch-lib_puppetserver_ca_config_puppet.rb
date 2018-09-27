--- lib/puppetserver/ca/config/puppet.rb.orig	2018-09-27 06:33:57 UTC
+++ lib/puppetserver/ca/config/puppet.rb
@@ -50,7 +50,7 @@ module Puppetserver
         def user_specific_conf_dir
           @user_specific_conf_dir ||=
             if running_as_root?
-              '/etc/puppetlabs/puppet'
+              '%%PREFIX%%/etc/puppet'
             else
               "#{ENV['HOME']}/.puppetlabs/etc/puppet"
             end
@@ -102,7 +102,7 @@ module Puppetserver
           # defaults below
           base_defaults = [
             [:confdir, user_specific_conf_dir],
-            [:ssldir,'$confdir/ssl'],
+            [:ssldir,'/var/puppet/ssl'],
             [:cadir, '$ssldir/ca'],
             [:certdir, '$ssldir/certs'],
             [:certname, default_certname],
