--- index.c.orig
+++ index.c
@@ -673,7 +673,7 @@
 //
 // SYNOPSIS
 //
-        inline int rank( int file_index, int occurences_in_file, double factor )
+        inline int my_rank( int file_index, int occurences_in_file, double factor )
 //
 // DESCRIPTION
 //
@@ -883,7 +883,7 @@
                     continues = true;
                 o << enc_int( file->index_ )
                   << enc_int( file->occurrences_ )
-                  << enc_int( rank(file->index_, file->occurrences_, factor) );
+                  << enc_int( my_rank(file->index_, file->occurrences_, factor) );
                 if ( !file->meta_ids_.empty() )
                     file->write_meta_ids( o );
 #ifdef  FEATURE_word_pos
@@ -930,7 +930,7 @@
                     continues = true;
                 o << enc_int( file->index_ )
                   << enc_int( file->occurrences_ )
-                  << enc_int( rank(file->index_, file->occurrences_, factor) );
+                  << enc_int( my_rank(file->index_, file->occurrences_, factor) );
                 if ( !file->meta_ids_.empty() )
                     file->write_meta_ids( o );
 #ifdef  FEATURE_word_pos
@@ -995,7 +995,7 @@
         //
         double const factor = (double)Rank_Factor / info.occurrences_;
         TRANSFORM_EACH( word_info::file_list, info.files_, file )
-            file->rank_ = rank( file->index_, file->occurrences_, factor );
+            file->rank_ = my_rank( file->index_, file->occurrences_, factor );
     }
 
     if ( verbosity > 1 )
