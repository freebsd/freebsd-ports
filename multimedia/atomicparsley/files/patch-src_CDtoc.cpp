audio/cdparanoia uses 0xaa on FreeBSD

src/CDtoc.cpp:165:40: error: use of undeclared identifier 'LEADOUT_TRACK_NUMBER'
    if (track_TOC_desc->tracknumber == LEADOUT_TRACK_NUMBER) {
                                       ^

--- src/CDtoc.cpp.orig	2021-01-15 02:48:25 UTC
+++ src/CDtoc.cpp
@@ -73,7 +73,7 @@ CD_TOC_ *cdTOC = NULL;
 uint8_t LEADOUT_TRACK_NUMBER = MACOSX_LEADOUT_TRACK;
 #elif defined(__linux__)
 uint8_t LEADOUT_TRACK_NUMBER = CDROM_LEADOUT;
-#elif defined(_WIN32)
+#else
 uint8_t LEADOUT_TRACK_NUMBER =
     0xAA; // NOTE: for WinXP IOCTL_CDROM_READ_TOC_EX code, its 0xA2
 #endif
