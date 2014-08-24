--- src/simple-mtpfs-fuse.cpp~
+++ src/simple-mtpfs-fuse.cpp
@@ -314,7 +314,7 @@ bool SMTPFileSystem::parseOptions(int ar
 
     --m_options.m_device_no;
 
-#ifdef HAVE_LIBUSB1
+#if 0 //def HAVE_LIBUSB1
     // device file and -- device are mutually exclusive, fail if both set
     if (m_options.m_device_no && m_options.m_device_file) {
         m_options.m_good = false;
@@ -383,11 +383,9 @@ bool SMTPFileSystem::exec()
     }
 
 #ifdef HAVE_LIBUSB1
-    if (m_options.m_device_file) {
-        // Try to use device file first, if provided
-        if (!m_device.connect(m_options.m_device_file))
-            return false;
-    } else
+    // Try to use device file first, ignore otherwise
+    if (!m_options.m_device_file ||
+        !m_device.connect(m_options.m_device_file))
 #endif // HAVE_LIBUSB1
     {
         // Connect to MTP device by order number, if no device file supplied
