--- cdda2wav/interface.c	Mon Dec 29 11:28:09 2003
+++ cdda2wav/interface.c	Sun Jan 18 01:35:50 2004
@@ -444,7 +444,15 @@
     default:			/* for example ATAPI cds */
 #else
 #if defined (__FreeBSD__)
-    case 117:
+#if __FreeBSD_version >= 501113
+    case 4:	/* GEOM */
+	if (memcmp(pdev_name, "/dev/acd", sizeof("/dev/acd") - 1) != 0) {
+	    fprintf(stderr, "%s is not an ATAPI CDROM device\n", pdev_name);
+	    exit(SYNTAX_ERROR);
+	}
+	/* FALLTHROUGH */
+#endif
+    case 117:	/* pre-GEOM atapi cd */
 	if (!S_ISCHR(statstruct->st_mode)) {
 	    fprintf(stderr, "%s is not a char device\n",pdev_name);
 	    exit(SYNTAX_ERROR);
@@ -593,9 +601,6 @@
          exit(RACE_ERROR);
       }
 #endif
-	if (scgp != NULL && global.scsi_verbose) {
-		scgp->verbose = global.scsi_verbose;
-	}
   }
   return retval;
 }
@@ -888,6 +893,7 @@
 		FatalError("No memory for SCSI structure.\n");
 	}
 	scgp->silent = 0;
+	scgp->verbose = global.scsi_verbose;
 	SetupCookedIoctl( global.dev_name );
 #else
 	FatalError("Sorry, there is no known method to access the device.\n");
