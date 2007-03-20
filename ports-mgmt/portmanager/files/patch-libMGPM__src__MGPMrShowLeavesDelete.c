--- ./libMGPM/src/MGPMrShowLeavesDelete.c.orig	Mon Dec 12 15:32:34 2005
+++ ./libMGPM/src/MGPMrShowLeavesDelete.c	Fri Dec  8 17:13:00 2006
@@ -28,7 +28,6 @@
 */
 
 #include	<libMGPM.h>
-#include	<sgtty.h>
 
 int	nuke( char* leafPortDir );
 int	rebuildDb( structProperty* property );
@@ -39,19 +39,21 @@
 	char	exact[]			= "exact";
 	char	id[]			= "MGPMrShowLeavesDelete";
 	char*	command			= NULL;
-	char*	leafPortDir		= NULL;
+	char*	leafPortDir;
 	char*	leafPortName		= NULL;
 	char*	pkgDescFile		= NULL;
+	char**	cmd;
+	char**	env;
 	int	answer			= 1;
-	int	bufferSize		= 0xffff;
 	int	doubleBreak		= 0;
 	int	installedPortsDbIDX	= 0;
 	int	installedPortsDbQTY	= 0;
 	
-	command		= calloc( bufferSize, 1 );
-	leafPortDir	= calloc( bufferSize, 1 );
-	leafPortName	= calloc( bufferSize, 1 );
-	pkgDescFile	= calloc( bufferSize, 1 );
+	leafPortDir	= calloc( MAXSTRINGSIZE, 1 );
+	leafPortName	= calloc( MAXSTRINGSIZE, 1 );
+	
+	command		= calloc( MAXBUFFERSIZE, 1 );
+	pkgDescFile	= calloc( MAXBUFFERSIZE, 1 );
 
 	if( ( property->ignoreDb = MGdbOpen( property->ignoreDbFileName ) ) == NULL )
 	{
@@ -108,50 +110,94 @@
 			installedPortsDbIDX++;
 			continue;
 		}
-/*
-		if( answer != KEY_ENTER )
+
+		cmd	= malloc( sizeof( char* ) * 2 );
+		cmd[0]	= malloc( MAXSTRINGSIZE );
+		cmd[1]	= 0;
+
+		env	= malloc( sizeof( char* ) * 2 );
+		env[0]	= malloc( MAXSTRINGSIZE );
+		env[1]	= 0;
+
+		MGmStrcpy( env[0], "TERM=" );
+		MGmStrcat( env[0], getenv( "TERM" ) );
+
+		MGmStrcpy( cmd[0], "/usr/bin/clear" );
+
+		MGmSystem( cmd, env );
+
+		free( env[0] );		
+		free( env );
+
+		free( cmd[0] );		
+		free( cmd );
+
+		fprintf( stdout,"%s\n", SINGLE_LINES );
+		fprintf( stdout, "*** for safety run portmanager -u after using this feature for deletion ***\n" );
+		fprintf( stdout,"%s\n", SINGLE_LINES );
+		fprintf( stdout, "Ports with no ports depending on them AKA \"leaf ports.\"\n" );
+		fprintf( stdout, "These ports may be deinstalled because no other ports rely on them to run;\"\n" );
+		if( property->buildDependsAreLeaves )
 		{
-*/
-			system( "clear" );
-			fprintf( stdout,"%s\n", SINGLE_LINES );
-			fprintf( stdout, "*** for safety run portmanager -u after using this feature for deletion ***\n" );
-			fprintf( stdout,"%s\n", SINGLE_LINES );
-			fprintf( stdout, "Ports with no ports depending on them AKA \"leaf ports.\"\n" );
-			fprintf( stdout, "These ports may be deinstalled because no other ports rely on them to run;\"\n" );
-			if( property->buildDependsAreLeaves )
-			{
-				fprintf( stdout, "however, other ports may rely on these to build.\"\n" );
-			}
-			fprintf( stdout, "%s\n", SINGLE_LINES );
+			fprintf( stdout, "however, other ports may rely on these to build.\"\n" );
+		}
+		fprintf( stdout, "%s\n", SINGLE_LINES );
 
-			fprintf( stdout, "%s dir -=> %s\n\n", leafPortName, leafPortDir );
-			while( fflush( stdout ) );
+		fprintf( stdout, "%s dir -=> %s\n\n", leafPortName, leafPortDir );
+		while( fflush( stdout ) );
 
-			MGmStrcpy( pkgDescFile, PORTSDIR );
-			MGmStrcat( pkgDescFile, leafPortDir );
-			MGmStrcat( pkgDescFile, "/pkg-descr" );
+		MGmStrcpy( pkgDescFile, PORTSDIR );
+		MGmStrcat( pkgDescFile, leafPortDir );
+		MGmStrcat( pkgDescFile, "/pkg-descr" );
 
-			if( MGrIfFileExist( pkgDescFile ) )
-			{
-				MGmStrcpy( command, "cat " );
-				MGmStrcat( command, pkgDescFile );
-				system( command );
-				fprintf( stdout, "\n" );
-			}
-			else
-			{
-				MGmStrcpy( command, "grep COMMENT " );
-				MGmStrcat( command, PORTSDIR );
-				MGmStrcat( command, leafPortDir );
-				MGmStrcat( command, "/Makefile" );
-				system( command );
-			}
-			fprintf( stdout,"%s\n", SINGLE_LINES );
-			fprintf( stdout, "\n<ENTER> to skip\n<X><ENTER> removes port\n<N><ENTER> *Nuke it*, removes distribution files\n\n" ); 
-			fprintf( stdout,"%s\n", SINGLE_LINES );
-/*
+		if( MGrIfFileExist( pkgDescFile ) )
+		{
+			cmd	= malloc( sizeof( char* ) * 3 );
+			cmd[0]	= malloc( MAXSTRINGSIZE );
+			cmd[1]	= malloc( MAXSTRINGSIZE );
+			cmd[2]	= 0;
+
+			MGmStrcpy( cmd[0], "/bin/cat" );
+			MGmStrcpy( cmd[1], pkgDescFile );
+
+			MGmSystem( cmd, NULL );
+
+			free( cmd[0] );		
+			free( cmd[1] );
+			free( cmd );
+
+			fprintf( stdout, "\n" );
+			while( fflush( stdout ) );
+		}
+		else
+		{
+			cmd	= malloc( sizeof( char* ) * 4 );
+			cmd[0]	= malloc( MAXSTRINGSIZE );
+			cmd[1]	= malloc( MAXSTRINGSIZE );
+			cmd[2]	= malloc( MAXSTRINGSIZE );
+			cmd[3]	= 0;
+
+			MGmStrcpy( cmd[0], "/usr/bin/grep" );
+			MGmStrcpy( cmd[1], "COMMENT" );
+			MGmStrcpy( cmd[2], PORTSDIR );
+			MGmStrcat( cmd[2], leafPortDir );
+			MGmStrcat( cmd[2], "/Makefile" );
+
+			MGmSystem( cmd, NULL );
+
+			free( cmd[0] );		
+			free( cmd[1] );
+			free( cmd[2] );
+			free( cmd );
+
+			fprintf( stdout, "\n" );
+			while( fflush( stdout ) );
 		}
-*/
+		fprintf( stdout,"%s\n", SINGLE_LINES );
+		fprintf( stdout, "\n<ENTER> to skip\n<X><ENTER> removes port\n<N><ENTER> *Nuke it*, removes distribution files\n\n" ); 
+		fprintf( stdout,"%s\n", SINGLE_LINES );
+		while( fflush( stdout ) );
+
 		property->STDIN	= fopen( "/dev/stdin", "r" );	/* Flawfinder: ignore */
 		doubleBreak	= 0;
 		while( 1 == 1 )
@@ -243,9 +289,7 @@
 {
 	char	id[]		= "removePort";
 	char	exact[]		= "exact";
-	char*	command		= NULL;
-
-	command		= (char*)calloc( 0xffff, 1 );
+	char**	cmd;
 
 	property->installedPortsDb	= MGdbDelete( property->installedPortsDb, installedPortsDbIDX );
 
@@ -261,12 +305,26 @@
 		MGdbGoTop( property->availableDependenciesDb );
 	}
 
-	MGmStrcpy( command, "pkg_delete -f " );
-	MGmStrcat( command, leafPortNamePtr );
-	fprintf( stdout, "\nexecuting: %s\n", command );
+	cmd	= malloc( sizeof( char* ) * 4 );
+	cmd[0]	= malloc( MAXSTRINGSIZE );
+	cmd[1]	= malloc( MAXSTRINGSIZE );
+	cmd[2]	= malloc( MAXSTRINGSIZE );
+	cmd[3]	= 0;
+
+	MGmStrcpy( cmd[0], "/usr/sbin/pkg_delete" );
+	MGmStrcpy( cmd[1], "-f" );
+	MGmStrcpy( cmd[2], leafPortNamePtr );
+
+	fprintf( stdout, "\nexecuting: %s %s %s\n", cmd[0], cmd[1], cmd[2] );
 	while( fflush( stdout ) );
-	system( command );
-	free(command);
+
+	MGmSystem( cmd, NULL );
+
+	free( cmd[2] );
+	free( cmd[1] );
+	free( cmd[0] );		
+	free( cmd );
+
  	return( 0 );
 }
 
@@ -274,18 +332,35 @@
 int	nuke( char* leafPortDir )
 {
 	char	id[]		= "nuke";
-	char*	command		= NULL;
+	char**	cmd;
 
-	command		= (char*)calloc( 0xffff, 1 );
+	cmd	= malloc( sizeof( char* ) * 4 );
+	cmd[0]	= malloc( MAXSTRINGSIZE );
+	cmd[1]	= malloc( MAXSTRINGSIZE );
+	cmd[2]	= 0;
+
+	MGmStrcpy( cmd[0], PORTSDIR );
+	MGmStrcat( cmd[0], leafPortDir );
+	if( chdir( cmd[0] ) != 0 )
+	{
+		fprintf( stderr, "%s error: chdir %s failed\n", id, cmd[0] ); 
+		perror( "chroot" );
+		while( fflush( stderr ) );
+		assert( 0 );
+	}
 
-	MGmStrcpy( command, "cd " );
-	MGmStrcat( command, PORTSDIR );
-	MGmStrcat( command, leafPortDir );
-	MGmStrcat( command, "; make distclean" );
-	fprintf( stdout, "\nexecuting: %s\n", command );
+	MGmStrcpy( cmd[0], "/usr/bin/make" );
+	MGmStrcpy( cmd[1], "distclean" );
+
+	fprintf( stdout, "\nexecuting: %s %s\n", cmd[0],  cmd[1] );
 	while( fflush( stdout ) );
-	system( command );
-	free(command);
+
+	MGmSystem( cmd, NULL );
+
+	free( cmd[1] );
+	free( cmd[0] );		
+	free( cmd );
+
  	return( 0 );
 }
 
