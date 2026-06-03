--- sendmail/daemon.c.orig	2026-03-09 16:19:10 UTC
+++ sendmail/daemon.c
@@ -781,6 +781,8 @@ getrequests(ENVELOPE *e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLOCKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
