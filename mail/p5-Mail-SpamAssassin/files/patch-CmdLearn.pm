--- lib/Mail/SpamAssassin/CmdLearn.pm.orig	Thu Sep 18 21:02:40 2003
+++ lib/Mail/SpamAssassin/CmdLearn.pm	Fri Jan  2 20:18:28 2004
@@ -43,2 +43,3 @@
              'showdots'                         => \$opt{'showdots'},
+	     'quiet'				=> \$opt{'quiet'},
 	     'no-rebuild|norebuild'		=> \$opt{'norebuild'},
@@ -233,3 +234,3 @@
     print STDERR "\n" if ($opt{showdots});
-    print "Learned from $learnedcount message(s) ($messagecount message(s) examined).\n";
+    print "Learned from $learnedcount message(s) ($messagecount message(s) examined).\n" if (!$opt{quiet});
   };
