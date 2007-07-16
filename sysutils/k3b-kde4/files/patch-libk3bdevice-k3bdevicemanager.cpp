--- libk3bdevice/k3bdevicemanager.cpp.orig	Sat Jun 23 20:35:15 2007
+++ libk3bdevice/k3bdevicemanager.cpp	Fri Jul 13 23:37:31 2007
@@ -357,7 +357,7 @@
   int need_close = 0;
   int skip_device = 0;
   int bus, target, lun;
-  QString dev1, dev2;
+  QString cddev, passdev;
 
   if ((fd = open(XPT_DEVICE, O_RDWR)) == -1)
     {
@@ -400,29 +400,22 @@
 	  skip_device = 0;
 	if (need_close)
 	  {
-	    QString pass = dev1;
-	    QString dev = "/dev/" + dev2;
-	    if (dev2.startsWith("pass"))
-	      {
-		pass = dev2;
-		dev = "/dev/" + dev1;
-	      }
 #if __FreeBSD_version < 500100
-	    dev += "c";
+	    cddev += "c";
 #endif
-	    if (!dev1.isEmpty() && !dev2.isEmpty() && dev.startsWith("/dev/cd"))
+	    if (!cddev.isEmpty() && !passdev.isEmpty())
 	    {
-	      Device* device = new Device(dev.latin1());
+	      Device* device = new Device(cddev.latin1());
 	      device->m_bus = bus;
 	      device->m_target = target;
 	      device->m_lun = lun;
-	      device->m_passDevice = "/dev/" + pass;
-	      k3bDebug() << "(BSDDeviceScan) add device " << dev << ":" << bus << ":" << target << ":" << lun << endl;
+	      device->m_passDevice = passdev;
+	      k3bDebug() << "(BSDDeviceScan) add device " << cddev << ":" << bus << ":" << target << ":" << lun << " (" << passdev << ")" << endl;
 	      addDevice(device);
 	    }
 	    need_close = 0;
-	    dev1="";
-	    dev2="";
+	    cddev="";
+	    passdev="";
 	  }
 	bus = dev_result->path_id;
 	target = dev_result->target_id;
@@ -438,10 +431,11 @@
 	if (skip_device != 0)
 	  break;
 
-	if (need_close > 1)
-	  dev1 = periph_result->periph_name + QString::number(periph_result->unit_number);
-	else
-	  dev2 = periph_result->periph_name + QString::number(periph_result->unit_number);
+	k3bDebug() << "(BSDDeviceScan) periph: " << periph_result->periph_name << periph_result->unit_number << endl;
+	if (QString("cd") == periph_result->periph_name)
+	  cddev = "/dev/cd" + QString::number(periph_result->unit_number);
+	else if (QString("pass") == periph_result->periph_name)
+	  passdev = "/dev/pass" + QString::number(periph_result->unit_number);
 
 	need_close++;
 	break;
@@ -459,24 +453,17 @@
 
   if (need_close)
     {
-      QString pass = dev1;
-      QString dev = "/dev/" + dev2;
-      if (dev2.startsWith("pass"))
-	{
-	  pass = dev2;
-	  dev = "/dev/" + dev1;
-	}
 #if __FreeBSD_version < 500100
-      dev += "c";
+      cddev += "c";
 #endif
-      if (!dev1.isEmpty() && !dev2.isEmpty() && dev.startsWith("/dev/cd"))
+      if (!cddev.isEmpty() && !passdev.isEmpty())
       {
-        Device* device = new Device(dev.latin1());
+        Device* device = new Device(cddev.latin1());
         device->m_bus = bus;
         device->m_target = target;
         device->m_lun = lun;
-        device->m_passDevice = "/dev/" + pass;
-        k3bDebug() << "(BSDDeviceScan) add device " << dev << ":" << bus << ":" << target << ":" << lun << endl;
+        device->m_passDevice = passdev;
+	      k3bDebug() << "(BSDDeviceScan) add device " << cddev << ":" << bus << ":" << target << ":" << lun << " (" << passdev << ")" << endl;
         addDevice(device);
       }
     }
