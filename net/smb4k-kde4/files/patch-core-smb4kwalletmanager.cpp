--- core/smb4kwalletmanager.cpp.o	2011-01-11 11:27:23.214191514 -0500
+++ core/smb4kwalletmanager.cpp	2011-01-11 11:32:13.773985643 -0500
@@ -752,7 +752,7 @@
   QString password;
 
   KProcess proc;
-  proc.setShellCommand( Smb4KSettings::smbutil()+" crypt "+authInfo->password() );
+  proc.setShellCommand( Smb4KSettings::smbutil()+" crypt \""+authInfo->password() + "\"" );
   proc.setOutputChannelMode( KProcess::SeparateChannels );
 
   switch ( proc.execute() )
