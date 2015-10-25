--- SoObjects/Contacts/SOGoContactEntryPhoto.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Contacts/SOGoContactEntryPhoto.m
@@ -59,7 +59,7 @@
 
       [response setHeader: [self davContentType] forKey: @"content-type"];
       [response setHeader: [NSString stringWithFormat:@" %d",
-                                     [data length]]
+                                     (int)[data length]]
                    forKey: @"content-length"];
       [response setContent: data];
     }
