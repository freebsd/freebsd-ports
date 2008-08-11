--- dvd.c.orig	2008-02-19 00:27:04.000000000 -0500
+++ dvd.c	2008-08-08 19:02:43.000000000 -0400
@@ -510,7 +510,15 @@
 	   */
 	     
 
-	   k = strstr( tmp_bufferin, " " );
+	   k = strpbrk( tmp_bufferin, " \t" );
+
+	   /* Avoid a core dump by checking that the break token
+	      was found */
+	   if ( k == NULL )
+	     {
+	         fprintf(stderr, "[Error] Unable to parse the /etc/fstab file\n");
+	         return -1;
+	     }
 
 	   /*traverse the gap*/
 
@@ -646,21 +654,6 @@
    	   return ( off_t ) vob_size;
 	}
    
-      sprintf( stat_path, "%s_1.vob", path_to_vobs3 );
-      if( ( tmp_streamin1 = fopen( stat_path, "r" ) ) != NULL ) /*check if this path is correct */
-	{
-	  fclose ( tmp_streamin1 );
-	  subvob = 1;
-	  while( !stat( stat_path, &buf ) )
-	    {
-	      /* adjust path for next subvob */
-	      subvob++;
-          sprintf( stat_path, "%s_%d.vob", path_to_vobs3, subvob );	      
-	      vob_size += buf.st_size;
-	    }
-          return ( off_t ) vob_size; 
-	}
-
       /*none of the above seemed to have caught it, so this is the error return */
       return ( off_t ) 0; /* think that (off_t) is not really needed here?
 				  as it is defined as off_t and the function is
