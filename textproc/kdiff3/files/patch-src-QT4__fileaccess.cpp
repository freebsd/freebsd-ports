--- ./src-QT4/fileaccess.cpp.orig	2012-08-10 16:51:08.000000000 -0500
+++ ./src-QT4/fileaccess.cpp	2014-06-05 09:45:18.675613156 -0500
@@ -183,7 +183,8 @@
 
 void FileAccess::setFile( const QFileInfo& fi, FileAccess* pParent )
 {
-   m_filePath   = nicePath( fi.filePath() ); // remove "./" at start   
+   m_filePath   = pParent == 0 ? fi.absoluteFilePath() : 
+                                 nicePath( fi.filePath() ); // remove "./" at start   
 
    m_bSymLink   = fi.isSymLink();
    if ( m_bSymLink || (!m_bExists  && m_filePath.contains("@@") ) )
@@ -566,7 +567,16 @@
    if ( parent() != 0 )
       return parent()->absoluteFilePath() + "/" + m_filePath;
    else
-      return m_filePath;
+   {
+      if ( m_filePath.isEmpty() )
+	 return QString();
+      
+      QFileInfo fi( m_filePath );
+      if ( fi.isAbsolute() )
+	 return m_filePath;
+      else
+	 return fi.absoluteFilePath(); // Probably never reached
+   }
 }  // Full abs path
 
 // Just the name-part of the path, without parent directories
@@ -1184,7 +1194,7 @@
       m_bSuccess = false;
       KIO::FileCopyJob* pJob = KIO::file_move( m_pFileAccess->url(), kurl, permissions, KIO::HideProgressInfo );
       connect( pJob, SIGNAL(result(KJob*)), this, SLOT(slotSimpleJobResult(KJob*)));
-      connect( pJob, SIGNAL(percent(KJob*,unsigned long)), this, SLOT(slotPercent(KJob*, unsigned long)));
+      connect( pJob, SIGNAL(percent(KJob*,unsigned long)), &pp, SLOT(slotPercent(KJob*, unsigned long)));
 
       ProgressProxy::enterEventLoop( pJob,
          i18n("Renaming file: %1 -> %2",m_pFileAccess->prettyAbsPath(),dest) );
@@ -1673,7 +1683,7 @@
                   &pp,      SLOT( slotListDirInfoMessage(KJob*, const QString&) ));
 
          // This line makes the transfer via fish unreliable.:-(
-         //connect( pListJob, SIGNAL(percent(KJob*,unsigned long)), this, SLOT(slotPercent(KJob*, unsigned long)));
+         //connect( pListJob, SIGNAL(percent(KJob*,unsigned long)), &pp, SLOT(slotPercent(KJob*, unsigned long)));
 
          ProgressProxy::enterEventLoop( pListJob,
             i18n("Listing directory: %1",m_pFileAccess->prettyAbsPath()) );
