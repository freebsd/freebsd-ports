--- modules/demux/mkv.cpp.orig	2008-02-24 14:01:53.000000000 -0500
+++ modules/demux/mkv.cpp	2008-03-19 13:11:29.000000000 -0400
@@ -5845,7 +5845,7 @@
             binary *p_data = (*index)->GetBuffer();
             size_t i_size = *p_data++;
             // avoid reading too much from the buffer
-            i_size = min( i_size, ((*index)->GetSize() - 1) >> 3 );
+            i_size = min<size_t>( i_size, ((*index)->GetSize() - 1) >> 3 );
             for ( ; i_size > 0; i_size--, p_data += 8 )
             {
                 msg_Dbg( &sys.demuxer, "Matroska DVD enter command" );
@@ -5868,7 +5868,7 @@
             binary *p_data = (*index)->GetBuffer();
             size_t i_size = *p_data++;
             // avoid reading too much from the buffer
-            i_size = min( i_size, ((*index)->GetSize() - 1) >> 3 );
+            i_size = min<size_t>( i_size, ((*index)->GetSize() - 1) >> 3 );
             for ( ; i_size > 0; i_size--, p_data += 8 )
             {
                 msg_Dbg( &sys.demuxer, "Matroska DVD leave command" );
