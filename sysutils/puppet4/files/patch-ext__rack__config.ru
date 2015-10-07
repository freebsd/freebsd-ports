--- ext/rack/config.ru.orig	2015-08-09 23:14:59 UTC
+++ ext/rack/config.ru
@@ -14,11 +14,11 @@ ARGV << "--rack"
 # Rack applications typically don't start as root.  Set --confdir, --vardir,
 # --logdir, --rundir to prevent reading configuration from
 # ~/ based pathing.
-ARGV << "--confdir" << "/etc/puppetlabs/puppet"
-ARGV << "--vardir"  << "/opt/puppetlabs/server/data/puppetmaster"
-ARGV << "--logdir"  << "/var/log/puppetlabs/puppetmaster"
-ARGV << "--rundir"  << "/var/run/puppetlabs/puppetmaster"
-ARGV << "--codedir"  << "/etc/puppetlabs/code"
+ARGV << "--confdir" << "%%PREFIX%%/etc/puppet"
+ARGV << "--vardir"  << "/var/puppet"
+ARGV << "--logdir"  << "/var/log/puppet"
+ARGV << "--rundir"  << "/var/run/puppet"
+ARGV << "--codedir" << "%%PREFIX%%/etc/puppet"
 
 # always_cache_features is a performance improvement and safe for a master to
 # apply. This is intended to allow agents to recognize new features that may be
