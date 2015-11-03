--- SoObjects/SOGo/SOGoParentFolder.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoParentFolder.m
@@ -423,6 +423,38 @@ static SoSecurityManager *sm = nil;
   return error;
 }
 
+- (NSException *) appendCollectedSources
+{
+  GCSChannelManager *cm;
+  EOAdaptorChannel *fc;
+  NSURL *folderLocation;
+  NSString *sql, *gcsFolderType;
+  NSException *error;
+
+  cm = [GCSChannelManager defaultChannelManager];
+  folderLocation = [[GCSFolderManager defaultFolderManager] folderInfoLocation];
+  fc = [cm acquireOpenChannelForURL: folderLocation];
+  if ([fc isOpen])
+  {
+    gcsFolderType = [[self class] gcsFolderType];
+
+    sql = [NSString stringWithFormat: (@"SELECT c_path4 FROM %@"
+                                       @" WHERE c_path2 = '%@'"
+                                       @" AND c_folder_type = '%@'"),
+           [folderLocation gcsTableName], owner, gcsFolderType];
+  
+    error = [self fetchSpecialFolders: sql withChannel: fc andFolderType: SOGoCollectedFolder];
+
+    [cm releaseChannel: fc];
+  }
+  else
+    error = [NSException exceptionWithName: @"SOGoDBException"
+                                    reason: @"database connection could not be open"
+                                  userInfo: nil];
+ 
+  return error;
+}
+
 - (NSException *) initSubFolders
 {
   NSException *error;
