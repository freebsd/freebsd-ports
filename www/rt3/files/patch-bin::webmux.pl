$FreeBSD$

--- bin/webmux.pl.in.orig	Sat Feb 14 01:31:23 2004
+++ bin/webmux.pl.in	Thu Dec 25 23:01:15 2003
@@ -32,6 +32,9 @@
     $ENV{'ENV'}    = '' if defined $ENV{'ENV'};
     $ENV{'IFS'}    = '' if defined $ENV{'IFS'};
     @ORACLE_ENV_PREF@
+
+    eval { require Apache2; require Apache::compat }
+        if $ENV{'MOD_PERL'} and $ENV{'MOD_PERL'} =~ m{mod_perl/(?:2|1\.9)};
 }
 
 use lib ("@LOCAL_LIB_PATH@", "@RT_LIB_PATH@");
