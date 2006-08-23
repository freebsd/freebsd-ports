--- ./libicq2000-0.1/libicq2000/sigslot.h.orig	Wed Aug 23 01:30:57 2006
+++ ./libicq2000-0.1/libicq2000/sigslot.h	Wed Aug 23 01:34:04 2006
@@ -616,7 +616,6 @@
 				if((*it)->getdest() == pslot)
 				{
 					m_connected_slots.erase(it);
-					delete *it;
 				}
 
 				it = itNext;
