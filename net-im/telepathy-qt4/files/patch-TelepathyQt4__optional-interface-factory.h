--- ./TelepathyQt4/optional-interface-factory.h.orig	2012-01-13 15:03:15.336883448 +0100
+++ ./TelepathyQt4/optional-interface-factory.h	2012-01-13 15:03:58.296892805 +0100
@@ -97,7 +97,7 @@
             InterfaceSupportedChecking check = CheckInterfaceSupported) const
     {
         // Check for the remote object supporting the interface
-        QString name(QLatin1String(Interface::staticInterfaceName()));
+        QString name( (QLatin1String(Interface::staticInterfaceName())) );
         if (check == CheckInterfaceSupported && !mInterfaces.contains(name)) {
             return 0;
         }
@@ -113,7 +113,7 @@
         Q_UNUSED(interfaceMustBeASubclassOfAbstractInterface);
 
         // If there is a interface cached already, return it
-        QString name(QLatin1String(Interface::staticInterfaceName()));
+        QString name( (QLatin1String(Interface::staticInterfaceName())) );
         AbstractInterface *cached = getCached(name);
         if (cached)
             return static_cast<Interface *>(cached);
