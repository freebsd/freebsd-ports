--- ./t2pkg.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./t2pkg.c	2014-06-29 12:15:04.248542975 +0200
@@ -38,6 +38,7 @@
 extern off_t	lsize;
 extern char	*version;
 
+int		tran_format = -1;
 int		cksum = 0;
 int		force = 0;
 int		case_sensitive = 1;
@@ -718,31 +719,23 @@
 	}
 
 	/* create the destination path */
-	if ( snprintf( tmp, MAXPATHLEN, "%s/%s", dstdir, t->t_pinfo.pi_name )
+	if ( snprintf( dst, MAXPATHLEN, "%s/%s", dstdir, t->t_pinfo.pi_name )
 		>= MAXPATHLEN ) {
 	    fprintf( stderr, "%s/%s: path too long\n", dstdir,
 			t->t_pinfo.pi_name );
 	    exit( 2 );
 	}
-	if ( mkdirs( tmp ) < 0 ) {
-	    fprintf( stderr, "mkdirs %s: %s\n", tmp, strerror( errno ));
-	}
-	if ( realpath( tmp, dst ) == NULL ) {
-	    fprintf( stderr, "realpath %s: %s\n", tmp, strerror( errno ));
-	    exit( 2 );
+	if ( mkdirs( dst ) < 0 ) {
+	    fprintf( stderr, "mkdirs %s: %s\n", dst, strerror( errno ));
 	}
 
 	/* and the source path */
-	if ( snprintf( tmp, MAXPATHLEN, "%s/%s", root, t->t_pinfo.pi_name )
+	if ( snprintf( src, MAXPATHLEN, "%s/%s", root, t->t_pinfo.pi_name )
 		>= MAXPATHLEN ) {
 	    fprintf( stderr, "%s/%s: path too long\n", dstdir,
 			t->t_pinfo.pi_name );
 	    exit( 2 );
 	}
-	if ( realpath( tmp, src ) == NULL ) {
-	    fprintf( stderr, "realpath %s: %s\n", tmp, strerror( errno ));
-	    exit( 2 );
-	}
 
 	if ( local_update( t, dst, src, where ) != 0 ) {
 	    /* XXX is this really a good idea? */
