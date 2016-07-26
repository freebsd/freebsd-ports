--- ActiveSync/SOGoMailObject+ActiveSync.m.orig	2016-07-20 04:33:03 UTC
+++ ActiveSync/SOGoMailObject+ActiveSync.m
@@ -1003,7 +1003,7 @@ struct GlobalObjectId {
       [s appendFormat: @"<GlobalObjId xmlns=\"Email:\">%@</GlobalObjId>", [globalObjId activeSyncRepresentationInContext: context]];
 
       // We set the right message type - we must set AS version to 14.1 for this
-      if ([[context valueForKey: @"ASProtocolVersion"] floatValue] >= 14.1)
+      if ([[context objectForKey: @"ASProtocolVersion"] floatValue] >= 14.1)
         [s appendFormat: @"<MeetingMessageType xmlns=\"Email2:\">%d</MeetingMessageType>", 1];
 
       [s appendString: @"</MeetingRequest>"];
@@ -1169,7 +1169,7 @@ struct GlobalObjectId {
           truncated = 0;
         }
 
-      if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+      if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
         {
           [s appendFormat: @"<Body xmlns=\"Email:\">%@</Body>", content];
           [s appendFormat: @"<BodyTruncated xmlns=\"Email:\">%d</BodyTruncated>", truncated];
@@ -1204,7 +1204,7 @@ struct GlobalObjectId {
     {
       int i;
 
-      if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+      if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
         [s appendString: @"<Attachments xmlns=\"Email:\">"];
       else
         [s appendString: @"<Attachments xmlns=\"AirSyncBase:\">"];
@@ -1219,12 +1219,12 @@ struct GlobalObjectId {
           // FileReference must be a unique identifier across the whole store. We use the following structure:
           // mail/<foldername>/<message UID/<pathofpart>
           // mail/INBOX/2          
-          if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+          if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
             [s appendFormat: @"<AttName>mail/%@/%@/%@</AttName>", [[[self container] relativeImap4Name] stringByEscapingURL], [self nameInContainer], [value objectForKey: @"path"]];
           else
             [s appendFormat: @"<FileReference>mail/%@/%@/%@</FileReference>", [[[self container] relativeImap4Name] stringByEscapingURL], [self nameInContainer], [value objectForKey: @"path"]];
 
-          if ([[context valueForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
+          if ([[context objectForKey: @"ASProtocolVersion"] isEqualToString: @"2.5"])
             {
               [s appendFormat: @"<AttMethod>%d</AttMethod>", 1];
               [s appendFormat: @"<AttSize>%d</AttSize>", [[value objectForKey: @"size"] intValue]];
@@ -1273,7 +1273,7 @@ struct GlobalObjectId {
       [s appendFormat: @"</Categories>"];
     }
   
-    if ([[context valueForKey: @"ASProtocolVersion"] floatValue] >= 14.0)
+    if ([[context objectForKey: @"ASProtocolVersion"] floatValue] >= 14.0)
     {
       id value;
       NSString *reference;
