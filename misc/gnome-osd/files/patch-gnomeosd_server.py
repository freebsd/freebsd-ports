--- gnomeosd/server.py.orig	Wed Nov 16 16:26:50 2005
+++ gnomeosd/server.py	Wed Nov 16 16:28:14 2005
@@ -378,26 +378,27 @@
 
     bonobo.context_running_get().connect("last-unref", last_unref_cb)
 
-class DBusInterface(dbus.service.Object):
-    def __init__(self, bus_name, object_path="/Server"):
-        dbus.service.Object.__init__(self, bus_name, object_path)
+if HAVE_DBUS:
+    class DBusInterface(dbus.service.Object):
+        def __init__(self, bus_name, object_path="/Server"):
+            dbus.service.Object.__init__(self, bus_name, object_path)
 
-    #@dbus.service.method("pt.inescporto.telecom.GnomeOSD")
-    def showMessage(self, message, timeout=-1):
-        return message_show_cb(None, message, timeout)
-    showMessage = dbus.service.method("pt.inescporto.telecom.GnomeOSD")(showMessage)
+    	#@dbus.service.method("pt.inescporto.telecom.GnomeOSD")
+        def showMessage(self, message, timeout=-1):
+            return message_show_cb(None, message, timeout)
+        showMessage = dbus.service.method("pt.inescporto.telecom.GnomeOSD")(showMessage)
 
-    #@dbus.service.method("pt.inescporto.telecom.GnomeOSD")
-    def showMessageFull(self, message):
-        return message_show_full_cb(None, message)
-    showMessageFull = dbus.service.method("pt.inescporto.telecom.GnomeOSD")(showMessageFull)
+    	#@dbus.service.method("pt.inescporto.telecom.GnomeOSD")
+        def showMessageFull(self, message):
+            return message_show_full_cb(None, message)
+        showMessageFull = dbus.service.method("pt.inescporto.telecom.GnomeOSD")(showMessageFull)
+
+    def start_dbus_interface():
+        session_bus = dbus.SessionBus()
+        name = dbus.service.BusName("pt.inescporto.telecom.GnomeOSD",
+                                    bus=session_bus)
+        obj = DBusInterface(name)
 
-def start_dbus_interface():
-    session_bus = dbus.SessionBus()
-    name = dbus.service.BusName("pt.inescporto.telecom.GnomeOSD",
-                                bus=session_bus)
-    obj = DBusInterface(name)
-    
 
 def main():
     print "starting Bonobo interface..."
