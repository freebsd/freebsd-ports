--- dvd.c.orig	Wed Dec  7 21:31:56 2005
+++ dvd.c	Wed Feb  1 22:23:15 2006
@@ -692,28 +692,6 @@
 /* 	      fprintf(stderr,"debug: vob_size: %lli\n",buf.st_size); */
 	    }
 	}
-      strcpy( stat_path, path_to_vobs3 );
-      strcat( stat_path, "_1.vob" );
-      if( ( tmp_streamin1 = fopen( stat_path, "r" ) ) != NULL ) /*check if this path is correct */
-	{
-	  fclose ( tmp_streamin1 );
-	  subvob = 1;
-	  while( !stat( stat_path, &buf ) )
-	    {
-	      /* adjust path for next subvob */
-	      subvob++;
-	      strcpy( stat_path, path_to_vobs3 );
-	      strcat( stat_path, "_" );
-	      sprintf( temp1, "%d", subvob );
-	      strcat( stat_path, temp1 );
-	      strcat( stat_path, ".vob" );
-	      
-	      vob_size += buf.st_size;
-/* 	      fprintf(stderr,"debug: vob_size: %lli\n",vob_size); */
-/* 	      fprintf(stderr,"debug: vob_size: %lli\n",buf.st_size); */
-	    }
-	}
-
       return ( off_t ) vob_size; /* think that (off_t) is not really needed here?
 				  as it is defined as off_t and the function is
 				  also defined as off_t */
