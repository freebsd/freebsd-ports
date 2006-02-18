--- readcd/readcd.c.original	Sun Jan 15 17:14:03 2006
+++ readcd/readcd.c	Sun Jan 15 17:24:47 2006
@@ -253,9 +256,9 @@
 	int	fcount;
 	int	cac;
 	char	* const *cav;
-	int	scsibus	= 0;
-	int	target	= 0;
-	int	lun	= 0;
+	int	scsibus	= -1;
+	int	target	= -1;
+	int	lun	= -1;
 	int	silent	= 0;
 	int	verbose	= 0;
 	int	kdebug	= 0;
@@ -335,20 +338,22 @@
 				usage(EX_BAD);
 				/* NOTREACHED */
 			}
-		} else {
-			scsibus = 0;
 		}
 		cac--;
 		cav++;
 	}
 /*error("dev: '%s'\n", dev);*/
-
 	if (!scanbus)
 		cdr_defaults(&dev, NULL, NULL, NULL);
 	if (debug) {
 		printf("dev: '%s'\n", dev);
 	}
-	if (dev) {
+	if (!scanbus && dev == NULL &&
+	    scsibus == -1 && (target == -1 || lun == -1)) {
+		errmsgno(EX_BAD, "No SCSI device specified.\n");
+		usage(EX_BAD);
+	}
+	if (dev || scanbus) {
 		char	errstr[80];
 
 		/*
@@ -357,8 +362,9 @@
 		 * remote routines that are located inside libscg.
 		 */
 		scg_remote();
-		if ((strncmp(dev, "HELP", 4) == 0) ||
-		    (strncmp(dev, "help", 4) == 0)) {
+		if (dev != NULL &&
+		    ((strncmp(dev, "HELP", 4) == 0) ||
+		    (strncmp(dev, "help", 4) == 0))) {
 			scg_help(stderr);
 			exit(0);
 		}
@@ -1629,7 +1656,7 @@
 		end = scgp->cap->c_baddr + 1;
 	scgp->silent--;
 
-	if (end <= 0 || isrange || (askrange && scg_yes("Ignore disk size? ")))
+	if ((end <= 0 && isrange) || (askrange && scg_yes("Ignore disk size? ")))
 		end = 10000000;	/* Hack to read empty (e.g. blank=fast) disks */
 
 	if (parmp) {
