--- ./org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java.orig	Fri Nov  3 16:47:18 2006
+++ ./org/gudy/azureus2/platform/macosx/access/jnilib/OSXAccess.java	Thu May  3 00:24:10 2007
@@ -19,7 +19,7 @@
  */
 package org.gudy.azureus2.platform.macosx.access.jnilib;
 
-import org.eclipse.swt.internal.carbon.AEDesc;
+//import org.eclipse.swt.internal.carbon.AEDesc;
 
 import org.gudy.azureus2.core3.util.Debug;
 
@@ -42,7 +42,7 @@
 		}
 	}
 
-	public static final native int AEGetParamDesc(int theAppleEvent, int theAEKeyword, int desiredType, AEDesc result);
+//	public static final native int AEGetParamDesc(int theAppleEvent, int theAEKeyword, int desiredType, AEDesc result);
 
 	public static final native String getVersion();
 	
