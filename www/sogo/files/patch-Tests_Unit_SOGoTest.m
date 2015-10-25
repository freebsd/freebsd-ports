--- Tests/Unit/SOGoTest.m.orig	2015-09-16 18:41:31 UTC
+++ Tests/Unit/SOGoTest.m
@@ -245,10 +245,10 @@ NSString *_stringForCharacterAtIndex(NSU
       sc2 = _stringForCharacterAtIndex(i, str2, length2);
 
       if ([sc1 isEqualToString: sc2]) 
-        finalSTR = [finalSTR stringByAppendingFormat: @"%u |%@|\n", i, sc1];
+        finalSTR = [finalSTR stringByAppendingFormat: @"%lu |%@|\n", i, sc1];
       else
         {
-          finalSTR = [finalSTR stringByAppendingFormat: @"%u |%@|%@|<--\n", i, sc1, sc2];
+          finalSTR = [finalSTR stringByAppendingFormat: @"%lu |%@|%@|<--\n", i, sc1, sc2];
           differencesFound = YES;
         }
     }
