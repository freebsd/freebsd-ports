$FreeBSD$

--- proc.c	Tue Jun  4 20:07:29 2002
+++ proc.c	Tue Jun  4 20:14:09 2002
@@ -89,13 +89,13 @@
     int pid;
     extern int insource;
     int save_errno = errno;
-    union wait w;
+    int w;
     int     jobflags;
     struct rusage ru;
 
 loop:
     errno = 0;			/* reset, just in case */
-    pid = wait3(&w.w_status,
+    pid = wait3(&w,
        (setintr && (intty || insource) ? WNOHANG | WUNTRACED : WNOHANG), &ru);
 
     if (pid <= 0) {
@@ -117,7 +117,7 @@
     pp->p_flags &= ~(PRUNNING | PSTOPPED | PREPORTED);
     if (WIFSTOPPED(w)) {
 	pp->p_flags |= PSTOPPED;
-	pp->p_reason = w.w_stopsig;
+	pp->p_reason = WSTOPSIG(w);
     }
     else {
 	if (pp->p_flags & (PTIME | PPTIME) || adrof(STRtime))
@@ -125,16 +125,16 @@
 
 	pp->p_rusage = ru;
 	if (WIFSIGNALED(w)) {
-	    if (w.w_termsig == SIGINT)
+	    if (WTERMSIG(w) == SIGINT)
 		pp->p_flags |= PINTERRUPTED;
 	    else
 		pp->p_flags |= PSIGNALED;
-	    if (w.w_coredump)
+	    if (WCOREDUMP(w))
 		pp->p_flags |= PDUMPED;
-	    pp->p_reason = w.w_termsig;
+	    pp->p_reason = WTERMSIG(w);
 	}
 	else {
-	    pp->p_reason = w.w_retcode;
+	    pp->p_reason = WEXITSTATUS(w);
 	    if (pp->p_reason != 0)
 		pp->p_flags |= PAEXITED;
 	    else
