--- SoObjects/Appointments/SOGoAppointmentFolder.m.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Appointments/SOGoAppointmentFolder.m
@@ -2387,7 +2387,7 @@ firstInstanceCalendarDateRange: (NGCalen
   request = [context request];
   if (!([request isIPhone] || [request isICal4]))
     {
-      gdRT = [self groupDavResourceType];
+      gdRT = (NSArray *) [self groupDavResourceType];
       gdVEventCol = [NSArray arrayWithObjects: [gdRT objectAtIndex: 0],
                   XMLNS_GROUPDAV, nil];
       [colType addObject: gdVEventCol];
