--- src/lib/jcr.c.orig	2009-03-06 15:00:47.000000000 -0500
+++ src/lib/jcr.c	2009-04-11 20:34:50.407999331 -0400
@@ -1063,8 +1063,8 @@
       fprintf(fp, "\tuse_count=%i\n",
               jcr->use_count());
 #else
-      fprintf(fp, "\tuse_count=%i threadid=0x%x\n",
-              jcr->use_count(), (int)jcr->my_thread_id);
+      fprintf(fp, "\tuse_count=%i threadid=0x%lx\n",
+              jcr->use_count(), (long)jcr->my_thread_id);
 #endif
       fprintf(fp, "\tJobType=%c JobLevel=%c\n",
               jcr->get_JobType(), jcr->get_JobLevel());
