--- Makefile.PL.orig	2012-09-19 11:01:40.247410095 +1200
+++ Makefile.PL	2012-09-19 11:01:53.134452220 +1200
@@ -8,7 +8,6 @@
   VERSION_FROM => 'lib/Nagios/Plugin/Beanstalk.pm',
   ABSTRACT_FROM => 'lib/Nagios/Plugin/Beanstalk.pm',
   PL_FILES     => {},
-  EXE_FILES    => ['check_beanstalkd'],
   PREREQ_PM => {
     'Nagios::Plugin' => 0,
     'Beanstalk::Client' => 0,
