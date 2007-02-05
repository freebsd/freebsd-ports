--- libMGPM/src/MGPMrUpdate.c.orig	Wed Dec 14 13:23:59 2005
+++ libMGPM/src/MGPMrUpdate.c	Mon Feb  5 12:50:13 2007
@@ -60,6 +60,7 @@
 	char*	stopPortDirPtr					= NULL;
 	char*	strikePtr					= NULL;
 	char**	cmd;
+	char**	env;
 	int	answer						= 1;
 	int	availableDependenciesDbIDX			= 0;
 	int	availableDependenciesDbQTY			= 0;
@@ -74,12 +75,6 @@
 
 	property->optionsChanged	= 0;
 
-	localProperty.environment	= malloc( sizeof( char** ) * 4 );
-	localProperty.environment[0]	= malloc( MAXSTRINGSIZE );
-	localProperty.environment[1]	= malloc( MAXSTRINGSIZE );
-	localProperty.environment[2]	= malloc( MAXSTRINGSIZE );
-	localProperty.environment[3]	= 0;
-
 	localProperty.CURDIR			= calloc( MAXSTRINGSIZE, 1 );
 	localProperty.afterOptionsFileSize	= calloc( MAXSTRINGSIZE, 1 );
 	localProperty.afterOptionsFileTime	= calloc( MAXSTRINGSIZE, 1 );
@@ -110,7 +105,7 @@
 	property->installedPortsDb		= MGdbOpen( property->installedPortsDbFileName );
 	property->strikesDb			= MGdbOpen( property->strikesDbFileName );
 
-	if( ( strcmp( "/sysutils/portmanager", oldPortDir ) == 0 || strcmp( "/local/sysutils/portmanager", oldPortDir ) == 0 ) && property->forced )
+	if( ( strcmp( "/ports-mgmt/portmanager", oldPortDir ) == 0 || strcmp( "/local/ports-mgmt/portmanager", oldPortDir ) == 0 ) && property->forced )
 	{
 		fprintf( stdout, "ignoring portmanager, will not self update in forced mode by design\n" );
 		while( fflush( stdout ) );
@@ -122,30 +117,6 @@
 		return( 0 );
 	}
 
-	/*
-	 * setup environment
-	 */
-	MGmStrcpy( localProperty.environment[0], "PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/bin:/usr/X11R6/bin" );
-
-	if( getenv( "CCACHE_DIR" ) != NULL )
-	{
-		MGmStrcpy( localProperty.environment[1], "CCACHE_DIR=" );
-		MGmStrcat( localProperty.environment[1], getenv( "CCACHE_DIR" ) );
-	}
-	else
-	{
-		localProperty.environment[1][0]	= 0;
-	}
-
-	if( getenv( "CCACHE_PATH" ) != NULL )
-	{
-		MGmStrcpy( localProperty.environment[2], "CCACHE_PATH=/usr/bin:/usr/local/bin" );
-	}
-	else
-	{
-		localProperty.environment[2][0]	= 0;
-	}
-
 	/* 
 	 * test for bsd.ports.mk patch
 	 */
@@ -466,25 +437,53 @@
 */
 			/*
 			 * If here we know OPTIONS is defined, need to run make config
-			 * if /var/db/ports/{package name}/options exists
+			 * if /var/db/ports/{package name}/options does  not exist
 			 */
 			if( MGrIfFileExist( localProperty.optionsDir ) == 0 )
 			{
-				MGmStrcpy( localProperty.command, "cd " );
-				MGmStrcat( localProperty.command, PORTSDIR );
-				MGmStrcat( localProperty.command, oldPortDir );
-				MGmStrcat( localProperty.command, " && make config " );
-				if( MGrStrlen( localProperty.options ) > 0 )
+				cmd	= malloc( sizeof( char* ) * 3 );
+				cmd[0]	= malloc( MAXSTRINGSIZE );
+				cmd[1]	= malloc( MAXSTRINGSIZE );
+				cmd[2]	= 0;
+
+				env	= malloc( sizeof( char* ) * 2 );
+				env[0]	= malloc( MAXSTRINGSIZE );
+				env[1]	= 0;
+
+				MGmStrcpy( env[0], "TERM=" );
+				MGmStrcat( env[0], getenv( "TERM" ) );
+
+				MGmStrcpy( cmd[0], PORTSDIR );
+				MGmStrcat( cmd[0], oldPortDir );
+
+				fprintf( stdout, "%s\n", SINGLE_LINES );
+				fprintf( stdout, "config %s \n", cmd[0] );
+				while( fflush( stdout ) );
+
+				if( chdir( cmd[0] ) != 0 )
 				{
-					MGmStrcat( localProperty.command, localProperty.options );
+					fprintf( stderr, "%s error: chdir %s failed\n", id, cmd[0] ); 
+					perror( "chroot" );
+					while( fflush( stderr ) );
+					assert( 0 );
 				}
 
-				fprintf( stdout, "%s\n", SINGLE_LINES );
-				fprintf( stdout, "update %s \n", oldPortName );
-				fprintf( stdout, "%s %s command: #2 of 14  %s\n", id, PACKAGE_VERSION, localProperty.command );
-				fprintf( stdout, "%s\n", SINGLE_LINES );
+				MGmStrcpy( cmd[0], "/usr/bin/make" );
+				MGmStrcpy( cmd[1], "config" );
+				fprintf( stdout, "%s %s command: #2 of 14  %s %s\n", id, PACKAGE_VERSION, cmd[0], cmd[1] );
 				while( fflush( stdout ) );
-				system(localProperty.command);
+
+				MGmSystem( cmd, env );
+
+				free( env[0] );		
+				free( env );
+
+				free( cmd[1] );
+				free( cmd[0] );		
+				free( cmd );
+		
+				fprintf( stdout, "%s\n", SINGLE_LINES );
+
 			}
 			MGmStrcpy( localProperty.afterOptionsFileTime,
 					MGrIntToString( (int)MGrFileTime( localProperty.optionsDir ) ) );
@@ -567,17 +566,8 @@
 		MGmStrcpy( strike, strikePtr );
 		if( strike[0]	== '2' )
 		{
+			MGPMlogAdd( property, oldPortName, oldPortDir, "make Strike 3, marking port as ignore/looping ", " ", " " );
 			MGdbAdd( property->ignoreDb, oldPortDir, "looping, 3rd attempt at make", NULL );
-			if( property->log )
-			{
-				MGmStrcpy( localProperty.command, "echo \"make Strike 3 " );
-				MGmStrcat( localProperty.command, oldPortName );
-				MGmStrcat( localProperty.command, " " );
-				MGmStrcat( localProperty.command, oldPortDir );
-				MGmStrcat( localProperty.command, " marking port as ignore/looping " );
-				MGmStrcat( localProperty.command, " \">> /var/log/portmanager.log" );
-				system( localProperty.command );
-			}
 			rCleanUp( property, &localProperty );
 			return( 0 );
 		}
@@ -593,16 +583,8 @@
 							property->fieldStrikesIDX,
 							exact );
 			property->strikesDb	= MGdbDelete( property->strikesDb, MGdbGetRecno( property->strikesDb ) - 1 );
+			MGPMlogAdd( property, oldPortName, oldPortDir, "make Strike 2", " ", " " );
 			MGdbAdd( property->strikesDb, oldPortDir, "2", NULL );
-			if( property->log )
-			{
-				MGmStrcpy( localProperty.command, "echo \"make Strike 2 " );
-				MGmStrcat( localProperty.command, oldPortName );
-				MGmStrcat( localProperty.command, " " );
-				MGmStrcat( localProperty.command, oldPortDir );
-				MGmStrcat( localProperty.command, " \">> /var/log/portmanager.log" );
-				system( localProperty.command );
-			}
 /*
  * dualOriginCheck( property, oldPortName ); used to be here in old portmanager ver < 0.3.1, seems to be no longer
  * needed, keep this note just in case
@@ -797,20 +779,28 @@
 							MGPMlogAdd( property, "conflicting installed ", localProperty.installedPortName,
 								" removed from system: conflicted with ", oldPortName, " " );
 						}
+						cmd	= malloc( sizeof( char* ) * 4 );
+						cmd[0]	= malloc( MAXSTRINGSIZE );
+						cmd[1]	= malloc( MAXSTRINGSIZE );
+						cmd[2]	= malloc( MAXSTRINGSIZE );
+						cmd[3]	= 0;
+
+						MGmStrcpy( cmd[0], "/usr/sbin/pkg_delete" );
+						MGmStrcpy( cmd[1], "-f" );
+						MGmStrcpy( cmd[2], localProperty.installedPortName );
 
-						MGmStrcpy( localProperty.command, "pkg_delete -f " );
-						MGmStrcat( localProperty.command, localProperty.installedPortName );		
-						fprintf( stdout, "executing: %s\n", localProperty.command );
+						fprintf( stdout, "\nexecuting: %s %s %s\n", cmd[0], cmd[1], cmd[2] );
 						while( fflush( stdout ) );
-						errorCode	= system( localProperty.command );
-						if( property->log )
-						{
-							MGmStrcpy( localProperty.command, "echo \"removed conflicting port " );
-							MGmStrcat( localProperty.command, localProperty.installedPortName );
-							MGmStrcat( localProperty.command, " " );
-							MGmStrcat( localProperty.command, " \">> /var/log/portmanager.log" );
-							system( localProperty.command );
-						}
+
+						MGmSystem( cmd, NULL );
+
+						free( cmd[2] );
+						free( cmd[1] );
+						free( cmd[0] );		
+						free( cmd );
+
+						MGPMlogAdd( property, "removed conflicting port", localProperty.installedPortName,
+							" ", " ", " " );
 					}
 					installedPortsDbIDX++;
 				}
@@ -848,15 +838,7 @@
 		fprintf( stderr, "marking %s as ignored\n", oldPortName );
 		fprintf( stdout, "%s\n", DOUBLE_LINES );
 		while( fflush( stderr ) );
-		if( property->log )
-		{
-			MGmStrcpy( localProperty.command, "echo \"      " );
-			MGmStrcat( localProperty.command, oldPortName );
-			MGmStrcat( localProperty.command, " " );
-			MGmStrcat( localProperty.command, oldPortDir );
-			MGmStrcat( localProperty.command, " conflicts with another installed port so marked ignore\" >> /var/log/portmanager.log" );
-			system( localProperty.command );
-		}
+		MGPMlogAdd( property, oldPortName, oldPortDir, "conflicts with another installed port so marked ignore", " ", " " );
 		MGdbAdd( property->ignoreDb, oldPortDir, "conflicts with another installed port", NULL );
 		rCleanUp( property, &localProperty );
 		return( 0 );
@@ -986,15 +968,7 @@
 	while( fflush( stdout ) );
 	if( ( errorCode = system(localProperty.command) ) )
 	{
-		if( property->log )
-		{
-			MGmStrcpy( localProperty.command, "echo \"      " );
-			MGmStrcat( localProperty.command, oldPortName );
-			MGmStrcat( localProperty.command, " " );
-			MGmStrcat( localProperty.command, oldPortDir );
-			MGmStrcat( localProperty.command, " failed to fetch\" >> /var/log/portmanager.log" );
-			system( localProperty.command );
-		}
+		MGPMlogAdd( property, oldPortName, oldPortDir, "failed to fetch, adding to ignore.db", " ", " " );
 		fprintf( stdout, "%s %s error: make fetch returned an error, adding %s to ignore.db\n", id, PACKAGE_VERSION, oldPortDir );
 		while( fflush( stdout ) );
 		MGdbAdd( property->ignoreDb, oldPortDir, "failed during make fetch", NULL );
@@ -1005,70 +979,29 @@
 	/************************************************************************/
 	/*			Command "9" " make"				*/
 	/************************************************************************/
+	MGmStrcpy( localProperty.command, "cd " );
+	MGmStrcat( localProperty.command, PORTSDIR );
+	MGmStrcat( localProperty.command, oldPortDir );
+	MGmStrcat( localProperty.command, " && make " );
 	if( MGrStrlen( localProperty.options ) > 0 )
 	{
-		cmd	= malloc( sizeof( char** ) * 3 );
-		cmd[0]	= malloc( MAXSTRINGSIZE );
-		cmd[1]	= malloc( MAXBUFFERSIZE );
-		cmd[2]	= 0;
-		MGmStrcpy( cmd[0], PORTSDIR );
-		MGmStrcat( cmd[0], oldPortDir );
-		if( chdir( cmd[0] ) != 0 )
-		{
-			fprintf( stderr, "%s error: chdir %s failed\n", id, cmd[0] ); 
-			perror( "chroot" );
-			while( fflush( stderr ) );
-			assert( 0 );
-		}
-		MGmStrcpy( cmd[0], "/usr/bin/make" );
-		MGmBuffercpy( cmd[1], localProperty.options, MAXBUFFERSIZE );
-		fprintf( stdout, "%s\n", SINGLE_LINES );
-		fprintf( stdout, "update %s \n", oldPortName );
-		fprintf( stdout, "%s %s command: #9 of 14  %s\nOPTIONS-=>%s\n", id, PACKAGE_VERSION, cmd[0], cmd[1] );
-		fprintf( stdout, "%s\n", SINGLE_LINES );
-		while( fflush( stdout ) );
-		MGmSystem( cmd, localProperty.environment );	
-		free( cmd[0] );
-		free( cmd[1] );
-		free( cmd );
-	}
-	else
-	{
-		cmd	= malloc( sizeof( char** ) * 2 );
-		cmd[0]	= malloc( MAXSTRINGSIZE );
-		cmd[1]	= 0;
-		MGmStrcpy( cmd[0], PORTSDIR );
-		MGmStrcat( cmd[0], oldPortDir );
-		if( chdir( cmd[0] ) != 0 )
-		{
-			fprintf( stderr, "%s error: chdir %s failed\n", id, cmd[0] ); 
-			perror( "chroot" );
-			while( fflush( stderr ) );
-			assert( 0 );
-		}
-		MGmStrcpy( cmd[0], "/usr/bin/make" );
-		fprintf( stdout, "%s\n", SINGLE_LINES );
-		fprintf( stdout, "update %s \n", oldPortName );
-		fprintf( stdout, "%s %s command: #9 of 14  %s\n", id, PACKAGE_VERSION, cmd[0] );
-		fprintf( stdout, "%s\n", SINGLE_LINES );
-		while( fflush( stdout ) );
-		MGmSystem( cmd, localProperty.environment );	
-		free( cmd[0] );
-		free( cmd );
+		MGmStrcat( localProperty.command, localProperty.options );
 	}
 
-	if( MGrIfDirEntry( localProperty.workFullPath, ".build_done" ) == 0 )
+	fprintf( stdout, "%s\n", SINGLE_LINES );
+	fprintf( stdout, "update %s \n", oldPortName );
+	fprintf( stdout, "%s %s command: #9 of 14  %s\n", id, PACKAGE_VERSION, localProperty.command );
+	fprintf( stdout, "%s\n", SINGLE_LINES );
+	while( fflush( stdout ) );
+	if( ( errorCode = system(localProperty.command) ) )
 	{
-		fprintf( stderr, "%s\n", SINGLE_LINES );
-		fprintf( stderr, "%s error:  %s %s failed during make, adding to ignore.db\n", id, oldPortName, oldPortDir );
-		fprintf( stderr, "%s\n", SINGLE_LINES );
-		while( fflush( stderr ) );
-		MGPMlogAdd( property, oldPortName, oldPortDir, "port failed to build during make, adding to ignore.db", " ",  " " );
-		MGdbAdd( property->ignoreDb, oldPortDir, "port failed to build during make\n", NULL );
+		MGPMlogAdd( property, oldPortName, oldPortDir, "failed during make, adding to ignore.db", " ", " " );
+		fprintf( stdout, "%s %s error: make returned an error, adding %s to ignore.db\n", id, PACKAGE_VERSION, oldPortDir );
+		while( fflush( stdout ) );
+		MGdbAdd( property->ignoreDb, oldPortDir, "failed during make", NULL );
 		rCleanUp( property, &localProperty );
 		return(0);
 	}
-
 	/************************************************************************/
 	/*			Command "10" pkg_create -b			*/
 	/************************************************************************/
@@ -1113,12 +1046,12 @@
 	/*
 	 * inforced mass update mode portmanager  CANNOT loose its databases
 	 */
-	if( ( strcmp( oldPortDir, "/sysutils/portmanager" ) == 0 || strcmp( oldPortDir, "/local/sysutils/portmanager" ) == 0 ) &&
+	if( ( strcmp( oldPortDir, "/ports-mgmt/portmanager" ) == 0 || strcmp( oldPortDir, "/local/ports-mgmt/portmanager" ) == 0 ) &&
 		property->pmMode == SINGLE )
 	{
 		MGmStrcpy( localProperty.command, "cd " );
 		MGmStrcat( localProperty.command, PORTSDIR );
-		MGmStrcat( localProperty.command, "/sysutils/portmanager; " );
+		MGmStrcat( localProperty.command, "/ports-mgmt/portmanager; " );
 		MGmStrcat( localProperty.command, "make -V PKG_DBDIR" );
 		pHandle	= popen( localProperty.command, "r" );
 		localProperty.buffer[0]	= 0;
@@ -1146,7 +1079,7 @@
 		/*
 		 * have to do this here before db's are wacked
 		 */
-		if( ( strcmp( oldPortDir, "/sysutils/portmanager" ) == 0 || strcmp( oldPortDir, "/local/sysutils/portmanager" ) == 0 ) &&
+		if( ( strcmp( oldPortDir, "/ports-mgmt/portmanager" ) == 0 || strcmp( oldPortDir, "/local/ports-mgmt/portmanager" ) == 0 ) &&
 			property->pmMode == MULTI )
 		{
 			/*
@@ -1266,7 +1199,7 @@
 		MGmStrcat(localProperty.command, TEMPDIR);
 		MGmStrcat(localProperty.command, "/");
 		MGmStrcat(localProperty.command, oldPortName);
-		MGmStrcat(localProperty.command, ".tgz");
+		MGmStrcat(localProperty.command, ".t[bg]z");
 		fprintf( stdout, "%s\n", SINGLE_LINES );
 		fprintf( stderr, "restoring original port from backup \n" );
 		fprintf( stderr, "%s %s command: #12 of 14!! ***Emergancy restore***  %s\n", id, PACKAGE_VERSION, localProperty.command );
@@ -1330,7 +1263,7 @@
 			MGmStrcat( localProperty.command, TEMPDIR);
 			MGmStrcat( localProperty.command, "; rm -f ");
 			MGmStrcat( localProperty.command, oldPortName);
-			MGmStrcat( localProperty.command, ".tgz" );
+			MGmStrcat( localProperty.command, ".t[bg]z" );
 			fprintf( stdout, "%s\n", SINGLE_LINES );
 			fprintf( stderr, "deleting backup copy, installation of updated %s successful\n", oldPortDir );
 			fprintf( stdout, "%s %s localProperty.command: #12 of 14 %s\n", id, PACKAGE_VERSION, localProperty.command );
@@ -1414,7 +1347,7 @@
 	/*
 	 * if portmanager updated there won't be any databases, so need to clean the old fashoned way
 	 */
-	if( ( strcmp( oldPortDir, "/sysutils/portmanager" ) == 0 || strcmp( oldPortDir, "/local/sysutils/portmanager" ) == 0 ) &&
+	if( ( strcmp( oldPortDir, "/ports-mgmt/portmanager" ) == 0 || strcmp( oldPortDir, "/local/ports-mgmt/portmanager" ) == 0 ) &&
 		property->pmMode == MULTI )
 	{
 		rCleanDir( oldPortDir, localProperty.workDir );
@@ -1460,7 +1393,7 @@
 	/*
 	 * portmanager auto restart after updating itself
 	 */
-	if( ( strcmp( oldPortDir, "/sysutils/portmanager" ) == 0 || strcmp( oldPortDir, "/local/sysutils/portmanager" ) == 0 ) &&
+	if( ( strcmp( oldPortDir, "/ports-mgmt/portmanager" ) == 0 || strcmp( oldPortDir, "/local/ports-mgmt/portmanager" ) == 0 ) &&
 		property->pmMode == MULTI )
 	{
 		/*
@@ -1556,12 +1489,6 @@
 	MGdbDestroy( property->installedPortsDb );
 	MGdbDestroy( property->strikesDb );
 
-
-	free( localProperty->environment[0] );
-	free( localProperty->environment[1] );
-	free( localProperty->environment[2] );
-	free( localProperty->environment );
-
 	free( localProperty->CURDIR );
 	free( localProperty->afterOptionsFileSize );
 	free( localProperty->afterOptionsFileTime );
@@ -1655,7 +1582,7 @@
 	 */
 	MGmStrcpy( localProperty->command, "cd " );
 	MGmStrcat( localProperty->command, PORTSDIR );
-	MGmStrcat( localProperty->command, "/sysutils/portmanager; make -V PKGNAME" );
+	MGmStrcat( localProperty->command, "/ports-mgmt/portmanager; make -V PKGNAME" );
 	pHandle	= popen( localProperty->command, "r" );
 	localProperty->buffer[0]	= 0;
 	fread( localProperty->buffer, MAXBUFFERSIZE - 1, 1, pHandle );
@@ -1693,7 +1620,7 @@
 			 */
 			MGmStrcpy( localProperty->command, "cd " );
 			MGmStrcat( localProperty->command, PORTSDIR );
-			MGmStrcat( localProperty->command, "/sysutils/portmanager; make -V PKGNAME" );
+			MGmStrcat( localProperty->command, "/ports-mgmt/portmanager; make -V PKGNAME" );
 			pHandle	= popen( localProperty->command, "r" );
 			localProperty->buffer[0]	= 0;
 			fread( localProperty->buffer, MAXBUFFERSIZE - 1, 1, pHandle );
@@ -1737,7 +1664,7 @@
 	 */
 	MGmStrcpy( localProperty->command, "cd " );
 	MGmStrcat( localProperty->command, PORTSDIR );
-	MGmStrcat( localProperty->command, "/sysutils/portmanager; make -V PORTMANAGER" );
+	MGmStrcat( localProperty->command, "/ports-mgmt/portmanager; make -V PORTMANAGER" );
 	pHandle	= popen( localProperty->command, "r" );
 	localProperty->buffer[0]	= 0;
 	fread( localProperty->buffer, MAXBUFFERSIZE - 1, 1, pHandle );
