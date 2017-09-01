--- unetbootin.cpp.orig	2017-07-14 08:54:12 UTC
+++ unetbootin.cpp
@@ -301,8 +301,13 @@ bool unetbootin::ubninitialize(QList<QPair<QString, QS
 	#endif
 	sevzcommand = locatecommand("7z", tr("either"), "p7zip-full");
 #endif // Q_OS_LINUX
+#ifdef Q_OS_FREEBSD
+	syslinuxcommand = locatecommand("syslinux", tr("FAT32-formatted USB drive"), "syslinux");
+	sevzcommand = locatecommand("7z", tr("either"), "p7zip");
+	mke2fscommand = locatecommand("mke2fs", tr("LiveUSB persistence"), "e2fsprogs");
+#endif // Q_OS_FREEBSD
 	ubntmpf = QDir::toNativeSeparators(QString("%1/").arg(QDir::tempPath()));
-    #ifdef Q_OS_LINUX
+    #ifdef Q_OS_UNIX
     if (ubntmpf.isEmpty() || ubntmpf == "/")
     {
         ubntmpf = "/tmp/";
@@ -649,6 +654,57 @@ QStringList unetbootin::listsanedrives()
 				}
 				*/
 		#endif
+#ifdef Q_OS_FREEBSD
+		struct xvfsconf fsconf;
+		struct statfs *fslist;
+
+		/*
+		 * Find out VFS number assigned by kernel for MSDOSFS,
+		 * because it's faster to compare numbers than strings.
+		 * This also helps to ensure that it is configured in
+		 * the kernel.
+		 */
+		if (getvfsbyname("msdosfs", &fsconf) == -1)
+			goto out;
+
+		/*
+		 * Quick sanity check of the number of active mountpoints
+		 * using the filesystem (we need mounted storage to work).
+		 */
+		if (fsconf.vfc_refcount < 1)
+			goto out;
+
+		int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+		if (numfs < 1)
+			goto out;
+
+		QRegExp pendrives_sdcards("^/dev/(da|mmcsd)\\d+");
+
+		for (int i = 0; i < numfs; ++i)
+		{
+			/*
+			 * We're interested in MSDOSFS (FAT) filesystems
+			 * that are mounted off removable storage (e.g.,
+			 * USB memsticks, SD cards).  Assume that device
+			 * names for those are /dev/da* and /dev/mmcsd*.
+			 * (Perhaps not entirely accurate assumption.)
+			 */
+			if ((int)fslist[i].f_type == fsconf.vfc_typenum &&
+				QString(fslist[i].f_mntfromname)
+				.contains(pendrives_sdcards))
+			{
+				/*
+				 * Unlike other implementations above, we
+				 * append tuples of device name *and* the
+				 * mount point, so we do not have to find
+				 * mount point separately later.
+				 */
+				fulldrivelist.append(QString("%1:%2")
+					.arg(fslist[i].f_mntfromname)
+					.arg(fslist[i].f_mntonname));
+			}
+		}
+#endif
 #ifdef Q_OS_MAC
 QString systemprofilertext = callexternapp("system_profiler", "SPStorageDataType");
 QRegExp filesystemregex("File System: (.+)\\n");
@@ -669,6 +725,7 @@ for (int i = 0; i < filesystemlist.size(); ++i)
 }
 #endif
 	}
+out:
 	return fulldrivelist;
 }
 
@@ -3412,21 +3469,36 @@ void unetbootin::instIndvfl(QString srcfName, QString 
 				srcF.setFileName(QFile::exists("/usr/share/syslinux/memdisk") ? "/usr/share/syslinux/memdisk" : "/usr/lib/syslinux/memdisk");
 	else if (srcfName == "menu.c32")
 	{
+#ifdef Q_OS_LINUX
 				srcF.setFileName(QFile::exists("/usr/share/syslinux/menu.c32") ? "/usr/share/syslinux/menu.c32" : "/usr/lib/syslinux/menu.c32");
 				if (QFile::exists("/usr/lib/syslinux/modules/bios/menu.c32"))
 					srcF.setFileName("/usr/lib/syslinux/modules/bios/menu.c32");
+#endif
+#ifdef Q_OS_FREEBSD
+		srcF.setFileName(LOCALBASE "/share/syslinux/bios/com32/menu/menu.c32");
+#endif
 	}
     else if (srcfName == "libutil.c32")
 	{
+#ifdef Q_OS_LINUX
                 srcF.setFileName(QFile::exists("/usr/share/syslinux/libutil.c32") ? "/usr/share/syslinux/libutil.c32" : "/usr/lib/syslinux/libutil.c32");
 		if (QFile::exists("/usr/lib/syslinux/modules/bios/libutil.c32"))
 			srcF.setFileName("/usr/lib/syslinux/modules/bios/libutil.c32");
+#endif
+#ifdef Q_OS_FREEBSD
+		srcF.setFileName(LOCALBASE "/share/syslinux/bios/com32/libutil/libutil.c32");
+#endif
 	}
     else if (srcfName == "libcom32.c32")
 	{
+#ifdef Q_OS_LINUX
                 srcF.setFileName(QFile::exists("/usr/share/syslinux/libcom32.c32") ? "/usr/share/syslinux/libcom32.c32" : "/usr/lib/syslinux/libcom32.c32");
 		if (QFile::exists("/usr/lib/syslinux/modules/bios/libcom32.c32"))
 			srcF.setFileName("/usr/lib/syslinux/modules/bios/libcom32.c32");
+#endif
+#ifdef Q_OS_FREEBSD
+		srcF.setFileName(LOCALBASE "/share/syslinux/bios/com32/lib/libcom32.c32");
+#endif
 	}
     else if (srcfName == "mbr.bin")
 	{
@@ -3516,11 +3588,19 @@ void unetbootin::runinst()
 	}
 	if (installType == tr("USB Drive"))
 	{
+#ifdef Q_OS_LINUX
 		targetDev = driveselect->currentText();
 		devluid = getdevluid(targetDev);
 		ginstallDir = "";
 		installDir = ginstallDir;
 		targetDrive = QString("%1/").arg(locatemountpoint(targetDev));
+#endif
+#ifdef Q_OS_FREEBSD
+		QStringList driveinfo = driveselect->currentText().split(":");
+		targetDev = driveinfo.at(0);
+		installDir = ginstallDir = "";
+		targetDrive = QString("%1/").arg(driveinfo.at(1));
+#endif
 	}
 #ifdef Q_OS_LINUX
 	if (targetDev.contains(QRegExp("p\\d$")))
@@ -3528,7 +3608,7 @@ void unetbootin::runinst()
 	else
 		rawtargetDev = QString(targetDev).remove(QRegExp("\\d$"));
 #endif
-#ifdef Q_OS_MAC
+#ifdef Q_OS_UNIX
 	rawtargetDev = QString(targetDev).remove(QRegExp("s\\d$"));
 #endif
 	#endif
@@ -4281,21 +4361,47 @@ void unetbootin::runinstusb()
             instIndvfl("libutil.c32", QString("%1libutil.c32").arg(targetPath));
             instIndvfl("libcom32.c32", QString("%1libcom32.c32").arg(targetPath));
         }
+	setuppersspace();
+#ifdef Q_OS_FREEBSD
+		/*
+		 * On FreeBSD, we only support installing on MSDOSFS (no
+		 * extlinux in the ports).  This also simplifies things
+		 * a bit, and that's what most users usually want anyway.
+		 *
+		 * Because of syslinux' stupidity, we have to remove any
+		 * existing ldlinux.c32 and ldlinux.sys files, otherwise
+		 * it will fail to install loader (even with -f switch).
+		 * Then we have to unmount the filesystem to avoid the
+		 * "Operation not permitted" error, and must enforce it
+		 * because syslinux expects a block device, and, well,
+		 * there are no "block devices" in FreeBSD.
+		 */
+		rmFile(targetPath + "ldlinux.c32");
+		rmFile(targetPath + "ldlinux.sys");
+		callexternapp("umount", targetDev);
+		callexternapp(syslinuxcommand, "-i -f " + targetDev);
+
+		if (rawtargetDev != targetDev)
+		{
+			/*
+			 * We have partition table (not operating on raw
+			 * disk), so we need to install MBR and mark our
+			 * partition as active.  Assume our targetDev is
+			 * /dev/{da,mmcsd}XsY and use the last digit as
+			 * partition index for gpart(8).
+			 */
+			QString idx = targetDev.right(1);
+			callexternapp("gpart",
+				"bootcode -b /boot/mbr " + rawtargetDev);
+			callexternapp("gpart", "set -a "
+				"active -i " + idx + " " + rawtargetDev);
+		}
+#endif
 	fininstall();
 }
 
-void unetbootin::killApplication()
+void unetbootin::setuppersspace()
 {
-	exit(0);
-}
-
-void unetbootin::fininstall()
-{
-	#ifdef Q_OS_UNIX
-	this->tprogress->setValue(this->tprogress->maximum()*2/3);
-	pdesc1->setText(tr("Syncing filesystems"));
-	callexternapp("sync", "");
-	#endif
 	if (this->persistenceSpaceMB > 0)
 	{
 		pdesc1->setText(tr("Setting up persistence"));
@@ -4334,6 +4440,20 @@ void unetbootin::fininstall()
 		rmFile(mke2fscommand);
 #endif
 	}
+}
+
+void unetbootin::killApplication()
+{
+	exit(0);
+}
+
+void unetbootin::fininstall()
+{
+	#ifdef Q_OS_UNIX
+	this->tprogress->setValue(this->tprogress->maximum()*2/3);
+	pdesc1->setText(tr("Syncing filesystems"));
+	callexternapp("sync", "");
+	#endif
 	pdesc1->setText("");
 	progresslayer->setEnabled(false);
 	progresslayer->hide();
