--- WorkInProgress.m.orig	2005-05-12 17:58:49.000000000 +0200
+++ WorkInProgress.m	2009-11-14 23:48:17.000000000 +0100
@@ -23,6 +23,7 @@
 
 #include <Foundation/Foundation.h>
 #include <AppKit/AppKit.h>
+#include <GNUstepGUI/GSTheme.h>
 
 #include "Functions.h"
 #include "Constants.h"
@@ -32,6 +33,12 @@
 static NSString *nibName = @"WorkInProgress";
 #define PI_LENGTH 2
 
+static inline NSSize
+my_sizeForBorderType (NSBorderType aType)
+{
+  return [[GSTheme theme] sizeForBorderType: aType];
+}
+
 @implementation WorkInProgressIndicator
 
 /** Display the next step
@@ -77,7 +84,7 @@
     [super drawRect: rect];
 
     // Calculate the inside rect to be drawn
-	NSSize borderSize = _sizeForBorderType (NSBezelBorder);
+	NSSize borderSize = my_sizeForBorderType (NSBezelBorder);
 	r = NSInsetRect(_bounds, borderSize.width, borderSize.height);
 
     value = [self doubleValue];
