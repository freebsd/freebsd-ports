src/mp4.cpp:679:20: error: cannot initialize return object of type 'mp4v2_ismacrypParams *' (aka 'mp4v2_ismacryp_session_params *') with an rvalue of type 'MP4TrackId' (aka 'unsigned int')
            return MP4_INVALID_TRACK_ID;
                   ^~~~~~~~~~~~~~~~~~~~
./include/mp4v2/general.h:45:33: note: expanded from macro 'MP4_INVALID_TRACK_ID'
#define MP4_INVALID_TRACK_ID    ((MP4TrackId)0)       /**< Constant: invalid MP4TrackId. */
                                ^~~~~~~~~~~~~~~

--- src/mp4.cpp.orig	2009-07-13 23:07:12 UTC
+++ src/mp4.cpp
@@ -676,7 +676,7 @@ MP4FileHandle MP4ReadProvider( const char* fileName, u
         }
 
         catch (...) {
-            return MP4_INVALID_TRACK_ID;
+            return NULL;
         }
     }
 
