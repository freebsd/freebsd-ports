--- SOPE/NGCards/versitCardsSaxDriver/VSSaxDriver.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/NGCards/versitCardsSaxDriver/VSSaxDriver.m
@@ -1045,7 +1045,7 @@ static NSCharacterSet *whitespaceCharSet
   if (debugOn)
     {
       NSLog(@"%s: trying to decode data (0x%p,len=%d) ...",
-	    __PRETTY_FUNCTION__, _data, [_data length]);
+	    __PRETTY_FUNCTION__, _data, (int)[_data length]);
     }
   
   if ((len = [_data length]) == 0)
@@ -1164,7 +1164,7 @@ static NSCharacterSet *whitespaceCharSet
   if (debugOn)
     {
       NSLog(@"%s: trying to parse string (0x%p,len=%d) ...",
-            __PRETTY_FUNCTION__, _source, [_source length]);
+            __PRETTY_FUNCTION__, _source, (int)[_source length]);
     }
   if (!_sysId) _sysId = @"<string>";
   [self _parseString: _source];
