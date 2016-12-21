--- plugins/check_ssh.c.orig	2016-11-29 08:45:08 UTC
+++ plugins/check_ssh.c
@@ -255,6 +255,7 @@ ssh_connect (char *haddr, int hport, cha
 			printf
 				(_("SSH CRITICAL - %s (protocol %s) version mismatch, expected '%s'\n"),
 				 ssh_server, ssh_proto, remote_version);
+			recv (sd, output, BUFF_SZ, 0);
 			close(sd);
 			exit (STATE_CRITICAL);
 		}
@@ -273,6 +274,7 @@ ssh_connect (char *haddr, int hport, cha
 			(_("SSH OK - %s (protocol %s) | %s\n"),
 			 ssh_server, ssh_proto, fperfdata("time", elapsed_time, "s",
 			 FALSE, 0, FALSE, 0, TRUE, 0, TRUE, (int)socket_timeout));
+		recv (sd, output, BUFF_SZ, 0);
 		close(sd);
 		exit (STATE_OK);
 	}
