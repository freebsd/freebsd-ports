--- org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java.orig	Sun Sep 24 16:18:49 2006
+++ org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java	Sun Sep 24 16:19:07 2006
@@ -19,7 +19,7 @@
  */
 package org.gudy.azureus2.platform.macosx.access.jnilib;
 
-import org.eclipse.swt.internal.carbon.AEDesc;
+// import org.eclipse.swt.internal.carbon.AEDesc;
 
 import org.gudy.azureus2.core3.util.Debug;
 
@@ -42,7 +42,7 @@
 		}
 	}
 
-	public static final native int AEGetParamDesc(int theAppleEvent, int theAEKeyword, int desiredType, AEDesc result);
+//	public static final native int AEGetParamDesc(int theAppleEvent, int theAEKeyword, int desiredType, AEDesc result);
 
 	public static final native String getVersion();
 	
