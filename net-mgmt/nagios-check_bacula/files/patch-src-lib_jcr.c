--- src/lib/jcr.c.orig	2009-05-13 19:00:23.000000000 +0200
+++ src/lib/jcr.c	2009-05-13 19:00:43.000000000 +0200
@@ -1064,7 +1064,7 @@
               jcr->use_count());
 #else
       fprintf(fp, "\tuse_count=%i threadid=0x%x\n",
-              jcr->use_count(), (int)jcr->my_thread_id);
+              jcr->use_count(), jcr->my_thread_id);
 #endif
       fprintf(fp, "\tJobType=%c JobLevel=%c\n",
               jcr->get_JobType(), jcr->get_JobLevel());
