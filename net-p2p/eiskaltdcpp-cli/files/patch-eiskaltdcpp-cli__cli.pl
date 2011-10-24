--- ./eiskaltdcpp-cli/cli.pl.orig	2011-10-02 18:12:43.000000000 +0300
+++ ./eiskaltdcpp-cli/cli.pl	2011-10-06 09:30:39.000000000 +0300
@@ -36,8 +36,7 @@
     unshift @INC, 
 	 "$XDG_CONFIG_HOME/eiskaltdc++",
 	 "~/.config/eiskaltdc++/",
-	 "/usr/local/share/eiskaltdcpp/cli",
-	 "/usr/share/eiskaltdcpp/cli"
+	 "/usr/local/etc/eiskaltdcpp"
 }
 
 # preparing terminal
