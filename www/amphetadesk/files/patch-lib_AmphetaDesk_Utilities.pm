--- lib/AmphetaDesk/Utilities.pm.orig	Sun Oct  9 19:45:59 2005
+++ lib/AmphetaDesk/Utilities.pm	Sun Oct  9 19:51:44 2005
@@ -112,7 +112,7 @@
    $hour = sprintf "%02.0d", $hour;
 
    # print the entry to our log file.
-   print LOG "[$hour:$min:$sec] $message\n";
+   print LOG "[$hour:$min:$sec] $message\n" if fileno LOG;
 
    # and save the message in our response log
    # if the message is also being sent to the gui.
@@ -127,7 +127,7 @@
       $os = "MacOS"   if $^O =~ /Mac/;
       $os = "Windows" if $^O =~ /Win/;
       $os = "Linux" unless defined $os;
-      my $packname = "AmphetaDesk::OS::";
+      my $packname = "AmphetaDesk::AmphetaDesk::OS::";
       my $funcname = "::gui_note";
       &{ $packname. $os . $funcname }($message) if $gui;
    }
@@ -151,7 +151,7 @@
       $os = "MacOS"   if $^O =~ /Mac/;
       $os = "Windows" if $^O =~ /Win/;
       $os = "Linux" unless defined $os;
-      my $packname = "AmphetaDesk::OS::";
+      my $packname = "AmphetaDesk::AmphetaDesk::OS::";
       my $funcname = "::gui_note";
       &{ $packname. $os . $funcname }($message);
    }
