--- src/TRLocalPacketFilter.m.orig	2012-03-03 19:17:45 UTC
+++ src/TRLocalPacketFilter.m
@@ -43,6 +43,8 @@
 #import <errno.h>
 #import <assert.h>
 
+#import "TRLog.h"
+#import "xmalloc.h"
 
 /* Private Methods */
 
