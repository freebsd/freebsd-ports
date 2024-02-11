Index: peerlist.cpp
===================================================================
--- peerlist.cpp	(révision 322)
+++ peerlist.cpp	(copie de travail)
@@ -612,8 +612,9 @@
   }
   if( mark < slots && data[mark].count == 1 ) m_dup_req_pieces++;
   CONSOLE.Debug("%d dup req pieces", (int)m_dup_req_pieces);
+  auto midx = (mark < slots) ? data[mark].idx : BTCONTENT.GetNPieces(); 
   delete []data;
-  return (mark < slots) ? data[mark].idx : BTCONTENT.GetNPieces();
+  return midx;
 }
 
 void PeerList::FindValuedPieces(BitField &bf, const btPeer *proposer,
