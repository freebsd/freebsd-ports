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
@@ -555,8 +563,25 @@
 	}
       dontneedgroup();
       dontneedroot();
+#if defined (__FreeBSD__)
+      /*
+       * i_read_c_block(), used by paranoia_read_limited() for reading the
+       * data from the CD, doesn't use a page aligned buffer as required by
+       * FreeBSD for SCSI transfers (well, most OS do). Probably this should
+       * be dealt with in cdda_read() (called by i_read_c_block() with the
+       * unaligned buffer and in turn calls ReadCdRom() to do the actual read)
+       * but it seems like overkill to add yet another buffer (would make it
+       * 3 or so from do_read() to ReadCdRom() alone). Instead, limit the
+       * transfer size via the maximum for the sectors to read at once to a
+       * value that lets the data fit into a page (for FreeBSD the code below
+       * would set the maximum sectors to 27).
+       */
+      if (global.nsectors > 26)
+        global.nsectors = 26;
+#else
       if (global.nsectors > (unsigned) scg_bufsize(scgp, 3*1024*1024)/CD_FRAMESIZE_RAW)
         global.nsectors = scg_bufsize(scgp, 3*1024*1024)/CD_FRAMESIZE_RAW;
+#endif
       if (global.overlap >= global.nsectors)
         global.overlap = global.nsectors-1;
 
@@ -593,9 +618,6 @@
          exit(RACE_ERROR);
       }
 #endif
-	if (scgp != NULL && global.scsi_verbose) {
-		scgp->verbose = global.scsi_verbose;
-	}
   }
   return retval;
 }
@@ -888,6 +910,7 @@
 		FatalError("No memory for SCSI structure.\n");
 	}
 	scgp->silent = 0;
+	scgp->verbose = global.scsi_verbose;
 	SetupCookedIoctl( global.dev_name );
 #else
 	FatalError("Sorry, there is no known method to access the device.\n");
