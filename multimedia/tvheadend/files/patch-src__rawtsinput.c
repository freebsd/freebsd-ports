--- src/rawtsinput.c.orig	2013-04-18 16:23:19.000000000 +0200
+++ src/rawtsinput.c	2013-04-23 13:12:48.224810259 +0200
@@ -276,7 +276,11 @@
 	  slp.tv_sec  =  d / 1000000;
 	  slp.tv_nsec = (d % 1000000) * 1000;
 	
+#ifdef clock_nanosleep
 	  clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &slp, NULL);
+#else
+	  nanosleep(&slp, NULL);
+#endif
 	  didsleep = 1;
 	}
 	t->s_pcr_last = pcr;
