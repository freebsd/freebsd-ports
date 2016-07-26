--- ActiveSync/iCalEvent+ActiveSync.m.orig	2016-07-20 04:33:18 UTC
+++ ActiveSync/iCalEvent+ActiveSync.m
@@ -244,7 +244,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
       // otherwise it'll prevent WP8 phones from sync'ing. See #3028 for details.
       o = [o activeSyncRepresentationInContext: context];
 
-      if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+      if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
         {
           [s appendFormat: @"<Body xmlns=\"Calendar:\">%@</Body>", o];
           [s appendString: @"<BodyTruncated xmlns=\"Calendar:\">0</BodyTruncated>"];
@@ -487,7 +487,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
     }
   
   // FIXME: merge with iCalToDo
-  if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+  if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
     {
       if ((o = [theValues objectForKey: @"Body"]))
         [self setComment: o];
