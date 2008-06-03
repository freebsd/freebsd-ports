--- org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java.orig	2008-06-03 11:20:58.000000000 -0400
+++ org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java	2008-06-03 11:23:02.000000000 -0400
@@ -19,7 +19,7 @@
  */
 package org.gudy.azureus2.platform.macosx.access.jnilib;
 
-import org.eclipse.swt.internal.carbon.AEDesc;
+// import org.eclipse.swt.internal.carbon.AEDesc;
 
 import org.gudy.azureus2.core3.util.*;
 
@@ -42,7 +42,7 @@
 		}
 	}
 
-	public static final native int AEGetParamDesc(int theAppleEvent, int theAEKeyword, int desiredType, AEDesc result);
+//	public static final native int AEGetParamDesc(int theAppleEvent, int theAEKeyword, int desiredType, AEDesc result);
 
 	public static final native String getVersion();
 
