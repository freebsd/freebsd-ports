--- src/lib/STOFFOLEParser.cxx.orig	2018-01-30 09:10:08 UTC
+++ src/lib/STOFFOLEParser.cxx
@@ -506,7 +506,7 @@ bool STOFFOLEParser::readSummaryInformation(STOFFInput
   ascii.addPos(pos);
   ascii.addNote(f.str().c_str());
 
-  for (auto const posToType : posToTypeMap) {
+  for (auto const &posToType : posToTypeMap) {
     pos=posToType.first;
     input->seek(pos, librevenge::RVNG_SEEK_SET);
     f.str("");
