--- src/knemod/interfacetooltip.cpp.orig	Sat Apr  1 21:44:22 2006
+++ src/knemod/interfacetooltip.cpp	Sun Apr  2 21:30:52 2006
@@ -101,6 +101,23 @@
 
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
@@ -109,6 +126,7 @@
         {
             if ( toolTipContent & BCAST_ADDRESS )
                 text += "<tr><td>" + mToolTips[18].first + "</td><td>" + data.broadcastAddress + "</td></tr>";
+#endif
             if ( toolTipContent & GATEWAY )
                 text += "<tr><td>" + mToolTips[19].first + "</td><td>" + data.defaultGateway + "</td></tr>";
             if ( toolTipContent & HW_ADDRESS )
