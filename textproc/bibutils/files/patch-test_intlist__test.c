--- test/intlist_test.c.orig	2019-01-06 09:13:07 UTC
+++ test/intlist_test.c
@@ -275,7 +275,7 @@ test_randomize( void )
 	check_len( &a, 100 );
 	for ( i=0; i<99; ++i ) {
 		m = intlist_find( &a, i );
-		check( (m>=0&&m<99), "intlist_randomize() shouldn't remove values" );
+		check( (m>=0&&m<=99), "intlist_randomize() shouldn't remove values" );
 	}
 
 	intlist_free( &a );
