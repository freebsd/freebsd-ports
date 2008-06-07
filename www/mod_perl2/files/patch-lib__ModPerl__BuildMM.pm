--- ./lib/ModPerl/BuildMM.pm.orig	2008-05-08 13:00:34.000000000 -0400
+++ ./lib/ModPerl/BuildMM.pm	2008-05-08 13:01:03.000000000 -0400
@@ -359,7 +359,7 @@
 
     $apr_config ||= $build->get_apr_config();
 
-    if ($path =~ m/(Thread|Global)Mutex/) {
+    if ($path =~ m/(Thread|Global)(Mutex|RWLock)/) { 
         return unless $apr_config->{HAS_THREADS};
     }
 
