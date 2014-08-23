--- eiskaltdcpp-cli/cli-xmlrpc.pl.orig	2013-08-29 21:25:02.000000000 +0400
+++ eiskaltdcpp-cli/cli-xmlrpc.pl	2014-08-10 16:45:28.978906623 +0400
@@ -36,8 +36,7 @@
     unshift @INC, 
 	 "$XDG_CONFIG_HOME/eiskaltdc++",
 	 "~/.config/eiskaltdc++/",
-	 "/usr/local/share/eiskaltdcpp/cli",
-	 "/usr/share/eiskaltdcpp/cli"
+	 "/usr/local/etc/eiskaltdcpp"
 }
 
 # preparing terminal
