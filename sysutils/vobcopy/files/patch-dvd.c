--- dvd.c.orig	Tue Dec  5 00:06:52 2006
+++ dvd.c	Tue Dec  5 00:09:54 2006
@@ -637,21 +637,6 @@
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
