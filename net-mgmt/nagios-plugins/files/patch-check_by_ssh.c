--- plugins/check_by_ssh.c.orig	Thu Feb 28 07:42:57 2002
+++ plugins/check_by_ssh.c	Sun Jul 14 09:50:43 2002
@@ -382,6 +382,8 @@
 		 "   list of nagios service names, separated by ':' [optional]\n"
 		 "-n, --name=NAME\n"
 		 "   short name of host in nagios configuration [optional]\n"
+		 "-v, --verbose\n"
+		 "   display command being executed\n"
 		 "\n"
 		 "The most common mode of use is to refer to a local identity file with\n"
 		 "the '-i' option. In this mode, the identity pair should have a null\n"
@@ -405,7 +407,7 @@
 {
 	printf
 		("Usage:\n"
-		 "check_by_ssh [-f] [-t timeout] [-i identity] [-l user] -H <host> <command>\n"
+		 "check_by_ssh [-fv] [-t timeout] [-i identity] [-l user] -H <host> <command>\n"
 		 "             [-n name] [-s servicelist] [-O outputfile] [-P port]\n"
 		 "check_by_ssh  -V prints version info\n"
 		 "check_by_ssh  -h prints more detailed help\n");
