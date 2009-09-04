--- kioslave/audiocd/audiocd.cpp.orig	2009-09-03 16:55:47.000000000 +0200
+++ kioslave/audiocd/audiocd.cpp	2009-09-03 19:36:22.000000000 +0200
@@ -225,20 +225,21 @@
 	// name associated with the device, which throws the rest of audiocd
 	// for a loop.
 	//
+	QString devname;
 	if ( !(drive->dev) || (COOKED_IOCTL == drive->interface) )
 	{
 		// For ATAPI devices, we have no real choice. Use the
 		// user selected value, even if there is none.
 		//
 		kWarning(7117) << "Found an ATAPI device, assuming it is the one specified by the user.";
-		d->cd.setDevice( d->device );
+		devname = d->device;
 	}
 	else
 	{
 		kDebug(7117) << "Found a SCSI or ATAPICAM device.";
 		if ( strlen(drive->dev->device_path) > 0 )
 		{
-			d->cd.setDevice( drive->dev->device_path );
+			devname = drive->dev->device_path;
 		}
 		else
 		{
@@ -246,13 +247,14 @@
 			// circumstances, so build a representation from
 			// the unit number and SCSI device name.
 			//
-			QString devname = QString::fromLatin1( "/dev/%1%2" )
+			devname = QString::fromLatin1( "/dev/%1%2" )
 				.arg( drive->dev->given_dev_name )
 				.arg( drive->dev->given_unit_number ) ;
 			kDebug(7117) << "  Using derived name " << devname;
-			d->cd.setDevice( devname );
 		}
 	}
+	if (d->cd.deviceName() != devname)
+		d->cd.setDevice( devname );
 #else
 #ifdef __GNUC__
 	#warning audiocd ioslave is not going to work for you
