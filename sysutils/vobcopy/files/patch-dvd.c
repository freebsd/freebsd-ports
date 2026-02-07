--- dvd.c.orig	2022-05-03 19:55:34 UTC
+++ dvd.c
@@ -176,7 +176,7 @@ int get_device( char *path, char *device )
        if( !strcmp( path, buf.f_mntonname ) )
          {
            mounted = TRUE;
-#if defined(__FreeBSD__) && (__FreeBSD_Version > 500000)
+#if defined(__FreeBSD__) && (__FreeBSD_version > 500000)
           strcpy(device, buf.f_mntfromname);
 #else
 	   strcpy(device, "/dev/r");
@@ -294,7 +294,7 @@ this is the code for the other-OSs, not solaris*/
 #endif
 
     
-    if( ( tmp_streamin = fopen( "/etc/mtab", "r" ) ) )
+    if( ( tmp_streamin = fopen( "/etc/fstab", "r" ) ) )
       {
 	strcpy( tmp_path, path );
 	strcat( tmp_path, " " ); /* otherwise it would detect that e.g. 
@@ -346,7 +346,7 @@ this is the code for the other-OSs, not solaris*/
 
 		if( ( k = strstr( tmp_bufferin, "/dev/" ) ) == NULL )
 		  {
-		    fprintf( stderr, _("[Error] Weird, no /dev/ entry found in the line where iso9660 or udf gets mentioned in /etc/fstab\n") );
+		    fprintf( stderr, _("[Error] Weird, no /dev/ entry found in the line where cd9660 or udf gets mentioned in /etc/fstab\n") );
 		    return -1;
 		  }
 		l=0;
@@ -404,7 +404,8 @@ int get_device_on_your_own( char *path, char *device )
   struct statvfs *mntbuf;
 #endif
 
-  if( ( n = getmntinfo( &mntbuf, 0 ) ) > 0 )
+  path[0] = '\0';
+  if( ( n = getmntinfo( &mntbuf, MNT_NOWAIT ) ) > 0 )
     {
       for( i = 0; i < n; i++ )
         {
@@ -412,7 +413,7 @@ int get_device_on_your_own( char *path, char *device )
             {
               dvd_count++;
               strcpy( path, mntbuf[i].f_mntonname );
-#if defined(__FreeBSD__) && (__FreeBSD_Version > 500000)
+#if defined(__FreeBSD__) && (__FreeBSD_version > 500000)
              strcat(device, mntbuf[i].f_mntfromname);
 #else
 	      strcpy(device, "/dev/r");
@@ -495,14 +496,14 @@ int get_device_on_your_own( char *path, char *device )
    *read the device out of /etc/mtab
    */
 
- if( ( tmp_streamin = fopen( "/etc/mtab", "r" ) ) )
+ if( ( tmp_streamin = fopen( "/etc/fstab", "r" ) ) )
    {
-/*      strcpy(tmp_path, "iso9660"); */
+/*      strcpy(tmp_path, "cd9660"); */
      memset( tmp_bufferin, 0, MAX_STRING * sizeof( char ) );
      while( fgets( tmp_bufferin, MAX_STRING, tmp_streamin ) ) 
      {
 /*        if(strstr( tmp_bufferin, tmp_path)) */
-       if (strstr( tmp_bufferin, "iso9660" ) || 
+       if (strstr( tmp_bufferin, "cd9660" ) || 
            strstr( tmp_bufferin, "udf" )     || 
            strstr( tmp_bufferin, "cdrom" )   || 
            strstr( tmp_bufferin, "dvd" ) )
@@ -514,7 +515,7 @@ int get_device_on_your_own( char *path, char *device )
 
 	   if( ( k = strstr( tmp_bufferin, "/dev/" ) ) == NULL )
 	     {
-	       fprintf( stderr, _("[Error] Weird, no /dev/ entry found in the line where iso9660, udf or cdrom gets mentioned in /etc/mtab\n") );
+	       fprintf( stderr, _("[Error] Weird, no /dev/ entry found in the line where cd9660, udf or cdrom gets mentioned in /etc/mtab\n") );
 	       dvd_count--;
 	       continue;
 	     }
@@ -544,8 +545,17 @@ int get_device_on_your_own( char *path, char *device )
 	   */
 	     
 
-	   k = strstr( tmp_bufferin, " " );
+	   k = strpbrk( tmp_bufferin, " \t" );
 
+	   /* Avoid a core dump by checking that the break token
+	      was found */
+	   if ( k == NULL )
+	     {
+	         fprintf(stderr, "[Error] Unable to parse the /etc/fstab file\n");
+	         path[0] = '\0';
+	         return -1;
+	     }
+
 	   /*traverse the gap*/
 
 	   if( isgraph( (int) *(k) ))
@@ -680,21 +690,6 @@ off_t get_vob_size( int title, char *provided_input_di
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
-          snprintf( stat_path, sizeof(stat_path), "%s_%d.vob", path_to_vobs3, subvob );
-	      vob_size += buf.st_size;
-	    }
-          return ( off_t ) vob_size; 
-	}
-
       /*none of the above seemed to have caught it, so this is the error return */
       return ( off_t ) 0; /* think that (off_t) is not really needed here?
 				  as it is defined as off_t and the function is
