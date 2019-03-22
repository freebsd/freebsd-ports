--- unetbootin.cpp.orig	2018-04-28 01:24:54 UTC
+++ unetbootin.cpp
@@ -9,6 +9,11 @@ This program is distributed in the hope that it will b
 
 #include "unetbootin.h"
 
+#include <QMessageBox>
+#include <QFileDialog>
+#include <QProgressDialog>
+#include <QDebug>
+
 static const QList<QRegExp> ignoredtypesbothRL = QList<QRegExp>()
 << QRegExp("isolinux.bin$", Qt::CaseInsensitive)
 << QRegExp("isolinux.cfg$", Qt::CaseInsensitive)
@@ -101,8 +106,8 @@ void callexternappT::run()
 void callexternappWriteToStdinT::run()
 {
 	QProcess lnexternapp;
-    lnexternapp.start("\"" + execFile + "\" " + execParm);
-	lnexternapp.write(writeToStdin.toAscii().data());
+	lnexternapp.start("\"" + execFile + "\" " + execParm);
+	lnexternapp.write(writeToStdin.toLatin1().data());
 	lnexternapp.closeWriteChannel();
 	lnexternapp.waitForFinished(-1);
 	retnValu = QString(lnexternapp.readAll());
@@ -133,16 +138,6 @@ void copyfileT::run()
 	emit finished();
 }
 
-ubngetrequestheader::ubngetrequestheader(QString urhost, QString urpath)
-{
-	this->setRequest("GET", urpath);
-	this->setValue("HOST", urhost);
-	this->setValue("User-Agent", "UNetbootin/1.1.1");
-//	this->setValue("User-Agent", "Wget/1.10.2");
-	this->setValue("Accept", "*/*");
-	this->setValue("Connection", "Keep-Alive");
-}
-
 randtmpfile::randtmpfile(QString rfpath, QString rfextn)
 {
 	QString basefn = getrandfilename(rfpath, rfextn);
@@ -159,7 +154,7 @@ QString randtmpfile::getrandfilename(QString rfpath, Q
 	}
 	return basefn;
 }
-
+/*
 void nDirListStor::sAppendSelfUrlInfoList(QUrlInfo curDirUrl)
 {
 	if (curDirUrl.isValid() && curDirUrl.isReadable() && curDirUrl.isFile() && curDirUrl.size() > nMinFileSizeBytes && curDirUrl.size() < nMaxFileSizeBytes)
@@ -171,7 +166,7 @@ void nDirListStor::sAppendSelfUrlInfoList(QUrlInfo cur
 		nDirFileListSL.append(curDirUrl.name());
 	}
 }
-
+*/
 unetbootin::unetbootin(QWidget *parent)
 	: QWidget(parent)
 {
@@ -301,8 +296,13 @@ bool unetbootin::ubninitialize(QList<QPair<QString, QS
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
@@ -471,19 +471,23 @@ bool unetbootin::ubninitialize(QList<QPair<QString, QS
 		{
 			if (psecond.contains("listdistros", Qt::CaseInsensitive))
 			{
+				QTextStream out(stdout);
 				for (int i = 1; i < this->distroselect->count(); ++i)
 				{
-					printf("%s\n", this->distroselect->itemText(i).toAscii().constData());
+					out << this->distroselect->itemText(i) << endl;
 				}
+				out.flush();
 				QApplication::exit();
 				exit(0);
 			}
 			else if (psecond.contains("listversions", Qt::CaseInsensitive))
 			{
+				QTextStream out(stdout);
 				for (int i = 0; i < this->dverselect->count(); ++i)
 				{
-					printf("%s\n", this->dverselect->itemText(i).toAscii().constData());
+					out << this->dverselect->itemText(i) << endl;
 				}
+				out.flush();
 				QApplication::exit();
 				exit(0);
 			}
@@ -649,6 +653,57 @@ QStringList unetbootin::listsanedrives()
 				}
 				*/
 		#endif
+#ifdef Q_OS_FREEBSD
+		struct xvfsconf fsconf;
+		struct statfs *fslist;
+
+		/*
+		 * Make sure that MSDOSFS is configured with the kernel.
+		 * As a nice side effect, this would allow to compare a
+		 * number (assigned by VFS) instead of "msdosfs" string
+		 * when iterating over mounted filesystems.
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
@@ -669,6 +724,7 @@ for (int i = 0; i < filesystemlist.size(); ++i)
 }
 #endif
 	}
+out:
 	return fulldrivelist;
 }
 
@@ -700,17 +756,17 @@ QStringList unetbootin::listalldrives()
 	return fulldrivelist;
 }
 
-void unetbootin::on_typeselect_currentIndexChanged(int typeselectIndex)
+void unetbootin::on_typeselect_currentIndexChanged(int)
 {
 	refreshdriveslist();
 }
 
-void unetbootin::on_dverselect_currentIndexChanged()
+void unetbootin::on_dverselect_currentIndexChanged(int)
 {
 	radioDistro->setChecked(true);
 }
 
-void unetbootin::on_diskimagetypeselect_currentIndexChanged()
+void unetbootin::on_diskimagetypeselect_currentIndexChanged(int)
 {
 	radioFloppy->setChecked(true);
 }
@@ -1098,9 +1154,14 @@ bool unetbootin::checkifoutofspace(QString destindir)
 	bool outofspace = false;
 	#ifdef Q_OS_UNIX
 	struct statfs diskstatS;
-	if (!statfs(QString(destindir+"/.").toAscii(), &diskstatS))
+	if (!statfs(QString(destindir+"/.").toLatin1(), &diskstatS))
 	{
-		if (diskstatS.f_bavail * diskstatS.f_bfree < 1024)
+		/*
+		 * Refuse to work if available disk space is less than 1MB
+		 * (1024KB).  Even this seems very low, but original value
+		 * of 1024 bytes was simply ridiculous.
+		 */
+		if (diskstatS.f_bsize / 1024 * diskstatS.f_bavail < 1024)
 			outofspace = true;
 	}
 	#endif
@@ -2620,31 +2681,27 @@ void unetbootin::downloadfile(QString fileurl, QString
 	{
 		rmFile(targetfile);
 	}
-	QUrl dlurl(fileurl);
-	bool isftp = false;
-	if (dlurl.scheme() == "ftp")
-	{
-		isftp = true;
-	}
-	QHttp dlhttp;
-	QFtp dlftp;
+	QNetworkAccessManager manager;
+	QNetworkRequest dlurl(fileurl);
+	QNetworkReply * networkReply = manager.get(dlurl);
+
 	QEventLoop dlewait;
 	pdesc5->setText("");
 	pdesc4->setText(tr("Downloading files, please wait..."));
 	pdesc3->setText(tr("<b>Source:</b> <a href=\"%1\">%1</a>").arg(fileurl));
 	pdesc2->setText(tr("<b>Destination:</b> %1").arg(targetfile));
 	pdesc1->setText(tr("<b>Downloaded:</b> 0 bytes"));
-	QString realupath = QString(fileurl).remove(0, fileurl.indexOf(QString("://%1").arg(dlurl.host())) + QString("://%1").arg(dlurl.host()).length());
-	if (isftp)
-	{
-		connect(&dlftp, SIGNAL(done(bool)), &dlewait, SLOT(quit()));
-		connect(&dlftp, SIGNAL(dataTransferProgress(qint64, qint64)), this, SLOT(dlprogressupdate64(qint64, qint64)));
-	}
-	else
-	{
-		connect(&dlhttp, SIGNAL(done(bool)), &dlewait, SLOT(quit()));
-		connect(&dlhttp, SIGNAL(dataReadProgress(int, int)), this, SLOT(dlprogressupdate(int, int)));
-	}
+
+	QUrl redirectUrl;
+	bool downloadFailed = false;
+	QNetworkReply::NetworkError errorCode;
+
+	connect(networkReply, &QNetworkReply::finished, &dlewait, &QEventLoop::quit);
+	connect(networkReply, &QNetworkReply::downloadProgress, this, &unetbootin::dlprogressupdate64);
+	connect(networkReply, &QNetworkReply::redirected, [&](const QUrl &url){ redirectUrl = url; });
+	connect(networkReply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
+			[&](QNetworkReply::NetworkError code){ downloadFailed = true; errorCode = code; });
+
 	QFile dloutfile;
 	if (installType == tr("USB Drive"))
 	{
@@ -2655,82 +2712,38 @@ void unetbootin::downloadfile(QString fileurl, QString
 		dloutfile.setFileName(targetfile);
 	}
 	dloutfile.open(QIODevice::WriteOnly);
-	if (isftp)
-	{
-		dlftp.connectToHost(dlurl.host());
-		dlftp.login();
-		dlftp.get(realupath, &dloutfile);
-	}
-	else
-	{
-		dlhttp.setHost(dlurl.host());
-		ubngetrequestheader dlrequest(dlurl.host(), realupath);
-		dlhttp.request(dlrequest, 0, &dloutfile);
-	}
+
+	connect(networkReply, &QNetworkReply::downloadProgress, [&](qint64, qint64){
+		dloutfile.write(networkReply->readAll());
+	});
+
 	dlewait.exec();
-	if (!isftp)
+
+	if (!redirectUrl.isEmpty())
 	{
-		QHttpResponseHeader dlresponse(dlhttp.lastResponse());
-		int dlrstatus = dlresponse.statusCode();
-		if (dlrstatus >= 300 && dlrstatus < 400 && dlresponse.hasKey("Location"))
-		{
-			dloutfile.close();
-			rmFile(dloutfile);
-			downloadfile(dlresponse.value("Location"), targetfile, minsize);
-			return;
-		}
+		networkReply->deleteLater();
+		downloadfile(redirectUrl.toString(), targetfile, minsize);
+		return;
 	}
-	if (isftp)
+
+	if (downloadFailed)
 	{
-		dlftp.close();
+		qDebug() << "Failed to download URL: " << fileurl;
+		qDebug() << "Error code: " << errorCode;
+		qDebug() << "Error string: " << networkReply->errorString();
+		networkReply->deleteLater();
+		showDownloadFailedScreen(fileurl);
+		return;
 	}
-	else
-	{
-		dlhttp.close();
-	}
+
+	dloutfile.write(networkReply->readAll());
+	networkReply->deleteLater();
 	dloutfile.close();
 	if (installType == tr("USB Drive"))
 	{
 		dloutfile.rename(targetfile);
 	}
-    if (QFile(targetfile).size() <= 4096)
-    {
-        QString redirectTargetURL;
-        QFile seeRedirect(targetfile);
-        seeRedirect.open(QIODevice::ReadOnly | QIODevice::Text);
-        QTextStream seeRedirectTextStream(&seeRedirect);
-        while (!seeRedirectTextStream.atEnd())
-        {
-            QString curline = seeRedirectTextStream.readLine();
-            if (curline.contains("content=\"0;url="))
-            {
-                int urlstartidx = curline.indexOf("content=\"0;url=") + QString("content=\"0;url=").size();
-                redirectTargetURL = curline.mid(urlstartidx);
-                if (redirectTargetURL.contains("\""))
-                {
-                    redirectTargetURL = redirectTargetURL.left(redirectTargetURL.indexOf("\""));
-                }
-                break;
-            }
-            if (curline.contains("content='0;url="))
-            {
-                int urlstartidx = curline.indexOf("content='0;url=") + QString("content='0;url=").size();
-                redirectTargetURL = curline.mid(urlstartidx);
-                if (redirectTargetURL.contains("'"))
-                {
-                    redirectTargetURL = redirectTargetURL.left(redirectTargetURL.indexOf("'"));
-                }
-                break;
-            }
-        }
-        seeRedirect.close();
-        if (!redirectTargetURL.isEmpty())
-        {
-            rmFile(targetfile);
-            downloadfile(redirectTargetURL, targetfile, minsize);
-            return;
-        }
-    }
+
 	if (QFile(targetfile).size() < minsize)
 	{
 		// download failed
@@ -2745,7 +2758,8 @@ void unetbootin::downloadfile(QString fileurl, QString
 	if (testingDownload)
 	{
 		// Note that this only tests that the first download succeeds
-		printf("exitstatus:downloadcomplete\n");
+		QTextStream out(stdout);
+		out << "exitstatus:downloadcomplete" << endl << flush;
 		QApplication::exit();
 		exit(0);
 	}
@@ -2761,40 +2775,26 @@ void unetbootin::showDownloadFailedScreen(const QStrin
 	this->downloadFailed = true;
 	if (exitOnCompletion)
 	{
-		printf("exitstatus:downloadfailed\n");
+		QTextStream out(stdout);
+		out << "exitstatus:downloadfailed" << endl << flush;
 		QApplication::exit();
 		exit(0);
 	}
 }
 
-void unetbootin::dlprogressupdate(int dlbytes, int maxbytes)
-{
- QTime time = QTime::currentTime();
- static int oldsec = 0;
- // refresh the progress bar every second
- if(oldsec != time.second())
- {
-   oldsec = time.second();
-     tprogress->setValue(dlbytes);
-     tprogress->setMaximum(maxbytes);
-   // display the downloaded size with suffix
-     pdesc1->setText(tr("<b>Downloaded:</b> %1 of %2").arg(displayfisize(dlbytes)).arg(displayfisize(maxbytes)));
- }
-}
-
 void unetbootin::dlprogressupdate64(qint64 dlbytes, qint64 maxbytes)
 {
- QTime time = QTime::currentTime();
- static int oldsec = 0;
- // refresh the progress bar every second
- if(oldsec != time.second())
- {
-   oldsec = time.second();
-     tprogress->setValue(dlbytes);
-     tprogress->setMaximum(maxbytes);
-   // display the downloaded size with suffix
-     pdesc1->setText(tr("<b>Downloaded:</b> %1 of %2").arg(displayfisize(dlbytes)).arg(displayfisize(maxbytes)));
- }
+	QTime time = QTime::currentTime();
+	static int oldsec = 0;
+	// refresh the progress bar every second
+	if(oldsec != time.second())
+	{
+		oldsec = time.second();
+		tprogress->setValue(dlbytes);
+		tprogress->setMaximum(maxbytes);
+		// display the downloaded size with suffix
+		pdesc1->setText(tr("<b>Downloaded:</b> %1 of %2").arg(displayfisize(dlbytes)).arg(displayfisize(maxbytes)));
+	}
 }
 
 void unetbootin::cpprogressupdate64(qint64 dlbytes, qint64 maxbytes)
@@ -2812,31 +2812,35 @@ void unetbootin::cpprogressupdate64(qint64 dlbytes, qi
  }
 }
 
-QString unetbootin::downloadpagecontents(QString pageurl)
+QString unetbootin::downloadpagecontents(QUrl pageurl)
 {
-	QUrl pgurl(pageurl);
-	QHttp pghttp;
+	QNetworkAccessManager manager;
+	QNetworkRequest dlurl(pageurl);
+	QNetworkReply * networkReply = manager.get(dlurl);
 	QEventLoop pgwait;
-	connect(&pghttp, SIGNAL(done(bool)), &pgwait, SLOT(quit()));
-	pghttp.setHost(pgurl.host());
-	QString realpgupath = QString(pageurl).remove(0, pageurl.indexOf(QString("://%1").arg(pgurl.host())) + QString("://%1").arg(pgurl.host()).length());
-	ubngetrequestheader pgrequest(pgurl.host(), realpgupath);
-	pghttp.request(pgrequest);
+	QUrl redirectUrl;
+	connect(networkReply, &QNetworkReply::finished, &pgwait, &QEventLoop::quit);
+	connect(networkReply, &QNetworkReply::redirected, [&redirectUrl](const QUrl &url){ redirectUrl = url; });
+
 	pgwait.exec();
-	QHttpResponseHeader pgresponse(pghttp.lastResponse());
-	int pgrstatus = pgresponse.statusCode();
-	if (pgrstatus >= 300 && pgrstatus < 400 && pgresponse.hasKey("Location"))
+
+	if (!redirectUrl.isEmpty())
 	{
-		return downloadpagecontents(pgresponse.value("Location"));
+		networkReply->deleteLater();
+		return downloadpagecontents(redirectUrl);
 	}
-	else
-	{
-		return QString(pghttp.readAll());
-	}
+
+	QString result = networkReply->readAll();
+	networkReply->close();
+	networkReply->deleteLater();
+	return result;
 }
 
 QStringList unetbootin::lstFtpDirFiles(QString ldfDirStringUrl, int ldfMinSize, int ldfMaxSize)
 {
+	qDebug() << "lstFtpDirFiles called for " << ldfDirStringUrl;
+	return {};
+/*
 	QUrl ldfDirUrl(ldfDirStringUrl);
 	QFtp ldfFtp;
 	QEventLoop ldfWait;
@@ -2851,14 +2855,14 @@ QStringList unetbootin::lstFtpDirFiles(QString ldfDirS
 	ldfFtp.list(ldfDirUrl.path());
 	ldfWait.exec();
 	ldfFtp.close();
-	return nDirListStorL.nDirFileListSL;
+	return nDirListStorL.nDirFileListSL;*/
 }
 
 QStringList unetbootin::lstHttpDirFiles(QString ldfDirStringUrl)
 {
 	QStringList relativefilelinksL;
 	QStringList relativelinksLPreFilter =
-		downloadpagecontents(ldfDirStringUrl)
+		downloadpagecontents(QUrl(ldfDirStringUrl))
 		.replace(">", ">\n")
 		.replace("<", "\n<")
 		.split("\n");
@@ -3218,11 +3222,11 @@ int unetbootin::letterToNumber(QChar lettertoconvert)
 {
 	if (lettertoconvert.isLower())
 	{
-		return static_cast<int>(lettertoconvert.toAscii() - 'a');
+		return static_cast<int>(lettertoconvert.toLatin1() - 'a');
 	}
 	if (lettertoconvert.isUpper())
 	{
-		return static_cast<int>(lettertoconvert.toAscii() - 'A');
+		return static_cast<int>(lettertoconvert.toLatin1() - 'A');
 	}
 	else
 	{
@@ -3412,21 +3416,36 @@ void unetbootin::instIndvfl(QString srcfName, QString 
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
@@ -3516,11 +3535,19 @@ void unetbootin::runinst()
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
@@ -3528,7 +3555,7 @@ void unetbootin::runinst()
 	else
 		rawtargetDev = QString(targetDev).remove(QRegExp("\\d$"));
 #endif
-#ifdef Q_OS_MAC
+#ifdef Q_OS_UNIX
 	rawtargetDev = QString(targetDev).remove(QRegExp("s\\d$"));
 #endif
 	#endif
@@ -3724,7 +3751,7 @@ void unetbootin::writegrub2cfg()
 	QString menulstxt = QString(
 	"%9\n\n"
 #ifndef NODEFAULTBOOT
-	"\nmenuentry \""UNETBOOTINB"\" {\n"
+	"\nmenuentry \"" UNETBOOTINB "\" {\n"
 	"\tset root=%8\n"
 	"\t%1 %2 %3 %4\n"
 	"\t%5 %6 %7\n"
@@ -3845,7 +3872,7 @@ void unetbootin::runinsthdd()
 	"timeout 10\n"
 	#endif
 #ifndef NODEFAULTBOOT
-	"\ntitle "UNETBOOTINB"\n"
+	"\ntitle " UNETBOOTINB "\n"
 	#ifdef Q_OS_WIN32
 	"find --set-root %3\n"
 	#endif
@@ -4281,21 +4308,47 @@ void unetbootin::runinstusb()
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
@@ -4334,6 +4387,20 @@ void unetbootin::fininstall()
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
@@ -4343,7 +4410,7 @@ void unetbootin::fininstall()
 	sdesc4->setText(QString("<b>%1 %2</b>").arg(sdesc4->text()).arg(trcurrent));
 	if (installType == tr("Hard Disk"))
 	{
-		rebootmsgtext->setText(tr("After rebooting, select the "UNETBOOTINB" menu entry to boot.%1").arg(postinstmsg));
+		rebootmsgtext->setText(tr("After rebooting, select the " UNETBOOTINB " menu entry to boot.%1").arg(postinstmsg));
 	}
 	if (installType == tr("USB Drive"))
 	{
@@ -4357,7 +4424,8 @@ void unetbootin::fininstall()
     finishLogging();
 	if (exitOnCompletion)
 	{
-		printf("exitstatus:success\n");
+		QTextStream out(stdout);
+		out << "exitstatus:success" << endl << flush;
 		QApplication::exit();
 		exit(0);
 	}
