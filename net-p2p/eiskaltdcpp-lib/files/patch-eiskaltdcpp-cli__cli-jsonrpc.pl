--- eiskaltdcpp-cli/cli-jsonrpc.pl.orig	2013-08-29 21:25:02.000000000 +0400
+++ eiskaltdcpp-cli/cli-jsonrpc.pl	2014-08-10 16:43:19.942914548 +0400
@@ -35,8 +35,7 @@
     unshift @INC, 
 	 "$XDG_CONFIG_HOME/eiskaltdc++",
 	 "$HOME/.config/eiskaltdc++/",
-	 "/usr/local/share/eiskaltdcpp/cli",
-	 "/usr/share/eiskaltdcpp/cli"
+	 "/usr/local/etc/eiskaltdcpp"
 }
 
 # preparing terminal
