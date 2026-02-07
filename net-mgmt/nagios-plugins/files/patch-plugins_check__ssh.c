--- plugins/check_ssh.c.orig	2020-02-24 15:17:13 UTC
+++ plugins/check_ssh.c
@@ -63,7 +63,7 @@ main (int argc, char **argv)
 {
 	int result = STATE_UNKNOWN;
 
-	setlocale (LC_ALL, "");
+	setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");
 	bindtextdomain (PACKAGE, LOCALEDIR);
 	textdomain (PACKAGE);
 
@@ -252,6 +252,7 @@ ssh_connect (char *haddr, int hport, cha
 			printf
 				(_("SSH CRITICAL - %s (protocol %s) version mismatch, expected '%s'\n"),
 				 ssh_server, ssh_proto, remote_version);
+			recv (sd, output, BUFF_SZ, 0);
 			close(sd);
 			exit (STATE_CRITICAL);
 		}
@@ -270,6 +271,7 @@ ssh_connect (char *haddr, int hport, cha
 			(_("SSH OK - %s (protocol %s) | %s\n"),
 			 ssh_server, ssh_proto, fperfdata("time", elapsed_time, "s",
 			 FALSE, 0, FALSE, 0, TRUE, 0, TRUE, (int)timeout_interval));
+		recv (sd, output, BUFF_SZ, 0);
 		close(sd);
 		exit (STATE_OK);
 	}
