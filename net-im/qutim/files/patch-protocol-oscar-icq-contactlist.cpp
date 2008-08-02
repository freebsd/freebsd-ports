--- protocol/oscar/icq/contactlist.cpp.orig	2008-07-22 19:34:21.000000000 +0400
+++ protocol/oscar/icq/contactlist.cpp	2008-07-22 20:14:46.000000000 +0400
@@ -16,6 +16,7 @@
 //#include <QtGui>
 #include <QTcpSocket>
 #include <QNetworkProxy>
+#include <sys/time.h>
 #include "treegroupitem.h"
 #include "treebuddyitem.h"
 #include "icqmessage.h"
@@ -1559,8 +1560,14 @@
 		msg->message = codec->toUnicode(socket->read(length - 1));
 		
 		QDateTime curTime = QDateTime::currentDateTime();
+		
+		// Use POSIX-compatible way to get daylight saving correction
+		struct timeval tp;
+		struct timezone tzp;
+		gettimeofday(&tp, &tzp);
+		
 		int offset = (curTime.toLocalTime().time().hour() - curTime.toUTC().time().hour()) * 3600 + 
-			(curTime.toLocalTime().time().minute() - curTime.toUTC().time().minute()) * 60 - daylight * 3600;
+			(curTime.toLocalTime().time().minute() - curTime.toUTC().time().minute()) * 60 - tzp.tz_dsttime * 3600;
 		offlineDateTime = offlineDateTime.addSecs(offset);
 		
 		msg->date = offlineDateTime;
