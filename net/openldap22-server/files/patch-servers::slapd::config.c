--- servers/slapd/config.c	Mon Oct 13 03:57:02 2003
+++ servers/slapd/config.c	Sun Oct 19 15:33:56 2003
@@ -2782,9 +2782,9 @@
 		ber_dupbv( &si->updatedn, &be->be_rootndn );
 	si->bindmethod = LDAP_AUTH_SIMPLE;
 	si->schemachecking = 0;
-	si->filterstr = "(objectclass=*)";
+	ber_str2bv( "(objectclass=*)", sizeof("(objectclass=*)")-1, 0, &si->filterstr );
 	if ( be->be_suffix && be->be_suffix[0].bv_val )
-		si->base = ch_strdup( be->be_suffix[0].bv_val );
+		ber_dupbv( &si->base, &be->be_nsuffix[0] );
 	si->scope = LDAP_SCOPE_SUBTREE;
 	si->attrsonly = 0;
 	si->attrs = (char **) ch_calloc( 1, sizeof( char * ));
@@ -2914,14 +2914,11 @@
 			}
 		} else if ( !strncasecmp( cargv[ i ],
 				UPDATEDNSTR, sizeof( UPDATEDNSTR ) - 1 ) ) {
-			char *str;
 			struct berval updatedn = {0, NULL};
 			val = cargv[ i ] + sizeof( UPDATEDNSTR );
-			str = ch_strdup( val );
-			ber_str2bv( str, strlen(str), 1, &updatedn );
+			ber_str2bv( val, 0, 0, &updatedn );
+			ch_free( si->updatedn.bv_val );
 			dnNormalize( 0, NULL, NULL, &updatedn, &si->updatedn, NULL );
-			ch_free( str );
-			ch_free( updatedn.bv_val );
 		} else if ( !strncasecmp( cargv[ i ], BINDMETHSTR,
 				sizeof( BINDMETHSTR ) - 1 ) ) {
 			val = cargv[ i ] + sizeof( BINDMETHSTR );
@@ -2987,11 +2984,17 @@
 		} else if ( !strncasecmp( cargv[ i ],
 				FILTERSTR, sizeof( FILTERSTR ) - 1 ) ) {
 			val = cargv[ i ] + sizeof( FILTERSTR );
-			si->filterstr = ch_strdup( val );
+			ber_str2bv( val, 0, 1, &si->filterstr );
 		} else if ( !strncasecmp( cargv[ i ],
 				SEARCHBASESTR, sizeof( SEARCHBASESTR ) - 1 ) ) {
+			struct berval bv;
 			val = cargv[ i ] + sizeof( SEARCHBASESTR );
-			si->base = ch_strdup( val );
+			ch_free( si->base.bv_val );
+			ber_str2bv( val, 0, 0, &bv );
+			if ( dnNormalize( 0, NULL, NULL, &bv, &si->base, NULL )) {
+				fprintf( stderr, "Invalid base DN \"%s\"\n", val );
+				return 1;
+			}
 		} else if ( !strncasecmp( cargv[ i ],
 				SCOPESTR, sizeof( SCOPESTR ) - 1 ) ) {
 			val = cargv[ i ] + sizeof( SCOPESTR );
