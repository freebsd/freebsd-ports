--- lib/AmphetaDesk/OS/Linux.pm.orig	Thu May 23 23:35:38 2002
+++ lib/AmphetaDesk/OS/Linux.pm	Tue Oct 11 18:46:17 2005
@@ -15,11 +15,26 @@
 use strict;
 use AmphetaDesk::Settings;
 use AmphetaDesk::Utilities;
+use POSIX ":sys_wait_h";
+use POSIX ":unistd_h";
 require Exporter;
 use vars qw( @ISA @EXPORT );
 @ISA = qw( Exporter );
 @EXPORT = qw( gui_init gui_listen gui_note open_url );
 
+# taken from perlipc man page
+sub sigchild {
+  my $child;
+
+  # If a second child dies while in the signal handler caused by the
+  # first death, we won't get another signal. So must loop here else
+  # we will leave the unreaped child as a zombie. And the next time
+  # two children die we get another zombie. And so on.
+  while (($child = waitpid(-1,WNOHANG)) > 0) {}
+
+  $SIG{CHLD} = \&sigchild;
+}
+
 ###############################################################################
 # gui_init - start the gui and display the window.                            #
 ###############################################################################
@@ -105,8 +120,41 @@
    # construct our url.
    my $url = "http://127.0.0.1:" . get_setting("urls_port") . "/index.html";
 
+   # default browser
+   my $browser;
+
    # we spit out our suggestion just to catch all instances.
    note("If your browser doesn't load, go to <$url>.", 1);
+
+   # what browser?
+   if ($ENV{'BROWSER'}) {
+     $browser = $ENV{'BROWSER'};
+   } else {
+     if (get_setting("user_browser_path")) {
+       $browser = get_setting("user_browser_path");
+     }
+   }
+
+   if ( ($browser) && ( (-x $browser) || (-X $browser) ) ) {
+     note("Your environment states that $browser is your default program.");
+
+     $SIG{CHLD} = \&sigchild;
+
+     if (fork() == 0) {
+       my @args = ("$browser", "$url");
+
+       setsid();
+       close(STDIN);
+       close(STDOUT);
+       close(STDERR);
+
+       exec(@args) == 0
+         or note("The browser <$browser> does not exist. Please select another.");
+
+       exit 1;
+     }
+
+   }
 
    return 1;
 
