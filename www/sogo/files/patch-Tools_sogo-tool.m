--- Tools/sogo-tool.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/sogo-tool.m
@@ -149,7 +149,7 @@
                   command, [currentTool objectAtIndex: 1]];
     }
 
-  NSLog (helpString);
+  NSLog (@"%@", helpString);
 }
 
 - (void) registerTools
