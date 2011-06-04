--- rkward/rbackend/rkfrontendtransmitter.cpp.orig	2011-05-25 10:18:05.000000000 +0200
+++ rkward/rbackend/rkfrontendtransmitter.cpp	2011-06-04 16:09:46.000000000 +0200
@@ -63,7 +63,7 @@
 	args.append ("--data-dir " + RKSettingsModuleGeneral::filesPath ());
 	backend->setProcessChannelMode (QProcess::MergedChannels);	// at least for now. Seems difficult to get interleaving right, without this.
 	connect (backend, SIGNAL (finished (int, QProcess::ExitStatus)), this, SLOT (backendExit (int)));
-	QString backend_executable = KStandardDirs::findExe (QDir::toNativeSeparators (QCoreApplication::applicationDirPath () + "/rkward.rbackend"));
+	QString backend_executable = "%%PREFIX%%/lib/kde4/libexec//rkward.rbackend";
 	if (backend_executable.isEmpty ()) backend_executable = KStandardDirs::findExe (QDir::toNativeSeparators (QCoreApplication::applicationDirPath () + "/rbackend/rkward.rbackend"));	// for running directly from the build-dir
 	RK_ASSERT (!backend_executable.isEmpty ());
 	backend->start (backend_executable, args, QIODevice::ReadOnly);
