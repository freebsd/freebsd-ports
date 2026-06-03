--- plaso/parsers/sqlite_plugins/windows_timeline.py.orig	2026-05-12 13:50:02 UTC
+++ plaso/parsers/sqlite_plugins/windows_timeline.py
@@ -86,10 +86,10 @@ class WindowsTimelinePlugin(interface.SQLitePlugin):
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
