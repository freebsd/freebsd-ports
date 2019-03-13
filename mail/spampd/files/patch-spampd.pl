--- spampd.pl.orig	2019-03-12 15:58:04 UTC
+++ spampd.pl
@@ -877,6 +877,7 @@ my $sa_options = {
   'debug'                => $debug,
   'local_tests_only'     => $sa_local_only,
   'home_dir_for_helpers' => $sa_home_dir,
+  'user_dir'             => (getpwnam($user))[7],
   'userstate_dir'        => $sa_home_dir,
   'username'             => $user
 };
