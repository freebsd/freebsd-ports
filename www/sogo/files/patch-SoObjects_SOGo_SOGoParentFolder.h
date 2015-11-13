--- SoObjects/SOGo/SOGoParentFolder.h.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoParentFolder.h
@@ -45,6 +45,7 @@
 
 - (NSException *) appendPersonalSources;
 - (void) removeSubFolder: (NSString *) subfolderName;
+- (NSException *) appendCollectedSources;
 
 - (void) setBaseOCSPath: (NSString *) newOCSPath;
 
