--- plugins/check_by_ssh.c.orig	Wed Nov 20 02:19:07 2002
+++ plugins/check_by_ssh.c	Tue Nov 26 14:20:28 2002
@@ -361,6 +361,8 @@
 		 "   list of nagios service names, separated by ':' [optional]\n"
 		 "-n, --name=NAME\n"
 		 "   short name of host in nagios configuration [optional]\n"
+		 "-v, --verbose\n"
+		 "   display command being executed\n"
 		 "-4, --use-ipv4\n"
 		 "   tell ssh to use IPv4\n"
 		 "-6, --use-ipv6\n"
@@ -388,7 +390,7 @@
 {
 	printf
 		("Usage:\n"
-		 "check_by_ssh [-f46] [-t timeout] [-i identity] [-l user] -H <host> -C <command>\n"
+		 "check_by_ssh [-fv46] [-t timeout] [-i identity] [-l user] -H <host> -C <command>\n"
 		 "             [-n name] [-s servicelist] [-O outputfile] [-p port]\n"
 		 "check_by_ssh  -V prints version info\n"
 		 "check_by_ssh  -h prints more detailed help\n");
