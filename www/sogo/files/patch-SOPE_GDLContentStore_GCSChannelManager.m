--- SOPE/GDLContentStore/GCSChannelManager.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/GDLContentStore/GCSChannelManager.m
@@ -500,7 +500,7 @@ static NSTimeInterval ChannelCollectionT
   ms = [NSMutableString stringWithCapacity: 256];
   [ms appendFormat: @"<0x%p[%@]: ", self, NSStringFromClass ([self class])];
 
-  [ms appendFormat: @" #adaptors=%d", [urlToAdaptor count]];
+  [ms appendFormat: @" #adaptors=%d", (int)[urlToAdaptor count]];
 
   [ms appendString: @">"];
   return ms;
