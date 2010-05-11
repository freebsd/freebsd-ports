--- kioslave/audiocd/audiocd.cpp.orig	2009-12-31 13:30:01.000000000 +0000
+++ kioslave/audiocd/audiocd.cpp	2010-01-11 00:05:10.235745679 +0000
@@ -215,52 +215,6 @@
 	return encoderFromExtension(filename.right(len - pos));
 }
 
-static void setDeviceToCd(KCompactDisc *cd, struct cdrom_drive *drive)
-{
-#if defined(HAVE_CDDA_IOCTL_DEVICE)
-	cd->setDevice(drive->ioctl_device_name, 50, false);
-#elif defined(__FreeBSD__) || defined(__DragonFly__)
-	// FreeBSD's cdparanoia as of january 5th 2006 has rather broken
-	// support for non-SCSI devices. Although it finds ATA cdroms just
-	// fine, there is no straightforward way to discover the device
-	// name associated with the device, which throws the rest of audiocd
-	// for a loop.
-	//
-	if ( !(drive->dev) || (COOKED_IOCTL == drive->interface) )
-	{
-		// For ATAPI devices, we have no real choice. Use the
-		// user selected value, even if there is none.
-		//
-		kWarning(7117) << "Found an ATAPI device, assuming it is the one specified by the user.";
-		cd->setDevice( d->device );
-	}
-	else
-	{
-		kDebug(7117) << "Found a SCSI or ATAPICAM device.";
-		if ( strlen(drive->dev->device_path) > 0 )
-		{
-			cd->setDevice( drive->dev->device_path );
-		}
-		else
-		{
-			// But the device_path can be empty under some
-			// circumstances, so build a representation from
-			// the unit number and SCSI device name.
-			//
-			QString devname = QString::fromLatin1( "/dev/%1%2" )
-				.arg( drive->dev->given_dev_name )
-				.arg( drive->dev->given_unit_number ) ;
-			kDebug(7117) << "  Using derived name " << devname;
-			cd->setDevice( devname );
-		}
-	}
-#else
-#ifdef __GNUC__
-	#warning audiocd ioslave is not going to work for you
-#endif
-#endif
-}
-
 struct cdrom_drive * AudioCDProtocol::initRequest(const KUrl & url)
 {
 	if (url.hasHost())
@@ -284,7 +238,53 @@
 	{
 		// Update our knowledge of the disc
 		KCompactDisc cd(KCompactDisc::Asynchronous);
-		setDeviceToCd(&cd, drive);
+#if defined(HAVE_CDDA_IOCTL_DEVICE)
+		cd.setDevice(drive->ioctl_device_name, 50, false);
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+		// FreeBSD's cdparanoia as of january 5th 2006 has
+		// rather broken support for non-SCSI devices.
+		// Although it finds ATA cdroms just fine, there is
+		// no straightforward way to discover the device name
+		// associated with the device, which throws the rest
+		// of audiocd for a loop.
+		//
+		QString devname;
+		if ( !(drive->dev) || (COOKED_IOCTL == drive->interface) )
+		{
+			// For ATAPI devices, we have no real choice.
+			// Use the user selected value, even if there
+			// is none.
+			//
+			kWarning(7117) << "Found an ATAPI device, assuming it is the one specified by the user.";
+			devname = d->device;
+		}
+		else
+		{
+			kDebug(7117) << "Found a SCSI or ATAPICAM device.";
+			if ( strlen(drive->dev->device_path) > 0 )
+			{
+				devname = drive->dev->device_path;
+			}
+			else
+			{
+				// But the device_path can be empty
+				// under some circumstances, so build
+				// a representation from the unit
+				// number and SCSI device name.
+				//
+				devname = QString::fromLatin1( "/dev/%1%2" )
+					.arg( drive->dev->given_dev_name )
+					.arg( drive->dev->given_unit_number ) ;
+				kDebug(7117) << "  Using derived name " << devname;
+			}
+		}
+		if ( cd.deviceName() != devname )
+			cd.setDevice( devname );
+#else
+#ifdef __GNUC__
+	#warning audiocd ioslave is not going to work for you
+#endif
+#endif
 		d->setToc(drive);
 		
 		d->tracks = cd.tracks();
