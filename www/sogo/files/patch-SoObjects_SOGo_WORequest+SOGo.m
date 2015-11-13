--- SoObjects/SOGo/WORequest+SOGo.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/WORequest+SOGo.m
@@ -180,14 +180,24 @@
   cc = [self clientCapabilities];
 
   b = (
-       [[cc userAgent] rangeOfString: @"CFNetwork"].location != NSNotFound
-       && [[cc userAgent] rangeOfString: @"Darwin"].location != NSNotFound
-       || (
-           [[cc userAgent] rangeOfString: @"CFNetwork"].location != NSNotFound
-            || [[cc userAgent] rangeOfString: @"Mac OS X"].location != NSNotFound
-           )
-       && [[cc userAgent] rangeOfString: @"AddressBook"].location != NSNotFound
-       );
+        (
+          (
+            [[cc userAgent] rangeOfString: @"CFNetwork"].location != NSNotFound
+            && [[cc userAgent] rangeOfString: @"Darwin"].location != NSNotFound
+          )
+          ||
+          (
+            [[cc userAgent] rangeOfString: @"CFNetwork"].location != NSNotFound
+            &&
+            (
+              [[cc userAgent] rangeOfString: @"Mac OS X"].location != NSNotFound
+              ||
+              [[cc userAgent] rangeOfString: @"Mac_OS_X"].location != NSNotFound
+            )
+          )
+        )
+        && [[cc userAgent] rangeOfString: @"AddressBook"].location != NSNotFound
+      );
 
   return b;
 }
