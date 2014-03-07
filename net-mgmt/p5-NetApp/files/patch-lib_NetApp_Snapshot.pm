--- lib/NetApp/Snapshot.pm.orig	2012-06-05 22:44:25.000000000 +0800
+++ lib/NetApp/Snapshot.pm	2013-12-30 23:50:33.000000000 +0800
@@ -8,6 +8,7 @@
 use warnings;
 use English;
 use Carp;
+use DateTime;
 
 use Class::Std;
 use Params::Validate qw( :all );
@@ -243,6 +244,7 @@
     my (%args)		= validate( @_, {
         parent		=> { type	=> OBJECT },
         name		=> { type	=> SCALAR },
+        snapname	=> { default	=> DateTime->now() },
     });
 
     my $parent		= $args{parent};
@@ -253,7 +255,7 @@
         push @command, '-A';
     }
 
-    push @command, $args{name};
+    push @command, $args{name}, $args{snapname};
 
     return $parent->get_filer->_run_command(
         command		=> \@command,
