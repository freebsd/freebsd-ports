#
# Fix pipefail option
#
# http://lists.gnu.org/archive/html/bug-bash/2004-08/msg00215.html
#
--- jobs.c.orig	Fri Apr 23 21:28:25 2004
+++ jobs.c	Wed Aug 18 14:32:19 2004
@@ -1778,8 +1778,11 @@
   if (pipefail_opt)
     {
       fail = 0;
-      for (p = jobs[job]->pipe; p->next != jobs[job]->pipe; p = p->next)
-        if (p->status != EXECUTION_SUCCESS) fail = p->status;
+      p = jobs[job]->pipe;
+      do {
+       if (p->status != EXECUTION_SUCCESS) fail = p->status;
+       p=p->next;
+      } while(p!=jobs[job]->pipe);
       return fail;
     }
 
