--- kplayer/kplayernode.cpp.orig	2008-01-11 13:27:11.000000000 +0000
+++ kplayer/kplayernode.cpp
@@ -2397,8 +2397,10 @@ KPlayerContainerNode* KPlayerDevicesNode
 {
   QMap<QString, QString>::ConstIterator iterator = m_type_map.find (id);
   QString type (iterator == m_type_map.end() ? media() -> type (id) : iterator.value());
-  KPlayerDeviceNode* node = type == "TV" ? (KPlayerDeviceNode*) new KPlayerTVNode
-    : type == "DVB" ? (KPlayerDeviceNode*) new KPlayerDVBNode : (KPlayerDeviceNode*) new KPlayerDiskNode;
+  KPlayerDeviceNode* node;
+       if (type == "TV")  { node = (KPlayerDeviceNode*) new KPlayerTVNode; }
+  else if (type == "DVB") { node = (KPlayerDeviceNode*) new KPlayerDVBNode; } 
+  else                    { node = (KPlayerDeviceNode*) new KPlayerDiskNode; }
   node -> setup (this, id, origin);
   return node;
 }
