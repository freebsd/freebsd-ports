--- SoObjects/SOGo/SOGoCacheGCSFolder.h.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoCacheGCSFolder.h
@@ -40,6 +40,8 @@
 
 - (NSMutableString *) pathForChild: (NSString *) childName;
 
+- (void) addUserInAcls: (NSString *) user;
+
 - (NSArray *) toOneRelationshipKeys;
 - (NSArray *) toManyRelationshipKeys;
 
