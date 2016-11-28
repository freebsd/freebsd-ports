/wrkdirs/usr/ports/multimedia/k9copy-kde4/work/k9copy-2.3.4-Source/src/backup/k9dvdbackup.cpp:888:24: error: call to 'abs' is ambiguous
            *_offset = abs(vobu1->newSector - vobu2->newSector)  | maskOffset1 ;
                       ^~~
/usr/include/stdlib.h:83:6: note: candidate function
int      abs(int) __pure2;
         ^
/usr/include/c++/v1/stdlib.h:115:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long      abs(     long __x) _NOEXCEPT {return  labs(__x);}
                                           ^
/usr/include/c++/v1/stdlib.h:117:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long long abs(long long __x) _NOEXCEPT {return llabs(__x);}
                                           ^

--- src/backup/k9dvdbackup.cpp.orig	2016-11-18 20:25:13 UTC
+++ src/backup/k9dvdbackup.cpp
@@ -885,7 +885,8 @@ k9Vobu * k9DVDBackup::remapOffset(uint32
 
 
         if ((vobu1 !=NULL) && (vobu2!=NULL)) {
-            *_offset = abs(vobu1->newSector - vobu2->newSector)  | maskOffset1 ;
+            uint32_t delta = ( vobu1->newSector > vobu2->newSector ? vobu1->newSector - vobu2->newSector : vobu2->newSector - vobu1->newSector );
+            *_offset = delta  | maskOffset1 ;
             *_offset |= maskOffset2;
             return vobu2;
         }
