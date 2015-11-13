--- SoObjects/SOGo/SQLSource.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SQLSource.m
@@ -880,7 +880,7 @@
 
   reason = [NSString stringWithFormat: @"method '%@' is not available"
                      @" for class '%@'", NSStringFromSelector (_cmd),
-                     NSStringFromClass (isa)];
+                     NSStringFromClass (object_getClass(self))];
 
   return [NSException exceptionWithName: @"SQLSourceIOException"
                                  reason: reason
@@ -893,7 +893,7 @@
 
   reason = [NSString stringWithFormat: @"method '%@' is not available"
                      @" for class '%@'", NSStringFromSelector (_cmd),
-                     NSStringFromClass (isa)];
+                     NSStringFromClass (object_getClass(self))];
 
   return [NSException exceptionWithName: @"SQLSourceIOException"
                                  reason: reason
@@ -906,7 +906,7 @@
 
   reason = [NSString stringWithFormat: @"method '%@' is not available"
                      @" for class '%@'", NSStringFromSelector (_cmd),
-                     NSStringFromClass (isa)];
+                     NSStringFromClass (object_getClass(self))];
 
   return [NSException exceptionWithName: @"SQLSourceIOException"
                                  reason: reason
@@ -932,7 +932,7 @@
 
   reason = [NSString stringWithFormat: @"method '%@' is not available"
                      @" for class '%@'", NSStringFromSelector (_cmd),
-                     NSStringFromClass (isa)];
+                     NSStringFromClass (object_getClass(self))];
 
   return [NSException exceptionWithName: @"SQLSourceIOException"
                                  reason: reason
@@ -947,7 +947,7 @@
 
   reason = [NSString stringWithFormat: @"method '%@' is not available"
                      @" for class '%@'", NSStringFromSelector (_cmd),
-                     NSStringFromClass (isa)];
+                     NSStringFromClass (object_getClass(self))];
 
   return [NSException exceptionWithName: @"SQLSourceIOException"
                                  reason: reason
@@ -961,7 +961,7 @@
 
   reason = [NSString stringWithFormat: @"method '%@' is not available"
                      @" for class '%@'", NSStringFromSelector (_cmd),
-                     NSStringFromClass (isa)];
+                     NSStringFromClass (object_getClass(self))];
 
   return [NSException exceptionWithName: @"SQLSourceIOException"
                                  reason: reason
