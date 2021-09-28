--- spampd.pl.orig	2021-09-28 04:11:50 UTC
+++ spampd.pl
@@ -470,6 +470,7 @@ sub new {
       userstate_dir        =>
         '/var/spool/spamassassin/spampd',         # home directory for SA files and plugins (--homedir option)
       home_dir_for_helpers => '',                 # this will be set to the same as userstate_dir once options are parsed
+      user_dir             => (getpwnam($user))[7],
       username             => '',                 # this will be set to the same user as we're running as once options are parsed
       userprefs_filename   => undef,              # add this config file for SA "user_prefs" settings (--saconfig option)
       dont_copy_prefs      => 1,                  # tell SA not to copy user pref file into its working dir
