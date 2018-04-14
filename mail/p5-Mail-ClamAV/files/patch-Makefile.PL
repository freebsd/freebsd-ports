--- Makefile.PL.orig	2009-04-29 19:06:39 UTC
+++ Makefile.PL
@@ -51,7 +51,7 @@ sub main {
     }
 
     my $clver = get_cl_version();
-    return warn_cl_version_bad() if $clver lt $minclversion;
+    return warn_cl_version_bad() if (($clver =~ /^0\.9/) && ($clver lt $minclversion)) && ($clver lt '0.100.0');
 
     my $inc = get_cl_inc_paths();
     my $libs = get_cl_libs();
