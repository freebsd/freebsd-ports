--- lib/Mail/Milter/Authentication/Config.pm.orig	2024-02-05 02:41:57 UTC
+++ lib/Mail/Milter/Authentication/Config.pm
@@ -21,7 +21,7 @@ our @EXPORT_OK = qw{
 };
 
 
-our $PREFIX = '/etc';
+our $PREFIX = '%%ETCDIR%%';
 our $IDENT  = 'authentication_milter';
 my  $CONFIG;
 
@@ -31,19 +31,19 @@ sub default_config {
         'debug'                           => 0,
         'dryrun'                          => 0,
         'logtoerr'                        => 0,
-        'error_log'                       => '/var/log/authentication_milter.err',
+        "log_dispatchouli"                => {},
         'extended_log'                    => 1,
         'legacy_log'                      => 0,
-        'connection'                      => 'inet:12345@localhost',
-        'umask'                           => '0000',
-        'runas'                           => 'nobody',
-        'rungroup'                        => 'nogroup',
+        'connection'                      => 'unix:%%RUNDIR%%/auth_milter.sock',
+        'umask'                           => '0077',
+        'runas'                           => '%%DEFAULT_USER%%',
+        'rungroup'                        => '%%DEFAULT_GROUP%%',
         'listen_backlog'                  => 20,
         'check_for_dequeue'               => 60,
-        'min_children'                    => 20,
-        'max_children'                    => 200,
-        'min_spare_children'              => 10,
-        'max_spare_children'              => 20,
+        'min_children'                    => 1,
+        'max_children'                    => 2,
+        'min_spare_children'              => 1,
+        'max_spare_children'              => 1,
         'max_requests_per_child'          => 200,
         'protocol'                        => 'milter',
         'connect_timeout'                 => 30,
@@ -61,9 +61,9 @@ sub default_config {
         'ip_map'                          => {},
         'authserv_id'                     => '',
         'handlers'                        => {},
-        'cache_dir'                       => '/var/cache/authentication_milter',
-        'spool_dir'                       => '/var/spool/authentication_milter',
-        'lib_dir'                         => '/var/lib/authentication_milter',
+        'cache_dir'                       => '%%CACHEDIR%%',
+        'spool_dir'                       => '%%SPOOLDIR%%',
+        'lib_dir'                         => '%%VARLIBDIR%%',
         'lock_file'                       => '',
     };
 
@@ -104,7 +104,7 @@ sub setup_config {
         else {
             if ( $EUID == 0 ) {
                 # We are root, create in global space
-                $dir = '/var/'.$type.'/authentication_milter';
+                $dir = '/var/'.$type.'/auth_milter';
                 mkdir $dir if ! -e $dir;
                 # Create the subdir for this IDENT
                 $dir .= '/'.$safe_ident;
@@ -119,7 +119,7 @@ sub setup_config {
             else {
                 # We are a user! Create something in a temporary space
                 $dir = join( '_',
-                  '/tmp/authentication_milter',
+                  '/tmp/auth_milter',
                   $type,
                   $EUID,
                   $safe_ident,
