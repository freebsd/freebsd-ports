
$FreeBSD$

--- testsmb.c.orig	Mon Aug  2 09:54:32 2004
+++ testsmb.c	Mon Aug  2 09:55:00 2004
@@ -126,7 +126,7 @@
 		break;
 	default:
 		fprintf(stderr, "No known SMBus(I2C) chip found.\n");
-		goto exit;
+		continue;
 	}
 
 	if(OpenIO() == -1) return -1;
@@ -141,7 +141,6 @@
 	}
 	
 	CloseIO();
-exit:
 
   } /* endo of Big roop for smb_base candidates */
   exit (0);
