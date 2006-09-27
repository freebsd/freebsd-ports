--- dev/ipmi/ipmi_ssif.c.orig	2006-09-22 15:11:29.000000000 -0700
+++ dev/ipmi/ipmi_ssif.c	2006-09-25 19:10:59.000000000 -0700
@@ -183,7 +183,7 @@
 		return (0);
 	count = SMBUS_DATA_SIZE;
 	error = smbus_error(smbus_bread(smbus,
-	    sc->ipmi_ssif_smbus_address, SMBUS_READ_START, &count, ssif_buf));
+	    sc->ipmi_ssif_smbus_address, SMBUS_READ_START, count, ssif_buf));
 	if (error == ENXIO || error == EBUSY) {
 		smbus_release_bus(smbus, dev);
 #ifdef SSIF_DEBUG
@@ -259,7 +259,7 @@
 		/* Read another packet via READ_CONT. */
 		count = SMBUS_DATA_SIZE;
 		error = smbus_error(smbus_bread(smbus,
-		    sc->ipmi_ssif_smbus_address, SMBUS_READ_CONT, &count,
+		    sc->ipmi_ssif_smbus_address, SMBUS_READ_CONT, count,
 		    ssif_buf));
 		if (error) {
 #ifdef SSIF_ERROR_DEBUG
