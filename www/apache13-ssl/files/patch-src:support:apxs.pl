--- src/support/apxs.pl.orig	Mon Nov 29 21:05:12 2004
+++ src/support/apxs.pl	Mon Nov 29 21:05:56 2004
@@ -604,12 +604,10 @@
                 print FP $content;
                 close(FP);
                 if ($^O ne "MSWin32") {
-                    push(@cmds, "cp $cfgbase.conf $cfgbase.conf.bak");
                     push(@cmds, "cp $cfgbase.conf.new $cfgbase.conf");
                     push(@cmds, "rm $cfgbase.conf.new");
                 } else {
                     $cfgbase =~ s|/|\\|g;
-                    push(@cmds, "copy \"$cfgbase.conf\" \"$cfgbase.conf.bak\"");
                     push(@cmds, "copy \"$cfgbase.conf.new\" \"$cfgbase.conf\"");
                     push(@cmds, "del \"$cfgbase.conf.new\"");
                 }
