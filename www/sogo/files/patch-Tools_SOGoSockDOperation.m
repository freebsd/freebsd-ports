--- Tools/SOGoSockDOperation.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoSockDOperation.m
@@ -145,7 +145,7 @@ Class SOGoContactSourceFolderKlass = Nil
     [self _appendEntry: [resultEntries objectAtIndex: count]
               toResult: result];
 
-  [result appendFormat: @"RESULT\ncode: %", resultCode];
+  [result appendFormat: @"RESULT\ncode: %d", resultCode];
   [responseSocket
     safeWriteData: [result dataUsingEncoding: NSASCIIStringEncoding]];
 }
