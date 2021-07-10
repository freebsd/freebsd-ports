--- sendmail/daemon.c.orig	2021-06-22 08:24:43 UTC
+++ sendmail/daemon.c
@@ -775,6 +775,8 @@ getrequests(e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLACKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
