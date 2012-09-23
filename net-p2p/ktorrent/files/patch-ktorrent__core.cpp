--- ./ktorrent/core.cpp.orig	2012-09-01 08:59:57.000000000 +0000
+++ ./ktorrent/core.cpp	2012-09-23 19:02:36.644549119 +0000
@@ -1206,26 +1206,6 @@
 
 	bool Core::checkMissingFiles(TorrentInterface* tc)
 	{
-		QStringList not_mounted;
-		while(!tc->isStorageMounted(not_mounted))
-		{
-			QString msg = i18n("One or more storage volumes are not mounted. In order to start this torrent, they need to be mounted.");
-			KGuiItem retry(i18n("Retry"), "emblem-mounted");
-			if(KMessageBox::warningContinueCancelList(gui, msg, not_mounted, QString(), retry) == KMessageBox::Continue)
-			{
-				not_mounted.clear();
-				continue;
-			}
-			else
-			{
-				if(not_mounted.size() == 1)
-					tc->handleError(i18n("Storage volume %1 is not mounted", not_mounted.first()));
-				else
-					tc->handleError(i18n("Storage volumes %1 are not mounted", not_mounted.join(", ")));
-				return false;
-			}
-		}
-
 		QStringList missing;
 		if(!tc->hasMissingFiles(missing))
 			return true;
