--- org/gudy/azureus2/platform/PlatformManagerFactory.java.orig	2008-10-22 19:53:40.000000000 -0400
+++ org/gudy/azureus2/platform/PlatformManagerFactory.java	2008-10-22 19:53:58.000000000 -0400
@@ -48,21 +48,17 @@
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
