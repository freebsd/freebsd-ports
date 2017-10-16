--- sendmail/daemon.c.orig	2016-06-12 18:25:14.196269000 -0400
+++ sendmail/daemon.c	2016-06-12 18:31:47.159880000 -0400
@@ -754,6 +754,10 @@
 						anynet_ntoa(&RealHostAddr));
 			}
 
+#ifdef USE_BLACKLIST
+			blacklist_init();
+#endif
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
