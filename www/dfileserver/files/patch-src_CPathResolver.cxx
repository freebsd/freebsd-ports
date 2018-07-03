--- src/CPathResolver.cxx.orig	2018-07-02 11:45:26 UTC
+++ src/CPathResolver.cxx
@@ -100,7 +100,7 @@ CPathResolver::CPathResolver( string Con
 	mPaths = new SPathNode();
 
 	ifstream Config( ConfigFile.c_str(), ios::in );
-	if( Config == NULL ) throw( (exn_t)EXN_IO );
+	if( ! Config.is_open() ) throw( (exn_t)EXN_IO );
 
 	while( !Config.eof() ) {
 		string Fake, Real;
