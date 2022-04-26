--- sparsersb.cc.orig	2021-09-20 23:24:21 UTC
+++ sparsersb.cc
@@ -118,7 +118,7 @@
 #define RSBOI_WARN( MSG )
 #endif
 #define RSBOI_TODO( MSG ) RSBOI_WARN( MSG )/* new */
-#define RSBOI_FIXME( MSG ) RSBOI_WARN( "FIXME: "MSG )/* new */
+#define RSBOI_FIXME( MSG ) RSBOI_WARN( "FIXME: " MSG )/* new */
 
 #define RSBOI_PRINTF( ... ) printf( __VA_ARGS__ )
 #if RSBOI_VERBOSE
@@ -949,8 +949,8 @@ octave_value do_index_op_subsparse(const idx_vector & 
 						if(ovl(0).issparse())
 						{
   							SparseBoolMatrix sm = SparseBoolMatrix (ovl(0).sparse_matrix_value());
-							const octave_idx_type * ir = sm.mex_get_ir ();
-							const octave_idx_type * jc = sm.mex_get_jc ();
+							const octave_idx_type * ir = sm.ridx ();
+							const octave_idx_type * jc = sm.cidx ();
 					        	const octave_idx_type nr = sm.rows ();
         						const octave_idx_type nc = sm.cols ();
 							RSBOI_DEBUG_NOTICE(RSBOI_D_EMPTY_MSG);
@@ -1242,8 +1242,8 @@ err:
 						if(ovl(0).issparse() && ovl(0).isreal() && rhs.isreal())
 						{
   							const SparseBoolMatrix sm = SparseBoolMatrix (ovl(0).sparse_matrix_value());
-							const octave_idx_type * ir = sm.mex_get_ir ();
-							const octave_idx_type * jc = sm.mex_get_jc ();
+							const octave_idx_type * ir = sm.ridx ();
+							const octave_idx_type * jc = sm.cidx ();
         						const octave_idx_type nc = sm.cols ();
 							RSBOI_DEBUG_NOTICE(RSBOI_D_EMPTY_MSG);
 							const RSBOI_T rv = rhs.double_value();
