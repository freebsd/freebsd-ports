--- kmess/network/msnconnection.cpp.orig	Fri Aug 20 22:18:48 2004
+++ kmess/network/msnconnection.cpp	Fri Aug 20 22:22:17 2004
@@ -40,6 +40,7 @@
    ack_(0),
    identifier_(identifier),
    initialized_(false),
+   kStringHandler_(),
    missedPings_(0),
    sendPings_(false),
    writeLocked_(false)
