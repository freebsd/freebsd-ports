--- Session/Generate/ModUniqueId.pm~	Mon Sep 20 14:27:20 2004
+++ Session/Generate/ModUniqueId.pm	Mon Sep 20 14:27:31 2004
@@ -8,7 +8,7 @@
     my $session = shift;
     unless (exists $ENV{UNIQUE_ID}) {
 	require Carp;
-	Carp::croak 'Can\'t get UNIQUE_ID env variable. Make sure mod_unique_id is enabled.';
+	Carp::croak('Can\'t get UNIQUE_ID env variable. Make sure mod_unique_id is enabled.');
     }
     $session->{data}->{_session_id} = $ENV{UNIQUE_ID};
 }
