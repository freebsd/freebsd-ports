--- python/client.py.orig	2014-07-03 07:47:07 UTC
+++ python/client.py
@@ -118,7 +118,7 @@ class _DBusInterface(object):
 
 		try:
 			return method_getter()(*args, **kwargs)
-		except dbus.exceptions.DBusException, e:
+		except dbus.exceptions.DBusException as e:
 			return reconnecting_error_handler(e)
 
 	def __getattr__(self, name):
@@ -258,7 +258,7 @@ class ZeitgeistDBusInterface(object):
 			try:
 				proxy = get_bus().get_object(self.BUS_NAME,
 					self.OBJECT_PATH, follow_name_owner_changes=True)
-			except dbus.exceptions.DBusException, e:
+			except dbus.exceptions.DBusException as e:
 				if e.get_dbus_name() == "org.freedesktop.DBus.Error.ServiceUnknown":
 					raise RuntimeError(
 						"Found no running zeitgeist-daemon instance: %s" % \
@@ -1054,11 +1054,11 @@ class ZeitgeistClient:
 		"""
 		
 		if unique_id not in self._data_sources:
-			raise ValueError, 'set_data_source_enabled_callback() called before ' \
-			'register_data_source()'
+			raise ValueError('set_data_source_enabled_callback() called before ' \
+			'register_data_source()')
 		
 		if not callable(enabled_callback):
-			raise TypeError, 'enabled_callback: expected a callable method'
+			raise TypeError('enabled_callback: expected a callable method')
 		
 		self._data_sources[unique_id]['callback'] = enabled_callback
 	
