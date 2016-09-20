Do not require a modern compiler, we are only building docs.
--- qtserialbus/qtserialbus.pro.orig	2016-05-12 10:12:53 UTC
+++ qtserialbus/qtserialbus.pro
@@ -10,9 +10,6 @@ qtCompileTest(socketcan)
 qtCompileTest(socketcan_fd)
 load(qt_parts)
 
-requires(config_language) # enforce defined set of C++11
-!config_language:warning("Cannot compile the module with your compiler, missing C++11 language features.")
-
 linux {
     !config_socketcan:warning("You need linux/can.h and linux/can/raw.h linux headers for socketCAN support, disabling it")
     !config_socketcan_fd:warning("Newer kernel needed for flexible data-rate frame support 'canfd_frame'")
