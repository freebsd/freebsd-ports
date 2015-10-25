--- SoObjects/Appointments/MSExchangeFreeBusy.m.orig	2015-09-16 18:41:29 UTC
+++ SoObjects/Appointments/MSExchangeFreeBusy.m
@@ -344,7 +344,7 @@ size_t curl_body_function_freebusy(void 
   NSMutableString *s;
 
   s = [NSMutableString stringWithCapacity: 64];
-  [s appendFormat:@"<0x%08X[%@]:", self, NSStringFromClass([self class])];
+  [s appendFormat:@"<0x%08X[%@]:", (unsigned int)self, NSStringFromClass([self class])];
   if (freeBusyViewType)
     [s appendFormat:@" freeBusyViewType='%@'", freeBusyViewType];
   if (mergedFreeBusy)
