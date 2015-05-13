Fix Trash panel plugin (PLUG_TPA), now receives right signal (bug #11896)

--- thunar/thunar-file.c.orig	2015-05-05 17:25:29 UTC
+++ thunar/thunar-file.c
@@ -661,6 +661,7 @@ thunar_file_monitor_update (GFile       
       switch (event_type)
         {
         case G_FILE_MONITOR_EVENT_CREATED:
+        case G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED:
         case G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT:
         case G_FILE_MONITOR_EVENT_PRE_UNMOUNT:
         case G_FILE_MONITOR_EVENT_DELETED:
