Index: kweather.cpp
===================================================================
RCS file: /home/kde/kdetoys/kweather/kweather.cpp,v
retrieving revision 1.47
retrieving revision 1.48
diff -u -r1.47 -r1.48
--- kweather.cpp	8 Jan 2003 12:40:57 -0000	1.47
+++ kweather/kweather.cpp	24 Jan 2003 21:55:43 -0000	1.48
@@ -672,7 +672,7 @@
                 if (!client->isApplicationRegistered("KWeatherService"))
                 {
                         kdDebug() << "Could not find service so I am starting it..." << endl;
-                        if(!KApplication::startServiceByName("KWeatherService",QStringList(), &error,&appID ))
+                        if(!KApplication::startServiceByDesktopName("kweatherservice",QStringList(), &error,&appID ))
 
                         {
                                 kdDebug() << "Starting KWeatherService failed with message: " << error << endl;
