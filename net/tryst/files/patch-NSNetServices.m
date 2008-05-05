--- Source/NSNetServices.m.orig	2007-01-23 09:56:58.000000000 +0100
+++ Source/NSNetServices.m	2008-05-03 09:52:00.000000000 +0200
@@ -23,6 +23,7 @@
 #if defined( VERBOSE )
 #  import <Foundation/NSDebug.h>
 #endif /* VERBOSE */
+#import <Foundation/NSDictionary.h>
 #if defined( _REENTRANT )
 #  import <Foundation/NSLock.h>
 #endif /* _REENTRANT */
