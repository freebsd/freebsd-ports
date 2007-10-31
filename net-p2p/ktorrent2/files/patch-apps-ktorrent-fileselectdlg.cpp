--- apps/ktorrent/fileselectdlg.cpp	2007/10/07 11:30:13	722461
+++ apps/ktorrent/fileselectdlg.cpp	2007/10/07 11:32:52	722462
@@ -94,11 +94,20 @@
 void FileSelectDlg::accept()
 {
 	QStringList pe_ex;
+	
+	QString dn = m_downloadLocation->url();
+	if (!dn.endsWith(bt::DirSeparator()))
+		dn += bt::DirSeparator();
 
 	for (Uint32 i = 0;i < tc->getNumFiles();i++)
 	{
 		kt::TorrentFileInterface & file = tc->getTorrentFile(i);
 
+		// check for preexsting files
+		QString path = dn + tc->getStats().torrent_name + bt::DirSeparator() + file.getPath();
+		if (bt::Exists(path))
+			file.setPreExisting(true);
+		
 		if (file.doNotDownload() && file.isPreExistingFile())
 		{
 			// we have excluded a preexsting file
@@ -136,10 +145,7 @@
 	}
 	
 	//Setup custom download location
-	QString dn = m_downloadLocation->url();
 	QString ddir = tc->getDataDir();
-	if (!dn.endsWith(bt::DirSeparator()))
-		dn += bt::DirSeparator();
 	if (!ddir.endsWith(bt::DirSeparator()))
 		ddir += bt::DirSeparator();
 	
