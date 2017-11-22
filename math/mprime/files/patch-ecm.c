--- ecm.c.orig	2016-05-02 04:44:52 UTC
+++ ecm.c
@@ -1068,7 +1068,7 @@ int setN (
         }
 
 	if (IniGetInt (INI_FILE, "PhiExtensions", 0) &&
-	    w->k == 1.0 && abs(w->c) == 1 && (w->n%3) == 0) {		/*=== this input means Phi(3,-b^(n/3)) ===*/
+	    w->k == 1.0 && labs(w->c) == 1 && (w->n%3) == 0) {		/*=== this input means Phi(3,-b^(n/3)) ===*/
 		giant	tmp = allocgiant ((bits >> 5) + 5);
 		if (tmp == NULL) return (OutOfMemory (thread_num));
 		ultog (w->b, tmp);
@@ -1156,7 +1156,7 @@ int setN (
 /* Open file of known factors.  This code has been obsoleted by the */
 /* known factors list in worktodo.ini. */
 
-	if (w->k != 1.0 || w->b != 2 || abs(w->c) != 1) return (0);
+	if (w->k != 1.0 || w->b != 2 || labs(w->c) != 1) return (0);
 	fd = fopen (w->c == 1 ? "lowp.txt" : "lowm.txt", "r");
 	if (fd == NULL) return (0);
 
