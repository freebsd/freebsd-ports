--- SoObjects/SOGo/SOGoGroup.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoGroup.m
@@ -135,7 +135,7 @@
 {
   NSArray *allSources;
   NGLdapEntry *entry;
-  NSObject <SOGoSource> *source;
+  NSObject <SOGoSource, SOGoDNSource> *source;
   id o;
   NSEnumerator *gclasses;
   NSString *gclass;
@@ -154,7 +154,7 @@
 
   for (i = 0; i < [allSources count]; i++)
     {
-      source = [[SOGoUserManager sharedUserManager] sourceWithID: [allSources objectAtIndex: i]];
+      source = (NSObject <SOGoSource, SOGoDNSource> *) [[SOGoUserManager sharedUserManager] sourceWithID: [allSources objectAtIndex: i]];
 
       // Our different sources might not all implements groups support
       if ([source respondsToSelector: theSelector])
