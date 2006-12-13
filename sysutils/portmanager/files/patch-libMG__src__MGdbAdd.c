--- ./libMG/src/MGdbAdd.c.orig	Mon Dec 12 15:32:34 2005
+++ ./libMG/src/MGdbAdd.c	Fri Dec  8 17:13:00 2006
@@ -39,7 +39,9 @@
 	int	idx		= 0;
 	va_list	paramList;
 	
-	/* check if we have a valid object */
+	/*
+	 * check if we have a valid object
+	 */
 	if( db->parent.type != CLASS_TYPE_DB )
 	{
 		fprintf( stderr, "%s error: invalid object type\n", id);
@@ -71,6 +73,8 @@
 		 */ 
 		if( MGrBufferlen( paramPtr, MAXBUFFERSIZE ) < 1 )
 		{
+			fprintf( stderr, "%s error: attempt to place null data into record halted\n", id );
+			while( fflush( stderr ) );
 			assert(0);
 		}
 		fprintf( dbFileStream, "%s%c", paramPtr, 0 );
@@ -85,6 +89,7 @@
 		{
 			fprintf( stderr, "%s error: fields added (%d) exceed field quantity (%d)\n did you forget to terminate MGdbAdd with a NULL field?\n",
 				id, idx, db->fieldQty );
+			while( fflush( stderr ) );
 			assert(0);
 		}
 	}
