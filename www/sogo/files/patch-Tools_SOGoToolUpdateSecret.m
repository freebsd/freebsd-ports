--- Tools/SOGoToolUpdateSecret.m	2024-03-27 16:51:10.990469000 -0500
+++ Tools/SOGoToolUpdateSecret.m	2024-03-27 16:51:29.082221000 -0500
@@ -266,8 +266,6 @@
       [source synchronize];
     }
   }
-
-  return rc;
 }
 
 - (BOOL) updateToPlainData: (NSString*) oldSecret
