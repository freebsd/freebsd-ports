--- sendmail/daemon.c.orig	2021-07-14 05:34:51 UTC
+++ sendmail/daemon.c
@@ -788,6 +788,8 @@ getrequests(e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLACKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
