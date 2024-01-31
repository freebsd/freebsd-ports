--- sendmail/daemon.c.orig	2024-01-31 06:38:32 UTC
+++ sendmail/daemon.c
@@ -782,6 +782,8 @@ getrequests(e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLACKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
