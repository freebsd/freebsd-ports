--- plugins/check_ssh.c.orig	2014-11-30 22:28:21 UTC
+++ plugins/check_ssh.c
@@ -255,6 +255,7 @@ ssh_connect (char *haddr, int hport, cha
 			printf
 				(_("SSH WARNING - %s (protocol %s) version mismatch, expected '%s'\n"),
 				 ssh_server, ssh_proto, remote_version);
+			recv (sd, output, BUFF_SZ, 0);
 			close(sd);
 			exit (STATE_WARNING);
 		}
@@ -273,6 +274,7 @@ ssh_connect (char *haddr, int hport, cha
 			(_("SSH OK - %s (protocol %s) | %s\n"),
 			 ssh_server, ssh_proto, fperfdata("time", elapsed_time, "s",
 			 FALSE, 0, FALSE, 0, TRUE, 0, TRUE, (int)socket_timeout));
+		recv (sd, output, BUFF_SZ, 0);
 		close(sd);
 		exit (STATE_OK);
 	}
