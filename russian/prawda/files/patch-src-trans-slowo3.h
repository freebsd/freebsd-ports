--- src/trans/slowo3.h.orig	Sun Jan  2 19:38:50 2005
+++ src/trans/slowo3.h	Sun Jan  2 19:42:19 2005
@@ -110,7 +110,7 @@
    long             n_record( void );
    char             is_atom( long i_record );
    t_sTree         *tree( long i_tree );
-  inline t_sStruct *sstruct( long i_struct );
+  inline t_sStruct *sstruct( long i_struct ) { return &Struct[i_struct]; };
    t_sStruct       *get_from( long i_slowo );
    t_sStruct       *get_to( long i_slowo, long i_slowo1=0 );
    t_RelationList1  get_relation( long i_slowo, long i_variant );; };
