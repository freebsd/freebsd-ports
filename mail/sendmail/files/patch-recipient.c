--- sendmail/recipient.c	29 May 2002 18:20:03 -0000	8.330
+++ sendmail/recipient.c	27 Aug 2002 20:21:02 -0000	8.330.2.1
@@ -679,7 +679,7 @@
 	**  the current recipient is marked expensive.
 	*/
 
-	if (WILL_BE_QUEUED(e->e_sendmode) ||
+	if (UseMSP || WILL_BE_QUEUED(e->e_sendmode) ||
 	    (!bitset(EF_SPLIT, e->e_flags) && e->e_ntries == 0 &&
 	     FastSplit > 0))
 		sortfn = sorthost;
