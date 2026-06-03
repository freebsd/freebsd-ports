--- mkCTM/mkctm.c.ORI	2023-12-29 09:07:16.210417000 +0100
+++ mkCTM/mkctm.c	2023-12-29 09:07:16.211918000 +0100
@@ -155,6 +155,39 @@
 		strcpy(p, name);  strcat(p, de->d_name); strcat(p, "/");
 		DoDir(dir1, dir2, p);
 		s_same_dirs++;
+
+	} else if( de->d_type == DT_LNK ) {
+
+	  char	  lbuf1[ PATH_MAX ];
+	  char	  lbuf2[ PATH_MAX ];
+	  char*	  buf1;
+	  char*	  buf2;
+	  ssize_t ret1, ret2;
+
+	  if( asprintf( &buf1, "%s/%s/%s", dir1, name, de->d_name ) <= 0 )
+	    err( 3, "asprintf: %s", dir2 );
+	  if( asprintf( &buf2, "%s/%s/%s", dir2, name, de->d_name ) <= 0 )
+	    err( 3, "asprintf: %s", dir2 );
+
+	  if( (ret1 = readlink( buf1, lbuf1, sizeof lbuf1 - 1 )) == -1 )
+	    err( 3, "readlink: %s", buf1 );
+	  lbuf1[ ret1 ] = '\0';
+	  if( (ret2 = readlink( buf2, lbuf2, sizeof lbuf2 - 1 )) == -1 )
+	    err( 3, "readlink: %s", buf2 );
+	  lbuf2[ ret2 ] = '\0';
+
+	  if( strcmp( lbuf1, lbuf2 ) == 0 )
+	    return;
+
+	  change++;
+
+	  printf( "CTMLR %s%s\n", name, de->d_name );
+	  name_stat("CTMLM", dir2, name, de);
+	  printf( " %s\n", lbuf2 );
+
+	  free( buf1 );
+	  free( buf2 );
+
 	} else {
 		char *buf1 = alloca(strlen(dir1) + strlen(name) + 
 			strlen(de->d_name) + 3);
@@ -326,6 +359,25 @@
 		putchar('\n');
 		s_new_dirs++;
 		DoDir(dir1, dir2, p);
+
+	} else if( de->d_type == DT_LNK ) {
+
+	  char*	  buf2;
+	  char	  lbuf[ PATH_MAX ];
+	  ssize_t ret;
+
+	  if( asprintf( &buf2, "%s/%s/%s", dir2, name, de->d_name ) <= 0 )
+	    err( 3, "asprintf: %s", dir2 );
+
+	  if( (ret = readlink( buf2, lbuf, sizeof lbuf - 1 )) == -1 )
+	    err( 3, "readlink: %s", buf2 );
+	  lbuf[ ret ] = '\0';
+
+	  name_stat( "CTMLM", dir2, name, de );
+	  printf( " %s\n", lbuf );
+
+	  free( buf2 );
+
 	} else if (de->d_type == DT_REG) {
 		char *buf2 = alloca(strlen(dir2) + strlen(name) + 
 			strlen(de->d_name) + 3);
@@ -373,6 +425,14 @@
 			fprintf(stderr, "CTMDR %s%s\n", name, de->d_name);
 		}
 		s_del_dirs++;
+
+	} else if( de->d_type == DT_LNK ) {
+
+	  printf( "CTMLR %s%s\n", name, de->d_name );
+	  fprintf( logfile, "CTMLR %s%s\n", name, de->d_name );
+	  if( verbose > 1 )
+	    fprintf( stderr, "CTMLR %s%s\n", name, de->d_name );
+
 	} else if (de->d_type == DT_REG) {
 		char *buf1 = alloca(strlen(dir1) + strlen(name) + 
 			strlen(de->d_name) + 3);
@@ -436,6 +496,10 @@
 			nl[*i]->d_type = IFTODT(StatFile(buf)->st_mode);
 		if (nl[*i]->d_type == DT_REG || nl[*i]->d_type == DT_DIR)
 			break;
+
+		if( nl[*i]->d_type == DT_LNK )
+		  break;
+
 		(*wrong)++;
 		if (verbose > 0)
 			fprintf(stderr, "Wrong %s\n", buf);
