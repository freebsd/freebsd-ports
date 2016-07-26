--- ActiveSync/iCalToDo+ActiveSync.m.orig	2016-07-20 04:33:29 UTC
+++ ActiveSync/iCalToDo+ActiveSync.m
@@ -127,7 +127,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
       // otherwise it'll prevent WP8 phones from sync'ing. See #3028 for details.
       o = [o activeSyncRepresentationInContext: context];
 
-      if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+      if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
         {
           [s appendFormat: @"<Body xmlns=\"Tasks:\">%@</Body>", o];
           [s appendString: @"<BodyTruncated xmlns=\"Tasks:\">0</BodyTruncated>"];
@@ -161,7 +161,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
     [self setSummary: o];
 
   // FIXME: merge with iCalEvent
-  if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+  if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
     {
       if ((o = [theValues objectForKey: @"Body"]))
         [self setComment: o];
