--- src/gui/installer.cpp.orig	2013-12-07 22:55:52 UTC
+++ src/gui/installer.cpp
@@ -1031,7 +1031,7 @@ void InstallerImp::insertActions()
 	if( !isWindows() )
 	{
 		insert( new CreateConfigFile(value("dir-config"),"emailrelay.conf",
-			value("dir-config"),"emailrelay.conf.template") ) ;
+			value("dir-config"),"emailrelay.conf.sample") ) ;
 		insert( new EditConfigFile(value("dir-config"),"emailrelay.conf",commandlineMap().second) ) ;
 	}
 }
