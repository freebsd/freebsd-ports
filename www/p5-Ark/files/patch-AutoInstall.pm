--- inc/Module/AutoInstall.pm.orig	2009-06-01 09:53:37.000000000 +0900
+++ inc/Module/AutoInstall.pm	2009-06-07 13:45:32.000000000 +0900
@@ -637,10 +637,10 @@
     require CPAN;
     if ( $CPAN::HandleConfig::VERSION ) {
         # Newer versions of CPAN have a HandleConfig module
-        CPAN::HandleConfig->load;
+#        CPAN::HandleConfig->load;
     } else {
     	# Older versions had the load method in Config directly
-        CPAN::Config->load;
+#        CPAN::Config->load;
     }
 }
 
