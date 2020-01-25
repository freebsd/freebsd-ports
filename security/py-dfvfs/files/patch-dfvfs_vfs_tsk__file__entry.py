--- dfvfs/vfs/tsk_file_entry.py.orig	2019-06-08 17:38:10 UTC
+++ dfvfs/vfs/tsk_file_entry.py
@@ -105,7 +105,7 @@ class TSKTime(dfdatetime_interface.DateTimeValues):
     microseconds = date_time_values.get('microseconds', 0)
 
     self._timestamp = self._GetNumberOfSecondsFromElements(
-        year, month, day_of_month, hours, minutes, seconds)
+        year, month, day_of_month, hours, minutes, seconds, None)
     self.fraction_of_second = microseconds
 
     if pytsk3.TSK_VERSION_NUM >= 0x040200ff:
