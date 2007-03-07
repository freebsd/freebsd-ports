--- src/klamd.cpp.orig	Tue Mar  6 13:12:00 2007
+++ src/klamd.cpp	Tue Mar  6 13:13:55 2007
@@ -742,7 +742,7 @@
 {
 	if (!(dazukoLoaded)){
 		int result;
-		result = KMessageBox::warningContinueCancel(this, i18n( "I need to load a module called 'dazuko' first. This module will allow KlamAV to gain real-time access to files. If you don't want this message to appear in future, put the following command in your initialization scripts: 'modprobe dazuko.o'. You will next be asked for the root password."),
+		result = KMessageBox::warningContinueCancel(this, i18n( "I need to load a module called 'dazuko' first. This module will allow KlamAV to gain real-time access to files. If you don't want this message to appear in future, put the following command in your initialization scripts: 'kldload dazuko.ko'. You will next be asked for the root password."),
 		i18n( "Load Module" ),
 		i18n( "Load Module" ),
 		i18n( "Delete2" ));
@@ -815,7 +815,7 @@
 // 	
 // 	//kdDebug() << release << endl;
 // 	QString insmodCommand="insmod /lib/modules/" + release + "/dazuko.o";
-	QString insmodCommand="modprobe dazuko";
+	QString insmodCommand="kldload dazuko.ko";
 	//QString insmodCommand="insmod /opt/kde/bin/dazuko.o";
 	KProcIO *insmodproc = new KProcIO();
 	
