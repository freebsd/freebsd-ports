--- mkCTM/mkctm.c.ORI	2025-08-10 16:21:45.903739000 +0000
+++ mkCTM/mkctm.c	2025-08-14 06:30:11.360142000 +0000
@@ -44,6 +44,8 @@
 int	change;
 int	Have_ctm_status, Have_svn_revision;
 
+static char Enb[ BUFSIZ ];
+
 FILE	*logfile;
 
 u_long s1_ignored,	s2_ignored;
@@ -122,6 +124,63 @@
 	return 1;
 }
 
+int name_encode( const char* name, const char* d_name )
+{
+  static char b[ BUFSIZ ];
+  char* in;
+  char* cp;
+  uint16_t cnts, cntp;
+
+
+  // Create file name with path
+  //
+  if( snprintf( b, BUFSIZ, "%s%s", name, d_name ) >= BUFSIZ ) {
+    fprintf( stderr, "name_encode: snprintf\n" );
+    exit( 1 );
+  }
+
+
+  // Determine number of spaces and '%'
+  //
+  cntp = cnts = 0;
+  for( in=b; *in != '\0'; in++ ) {
+    if( *in == ' ' )
+      cnts++;
+    if( *in == '%' )
+      cntp++;
+  }
+
+
+  // No spaces found, return
+  //
+  if( cnts == 0 )
+    return 0;
+
+
+  // Die if encoded filename would become too long
+  //
+  if( strlen( b ) + cnts + cntp + 1 > BUFSIZ ) {
+    fprintf( stderr, "name_encode: name too long\n" );
+    exit( 1 );
+  }
+
+
+  // Encode file name (w/o leading '/')
+  //
+  cp = &Enb[0];
+  for( in = b; *in != '\0'; in++ ) {
+
+    if( *in == ' ' || *in == '%' ) {	// found space or '%'
+      *cp++ = '%';			// store magic
+      *cp++ = *in + 0x20;		// store encoded char
+
+    } else				// no space, no '%', copy
+      *cp++ = *in;
+  }
+
+  return 1;
+}
+
 void
 name_stat(const char *pfx, const char *dir, const char *name, struct dirent *de)
 {
@@ -133,6 +192,9 @@
 		strcat(buf, "/"); strcat(buf, name);
 		strcat(buf, "/"); strcat(buf, de->d_name);
 	st = StatFile(buf);
+  if( name_encode( name, de->d_name ) )
+    printf("%s /%s %u %u %o", pfx, Enb, st->st_uid, st->st_gid, st->st_mode & ~S_IFMT);
+  else
 	printf("%s %s%s %u %u %o", 
 	    pfx, name, de->d_name, 
 	    st->st_uid, st->st_gid, st->st_mode & ~S_IFMT);
@@ -181,8 +243,14 @@
 
 	  change++;
 
+  if( name_encode( name, de->d_name ) )
+    printf( "CTMLR /%s\n", Enb );
+  else
 	  printf( "CTMLR %s%s\n", name, de->d_name );
 	  name_stat("CTMLM", dir2, name, de);
+  if( name_encode( lbuf2, "" ) )
+    printf( " /%s\n", Enb );
+  else
 	  printf( " %s\n", lbuf2 );
 
 	  free( buf1 );
@@ -419,6 +487,9 @@
 		char *p = alloca(strlen(name)+strlen(de->d_name)+2);
 		strcpy(p, name);  strcat(p, de->d_name); strcat(p, "/");
 		DoDir(dir1, dir2, p);
+  if( name_encode( name, de->d_name ) )
+    printf("CTMDR /%s\n", Enb );
+  else
 		printf("CTMDR %s%s\n", name, de->d_name);
 		fprintf(logfile, "CTMDR %s%s\n", name, de->d_name);
 		if (verbose > 1) {
@@ -428,6 +499,9 @@
 
 	} else if( de->d_type == DT_LNK ) {
 
+  if( name_encode( name, de->d_name ) )
+    printf( "CTMLR /%s\n", Enb );
+  else
 	  printf( "CTMLR %s%s\n", name, de->d_name );
 	  fprintf( logfile, "CTMLR %s%s\n", name, de->d_name );
 	  if( verbose > 1 )
@@ -441,6 +515,9 @@
 			strcat(buf1, "/"); strcat(buf1, name);
 			strcat(buf1, "/"); strcat(buf1, de->d_name);
 		m1 = MD5File(buf1, md5_1);
+  if( name_encode( name, de->d_name ) )
+    printf("CTMFR /%s %s\n", Enb, m1);
+  else
 		printf("CTMFR %s%s %s\n", name, de->d_name, m1);
 		fprintf(logfile, "CTMFR %s%s %s\n", name, de->d_name, m1);
 		if (verbose > 1) {
