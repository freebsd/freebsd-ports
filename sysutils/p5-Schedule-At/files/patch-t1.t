--- t/t1.t.orig	Thu Feb 12 19:59:26 1998
+++ t/t1.t	Wed Jan 10 12:00:00 2001
@@ -28,7 +28,7 @@
 print "ok 3\n";
 
 my %atJobs = Schedule::At::getJobs();
-print "not " if !defined(%atJobs);
+print "not " if (not %atJobs);
 print "ok 4\n";
 
 $rv = Schedule::At::remove (TAG => 'Schedule::At');
