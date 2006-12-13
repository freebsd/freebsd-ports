--- ./libMG/src/MGdbRead.c.orig	Mon Dec 12 15:32:34 2005
+++ ./libMG/src/MGdbRead.c	Fri Dec  8 17:13:00 2006
@@ -58,6 +58,7 @@
 		fprintf( stderr, "%s error: unable to allocate %d bytes memory for db->dataBuffer\n",
 			id, dataBufferSize );
 		perror( "system message" );
+		while( fflush( stderr ) );
 		assert(0);
 	}
 	/*zzzzzzzzzzzzzz*/
@@ -70,6 +71,7 @@
 	{
 		fprintf( stderr, "%s error: reading file %s into db->dataBuffer\n", id, db->parent.path );
 		perror( "system message" );	\
+		while( fflush( stderr ) );
 		assert(0);
 	}
 
