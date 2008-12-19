--- modules/access/vcd/cdrom.c
+++ modules/access/vcd/cdrom.c
@@ -820,6 +820,7 @@ static int OpenVCDImage( vlc_object_t * p_this, const char *psz_dev,
     char *psz_vcdfile = NULL;
     char *psz_cuefile = NULL;
     FILE *cuefile     = NULL;
+    int *p_sectors    = NULL;
     char line[1024];
     bool b_found      = false;
 
@@ -858,7 +859,6 @@ static int OpenVCDImage( vlc_object_t * p_this, const char *psz_dev,
     cuefile = utf8_fopen( psz_cuefile, "rt" );
     if( cuefile == NULL )
     {
-        i_ret = -1;
         msg_Dbg( p_this, "could not find .cue file" );
         goto error;
     }
@@ -904,58 +904,56 @@ static int OpenVCDImage( vlc_object_t * p_this, const char *psz_dev,
     }
 
     if( p_vcddev->i_vcdimage_handle == -1)
-    {
-        i_ret = -1;
         goto error;
-    }
-    else i_ret = 0;
 
     /* Try to parse the i_tracks and p_sectors info so we can just forget
      * about the cuefile */
-    if( i_ret == 0 )
+    size_t i_tracks = 0;
+
+    while( fgets( line, 1024, cuefile ) )
     {
-        int p_sectors[100];
-        int i_tracks = 0;
-        int i_num;
-        char psz_dummy[10];
+        /* look for a TRACK line */
+        char psz_dummy[9];
+        if( !sscanf( line, "%9s", psz_dummy ) || strcmp(psz_dummy, "TRACK") )
+            continue;
 
+        /* look for an INDEX line */
         while( fgets( line, 1024, cuefile ) )
         {
-            /* look for a TRACK line */
-            if( !sscanf( line, "%9s", psz_dummy ) ||
-                strcmp(psz_dummy, "TRACK") )
-                continue;
-
-            /* look for an INDEX line */
-            while( fgets( line, 1024, cuefile ) )
-            {
-                int i_min, i_sec, i_frame;
+            int i_num, i_min, i_sec, i_frame;
 
-                if( (sscanf( line, "%9s %2u %2u:%2u:%2u", psz_dummy, &i_num,
-                            &i_min, &i_sec, &i_frame ) != 5) || (i_num != 1) )
-                    continue;
+            if( (sscanf( line, "%*9s %2u %2u:%2u:%2u", &i_num,
+                         &i_min, &i_sec, &i_frame ) != 4) || (i_num != 1) )
+                continue;
 
-                i_tracks++;
-                p_sectors[i_tracks - 1] = MSF_TO_LBA(i_min, i_sec, i_frame);
-                msg_Dbg( p_this, "vcd track %i begins at sector:%i",
-                         i_tracks - 1, p_sectors[i_tracks - 1] );
-                break;
-            }
+            int *buf = realloc (p_sectors, (i_tracks + 1) * sizeof (int));
+            if (buf == NULL)
+                goto error;
+            p_sectors = buf;
+            p_sectors[i_tracks] = MSF_TO_LBA(i_min, i_sec, i_frame);
+            msg_Dbg( p_this, "vcd track %i begins at sector:%i",
+                     i_tracks, p_sectors[i_tracks] );
+            i_tracks++;
+            break;
         }
-
-        /* fill in the last entry */
-        p_sectors[i_tracks] = lseek(p_vcddev->i_vcdimage_handle, 0, SEEK_END)
-                                / VCD_SECTOR_SIZE;
-        msg_Dbg( p_this, "vcd track %i, begins at sector:%i",
-                 i_tracks, p_sectors[i_tracks] );
-        p_vcddev->i_tracks = i_tracks;
-        p_vcddev->p_sectors = malloc( (i_tracks + 1) * sizeof(int) );
-        memcpy( p_vcddev->p_sectors, p_sectors, (i_tracks + 1) * sizeof(int) );
-
     }
 
+    /* fill in the last entry */
+    int *buf = realloc (p_sectors, (i_tracks + 1) * sizeof (int));
+    if (buf == NULL)
+        goto error;
+    p_sectors = buf;
+    p_sectors[i_tracks] = lseek(p_vcddev->i_vcdimage_handle, 0, SEEK_END)
+                                 / VCD_SECTOR_SIZE;
+    msg_Dbg( p_this, "vcd track %i, begins at sector:%i",
+             i_tracks, p_sectors[i_tracks] );
+    p_vcddev->i_tracks = ++i_tracks;
+    p_vcddev->p_sectors = p_sectors;
+    i_ret = 0;
+
 error:
     if( cuefile ) fclose( cuefile );
+    if( p_sectors ) free( p_sectors );
     if( psz_cuefile ) free( psz_cuefile );
     if( psz_vcdfile ) free( psz_vcdfile );free( p_sectors );
