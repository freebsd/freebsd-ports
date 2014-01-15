--- ./ext/rack/config.ru.orig	2013-12-20 16:47:22.876896492 +0000
+++ ./ext/rack/config.ru	2013-12-20 16:47:33.826895721 +0000
@@ -14,8 +14,8 @@
 # Rack applications typically don't start as root.  Set --confdir and --vardir
 # to prevent reading configuration from ~puppet/.puppet/puppet.conf and writing
 # to ~puppet/.puppet
-ARGV << "--confdir" << "/etc/puppet"
-ARGV << "--vardir"  << "/var/lib/puppet"
+ARGV << "--confdir" << "%%PREFIX%%/etc/puppet"
+ARGV << "--vardir"  << "/var/puppet"
 
 # NOTE: it's unfortunate that we have to use the "CommandLine" class
 #  here to launch the app, but it contains some initialization logic
