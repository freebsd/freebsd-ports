--- org/gudy/azureus2/platform/PlatformManagerFactory.java.orig	2009-07-10 06:30:32.000000000 -0500
+++ org/gudy/azureus2/platform/PlatformManagerFactory.java	2009-07-10 06:36:34.000000000 -0500
@@ -50,21 +50,17 @@
 				try{
 					if ( getPlatformType() == PlatformManager.PT_WINDOWS ){
 						
-						platform_manager = org.gudy.azureus2.platform.win32.PlatformManagerImpl.getSingleton();
+						platform_manager = null;
 						
 					}else if( getPlatformType() == PlatformManager.PT_MACOSX ){
 						
-	                    platform_manager = org.gudy.azureus2.platform.macosx.PlatformManagerImpl.getSingleton();
+	                    platform_manager = null;
 	                    
 					}else if( getPlatformType() == PlatformManager.PT_UNIX ){
 						
 						platform_manager = org.gudy.azureus2.platform.unix.PlatformManagerImpl.getSingleton();
 
 					}
-				}catch( PlatformManagerException e ){
-					
-						// exception will already have been logged
-					
 				}catch( Throwable e ){
 					
 					Debug.printStackTrace(e);
