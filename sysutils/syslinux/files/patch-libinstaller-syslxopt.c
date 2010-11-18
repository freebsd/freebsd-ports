--- libinstaller/syslxopt.c.orig	2010-10-20 21:25:38.000000000 +0200
+++ libinstaller/syslxopt.c	2010-11-16 15:09:16.897550744 +0100
@@ -44,6 +44,8 @@
     .activate_partition = 0,
     .force = 0,
     .bootsecfile = NULL,
+    .verbose = 0,
+    .bimage = NULL,
 };
 
 const struct option long_options[] = {
@@ -57,7 +59,7 @@
     {"stupid", 0, NULL, 's'},
     {"heads", 1, NULL, 'H'},
     {"raid-mode", 0, NULL, 'r'},
-    {"version", 0, NULL, 'v'},
+    {"version", 0, NULL, 'V'},
     {"help", 0, NULL, 'h'},
     {"once", 1, NULL, OPT_ONCE},
     {"clear-once", 0, NULL, 'O'},
@@ -65,10 +67,12 @@
     {"menu-save", 1, NULL, 'M'},
     {"mbr", 0, NULL, 'm'},	/* DOS/Win32 only */
     {"active", 0, NULL, 'a'},	/* DOS/Win32 only */
+    {"verbose", 0, NULL, 'v' },
+    {"bimage", 1, NULL, 'b' },
     {0, 0, 0, 0}
 };
 
-const char short_options[] = "t:fid:UuzsS:H:rvho:OM:ma";
+const char short_options[] = "t:fid:UuzsS:H:rVho:OM:mavb:";
 
 void __attribute__ ((noreturn)) usage(int rv, enum syslinux_mode mode)
 {
@@ -109,7 +113,9 @@
 	    "  --raid       -r  Fall back to the next device on boot failure\n"
 	    "  --once=...   %s  Execute a command once upon boot\n"
 	    "  --clear-once -O  Clear the boot-once command\n"
-	    "  --reset-adv      Reset auxilliary data\n",
+	    "  --reset-adv      Reset auxilliary data\n"
+	    "  --bimage=#   -b  Load a custom boot image\n"
+	    "  --verbose    -v  Increase verbosity level\n",
 	    mode == MODE_SYSLINUX  ? "  " : "-o");
     /*
      * Have to chop this roughly in half for the DOS installer due
@@ -209,11 +215,17 @@
 	case 'a':
 	    opt.activate_partition = 1;
 	    break;
-	case 'v':
+	case 'V':
 	    fprintf(stderr,
 		    "%s " VERSION_STR "  Copyright 1994-" YEAR_STR
 		    " H. Peter Anvin et al\n", program);
 	    exit(0);
+	case 'v':
+	    opt.verbose = 1;
+	    break;
+	case 'b':
+	    opt.bimage = optarg;
+	    break;
 	default:
 	    fprintf(stderr, "%s: Unknown option: -%c\n", program, optopt);
 	    usage(EX_USAGE, mode);
