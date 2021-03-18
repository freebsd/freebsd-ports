--- source/iked/crypto.cpp.orig	2012-12-11 06:56:33 UTC
+++ source/iked/crypto.cpp
@@ -376,10 +376,6 @@ bool dh_init( long group, DH ** dh_data, long * dh_siz
 	if( dh == NULL )
 		return false;
 
-	dh->p = NULL;
-	dh->g = NULL;
-	dh->length = 0;
-
 	//
 	// set p ( prime ) value
 	//
@@ -387,49 +383,50 @@ bool dh_init( long group, DH ** dh_data, long * dh_siz
 	unsigned char * p_data = NULL;
 	size_t			p_size = 0;
 
-	dh->p = BN_new();
-	if( dh->p == NULL )
+	BIGNUM *p = BN_new();
+	BIGNUM *g = BN_new();
+	if( p == NULL || g == NULL )
 		goto dh_failed;
 
 	switch( group )
 	{
 		case 1:
-			if( !BN_bin2bn( group1, sizeof( group1 ), dh->p ) )
+			if( !BN_bin2bn( group1, sizeof( group1 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 2:
-			if( !BN_bin2bn( group2, sizeof( group2 ), dh->p ) )
+			if( !BN_bin2bn( group2, sizeof( group2 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 5:
-			if( !BN_bin2bn( group5, sizeof( group5 ), dh->p ) )
+			if( !BN_bin2bn( group5, sizeof( group5 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 14:
-			if( !BN_bin2bn( group14, sizeof( group14 ), dh->p ) )
+			if( !BN_bin2bn( group14, sizeof( group14 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 15:
-			if( !BN_bin2bn( group15, sizeof( group15 ), dh->p ) )
+			if( !BN_bin2bn( group15, sizeof( group15 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 16:
-			if( !BN_bin2bn( group16, sizeof( group16 ), dh->p ) )
+			if( !BN_bin2bn( group16, sizeof( group16 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 17:
-			if( !BN_bin2bn( group17, sizeof( group17 ), dh->p ) )
+			if( !BN_bin2bn( group17, sizeof( group17 ), p ) )
 				goto dh_failed;
 			break;
 
 		case 18:
-			if( !BN_bin2bn( group18, sizeof( group18 ), dh->p ) )
+			if( !BN_bin2bn( group18, sizeof( group18 ), p ) )
 				goto dh_failed;
 			break;
 
@@ -441,13 +438,11 @@ bool dh_init( long group, DH ** dh_data, long * dh_siz
 	// set g ( generator ) value
 	//
 
-	dh->g = BN_new();
-	if( dh->g == NULL )
+	if( !BN_set_word( g, 2 ) )
 		goto dh_failed;
 
-	if( !BN_set_word( dh->g, 2 ) )
-		goto dh_failed;
-
+	DH_set0_pqg(dh, p, NULL, g);
+
 	//
 	// generate private and public DH values
 	//
@@ -456,7 +451,7 @@ bool dh_init( long group, DH ** dh_data, long * dh_siz
 		goto dh_failed;
 
 	*dh_data = dh;
-	*dh_size = BN_num_bytes( dh->p );
+	*dh_size = BN_num_bytes( DH_get0_p( dh ) );
 
 	return true;
 
