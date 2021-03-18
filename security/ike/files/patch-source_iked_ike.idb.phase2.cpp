--- source/iked/ike.idb.phase2.cpp.orig	2012-11-19 23:28:52 UTC
+++ source/iked/ike.idb.phase2.cpp
@@ -438,7 +438,7 @@ bool _IDB_PH2::setup_dhgrp()
 		}
 
 		xl.size( dh_size );
-		long result = BN_bn2bin( dh->pub_key, xl.buff() );
+		long result = BN_bn2bin( DH_get0_pub_key( dh ), xl.buff() );
 
 		//
 		// fixup public buffer alignment
