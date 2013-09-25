--- plugins/check_ssh.c.orig	2012-06-27 21:32:47.000000000 +0400
+++ plugins/check_ssh.c	2013-09-25 17:03:01.000000000 +0400
@@ -250,6 +250,7 @@ ssh_connect (char *haddr, int hport, cha
 			printf
 				(_("SSH WARNING - %s (protocol %s) version mismatch, expected '%s'\n"),
 				 ssh_server, ssh_proto, remote_version);
+			recv (sd, output, BUFF_SZ, 0);
 			close(sd);
 			exit (STATE_WARNING);
 		}
@@ -260,6 +261,7 @@ ssh_connect (char *haddr, int hport, cha
 			(_("SSH OK - %s (protocol %s) | %s\n"),
 			 ssh_server, ssh_proto, fperfdata("time", elapsed_time, "s",
 			 FALSE, 0, FALSE, 0, TRUE, 0, TRUE, (int)socket_timeout));
+		recv (sd, output, BUFF_SZ, 0);
 		close(sd);
 		exit (STATE_OK);
 	}
