--- ./plugins/check_ssh.c.orig	2014-03-04 22:41:57.000000000 +0100
+++ ./plugins/check_ssh.c	2014-05-20 23:08:11.000000000 +0200
@@ -255,6 +255,7 @@
 			printf
 				(_("SSH WARNING - %s (protocol %s) version mismatch, expected '%s'\n"),
 				 ssh_server, ssh_proto, remote_version);
+			recv (sd, output, BUFF_SZ, 0);
 			close(sd);
 			exit (STATE_WARNING);
 		}
@@ -273,6 +274,7 @@
 			(_("SSH OK - %s (protocol %s) | %s\n"),
 			 ssh_server, ssh_proto, fperfdata("time", elapsed_time, "s",
 			 FALSE, 0, FALSE, 0, TRUE, 0, TRUE, (int)socket_timeout));
+		recv (sd, output, BUFF_SZ, 0);
 		close(sd);
 		exit (STATE_OK);
 	}
