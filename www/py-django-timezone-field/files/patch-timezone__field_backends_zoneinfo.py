Remove the "Factory" timezone as it causes following error if the system
zoneinfo data is used:

ValueError: Invalid STD format in b'<Local time zone must be set--use tzsetup>0'

--- timezone_field/backends/zoneinfo.py.orig	2023-09-09 10:35:09 UTC
+++ timezone_field/backends/zoneinfo.py
@@ -10,6 +10,8 @@ class ZoneInfoBackend(TimeZoneBackend):
     utc_tzobj = zoneinfo.ZoneInfo("UTC")
     all_tzstrs = zoneinfo.available_timezones()
     base_tzstrs = zoneinfo.available_timezones()
+    all_tzstrs.discard("Factory")
+    base_tzstrs.discard("Factory")
 
     def is_tzobj(self, value):
         return isinstance(value, zoneinfo.ZoneInfo)
