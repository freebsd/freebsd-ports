--- servers/slapd/syncrepl.c	Mon Oct 13 03:57:03 2003
+++ servers/slapd/syncrepl.c	Sun Oct 19 15:33:56 2003
@@ -19,6 +19,12 @@
  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE, EVEN
  * IF IBM IS APPRISED OF THE POSSIBILITY OF SUCH DAMAGES.
  */
+/* Modified by Howard Chu
+ *
+ * Copyright (c) 2003 by Howard Chu, Symas Corporation
+ *
+ * Modifications provided under the terms of the OpenLDAP public license.
+ */
 
 #include "portable.h"
 
@@ -26,7 +32,6 @@
 
 #include <ac/string.h>
 #include <ac/socket.h>
-#include <db.h>
 
 #include "ldap_pvt.h"
 #include "lutil.h"
@@ -35,106 +40,142 @@
 
 #include "ldap_rq.h"
 
-static const struct berval slap_syncrepl_bvc = BER_BVC("syncreplxxx");
-static const struct berval slap_syncrepl_cn_bvc = BER_BVC("cn=syncreplxxx");
+#ifdef LDAP_SLAPI
+#include "slapi.h"
+#endif
+
+#define SYNCREPL_STR	"syncreplxxx"
+#define CN_STR	"cn="
+
+static const struct berval slap_syncrepl_bvc = BER_BVC(SYNCREPL_STR);
+static const struct berval slap_syncrepl_cn_bvc = BER_BVC(CN_STR SYNCREPL_STR);
 
 static void
-syncrepl_del_nonpresent( LDAP *, Operation * );
+syncrepl_del_nonpresent( LDAP *, Operation *, syncinfo_t * );
 
 /* callback functions */
-static int cookie_callback( struct slap_op *, struct slap_rep * );
 static int dn_callback( struct slap_op *, struct slap_rep * );
 static int nonpresent_callback( struct slap_op *, struct slap_rep * );
 static int null_callback( struct slap_op *, struct slap_rep * );
-static int contextcsn_callback( Operation*, SlapReply* );
 
-static AttributeDescription **sync_descs;
+static AttributeDescription *sync_descs[4];
 
 struct runqueue_s syncrepl_rq;
 
 void
-init_syncrepl()
+init_syncrepl(syncinfo_t *si)
 {
-	sync_descs = ch_malloc( 4 * sizeof( AttributeDescription * ));
-	sync_descs[0] = slap_schema.si_ad_objectClass;
-	sync_descs[1] = slap_schema.si_ad_structuralObjectClass;
-	sync_descs[2] = slap_schema.si_ad_entryCSN;
-	sync_descs[3] = NULL;
+	int i, j, k, n;
+	char **tmp;
+
+	if ( !sync_descs[0] ) {
+		sync_descs[0] = slap_schema.si_ad_objectClass;
+		sync_descs[1] = slap_schema.si_ad_structuralObjectClass;
+		sync_descs[2] = slap_schema.si_ad_entryCSN;
+		sync_descs[3] = NULL;
+	}
+
+	for ( n = 0; si->attrs[ n ] != NULL; n++ ) ;
+
+	if ( n ) {
+		/* Delete Attributes */
+		for ( i = 0; sync_descs[i] != NULL; i++ ) {
+			for ( j = 0; si->attrs[j] != NULL; j++ ) {
+				if ( !strcmp( si->attrs[j], sync_descs[i]->ad_cname.bv_val )) {
+					ch_free( si->attrs[j] );
+					for ( k = j; si->attrs[k] != NULL; k++ ) {
+						si->attrs[k] = si->attrs[k+1];
+					}
+				}
+			}
+		}
+		for ( n = 0; si->attrs[ n ] != NULL; n++ );
+		tmp = ( char ** ) ch_realloc( si->attrs, ( n + 4 ) * sizeof( char * ));
+		if ( tmp == NULL ) {
+#ifdef NEW_LOGGING
+			LDAP_LOG( OPERATION, ERR, "out of memory\n", 0,0,0 );
+#else
+			Debug( LDAP_DEBUG_ANY, "out of memory\n", 0,0,0 );
+#endif
+		}
+	} else {
+		tmp = ( char ** ) ch_realloc( si->attrs, 5 * sizeof( char * ));
+		if ( tmp == NULL ) {
+#ifdef NEW_LOGGING
+			LDAP_LOG( OPERATION, ERR, "out of memory\n", 0,0,0 );
+#else
+			Debug( LDAP_DEBUG_ANY, "out of memory\n", 0,0,0 );
+#endif
+		}
+		tmp[ n++ ] = ch_strdup( "*" );
+	}
+	
+	si->attrs = tmp;
+
+	/* Add Attributes */
+
+	for ( i = 0; sync_descs[ i ] != NULL; i++ ) {
+		si->attrs[ n++ ] = ch_strdup ( sync_descs[i]->ad_cname.bv_val );
+		si->attrs[ n ] = NULL;
+	}
 }
 
-int
+static int
 ldap_sync_search(
 	syncinfo_t *si,
 	LDAP *ld,
-	LDAPControl **sctrls,
-	LDAPControl **cctrls,
+	void *ctx,
 	int *msgidp )
 {
-	BerElement	*ber;
-	int timelimit;
-	ber_int_t id;
-
-	int rc;
-	BerElement	*sync_ber = NULL;
-	struct berval *sync_bvalp = NULL;
-	LDAPControl c[2];
-	LDAPControl **ctrls;
-	int err;
+	BerElementBuffer berbuf;
+	BerElement *ber = (BerElement *)&berbuf;
+	LDAPControl c[2], *ctrls[3];
 	struct timeval timeout;
+	int rc;
 
-    /* setup LDAP SYNC control */
-    sync_ber = ber_alloc_t( LBER_USE_DER );
-    ber_set_option( sync_ber, LBER_OPT_BER_MEMCTX, NULL );
-
-    if ( si->syncCookie ) {
-        ber_printf( sync_ber, "{eO}", abs(si->type), si->syncCookie );
-    } else {
-        ber_printf( sync_ber, "{e}", abs(si->type) );
-    }
-
-    if ( ber_flatten( sync_ber, &sync_bvalp ) == LBER_ERROR ) {
-        ber_free( sync_ber, 1 );
-        return LBER_ERROR;
-    }
-    ber_free( sync_ber, 1 );
-
-    ctrls = (LDAPControl**) sl_calloc( 3, sizeof(LDAPControl*), NULL );
-
-    c[0].ldctl_oid = LDAP_CONTROL_SYNC;
-    c[0].ldctl_value = (*sync_bvalp);
-    c[0].ldctl_iscritical = si->type < 0;
-    ctrls[0] = &c[0];
-
-    if ( si->authzId ) {
-        c[1].ldctl_oid = LDAP_CONTROL_PROXY_AUTHZ;
-        c[1].ldctl_value.bv_val = si->authzId;
-        c[1].ldctl_value.bv_len = strlen( si->authzId );
-        c[1].ldctl_iscritical = 1;
-        ctrls[1] = &c[1];
-    } else {
-        ctrls[1] = NULL;
-    }
-
-    ctrls[2] = NULL;
+	/* setup LDAP SYNC control */
+	ber_init2( ber, NULL, LBER_USE_DER );
+	ber_set_option( ber, LBER_OPT_BER_MEMCTX, &ctx );
 
-    err = ldap_set_option( ld, LDAP_OPT_SERVER_CONTROLS, ctrls );
+	if ( si->syncCookie ) {
+		ber_printf( ber, "{eO}", abs(si->type), si->syncCookie );
+	} else {
+		ber_printf( ber, "{e}", abs(si->type) );
+	}
+
+	if ( (rc = ber_flatten2( ber, &c[0].ldctl_value, 0 )) == LBER_ERROR ) {
+		ber_free_buf( ber );
+		return rc;
+	}
 
-    ber_bvfree( sync_bvalp );
-    ch_free( ctrls );
+	c[0].ldctl_oid = LDAP_CONTROL_SYNC;
+	c[0].ldctl_iscritical = si->type < 0;
+	ctrls[0] = &c[0];
 
-    if ( err != LDAP_OPT_SUCCESS )
-        fprintf( stderr, "Could not set controls : %d\n", err );
+	if ( si->authzId ) {
+		c[1].ldctl_oid = LDAP_CONTROL_PROXY_AUTHZ;
+		ber_str2bv( si->authzId, 0, 0, &c[1].ldctl_value );
+		c[1].ldctl_iscritical = 1;
+		ctrls[1] = &c[1];
+		ctrls[2] = NULL;
+	} else {
+		ctrls[1] = NULL;
+	}
 
 	timeout.tv_sec = si->tlimit > 0 ? si->tlimit : 1;
+	timeout.tv_usec = 0;
 
-	rc = ldap_search_ext( ld, si->base, si->scope, si->filterstr,
-						  si->attrs, si->attrsonly, sctrls, cctrls,
+	rc = ldap_search_ext( ld, si->base.bv_val, si->scope, si->filterstr.bv_val,
+						  si->attrs, si->attrsonly, ctrls, NULL,
 						  si->tlimit < 0 ? NULL : &timeout,
 						  si->slimit, msgidp );
+	ber_free_buf( ber );
 
 	return rc;
 }
 
+static const Listener dummy_list = { {0, ""}, {0, ""} };
+
 void *
 do_syncrepl(
 	void	*ctx,
@@ -142,18 +183,11 @@
 {
 	struct re_s* rtask = arg;
 	syncinfo_t *si = ( syncinfo_t * ) rtask->arg;
-	Backend *be = si->be;
-
-	SlapReply	rs = {REP_RESULT};
+	Backend *be;
 
-	LDAPControl	c[2];
-	LDAPControl	**sctrls = NULL;
 	LDAPControl	**rctrls = NULL;
 	LDAPControl	*rctrlp = NULL;
-	BerElement	*sync_ber = NULL;
-	struct berval	*sync_bvalp = NULL;
 
-	BerElement	*ctrl_ber = NULL;
 	BerElement	*res_ber = NULL;
 
 	LDAP	*ld = NULL;
@@ -162,10 +196,6 @@
 
 	ber_int_t	msgid;
 
-	int		nresponses, nreferences, nextended, npartial;
-	int		nresponses_psearch;
-
-	int		cancel_msgid = -1;
 	char		*retoid = NULL;
 	struct berval	*retdata = NULL;
 
@@ -182,31 +212,20 @@
 	ber_len_t	len;
 	int	syncinfo_arrived = 0;
 
-	char **tmp = NULL;
-	AttributeDescription** descs = NULL;
-
-	Connection conn;
+	Connection conn = {0};
 	Operation op = {0};
 	slap_callback	cb;
 
 	void *memctx = NULL;
 	ber_len_t memsiz;
 	
-	int i, j, k, n;
 	int rc_efree;
 
-	struct berval base_bv = { 0, NULL };
-	struct berval pbase = { 0, NULL };
-	struct berval nbase = { 0, NULL };
-	struct berval psubrdn = { 0, NULL };
-	struct berval nsubrdn = { 0, NULL };
 	struct berval psub = { 0, NULL };
-	struct berval nsub = { 0, NULL };
 	Modifications	*modlist = NULL;
-	Modifications	*ml, *mlnext;
-	char *def_filter_str = NULL;
 
-	struct berval slap_syncrepl_bv = BER_BVNULL;
+	char syncrepl_cbuf[sizeof(CN_STR SYNCREPL_STR)];
+	struct berval syncrepl_cn_bv = {sizeof(syncrepl_cbuf)-1, syncrepl_cbuf};
 
 	const char		*text;
 	int				match;
@@ -224,7 +243,7 @@
 		return NULL;
 
 	if ( abs(si->type) != LDAP_SYNC_REFRESH_ONLY &&
-	     abs(si->type) != LDAP_SYNC_REFRESH_AND_PERSIST ) {
+		abs(si->type) != LDAP_SYNC_REFRESH_AND_PERSIST ) {
 		return NULL;
 	}
 
@@ -235,14 +254,15 @@
 	rc = ldap_initialize( &ld, si->provideruri );
 	if ( rc != LDAP_SUCCESS ) {
 #ifdef NEW_LOGGING
-		LDAP_LOG( OPERATION, ERR, "do_syncrepl: "
-			"ldap_initialize failed (%s)\n",
+		LDAP_LOG( OPERATION, ERR,
+			"do_syncrepl: ldap_initialize failed (%s)\n",
 			si->provideruri, 0, 0 );
 #else
-		Debug( LDAP_DEBUG_ANY, "do_syncrepl: "
-			"ldap_initialize failed (%s)\n",
+		Debug( LDAP_DEBUG_ANY,
+			"do_syncrepl: ldap_initialize failed (%s)\n",
 			si->provideruri, 0, 0 );
 #endif
+		return NULL;
 	}
 
 	op.o_protocol = LDAP_VERSION3;
@@ -293,10 +313,10 @@
 
 		defaults = lutil_sasl_defaults( ld,
 				si->saslmech,
-			       	si->realm,
-			       	si->authcId,
-			       	si->passwd,
-			       	si->authzId );
+				   	si->realm,
+				   	si->authcId,
+				   	si->passwd,
+				   	si->authzId );
 
 		rc = ldap_sasl_interactive_bind_s( ld,
 				si->binddn,
@@ -306,6 +326,8 @@
 				lutil_sasl_interact,
 				defaults );
 
+		lutil_sasl_freedefs( defaults );
+
 		/* FIXME : different error behaviors according to
 			1) return code
 			2) on err policy : exit, retry, backoff ...
@@ -343,6 +365,16 @@
 	/* set thread context in syncinfo */
 	si->ctx = ctx;
 
+	be = si->be;
+
+	si->conn = &conn;
+	conn.c_connid = -1;
+	conn.c_send_ldap_result = slap_send_ldap_result;
+	conn.c_send_search_entry = slap_send_search_entry;
+	conn.c_send_search_reference = slap_send_search_reference;
+	conn.c_listener = (Listener *)&dummy_list;
+	conn.c_peer_name = slap_empty_bv;
+
 	/* set memory context */
 #define SLAB_SIZE 1048576
 	memsiz = SLAB_SIZE;
@@ -350,119 +382,44 @@
 	op.o_tmpmemctx = memctx;
 	op.o_tmpmfuncs = &sl_mfuncs;
 
-	op.o_si = si;
-	op.o_tag = LDAP_REQ_SEARCH;
 	op.o_dn = si->updatedn;
 	op.o_ndn = si->updatedn;
 	op.o_callback = &cb;
 	op.o_time = slap_get_time();
-	op.o_managedsait = 1;
 	op.o_threadctx = si->ctx;
+	op.o_managedsait = 1;
 	op.o_bd = be;
 	op.o_conn = &conn;
 	op.o_connid = op.o_conn->c_connid;
-	op.ors_scope = LDAP_SCOPE_BASE;
-	op.ors_deref = LDAP_DEREF_NEVER;
-	op.ors_slimit = 0;
-	op.ors_tlimit = 0;
-	op.ors_attrsonly = 0;
-	op.ors_attrs = NULL;
-	op.ors_filter = str2filter_x( &op, def_filter_str = "(objectClass=*)" );
-	ber_str2bv( def_filter_str, 0, 0, &op.ors_filterstr );
-
-	si->conn = &conn;
-	conn.c_send_ldap_result = slap_send_ldap_result;
-	conn.c_send_search_entry = slap_send_search_entry;
-	conn.c_send_search_reference = slap_send_search_reference;
+#if defined( LDAP_SLAPI )
+	op.o_pb = slapi_pblock_new();
+	slapi_x_create_object_extensions( SLAPI_X_EXT_OPERATION, &op );
+#endif /* defined( LDAP_SLAPI ) */
 
 	/* get syncrepl cookie of shadow replica from subentry */
-	ber_str2bv( si->base, 0, 0, &base_bv ); 
-	dnPrettyNormal( 0, &base_bv, &pbase, &nbase, op.o_tmpmemctx );
-
-	ber_dupbv( &slap_syncrepl_bv, (struct berval *) &slap_syncrepl_bvc );
-	slap_syncrepl_bv.bv_len = snprintf( slap_syncrepl_bv.bv_val,
-									slap_syncrepl_bvc.bv_len,
-									"syncrepl%d", si->id );
-	build_new_dn( &op.o_req_dn, &pbase, &slap_syncrepl_bv, op.o_tmpmemctx );
-	build_new_dn( &op.o_req_ndn, &nbase, &slap_syncrepl_bv, op.o_tmpmemctx );
 
-	/* set callback function */
-	cb.sc_response = cookie_callback;
-	cb.sc_private = si;
+	snprintf(syncrepl_cbuf, sizeof(syncrepl_cbuf), CN_STR "syncrepl%d",
+		si->id );
+	build_new_dn( &op.o_req_ndn, &si->base, &syncrepl_cn_bv, op.o_tmpmemctx );
+	op.o_req_dn = op.o_req_ndn;
 
-	/* search subentry to retrieve cookie */
 	si->syncCookie = NULL;
-	be->be_search( &op, &rs );
-
-	if ( op.o_req_dn.bv_val )
-		ch_free( op.o_req_dn.bv_val );
-	if ( op.o_req_ndn.bv_val )
-		ch_free( op.o_req_ndn.bv_val );
-	if ( op.ors_filter )
-		filter_free( op.ors_filter );
-	if ( op.ors_filterstr.bv_val )
-		ch_free( op.ors_filterstr.bv_val );
-	if ( slap_syncrepl_bv.bv_val )
-		ch_free( slap_syncrepl_bv.bv_val );
-	if ( pbase.bv_val )
-		ch_free( pbase.bv_val );
-	if ( nbase.bv_val )
-		ch_free( nbase.bv_val );
+	backend_attribute( &op, NULL, &op.o_req_ndn,
+		slap_schema.si_ad_syncreplCookie, &si->syncCookie );
 
 	ber_dupbv( &syncCookie_req, si->syncCookie );
 
 	psub = be->be_nsuffix[0];
 
-	for ( n = 0; si->attrs[ n ] != NULL; n++ ) ;
-
-	if ( n != 0 ) {
-		/* Delete Attributes */
-		descs = sync_descs;
-		for ( i = 0; descs[i] != NULL; i++ ) {
-			for ( j = 0; si->attrs[j] != NULL; j++ ) {
-				if ( !strcmp( si->attrs[j], descs[i]->ad_cname.bv_val )) {
-					ch_free( si->attrs[j] );
-					for ( k = j; si->attrs[k] != NULL; k++ ) {
-						si->attrs[k] = si->attrs[k+1];
-					}
-				}
-			}
-		}
-		for ( n = 0; si->attrs[ n ] != NULL; n++ );
-		tmp = ( char ** ) ch_realloc( si->attrs, ( n + 4 ) * sizeof( char * ));
-		if ( tmp == NULL ) {
-#ifdef NEW_LOGGING
-			LDAP_LOG( OPERATION, ERR, "out of memory\n", 0,0,0 );
-#else
-			Debug( LDAP_DEBUG_ANY, "out of memory\n", 0,0,0 );
-#endif
-		}
-	} else {
-		tmp = ( char ** ) ch_realloc( si->attrs, 5 * sizeof( char * ));
-		if ( tmp == NULL ) {
+	rc = ldap_sync_search( si, ld, memctx, &msgid );
+	if( rc != LDAP_SUCCESS ) {
 #ifdef NEW_LOGGING
-			LDAP_LOG( OPERATION, ERR, "out of memory\n", 0,0,0 );
+			LDAP_LOG ( OPERATION, ERR, "do_syncrepl: "
+				"ldap_search_ext: %s (%d)\n", ldap_err2string( rc ), rc, 0 );
 #else
-			Debug( LDAP_DEBUG_ANY, "out of memory\n", 0,0,0 );
+			Debug( LDAP_DEBUG_ANY, "do_syncrepl: "
+				"ldap_search_ext: %s (%d)\n", ldap_err2string( rc ), rc, 0 );
 #endif
-		}
-		tmp[ n++ ] = ch_strdup( "*" );
-	}
-	
-	descs = sync_descs;
-	si->attrs = tmp;
-
-	/* Add Attributes */
-
-	for ( i = 0; descs[ i ] != NULL; i++ ) {
-		si->attrs[ n++ ] = ch_strdup ( descs[i]->ad_cname.bv_val );
-		si->attrs[ n ] = NULL;
-	}
-
-	rc = ldap_sync_search( si, ld, NULL, NULL, &msgid );
-	if( rc != LDAP_SUCCESS ) {
-		fprintf( stderr, "syncrepl: ldap_search_ext: %s (%d)\n",
-							ldap_err2string( rc ), rc );
 		return NULL;
 	}
 
@@ -473,7 +430,6 @@
 	}
 
 	while (( rc = ldap_result( ld, LDAP_RES_ANY, LDAP_MSG_ONE, tout_p, &res )) >= 0 ) {
-
 		if ( rc == 0 ) {
 			if ( slapd_abrupt_shutdown ) {
 				break;
@@ -483,8 +439,8 @@
 		}
 
 		for ( msg = ldap_first_message( ld, res );
-		      msg != NULL;
-		      msg = ldap_next_message( ld, msg ) )
+			  msg != NULL;
+			  msg = ldap_next_message( ld, msg ) )
 		{
 			syncCookie.bv_len = 0; syncCookie.bv_val = NULL;
 			switch( ldap_msgtype( msg ) ) {
@@ -517,17 +473,18 @@
 			case LDAP_RES_SEARCH_RESULT:
 				ldap_parse_result( ld, msg, &err, NULL, NULL, NULL, &rctrls, 0 );
 				if ( rctrls ) {
+					BerElementBuffer berbuf;
+					BerElement	*ctrl_ber;
 					rctrlp = *rctrls;
-					ctrl_ber = ber_alloc_t( LBER_USE_DER );
-					ber_set_option( ctrl_ber, LBER_OPT_BER_MEMCTX, &op.o_tmpmemctx );
-					ber_write( ctrl_ber, rctrlp->ldctl_value.bv_val, rctrlp->ldctl_value.bv_len, 0 );
-					ber_reset( ctrl_ber, 1 );
+					ctrl_ber = (BerElement *)&berbuf;
+					ber_init2( ctrl_ber, &rctrlp->ldctl_value, LBER_USE_DER );
 
 					ber_scanf( ctrl_ber, "{" /*"}"*/);
 					if ( ber_peek_tag( ctrl_ber, &len )
 						== LDAP_SYNC_TAG_COOKIE ) {
 						ber_scanf( ctrl_ber, "o", &syncCookie );
 					}
+					ldap_controls_free( rctrls );
 				}
 				value_match( &match, slap_schema.si_ad_entryCSN,
 							slap_schema.si_ad_entryCSN->ad_type->sat_ordering,
@@ -541,8 +498,6 @@
 					if ( syncCookie.bv_len && match < 0) {
 						syncrepl_updateCookie( si, ld, &op, &psub, &syncCookie );
 					}
-					if ( ctrl_ber )
-						ber_free( ctrl_ber, 1 );
 					goto done;
 				} else {
 					/* FIXME : different error behaviors according to
@@ -553,10 +508,8 @@
 						syncrepl_updateCookie( si, ld, &op, &psub, &syncCookie);
 					}
 					if ( si->sync_mode == LDAP_SYNC_STATE_MODE && match < 0 ) {
-							syncrepl_del_nonpresent( ld, &op );
+							syncrepl_del_nonpresent( ld, &op, si );
 					}
-					if ( ctrl_ber )
-						ber_free( ctrl_ber, 1 );
 					goto done;
 				}
 				break;
@@ -595,7 +548,7 @@
 
 					if ( syncstate == LDAP_SYNC_STATE_MODE_DONE ) {
 						if ( match < 0 ) {
-							syncrepl_del_nonpresent( ld, &op );
+							syncrepl_del_nonpresent( ld, &op, si );
 						}
 						si->sync_mode = LDAP_SYNC_LOG_MODE;
 					} else if ( syncstate == LDAP_SYNC_LOG_MODE_DONE ) {
@@ -643,10 +596,14 @@
 				break;
 
 			}
-			if ( syncCookie.bv_val )
+			if ( syncCookie.bv_val ) {
 				ch_free( syncCookie.bv_val );
-			if ( syncUUID.bv_val )
+				syncCookie.bv_val = NULL;
+			}
+			if ( syncUUID.bv_val ) {
 				ch_free( syncUUID.bv_val );
+				syncUUID.bv_val = NULL;
+			}
 		}
 		ldap_msgfree( res );
 	}
@@ -668,6 +625,11 @@
 	}
 
 done:
+#if defined( LDAP_SLAPI )
+	if ( op.o_pb ) slapi_pblock_destroy( op.o_pb );
+	slapi_x_free_object_extensions( SLAPI_X_EXT_OPERATION, &op );
+#endif /* defined( LDAP_SLAPI ) */
+
 	if ( syncCookie.bv_val )
 		ch_free( syncCookie.bv_val );
 	if ( syncCookie_req.bv_val )
@@ -704,37 +666,22 @@
 	struct berval	*syncCookie
 )
 {
-	Entry		*e;
+	Entry		*e = NULL;
 	BerElement	*ber = NULL;
-	BerElement	*tmpber;
-	struct berval	bv = {0, NULL};
 	Modifications	tmp;
 	Modifications	*mod;
 	Modifications	**modtail = modlist;
-	Backend		*be = op->o_bd;
 
 	const char	*text;
 	char txtbuf[SLAP_TEXT_BUFLEN];
 	size_t textlen = sizeof txtbuf;
 
-	struct berval	**bvals = NULL;
-	char		*dn;
-	struct berval	bdn = {0, NULL};
-	Attribute	*attr;
-	struct berval	empty_bv = { 0, NULL };
+	struct berval	bdn = {0, NULL}, dn, ndn;
 	int		rc;
-	char		*a;
 
 	ber_len_t	len;
 	LDAPControl*	rctrlp;
 	LDAPControl**	rctrls = NULL;
-	BerElement*	ctrl_ber;
-
-	ber_tag_t	tag;
-
-	Modifications *ml = NULL;
-	AttributeDescription** descs;
-	int i;
 
 	*modlist = NULL;
 
@@ -751,61 +698,7 @@
 
 	op->o_tag = LDAP_REQ_ADD;
 
-	rc = ldap_get_dn_ber( ld, msg, &ber, &bdn );
-
-	if ( rc != LDAP_SUCCESS ) {
-#ifdef NEW_LOGGING
-		LDAP_LOG( OPERATION, ERR,
-			"syncrepl_message_to_entry : dn get failed (%d)", rc, 0, 0 );
-#else
-		Debug( LDAP_DEBUG_ANY,
-			"syncrepl_message_to_entry : dn get failed (%d)", rc, 0, 0 );
-#endif
-		return NULL;
-	}
-
-	e = ( Entry * ) ch_calloc( 1, sizeof( Entry ));
-	dnPrettyNormal( NULL, &bdn, &e->e_name, &e->e_nname, NULL );
-
-	e->e_attrs = NULL;
-
-	while ( ber_remaining( ber ) ) {
-		tag = ber_scanf( ber, "{mW}", &tmp.sml_type, &tmp.sml_values );
-
-		if ( tag == LBER_ERROR ) break;
-		if ( tmp.sml_type.bv_val == NULL ) break;
-
-		mod  = (Modifications *) ch_malloc( sizeof( Modifications ));
-
-		mod->sml_op = LDAP_MOD_REPLACE;
-		mod->sml_next = NULL;
-		mod->sml_desc = NULL;
-		mod->sml_type = tmp.sml_type;
-		mod->sml_bvalues = tmp.sml_bvalues;
-		mod->sml_nvalues = NULL;
-
-		*modtail = mod;
-		modtail = &mod->sml_next;
-	}
-
-	if ( ber_scanf( ber, "}") == LBER_ERROR ) {
-#ifdef NEW_LOGGING
-		LDAP_LOG( OPERATION, ERR,
-				"syncrepl_message_to_entry: ber_scanf failed\n", 0, 0, 0 );
-#else
-		Debug( LDAP_DEBUG_ANY, "syncrepl_message_to_entry: ber_scanf failed\n",
-				0, 0, 0 );
-#endif
-		return NULL;
-	}
-
-	ber_free( ber, 0 );
-	tmpber = ldap_get_message_ber( msg );
-	ber = ber_dup( tmpber );
-
-	ber_scanf( ber, "{xx" );
-
-	rc = ldap_pvt_get_controls( ber, &rctrls );
+	rc = ldap_get_entry_controls( ld, msg, &rctrls );
 	if ( rc != LDAP_SUCCESS ) {
 #ifdef NEW_LOGGING
 		LDAP_LOG( OPERATION, ERR,
@@ -818,16 +711,16 @@
 	}
 
 	if ( rctrls ) {
+		BerElementBuffer berbuf;
+		BerElement	*ctrl_ber;
+
 		rctrlp = *rctrls;
-		ctrl_ber = ber_alloc_t( LBER_USE_DER );
-		ber_set_option( ctrl_ber, LBER_OPT_BER_MEMCTX, &op->o_tmpmemctx );
-		ber_write( ctrl_ber, rctrlp->ldctl_value.bv_val, rctrlp->ldctl_value.bv_len, 0 );
-		ber_reset( ctrl_ber, 1 );
+		ctrl_ber = (BerElement *)&berbuf;
+		ber_init2( ctrl_ber, &rctrlp->ldctl_value, LBER_USE_DER );
 		ber_scanf( ctrl_ber, "{eo", syncstate, syncUUID );
 		if ( ber_peek_tag( ctrl_ber, &len ) == LDAP_SYNC_TAG_COOKIE ) {
 			ber_scanf( ctrl_ber, "o}", syncCookie );
 		}
-		ber_free( ctrl_ber, 1 );
 		ldap_controls_free( rctrls );
 	} else {
 #ifdef NEW_LOGGING
@@ -839,8 +732,48 @@
 #endif
 	}
 
+	rc = ldap_get_dn_ber( ld, msg, &ber, &bdn );
+
+	if ( rc != LDAP_SUCCESS ) {
+#ifdef NEW_LOGGING
+		LDAP_LOG( OPERATION, ERR,
+			"syncrepl_message_to_entry : dn get failed (%d)", rc, 0, 0 );
+#else
+		Debug( LDAP_DEBUG_ANY,
+			"syncrepl_message_to_entry : dn get failed (%d)", rc, 0, 0 );
+#endif
+		return NULL;
+	}
+
+	dnPrettyNormal( NULL, &bdn, &dn, &ndn, op->o_tmpmemctx );
+	ber_dupbv( &op->o_req_dn, &dn );
+	ber_dupbv( &op->o_req_ndn, &ndn );
+	sl_free( ndn.bv_val, op->o_tmpmemctx );
+	sl_free( dn.bv_val, op->o_tmpmemctx );
+
 	if ( *syncstate == LDAP_SYNC_PRESENT || *syncstate == LDAP_SYNC_DELETE ) {
-		goto done;
+		return NULL;
+	}
+
+	e = ( Entry * ) ch_calloc( 1, sizeof( Entry ) );
+	e->e_name = op->o_req_dn;
+	e->e_nname = op->o_req_ndn;
+
+	while ( ber_remaining( ber ) ) {
+		if ( (ber_scanf( ber, "{mW}", &tmp.sml_type, &tmp.sml_values ) ==
+			LBER_ERROR ) || ( tmp.sml_type.bv_val == NULL )) break;
+
+		mod  = (Modifications *) ch_malloc( sizeof( Modifications ));
+
+		mod->sml_op = LDAP_MOD_REPLACE;
+		mod->sml_next = NULL;
+		mod->sml_desc = NULL;
+		mod->sml_type = tmp.sml_type;
+		mod->sml_bvalues = tmp.sml_bvalues;
+		mod->sml_nvalues = NULL;
+
+		*modtail = mod;
+		modtail = &mod->sml_next;
 	}
 
 	if ( *modlist == NULL ) {
@@ -853,21 +786,6 @@
 #endif
 	}
 
-	ml = *modlist;
-	while ( ml != NULL ) {
-		AttributeDescription *ad = NULL;
-        rc = slap_bv2ad( &ml->sml_type, &ml->sml_desc, &text );
-
-		if( rc != LDAP_SUCCESS ) {
-			e = NULL;
-			goto done;
-		}
-
-		ad = ml->sml_desc;
-		ml->sml_desc = NULL;
-		ml = ml->sml_next;
-	}
-
 	rc = slap_mods_check( *modlist, 1, &text, txtbuf, textlen, NULL );
 
 	if ( rc != LDAP_SUCCESS ) {
@@ -878,7 +796,7 @@
 		Debug( LDAP_DEBUG_ANY, "syncrepl_message_to_entry: mods check (%s)\n",
 				text, 0, 0 );
 #endif
-		return NULL;
+		goto done;
 	}
 	
 	rc = slap_mods2entry( *modlist, &e, 1, 1, &text, txtbuf, textlen);
@@ -893,8 +811,11 @@
 	}
 
 done:
-
 	ber_free ( ber, 0 );
+	if ( rc != LDAP_SUCCESS ) {
+		entry_free( e );
+		e = NULL;
+	}
 
 	return e;
 }
@@ -924,20 +845,11 @@
 {
 	Backend *be = op->o_bd;
 	slap_callback	cb;
-	struct berval	csn_bv = {0, NULL};
 	struct berval	*syncuuid_bv = NULL;
-	char csnbuf[ LDAP_LUTIL_CSNSTR_BUFSIZE ];
 
 	SlapReply	rs = {REP_RESULT};
 	int rc = LDAP_SUCCESS;
 
-	struct berval base_bv = {0, NULL};
-
-	char *filterstr;
-	Filter *filter;
-
-	Attribute *a;
-
 	if ( refresh &&
 			( syncstate == LDAP_SYNC_PRESENT || syncstate == LDAP_SYNC_ADD )) {
 		syncuuid_bv = ber_dupbv( NULL, syncUUID );
@@ -953,24 +865,21 @@
 		}
 	}
 
-	filterstr = (char *) sl_malloc( strlen("entryUUID=") + syncUUID->bv_len + 1,
+	op->ors_filterstr.bv_len = strlen("entryUUID=") + syncUUID->bv_len;
+	op->ors_filterstr.bv_val = (char *) sl_malloc( op->ors_filterstr.bv_len + 1,
 									op->o_tmpmemctx ); 
-	strcpy( filterstr, "entryUUID=" );
-	strcat( filterstr, syncUUID->bv_val );
+	strcpy( op->ors_filterstr.bv_val, "entryUUID=" );
+	strcat( op->ors_filterstr.bv_val, syncUUID->bv_val );
 
 	si->e = e;
 	si->syncUUID_ndn = NULL;
 
-	filter = str2filter( filterstr );
-	ber_str2bv( filterstr, strlen(filterstr), 1, &op->ors_filterstr );
-	ch_free( filterstr );
-	op->ors_filter = filter;
+	op->ors_filter = str2filter_x( op, op->ors_filterstr.bv_val );
 	op->ors_scope = LDAP_SCOPE_SUBTREE;
 
 	/* get syncrepl cookie of shadow replica from subentry */
-	ber_str2bv( si->base, strlen(si->base), 1, &base_bv ); 
-	dnPrettyNormal( 0, &base_bv, &op->o_req_dn, &op->o_req_ndn, op->o_tmpmemctx );
-	ch_free( base_bv.bv_val );
+	op->o_req_dn = si->base;
+	op->o_req_ndn = si->base;
 
 	/* set callback function */
 	op->o_callback = &cb;
@@ -981,14 +890,10 @@
 
 	rc = be->be_search( op, &rs );
 
-	if ( op->o_req_dn.bv_val )
-		ch_free( op->o_req_dn.bv_val );
-	if ( op->o_req_ndn.bv_val )
-		ch_free( op->o_req_ndn.bv_val );
 	if ( op->ors_filter )
-		filter_free( op->ors_filter );
+		filter_free_x( op, op->ors_filter );
 	if ( op->ors_filterstr.bv_val )
-		ch_free( op->ors_filterstr.bv_val );
+		sl_free( op->ors_filterstr.bv_val, op->o_tmpmemctx );
 
 	cb.sc_response = null_callback;
 	cb.sc_private = si;
@@ -1086,7 +991,7 @@
 			rc = be->be_delete( op, &rs );
 		}
 		/* Already deleted otherwise */
-		return 1;
+		return 0;
 
 	default :
 #ifdef NEW_LOGGING
@@ -1103,23 +1008,17 @@
 static void
 syncrepl_del_nonpresent(
 	LDAP *ld,
-	Operation *op
+	Operation *op,
+	syncinfo_t *si
 )
 {
 	Backend* be = op->o_bd;
-	syncinfo_t *si = op->o_si;
 	slap_callback	cb;
-	struct berval	base_bv = {0, NULL};
-	Filter *filter;
 	SlapReply	rs = {REP_RESULT};
-	struct berval	filterstr_bv = {0, NULL};
 	struct nonpresent_entry *np_list, *np_prev;
 
-	ber_str2bv( si->base, strlen(si->base), 1, &base_bv ); 
-	dnPrettyNormal(0, &base_bv, &op->o_req_dn, &op->o_req_ndn, op->o_tmpmemctx );
-	ch_free( base_bv.bv_val );
-
-	filter = str2filter( si->filterstr );
+	op->o_req_dn = si->base;
+	op->o_req_ndn = si->base;
 
 	cb.sc_response = nonpresent_callback;
 	cb.sc_private = si;
@@ -1132,21 +1031,15 @@
 	op->ors_tlimit = 0;
 	op->ors_attrsonly = 0;
 	op->ors_attrs = NULL;
-	op->ors_filter = filter;
-	ber_str2bv( si->filterstr, strlen( si->filterstr ), 1, &op->ors_filterstr );
+	op->ors_filter = str2filter_x( op, si->filterstr.bv_val );
+	op->ors_filterstr = si->filterstr;
 
 	op->o_nocaching = 1;
 	be->be_search( op, &rs );
 	op->o_nocaching = 0;
 
-	if ( op->o_req_dn.bv_val )
-		ch_free( op->o_req_dn.bv_val );
-	if ( op->o_req_ndn.bv_val )
-		ch_free( op->o_req_ndn.bv_val );
 	if ( op->ors_filter )
-		filter_free( op->ors_filter );
-	if ( op->ors_filterstr.bv_val )
-		ch_free( op->ors_filterstr.bv_val );
+		filter_free_x( op, op->ors_filter );
 
 	if ( !LDAP_LIST_EMPTY( &si->nonpresentlist ) ) {
 		np_list = LDAP_LIST_FIRST( &si->nonpresentlist );
@@ -1173,6 +1066,11 @@
 }
 
 
+static struct berval gcbva[] = {
+	BER_BVC("top"),
+	BER_BVC("glue")
+};
+
 void
 syncrepl_add_glue(
 	syncinfo_t *si,
@@ -1186,72 +1084,72 @@
 )
 {
 	Backend *be = op->o_bd;
-	struct berval	uuid_bv = {0, NULL};
 	slap_callback cb;
 	Attribute	*a;
 	int	rc;
-	char	uuidbuf[ LDAP_LUTIL_UUIDSTR_BUFSIZE ];
-	int levels = 0;
-	int i, j, k;
+	int suffrdns;
+	int i;
 	struct berval dn = {0, NULL};
-	struct berval pdn = {0, NULL};
 	struct berval ndn = {0, NULL};
-	struct berval rdn = {0, NULL};
 	Entry	*glue;
 	SlapReply	rs = {REP_RESULT};
-	Connection *conn = op->o_conn;
-	char* ptr;
+	char	*ptr, *comma;
 
 	op->o_tag = LDAP_REQ_ADD;
 	op->o_callback = &cb;
 	cb.sc_response = null_callback;
 	cb.sc_private = si;
 
-	ber_dupbv( &dn, &e->e_nname );
-	ber_dupbv( &pdn, &e->e_nname );
+	dn = e->e_name;
+	ndn = e->e_nname;
 
-	ptr = dn.bv_val;
-	while ( !be_issuffix ( be, &pdn )) {
-		dnParent( &dn, &pdn );
-		dn.bv_val = pdn.bv_val;
-		dn.bv_len = pdn.bv_len;
-		levels++;
-	}
-	ch_free( ptr );
-
-	for ( i = 0; i <= levels; i++ ) {
-		glue = (Entry*) ch_calloc( 1, sizeof(Entry) );
-		ber_dupbv( &dn, &e->e_nname );
-		j = levels - i;
-
-		ptr = dn.bv_val;
-		for ( k = 0; k < j; k++ ) {
-			dnParent( &dn, &pdn );
-			dn.bv_val = pdn.bv_val;
-			dn.bv_len = pdn.bv_len;
+	/* count RDNs in suffix */
+	if ( be->be_nsuffix[0].bv_len ) {
+		for (i=0, ptr=be->be_nsuffix[0].bv_val; ptr; ptr=strchr( ptr, ',' )) {
+			ptr++;
+			i++;
 		}
+		suffrdns = i;
+	} else {
+		/* suffix is "" */
+		suffrdns = 0;
+	}
 
-		dnPrettyNormal( 0, &dn, &pdn, &ndn, op->o_tmpmemctx );
-		ber_dupbv( &glue->e_name, &pdn );
+	/* Start with BE suffix */
+	for ( i = 0, ptr = NULL; i < suffrdns; i++ ) {
+		comma = strrchr(dn.bv_val, ',');
+		if ( ptr ) *ptr = ',';
+		if ( comma ) *comma = '\0';
+		ptr = comma;
+	}
+	if ( ptr ) {
+		*ptr++ = ',';
+		dn.bv_len -= ptr - dn.bv_val;
+		dn.bv_val = ptr;
+	}
+	/* the normalizedDNs are always the same length, no counting
+	 * required.
+	 */
+	if ( ndn.bv_len > be->be_nsuffix[0].bv_len ) {
+		ndn.bv_val += ndn.bv_len - be->be_nsuffix[0].bv_len;
+		ndn.bv_len = be->be_nsuffix[0].bv_len;
+	}
+
+	while ( ndn.bv_val > e->e_nname.bv_val ) {
+		glue = (Entry *) ch_calloc( 1, sizeof(Entry) );
+		ber_dupbv( &glue->e_name, &dn );
 		ber_dupbv( &glue->e_nname, &ndn );
-		ch_free( ptr );
-		ch_free( pdn.bv_val );
-		ch_free( ndn.bv_val );
 
 		a = ch_calloc( 1, sizeof( Attribute ));
 		a->a_desc = slap_schema.si_ad_objectClass;
 
 		a->a_vals = ch_calloc( 3, sizeof( struct berval ));
-		ber_str2bv( "top", strlen("top"), 1, &a->a_vals[0] );
-		ber_str2bv( "glue", strlen("glue"), 1, &a->a_vals[1] );
+		ber_dupbv( &a->a_vals[0], &gcbva[0] );
+		ber_dupbv( &a->a_vals[1], &gcbva[1] );
 		a->a_vals[2].bv_len = 0;
 		a->a_vals[2].bv_val = NULL;
 
-		a->a_nvals = ch_calloc( 3, sizeof( struct berval ));
-		ber_str2bv( "top", strlen("top"), 1, &a->a_nvals[0] );
-		ber_str2bv( "glue", strlen("glue"), 1, &a->a_nvals[1] );
-		a->a_nvals[2].bv_len = 0;
-		a->a_nvals[2].bv_val = NULL;
+		a->a_nvals = a->a_vals;
 
 		a->a_next = glue->e_attrs;
 		glue->e_attrs = a;
@@ -1260,42 +1158,45 @@
 		a->a_desc = slap_schema.si_ad_structuralObjectClass;
 
 		a->a_vals = ch_calloc( 2, sizeof( struct berval ));
-		ber_str2bv( "glue", strlen("glue"), 1, &a->a_vals[0] );
+		ber_dupbv( &a->a_vals[0], &gcbva[1] );
 		a->a_vals[1].bv_len = 0;
 		a->a_vals[1].bv_val = NULL;
 
-		a->a_nvals = ch_calloc( 2, sizeof( struct berval ));
-		ber_str2bv( "glue", strlen("glue"), 1, &a->a_nvals[0] );
-		a->a_nvals[1].bv_len = 0;
-		a->a_nvals[1].bv_val = NULL;
+		a->a_nvals = a->a_vals;
 
 		a->a_next = glue->e_attrs;
 		glue->e_attrs = a;
 
-		if ( !strcmp( e->e_nname.bv_val, glue->e_nname.bv_val )) {
-			op->o_req_dn = e->e_name;
-			op->o_req_ndn = e->e_nname;
-			op->ora_e = e;
-			rc = be->be_add ( op, &rs );
-			if ( rc == LDAP_SUCCESS )
-				be_entry_release_w( op, e );
-			else 
-				entry_free( e );
-			entry_free( glue );
+		op->o_req_dn = glue->e_name;
+		op->o_req_ndn = glue->e_nname;
+		op->ora_e = glue;
+		rc = be->be_add ( op, &rs );
+		if ( rc == LDAP_SUCCESS ) {
+			be_entry_release_w( op, glue );
 		} else {
-			op->o_req_dn = glue->e_name;
-			op->o_req_ndn = glue->e_nname;
-			op->ora_e = glue;
-			rc = be->be_add ( op, &rs );
-			if ( rc == LDAP_SUCCESS ) {
-				be_entry_release_w( op, glue );
-			} else {
-			/* incl. ALREADY EXIST */
-				entry_free( glue );
-			}
+		/* incl. ALREADY EXIST */
+			entry_free( glue );
 		}
+
+		/* Move to next child */
+		for (ptr = dn.bv_val-2; ptr > e->e_name.bv_val && *ptr != ','; ptr--);
+		if ( ptr == e->e_name.bv_val ) break;
+		dn.bv_val = ++ptr;
+		dn.bv_len = e->e_name.bv_len - (ptr-e->e_name.bv_val);
+		for (ptr = ndn.bv_val-2; ptr > e->e_nname.bv_val && *ptr != ','; ptr--);
+		ndn.bv_val = ++ptr;
+		ndn.bv_len = e->e_nname.bv_len - (ptr-e->e_nname.bv_val);
 	}
 
+	op->o_req_dn = e->e_name;
+	op->o_req_ndn = e->e_nname;
+	op->ora_e = e;
+	rc = be->be_add ( op, &rs );
+	if ( rc == LDAP_SUCCESS )
+		be_entry_release_w( op, e );
+	else 
+		entry_free( e );
+
 	return;
 }
 
@@ -1317,7 +1218,7 @@
 };
 
 static struct berval scbva[] = {
-	BER_BVC("subentry"),
+	BER_BVNULL,
 	BER_BVNULL
 };
 
@@ -1344,6 +1245,7 @@
 	Entry* e = NULL;
 	int rc;
 
+	char syncrepl_cbuf[sizeof(CN_STR SYNCREPL_STR)];
 	struct berval slap_syncrepl_dn_bv = BER_BVNULL;
 	struct berval slap_syncrepl_cn_bv = BER_BVNULL;
 	
@@ -1375,6 +1277,7 @@
 	*modtail = mod;
 	modtail = &mod->sml_next;
 
+	if ( scbva[0].bv_val ) ch_free( scbva[0].bv_val );
 	ber_dupbv( &scbva[0], si->syncCookie );
 	mod = (Modifications *) ch_calloc( 1, sizeof( Modifications ));
 	mod->sml_op = LDAP_MOD_REPLACE;
@@ -1392,26 +1295,13 @@
 	*modtail = mod;
 	modtail = &mod->sml_next;
 
-#if 0
-	rc = slap_mods_check( modlist, 1, &text, txtbuf, textlen, NULL );
-
-	if ( rc != LDAP_SUCCESS ) {
-#ifdef NEW_LOGGING
-		LDAP_LOG( OPERATION, ERR,
-				"syncrepl_updateCookie: mods check (%s)\n", text, 0, 0 );
-#else
-		Debug( LDAP_DEBUG_ANY, "syncrepl_updateCookie: mods check (%s)\n",
-			 text, 0, 0 );
-#endif
-	}
-#endif
+	mlnext = mod;
 
 	op->o_tag = LDAP_REQ_ADD;
 	rc = slap_mods_opattrs( op, modlist, modtail,
 							 &text,txtbuf, textlen );
 
-	for ( ml = modlist; ml != NULL; ml = mlnext ) {
-		mlnext = ml->sml_next;
+	for ( ml = modlist; ml != NULL; ml = ml->sml_next ) {
 		ml->sml_op = LDAP_MOD_REPLACE;
 	}
 
@@ -1427,18 +1317,17 @@
 
 	e = ( Entry * ) ch_calloc( 1, sizeof( Entry ));
 
-	ber_dupbv( &slap_syncrepl_cn_bv, (struct berval *) &slap_syncrepl_cn_bvc );
+	slap_syncrepl_cn_bv.bv_val = syncrepl_cbuf;
 	slap_syncrepl_cn_bv.bv_len = snprintf( slap_syncrepl_cn_bv.bv_val,
 										slap_syncrepl_cn_bvc.bv_len,
 										"cn=syncrepl%d", si->id );
 
-	build_new_dn( &slap_syncrepl_dn_bv, pdn, &slap_syncrepl_cn_bv, NULL );
-	dnPrettyNormal( NULL, &slap_syncrepl_dn_bv, &e->e_name, &e->e_nname, NULL );
+	build_new_dn( &slap_syncrepl_dn_bv, pdn, &slap_syncrepl_cn_bv, op->o_tmpmemctx );
+	ber_dupbv( &e->e_name, &slap_syncrepl_dn_bv );
+	ber_dupbv( &e->e_nname, &slap_syncrepl_dn_bv );
 
-	if ( slap_syncrepl_cn_bv.bv_val )
-		ch_free( slap_syncrepl_cn_bv.bv_val );
 	if ( slap_syncrepl_dn_bv.bv_val )
-		ch_free( slap_syncrepl_dn_bv.bv_val );
+		sl_free( slap_syncrepl_dn_bv.bv_val, op->o_tmpmemctx );
 
 	e->e_attrs = NULL;
 
@@ -1519,10 +1408,21 @@
 
 done :
 
-	if ( cnbva[0].bv_val )
+	if ( cnbva[0].bv_val ) {
 		ch_free( cnbva[0].bv_val );
+		cnbva[0].bv_val = NULL;
+	}
+	if ( scbva[0].bv_val ) {
+		ch_free( scbva[0].bv_val );
+		scbva[0].bv_val = NULL;
+	}
+
+	if ( mlnext->sml_next ) {
+		slap_mods_free( mlnext->sml_next );
+		mlnext->sml_next = NULL;
+	}
 
-	for ( ; ml != NULL; ml = mlnext ) {
+	for (ml = modlist ; ml != NULL; ml = mlnext ) {
 		mlnext = ml->sml_next;
 		free( ml );
 	}
@@ -1543,27 +1443,6 @@
 }
 
 static int
-cookie_callback(
-	Operation* op,
-	SlapReply* rs
-)
-{
-	syncinfo_t *si = op->o_callback->sc_private;
-	Attribute *a;
-
-	if ( rs->sr_type != REP_SEARCH ) return LDAP_SUCCESS;
-
-	a = attr_find( rs->sr_entry->e_attrs, slap_schema.si_ad_syncreplCookie );
-
-	if ( a == NULL ) {
-		si->syncCookie = NULL;
-	} else {
-		si->syncCookie = ber_dupbv( NULL, &a->a_vals[0] );
-	}
-	return LDAP_SUCCESS;
-}
-
-static int
 dn_callback(
 	Operation*	op,
 	SlapReply*	rs
@@ -1602,8 +1481,6 @@
 	Attribute *a;
 	int count = 0;
 	struct berval* present_uuid = NULL;
-	slap_callback cb;
-	SlapReply	rs_cb = {REP_RESULT};
 	struct nonpresent_entry *np_entry;
 
 	if ( rs->sr_type == REP_RESULT ) {
@@ -1643,8 +1520,6 @@
 	SlapReply*	rs
 )
 {
-	syncinfo_t *si = op->o_callback->sc_private;
-
 	if ( rs->sr_err != LDAP_SUCCESS &&
 		 rs->sr_err != LDAP_REFERRAL &&
 		 rs->sr_err != LDAP_ALREADY_EXISTS &&
@@ -1671,7 +1546,6 @@
 )
 {
 	Entry* e;
-	int rc;
 
 	struct berval bv;
 
