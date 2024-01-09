--- plugins/lib/Munin/Plugin/SNMP.pm.orig	2014-11-24 21:46:24 UTC
+++ plugins/lib/Munin/Plugin/SNMP.pm
@@ -104,7 +104,7 @@ well.
 
 =cut
 
-    my ($host, $port, $version, $tail);
+    my ($host, $port, $version, $tail, $domain);
 
     # Decode plugin/symlink name and extract meaning from it - if possible.
     if ($0 =~ /^(?:.*\/)?snmp(v3)?_([^_]+)_(.*)/) {
@@ -122,8 +122,9 @@ well.
     $host    = $ENV{host}    || $host    || die "Could not find hostname";
     $version = $ENV{version} || $version || '2';
     $port    = $ENV{port}    || $port    || 161;
+    $domain  = $ENV{domain}  || $domain  || 'UDP/IPv4';
 
-    return ($host, $port, $version, $tail);
+    return ($host, $port, $version, $tail, $domain);
 }
 
 
@@ -205,13 +206,14 @@ Security is handled differently for vers
 
 =cut
 
-    my ($host, $port, $version, $tail) = config_session();
+    my ($host, $port, $version, $tail, $domain) = config_session();
 
     # Common options.
     my @options = (
         -hostname => $host,
         -port     => $port,
         -version  => $version,
+        -domain   => $domain,
     );
 
     # User defined options
