--- lib/ZnapZend.pm.orig	2017-02-08 07:38:40 UTC
+++ lib/ZnapZend.pm
@@ -2,7 +2,7 @@ package ZnapZend;
 
 use Mojo::Base -base;
 use Mojo::IOLoop::ForkCall;
-use Mojo::Util qw(slurp);
+use Mojo::File;
 use Mojo::Log;
 use ZnapZend::Config;
 use ZnapZend::ZFS;
@@ -571,12 +571,13 @@ my $createWorkers = sub {
 my $daemonize = sub {
     my $self = shift;
     my $pidFile = $self->pidfile || $self->defaultPidFile;
+	my $pidFileFile = Mojo::File->new($pidFile);
 
     if (-f $pidFile){
-        chomp(my $pid = slurp $pidFile);
+		chomp(my $pid = $pidFileFile->slurp);
         #pid is not empty and is numeric
-        if ($pid && ($pid = int($pid)) && kill 0, $pid){
-            die "I Quit! Another copy of znapzend ($pid) seems to be running. See $pidFile\n";
+		if ($pid && ($pid = int($pid)) && kill 0, $pid){
+		   die "I Quit! Another copy of znapzend ($pid) seems to be running. See $pidFile\n";
         }
     }
     #make sure pid file is writable before forking
