--- qdvdauthor/qplayer/mediacreator.cpp.orig	Mon Feb 14 20:53:57 2005
+++ qdvdauthor/qplayer/mediacreator.cpp	Mon Feb 14 20:53:59 2005
@@ -189,7 +189,7 @@
 	pParent = pParent;
 	pName = pName;
 	pExistingEngine = pExistingEngine;
-#ifdef VLC_SUPPORT
+#if (VLC_SUPPORT == 1)
 	pMediaInterface = (MediaInterface *) new VLCWidget (pParent, "VLCPart", pExistingEngine);
 #endif
 	return pMediaInterface;
@@ -206,7 +206,7 @@
 	if (m_qsPreferredEngine == "QMPlayerWidget")
 		pInfo = (MediaInfo *) new MPlayerInfo (pVoid);
 #endif
-#ifdef VLC_SUPPORT
+#if (VLC_SUPPORT == 1)
 	if (m_qsPreferredEngine == "VLCWidget")
 		pInfo = (MediaInfo *) new VLCInfo (pVoid);
 #endif
