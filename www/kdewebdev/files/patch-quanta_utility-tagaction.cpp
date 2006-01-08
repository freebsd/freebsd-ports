--- quanta/utility/tagaction.cpp.orig	Mon Dec 19 16:28:54 2005
+++ quanta/utility/tagaction.cpp	Mon Dec 19 16:59:38 2005
@@ -1145,7 +1145,7 @@
     long cursor_offset = selection.cursorOffset();
     kafkaCommon::splitStartAndEndNodeSubtree(start_node, start_offset, end_node, end_offset, commonParent, 
                                              commonParentStartChildLocation, commonParentEndChildLocation,
-                                             selection, false, modifs);
+                                             selection, 0, modifs);
 
     Q_ASSERT(start_node != end_node);
     
@@ -1221,7 +1221,7 @@
     int cursor_offset = selection.cursorOffset();*/
     kafkaCommon::splitStartAndEndNodeSubtree(start_node, start_offset, end_node, end_offset, commonParent, 
                                              commonParentStartChildLocation, commonParentEndChildLocation,
-                                             selection, /*cursor_node, cursor_offset, */false, modifs); 
+                                             selection, /*cursor_node, cursor_offset, */0, modifs); 
     
 //     kafkaCommon::coutTree(baseNode, 3);
     
