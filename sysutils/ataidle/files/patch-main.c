
$FreeBSD$

--- main.c
+++ main.c
@@ -52,7 +52,7 @@
 	long opt_val;
 	int ch;
 	struct ata_ident ident;
-	const char * const optstr = "hA:S:sI:iP:o";
+	const char * const optstr = "hA:S:sI:iP:owW";
 
 	/* need more than just the executable name */
 	if( argc == 1 )
@@ -151,6 +151,24 @@
 				}
 				break;
 
+			/* Write Cache Disable */
+			case 'w':
+				if (!(ident.cmd_supp1 & ATA_WC_SUPPORTED)) {
+					warnx("the device does not support write cache");
+					break;
+				}
+				rc = ata_setwc(ata, 0);
+				break;
+			
+			/* Write Cache Enable */
+                        case 'W':
+                                if (!(ident.cmd_supp1 & ATA_WC_SUPPORTED)) {
+                                        warnx("the device does not support write cache");
+                                        break;
+                                }
+                                rc = ata_setwc(ata, 1);
+                                break;
+
 			case 'h':
 			default:
 				usage();
