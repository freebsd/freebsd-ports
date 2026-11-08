--- sendmail/daemon.c.orig	2026-04-20 17:18:50 UTC
+++ sendmail/daemon.c
@@ -776,6 +776,8 @@ getrequests(ENVELOPE *e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLOCKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
