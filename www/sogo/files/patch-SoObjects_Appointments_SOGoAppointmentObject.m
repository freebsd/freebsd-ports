--- SoObjects/Appointments/SOGoAppointmentObject.m.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Appointments/SOGoAppointmentObject.m
@@ -45,6 +45,7 @@
 #import <NGCards/iCalDateTime.h>
 #import <NGCards/iCalTimeZone.h>
 #import <NGCards/iCalTimeZonePeriod.h>
+#import <NGCards/iCalToDo.h>
 #import <NGCards/NSString+NGCards.h>
 
 #import <SOGo/SOGoConstants.h>
@@ -747,11 +748,14 @@ inRecurrenceExceptionsForEvent: (iCalEve
     {
       e = [events objectAtIndex: i];
       if ([e recurrenceId])
-        for (j = 0; j < [theAttendees count]; j++)
-          if (shouldAdd)
+        for (j = 0; j < [theAttendees count]; j++) {
+          if (shouldAdd) {
             [e addToAttendees: [theAttendees objectAtIndex: j]];
-          else
+          }
+          else {
             [e removeFromAttendees: [theAttendees objectAtIndex: j]];
+          }
+        }
     }
 }
 
@@ -1037,7 +1041,7 @@ inRecurrenceExceptionsForEvent: (iCalEve
           if ([delegateEmail length])
             otherDelegate = [event findAttendeeWithEmail: delegateEmail];
           else
-            otherDelegate = NO;
+            otherDelegate = nil;
           
           /* we handle the addition/deletion of delegate users */
           addDelegate = NO;
@@ -1075,7 +1079,7 @@ inRecurrenceExceptionsForEvent: (iCalEve
                   if ([delegateEmail length])
                     otherDelegate = [event findAttendeeWithEmail: delegateEmail];
                   else
-                    otherDelegate = NO;
+                    otherDelegate = nil;
                 }
             }
           if (addDelegate)
@@ -1232,7 +1236,7 @@ inRecurrenceExceptionsForEvent: (iCalEve
               if ([delegateEmail length])
                 otherDelegate = [event findAttendeeWithEmail: delegateEmail];
               else
-                otherDelegate = NO;
+                otherDelegate = nil;
             }
           
           [self sendEMailUsingTemplateNamed: @"Deletion"
@@ -1990,7 +1994,7 @@ inRecurrenceExceptionsForEvent: (iCalEve
       if ([container resourceNameForEventUID: eventUID])
         {
           return [NSException exceptionWithHTTPStatus: 403
-                                               reason: [NSString stringWithFormat: @"Event UID already in use. (%s)", eventUID]];
+                                               reason: [NSString stringWithFormat: @"Event UID already in use. (%s)", (char *)eventUID]];
         }
      
       //
