--- lib/puppetserver/ca/config/puppet.rb.orig	2018-09-28 10:36:20 UTC
+++ lib/puppetserver/ca/config/puppet.rb
@@ -48,7 +48,7 @@ module Puppetserver
         def user_specific_conf_dir
           @user_specific_conf_dir ||=
             if Puppetserver::Ca::Utils::Config.running_as_root?
-              '/etc/puppetlabs/puppet'
+              '%%PREFIX%%/etc/puppet'
             else
               "#{ENV['HOME']}/.puppetlabs/etc/puppet"
             end
@@ -100,7 +100,7 @@ module Puppetserver
           # defaults below
           base_defaults = [
             [:confdir, user_specific_conf_dir],
-            [:ssldir,'$confdir/ssl'],
+            [:ssldir,'/var/puppet/ssl'],
             [:cadir, '$ssldir/ca'],
             [:certdir, '$ssldir/certs'],
             [:certname, default_certname],
