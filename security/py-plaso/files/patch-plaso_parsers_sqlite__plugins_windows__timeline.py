--- plaso/parsers/sqlite_plugins/windows_timeline.py.orig	2024-06-08 09:38:22 UTC
+++ plaso/parsers/sqlite_plugins/windows_timeline.py
@@ -89,10 +89,10 @@ class WindowsTimelinePlugin(interface.SQLitePlugin):
   QUERIES = [
       (('SELECT StartTime, Payload, PackageName FROM Activity '
         'INNER JOIN Activity_PackageId ON Activity.Id = '
-        'Activity_PackageId.ActivityId WHERE instr(Payload, "UserEngaged") > 0'
-        ' AND Platform = "packageid"'), 'ParseUserEngagedRow'),
+        'Activity_PackageId.ActivityId WHERE instr(Payload, \'UserEngaged\') > 0'
+        ' AND Platform = \'packageid\''), 'ParseUserEngagedRow'),
       (('SELECT StartTime, Payload, AppId FROM Activity '
-        'WHERE instr(Payload, "UserEngaged") = 0'), 'ParseGenericRow')]
+        'WHERE instr(Payload, \'UserEngaged\') = 0'), 'ParseGenericRow')]
 
   SCHEMAS = [{
       'Activity': (
