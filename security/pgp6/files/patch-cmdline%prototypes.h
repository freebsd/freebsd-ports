--- clients/pgp/cmdline/prototypes.h.orig	1999-11-08 16:56:31.000000000 -0800
+++ clients/pgp/cmdline/prototypes.h	2008-08-31 01:49:53.000000000 -0700
@@ -307,7 +307,6 @@ int get_CONVERSION( );
 
 int maintCheck( PGPFileSpecRef ringfilespec, int options );
 struct newkey;
-int maintUpdate( PGPFileSpecRef ringfilespec, struct newkey const *nkeys );
 void init_charset( void );
 void CONVERT_TO_CANONICAL_CHARSET( char *s );
 char EXT_C( char c );
@@ -317,9 +316,6 @@ struct IdeaCfbContext;
 int cryptRandOpen( struct IdeaCfbContext *cfb );
 void cryptRandSave( struct IdeaCfbContext *cfb );
 
-int cryptRandWriteFile( char const *name, struct IdeaCfbContext *cfb,
-        unsigned bytes );
-
 char * get_ext_c_ptr( void );
 
 /* see libPGPui.a */
