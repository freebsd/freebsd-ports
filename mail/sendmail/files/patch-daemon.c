--- sendmail/daemon.c.orig	2015-02-28 00:50:03 UTC
+++ sendmail/daemon.c
@@ -754,6 +754,8 @@ getrequests(e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLACKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
