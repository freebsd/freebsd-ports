--- readcd/readcd.c.original	Sun Jan 15 17:14:03 2006
+++ readcd/readcd.c	Sun Jan 15 17:24:47 2006
@@ -370,6 +370,8 @@
 			exit(err);
 		}
 	} else {
+                char	errstr[80];
+
 		if (scsibus == -1 && target >= 0 && lun >= 0)
 			scsibus = 0;
 
@@ -378,8 +380,17 @@
 		scgp->kdebug = kdebug;
 
 		scg_settarget(scgp, scsibus, target, lun);
-		if (scg__open(scgp, NULL) <= 0)
-			comerr("Cannot open SCSI driver.\n");
+
+		scgp = scg_open(dev, errstr, sizeof(errstr), 0, 0);
+
+		if (scgp == NULL) { 
+		         errmsg("%s%sCannot open SCSI driver.\n", errstr, errstr[0]?". ":"");
+		         errmsgno(EX_BAD, "For possible targets try 'readcd -scanbus'.%s\n",
+                                                geteuid() ? " Make sure you are root.":"");
+			 errmsgno(EX_BAD, "For possible transport specifiers try 'readcd dev=help'.\n");
+                        exit(EX_BAD);
+		}
+
 	}
 	scgp->silent = silent;
 	scgp->verbose = verbose;
