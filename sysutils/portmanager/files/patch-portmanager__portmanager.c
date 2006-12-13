--- ./portmanager/portmanager.c.orig	Mon Dec 12 19:20:58 2005
+++ ./portmanager/portmanager.c	Fri Dec  8 17:13:00 2006
@@ -34,7 +34,13 @@
 int	main( int argc, char** argv, char** argp)
 {
 	int	errorCode	= 0;
-	
+
+	if ( getuid() != 0 )
+	{
+		fprintf( stderr, "%s must be run as root\n", argv[0] );
+		exit( 1 );
+	}
+
 	errorCode	= MGPMrCommandLine( argc, (char**)argv, (char**)argp ); 
 	exit( errorCode );
 }
