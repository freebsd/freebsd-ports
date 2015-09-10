--- src/lib/VSDMetaData.cpp.orig	2015-07-25 07:17:57 UTC
+++ src/lib/VSDMetaData.cpp
@@ -302,7 +302,7 @@ bool libvisio::VSDMetaData::parseTimes(l
   uint32_t firstDirSectorLocation = readU32(input);
 
   // Seek to the Root Directory Entry
-  size_t sectorSize = std::pow(2, sectorShift);
+  size_t sectorSize = 1UL << sectorShift;
   input->seek((firstDirSectorLocation + 1) * sectorSize, librevenge::RVNG_SEEK_SET);
   // DirectoryEntryName: 64 bytes
   // DirectoryEntryNameLength: 2 bytes
