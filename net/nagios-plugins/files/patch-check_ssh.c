--- plugins/check_ssh.c.orig	Fri Jun 21 12:17:43 2002
+++ plugins/check_ssh.c	Fri Jun 21 12:23:16 2002
@@ -246,7 +246,7 @@
 			printf("%s\n", output);
 		ssh_proto = output + 4;
 		ssh_server = ssh_proto + strspn(ssh_proto, "0123456789-. ");
-		ssh_proto[strspn(ssh_proto, "0123456789-. ")] = 0;
+		ssh_proto[strspn(ssh_proto, "0123456789. ")] = 0;
 		printf
 			("SSH ok - protocol version %s - server version %s\n",
 		       ssh_proto, ssh_server);
@@ -272,7 +272,7 @@
 {
 	printf
 		("Usage:\n"
-		 " %s -t [timeout] -p [port] <host>\n"
+		 " %s [-t <timeout>] [-p <port>] <host>\n"
 		 " %s -V prints version info\n"
 		 " %s -h prints more detailed help\n", PROGNAME, PROGNAME, PROGNAME);
 }
