--- ExtProgressIndicator.m.orig	2005-05-12 17:58:49.000000000 +0200
+++ ExtProgressIndicator.m	2009-11-14 23:42:55.000000000 +0100
@@ -21,6 +21,8 @@
  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#include <AppKit/NSAttributedString.h>
+#include <GNUstepGUI/GSTheme.h>
 #include <AppKit/NSColor.h>
 #include <AppKit/NSParagraphStyle.h>
 #include <Foundation/Foundation.h>
@@ -29,6 +31,11 @@
 
 #include "Constants.h"
 
+static inline NSSize
+my_sizeForBorderType (NSBorderType aType)
+{
+  return [[GSTheme theme] sizeForBorderType: aType];
+}
 
 @implementation ExtProgressIndicator
 
@@ -79,7 +86,7 @@
 
     // Calculate the inside rect to be drawn
 	if (_isBezeled) {
-		NSSize borderSize = _sizeForBorderType (NSBezelBorder);
+		NSSize borderSize = my_sizeForBorderType (NSBezelBorder);
 		origRect = NSInsetRect(_bounds, borderSize.width, borderSize.height);
 	} else
 		origRect = _bounds;
