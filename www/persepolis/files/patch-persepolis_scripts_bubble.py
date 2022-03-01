--- persepolis/scripts/bubble.py.orig	2019-09-16 20:45:38 UTC
+++ persepolis/scripts/bubble.py
@@ -29,6 +29,8 @@ if os_type == 'Darwin':
 elif os_type == 'Windows':
     from persepolis.scripts.windows_notification import Windows_Notification
 
+else: import dbus
+
 # notifySend use notify-send program in user's system for sending notifications
 # and use playNotification function in play.py file for playing sound
 # notifications
@@ -68,7 +70,7 @@ def notifySend(message1, message2, time, sound, parent
 
     enable_notification = persepolis_setting.value('settings/notification')
 
-    time = str(time)
+    time = int(time)
     message1 = str(message1)
     message2 = str(message2)
 
@@ -77,14 +79,13 @@ def notifySend(message1, message2, time, sound, parent
         parent.system_tray_icon.showMessage(message1, message2, 0, 10000)
     else:
         if os_type == 'Linux' or os_type == 'FreeBSD' or os_type == 'OpenBSD':
-            subprocess.Popen(['notify-send', '--icon', 'persepolis',
-                              '--app-name', 'Persepolis Download Manager',
-                              '--expire-time', time,
-                              message1, message2],
-                             stderr=subprocess.PIPE,
-                             stdout=subprocess.PIPE,
-                             stdin=subprocess.PIPE,
-                             shell=False)
+            service = 'org.freedesktop.Notifications'
+            notify_iface = dbus.Interface(
+              dbus.SessionBus().get_object(service,
+              '/%s' % service.replace('.', '/')), service)
+            notify_iface.Notify('Persepolis Download Manager', 0,
+              '/usr/local/share/pixmaps/persepolis.svg', message1, message2,
+              [], {'urgency': 0}, time)
 
         elif os_type == 'Darwin':
             notifyMac("Persepolis Download Manager", message1, message2)
