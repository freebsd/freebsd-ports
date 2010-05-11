--- knetworkconf/knetworkconf/knetworkconfigparser.cpp.orig	2009-07-28 21:43:49.000000000 +0200
+++ knetworkconf/knetworkconf/knetworkconfigparser.cpp	2010-01-13 19:20:10.911935722 +0100
@@ -21,6 +21,9 @@
 #include <QPixmap>
 #include <QTextStream>
 #include <Q3PtrList>
+#ifdef Q_OS_FREEBSD
+#include <QProcess>
+#endif
 
 KNetworkConfigParser::KNetworkConfigParser(){
   networkInfo = new KNetworkInfo();
@@ -184,7 +187,8 @@
 }
 
 /**
-  Reads /proc/net/route looking for the default gateway.
+  Reads /proc/net/route or parses the output of /sbin/route (FreeBSD)
+  looking for the default gateway.
 
   NOTE:We should use the gateway reported by gst, but if there's a
   gw in a config file and one of the network interfaces is
@@ -193,22 +197,77 @@
 */
 void KNetworkConfigParser::loadRoutingInfo( KRoutingInfo *routingInfo){
 //  routingInfo = NULL;
-  QFile f( "/proc/net/route");
+#ifdef Q_OS_FREEBSD
+  QProcess *route = new QProcess(this);
+  QString routeBin = "/sbin/route";
+  bool success = false;
+  QByteArray output;
+  // Check for an IPv6 configuration.
+  route->start(routeBin, QStringList() << "get" << "-inet6" << "default");
+  if (route->waitForStarted(1000))
+  {
+    route->waitForFinished(1000);
+    output = route->readAllStandardOutput();
+  }
+  if (output.isEmpty())
+  {
+    // IPv6 is not enabled, check for an IPv4 configuration.
+    route = new QProcess(this);
+    route->start(routeBin, QStringList() << "get" << "default");
+    if (route->waitForStarted(1000))
+    {
+      route->waitForFinished(1000);
+      output = route->readAllStandardOutput();
+    }
+  }
+  if (!output.isEmpty())
+  {
+    QTextStream t(output);
+    QString gw, interface;
+    while (!t.atEnd())
+    {
+      QString s = t.readLine();
+      QString row = s.section(' ', 0, 0, QString::SectionSkipEmpty);
+      if (row == "gateway:")
+      {
+        gw = s.section(' ', 1, 1, QString::SectionSkipEmpty);
+      }
+      else if (row == "interface:")
+      {
+        interface = s.section(' ', 1, 1, QString::SectionSkipEmpty);
+      }
+      if (!gw.isEmpty() && !interface.isEmpty())
+      {
+        routingInfo->setGateway(gw);
+        routingInfo->setGatewayDevice(interface);
+        success = true;
+        break;
+      }
+    }
+  }
+  if (!success)
+  {
+    KMessageBox::error(0,
+                        i18n("Could not get information from %1.", routeBin),
+                        i18n("Could Not Get Information"));
+  }
+#else
+  QString fname = "/proc/net/route";
+  QFile f(fname);
   if ( !f.open(QIODevice::ReadOnly) )
   {
 //    return routingInfo;
     KMessageBox::error(0,
-                        i18n("Could not open file /proc/net/route."),
+                        i18n("Could not open file %1.", fname),
                         i18n("Could Not Open File"));
   }
   else
   {
 //    routingInfo = new KRoutingInfo();
     QTextStream t( &f );        // use a text stream
-    QString s;
     while (!t.atEnd())
     {
-      s = t.readLine();       // line of text excluding '\n'
+      QString s = t.readLine();       // line of text excluding '\n'
       QString interface = s.section('\t',0,0);
       QString destination = s.section('\t',1,1);
       QString gw = s.section('\t',2,2);
@@ -222,6 +281,7 @@
     }
   }
   f.close();
+#endif
 }
 QString
 KNetworkConfigParser::hexIPv4ToDecIPv4(const QString &hex)
