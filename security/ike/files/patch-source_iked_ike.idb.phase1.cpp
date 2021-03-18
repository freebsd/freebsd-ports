--- source/iked/ike.idb.phase1.cpp.orig	2011-02-01 07:21:32 UTC
+++ source/iked/ike.idb.phase1.cpp
@@ -676,7 +676,7 @@ bool _IDB_PH1::setup_dhgrp( IKE_PROPOSAL * proposal )
 	}
 
 	xl.size( dh_size );
-	long result = BN_bn2bin( dh->pub_key, xl.buff() );
+	long result = BN_bn2bin( DH_get0_pub_key( dh ), xl.buff() );
 
 	//
 	// fixup public buffer alignment
