--- knemod/interfacetooltip.cpp.orig	Fri Jan 21 17:51:13 2005
+++ knemod/interfacetooltip.cpp	Fri Jan 21 17:59:47 2005
@@ -99,6 +99,23 @@
 
     if ( data.available )
     {
+#ifdef Q_OS_FREEBSD
+        QDictIterator<AddrData> it( data.addrData );
+        for( ; it.current(); ++it )
+        {
+            if ( toolTipContent & IP_ADDRESS )
+                text += "<tr><td>" + mToolTips[4].first + "</td><td>" + it.currentKey() + "</td></tr>";
+            if ( toolTipContent & SUBNET_MASK )
+                text += "<tr><td>" + mToolTips[5].first + "</td><td>" + it.current()->subnetMask + "</td></tr>";
+            if ( mInterface->getType() == Interface::ETHERNET )
+            {
+                if ( toolTipContent & BCAST_ADDRESS )
+                    text += "<tr><td>" + mToolTips[18].first + "</td><td>" + it.current()->broadcastAddress + "</td></tr>";
+            }
+        }
+        if ( mInterface->getType() == Interface::ETHERNET )
+        {
+#else
         if ( toolTipContent & IP_ADDRESS )
             text += "<tr><td>" + mToolTips[4].first + "</td><td>" + data.ipAddress + "</td></tr>";
         if ( toolTipContent & SUBNET_MASK )
@@ -107,6 +124,7 @@
         {
             if ( toolTipContent & BCAST_ADDRESS )
                 text += "<tr><td>" + mToolTips[18].first + "</td><td>" + data.broadcastAddress + "</td></tr>";
+#endif
             if ( toolTipContent & GATEWAY )
                 text += "<tr><td>" + mToolTips[19].first + "</td><td>" + data.defaultGateway + "</td></tr>";
             if ( toolTipContent & HW_ADDRESS )
