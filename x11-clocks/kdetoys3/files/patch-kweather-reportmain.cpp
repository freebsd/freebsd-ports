Index: reportmain.cpp
===================================================================
RCS file: /home/kde/kdetoys/kweather/reportmain.cpp,v
retrieving revision 1.4
retrieving revision 1.5
diff -u -r1.4 -r1.5
--- reportmain.cpp	9 Dec 2002 06:55:56 -0000	1.4
+++ kweather/reportmain.cpp	24 Jan 2003 21:55:43 -0000	1.5
@@ -1,4 +1,4 @@
-/* $Id: reportmain.cpp,v 1.4 2002/12/09 06:55:56 mlaurent Exp $ */
+/* $Id: reportmain.cpp,v 1.5 2003/01/24 21:55:43 cloose Exp $ */
 
 #include <stdlib.h>
 #include <kapplication.h>
@@ -27,7 +27,7 @@
 	QCString appID = "";
 	if (!client->isApplicationRegistered("kweatherservice"))
 			{
-				if(KApplication::startServiceByName("kweatherservice",QStringList(), &error, &appID ))
+				if(KApplication::startServiceByDesktopName("kweatherservice",QStringList(), &error, &appID ))
 				{
 					kdDebug() << "Starting kweatherservice failed with message: " << error << endl;
 					exit(0);
