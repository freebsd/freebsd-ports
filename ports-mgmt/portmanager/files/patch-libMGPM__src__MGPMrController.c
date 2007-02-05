--- libMGPM/src/MGPMrController.c.orig	Mon Feb  5 12:46:30 2007
+++ libMGPM/src/MGPMrController.c	Mon Feb  5 12:47:49 2007
@@ -270,7 +270,7 @@
 				fprintf( stdout, "%s\n", "running in WITH_BUILD_DEPENDS_ARE_LEAVES mode" );
 				fprintf( stdout, "%s\n", "using this mode is not endorsed by author, if ports" );
 				fprintf( stdout, "%s\n", "fail building due to missing build dependencies" );
-				fprintf( stdout, "%s\n", "in sysutils/portmanager run \"make config\" and shut this mode off" );
+				fprintf( stdout, "%s\n", "in ports-mgmt/portmanager run \"make config\" and shut this mode off" );
 				fprintf( stdout, "%s\n", "then rebuild/reinstall portmanager before contacting author/maintainer" );
 				fprintf( stdout, "%s\n", DOUBLE_LINES );
 				while( fflush( stdout ) );
