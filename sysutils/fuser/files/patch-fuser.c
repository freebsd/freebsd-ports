--- fuser.c.orig	2006-03-14 14:07:08.000000000 +0300
+++ fuser.c	2009-12-21 22:51:33.000000000 +0300
@@ -608,6 +608,7 @@
 	char		*ep;
 	char		*kernimg = NULL; /* We are using curr. sys by default */
 	char		*mcore = NULL;
+  int     retvalue = 0;
 
 	while ((ch = getopt(argc, argv, "C:K:cfkms:u")) != -1)
 		switch(ch) {
@@ -696,8 +697,13 @@
 			if (ufl != 0) {
 				print_file_info(pinfo->pid, \
 				    pinfo->uid, ufl);
-				if ((flags & KFLAG) != 0)
-					(void)kill(pinfo->pid, sig);
+				if ((flags & KFLAG) != 0) {
+            if (geteuid() == getuid() || pinfo->uid == getuid()) {
+              (void)kill(pinfo->pid, sig);
+            } else {
+              retvalue = 1;
+            }
+        } 
 			}
 		}
 		(void)fprintf(stderr, "\n");
@@ -707,7 +713,7 @@
 	SLIST_FREE(&prclist, next, pinfo_free);
 	(void)kvm_close(kd);
 
-	return 0;
+	return retvalue;
 		
 }
 
