--- plugins/check_by_ssh.c.orig	Fri Jun 21 11:19:56 2002
+++ plugins/check_by_ssh.c	Fri Jun 21 11:54:25 2002
@@ -191,7 +191,7 @@
 	if (commands>1)
 		remotecmd=strscat(remotecmd,";echo STATUS CODE: $?;");
 
-	if (strlen (remotecmd) <= 1)
+	if (remotecmd==NULL)
 		usage ("No remotecmd\n");
 
 	comm = ssprintf(comm,"%s %s '%s'",comm,hostname,remotecmd);
@@ -369,6 +369,8 @@
 		 "   list of netsaint service names, separated by ':' [optional]\n"
 		 "-n, --name=NAME\n"
 		 "   short name of host in netsaint configuration [optional]\n"
+		 "-v, --verbose\n"
+		 "   short name of host in netsaint configuration [optional]\n"
 		 "\n"
 		 "The most common mode of use is to refer to a local identity file with\n"
 		 "the '-i' option. In this mode, the identity pair should have a null\n"
@@ -388,7 +390,7 @@
 
 
 #define OPTIONS "\
--H <host> [-P port] [-f] [-y] [-t timeout] [-i identity]\n
+-H <host> -C <command> [-fyv] [-P port] [-t timeout] [-i identity]\n
              [-l user] [-n name] [-s servicelist] [-O outputfile]"
 
 void print_usage(void)
