#
# ITS#2348: Index corruption and crash in back-ldbm
#
--- servers/slapd/back-ldbm/idl.c.orig	Fri Aug 23 20:09:40 2002
+++ servers/slapd/back-ldbm/idl.c	Wed Mar 12 12:42:29 2003
@@ -478,9 +478,9 @@
 	 */
 
 	/* select the block to try inserting into *//* XXX linear search XXX */
-	for ( i = 0; !ID_BLOCK_NOID(idl, i) && id > ID_BLOCK_ID(idl, i); i++ )
+	for ( i = 0; !ID_BLOCK_NOID(idl, i) && id >= ID_BLOCK_ID(idl, i); i++ )
 		;	/* NULL */
-
+	
 	if ( i != 0 ) {
 		i--;
 		first = 0;
@@ -488,6 +488,11 @@
 		first = 1;
 	}
 
+	/* At this point the following condition must be true:
+	 * ID_BLOCK_ID(idl, i) <= id && id < ID_BLOCK_ID(idl, i+1)
+	 * except when i is the first or the last block.
+	 */
+
 	/* get the block */
 	cont_alloc( &k2, &key );
 	cont_id( &k2, ID_BLOCK_ID(idl, i) );
@@ -533,15 +538,16 @@
 
 		/* is there a next block? */
 		if ( !first && !ID_BLOCK_NOID(idl, i + 1) ) {
+			Datum k3;
 			/* read it in */
-			cont_alloc( &k2, &key );
-			cont_id( &k2, ID_BLOCK_ID(idl, i + 1) );
-			if ( (tmp2 = idl_fetch_one( be, db, k2 )) == NULL ) {
+			cont_alloc( &k3, &key );
+			cont_id( &k3, ID_BLOCK_ID(idl, i + 1) );
+			if ( (tmp2 = idl_fetch_one( be, db, k3 )) == NULL ) {
 				Debug( LDAP_DEBUG_ANY,
 				    "idl_insert_key: idl_fetch_one returned NULL\n",
 				    0, 0, 0 );
 				/* split the original block */
-				cont_free( &k2 );
+				cont_free( &k3 );
 				goto split;
 			}
 
@@ -552,9 +558,6 @@
 			 */
 			if (id < ID_BLOCK_ID(tmp, ID_BLOCK_NIDS(tmp) - 1)) {
 			    ID id2 = ID_BLOCK_ID(tmp, ID_BLOCK_NIDS(tmp) - 1);
-			    Datum k3;
-
-			    ldbm_datum_init( k3 );
 
 			    --ID_BLOCK_NIDS(tmp);
 			    /* This must succeed since we just popped one
@@ -562,16 +565,11 @@
 			     */
 			    rc = idl_insert( &tmp, id, db->dbc_maxids );
 
-				k3.dptr = ch_malloc(k2.dsize);
-				k3.dsize = k2.dsize;
-				AC_MEMCPY(k3.dptr, k2.dptr, k3.dsize);
-			    if ( (rc = idl_store( be, db, k3, tmp )) != 0 ) {
+			    if ( (rc = idl_store( be, db, k2, tmp )) != 0 ) {
 				Debug( LDAP_DEBUG_ANY,
 			    "idl_insert_key: idl_store returned %d\n", rc, 0, 0 );
 			    }
 
-				free( k3.dptr );
-
 			    id = id2;
 			    /* This new id will necessarily be inserted
 			     * as the first id of the next block by the
@@ -583,7 +581,7 @@
 			    db->dbc_maxids )) ) {
 			case 1:		/* id inserted first in block */
 				rc = idl_change_first( be, db, key, idl,
-				    i + 1, k2, tmp2 );
+				    i + 1, k3, tmp2 );
 				/* FALL */
 
 			case 2:		/* id already there - how? */
@@ -598,8 +596,10 @@
 					    id, 0, 0 );
 				}
 
+				cont_free( &k3 );
 				idl_free( tmp );
 				idl_free( tmp2 );
+				cont_free( &k2 );
 				idl_free( idl );
 				return( 0 );
 
@@ -607,6 +607,7 @@
 				break;
 			}
 
+			cont_free( &k3 );
 			idl_free( tmp2 );
 		}
 
