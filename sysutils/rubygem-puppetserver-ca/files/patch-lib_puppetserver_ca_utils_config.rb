--- lib/puppetserver/ca/utils/config.rb.orig	2020-11-28 01:14:43 UTC
+++ lib/puppetserver/ca/utils/config.rb
@@ -23,7 +23,7 @@ module Puppetserver
 
         def self.puppet_confdir
           if running_as_root?
-            '/etc/puppetlabs/puppet'
+            '/usr/local/etc/puppet'
           else
             "#{ENV['HOME']}/.puppetlabs/etc/puppet"
           end
@@ -34,11 +34,13 @@ module Puppetserver
         end
 
         def self.default_ssldir(confdir = puppet_confdir)
-          File.join(confdir, 'ssl')
+          res = File.join(confdir, 'ssl')
+          res = '/var/puppet/ssl' unless File.directory?(res)
+          res
         end
 
         def self.old_default_cadir(confdir = puppet_confdir)
-          File.join(confdir, 'ssl', 'ca')
+          '/var/puppet/ssl/ca'
         end
 
         def self.new_default_cadir(confdir = puppet_confdir)
