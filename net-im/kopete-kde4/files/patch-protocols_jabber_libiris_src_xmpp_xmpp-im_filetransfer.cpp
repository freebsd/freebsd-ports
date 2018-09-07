--- protocols/jabber/libiris/src/xmpp/xmpp-im/filetransfer.cpp.orig	2018-09-07 10:16:18 UTC
+++ protocols/jabber/libiris/src/xmpp/xmpp-im/filetransfer.cpp
@@ -430,7 +430,7 @@ FileTransfer *FileTransferManager::takeI
 
 bool FileTransferManager::isActive(const FileTransfer *ft) const
 {
-	return d->list.contains(const_cast<FileTransfer*>(ft)) > 0;
+	return d->list.contains(const_cast<FileTransfer*>(ft));
 }
 
 void FileTransferManager::setDisabled(const QString &ns, bool state)
