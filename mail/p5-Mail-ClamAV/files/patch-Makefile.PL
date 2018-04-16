--- Makefile.PL.orig	2009-04-29 19:06:39 UTC
+++ Makefile.PL
@@ -2,6 +2,7 @@ use 5.006;
 
 use lib '.';
 use Inline::MakeMaker; # bundled
+use version;
 
 # see ExtUtils::MY documentation
 sub MY::top_targets {
@@ -51,7 +52,7 @@ sub main {
     }
 
     my $clver = get_cl_version();
-    return warn_cl_version_bad() if $clver lt $minclversion;
+    return warn_cl_version_bad() if ( version->parse($clver) < version->parse($minclversion) );
 
     my $inc = get_cl_inc_paths();
     my $libs = get_cl_libs();
