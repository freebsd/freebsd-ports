--- plugins/check_ssh.c.orig	Thu Feb 28 07:42:59 2002
+++ plugins/check_ssh.c	Sun Jul 14 09:59:41 2002
@@ -250,7 +250,7 @@
 			printf ("%s\n", output);
 		ssh_proto = output + 4;
 		ssh_server = ssh_proto + strspn (ssh_proto, "0123456789-. ");
-		ssh_proto[strspn (ssh_proto, "0123456789-. ")] = 0;
+		ssh_proto[strspn (ssh_proto, "0123456789. ")] = 0;
 		printf
 			("SSH ok - protocol version %s - server version %s\n",
 			 ssh_proto, ssh_server);
@@ -277,7 +277,7 @@
 {
 	printf
 		("Usage:\n"
-		 " %s -t [timeout] -p [port] <host>\n"
+		 " %s [-t <timeout>] [-p <port>] <host>\n"
 		 " %s -V prints version info\n"
 		 " %s -h prints more detailed help\n", PROGNAME, PROGNAME, PROGNAME);
 }
