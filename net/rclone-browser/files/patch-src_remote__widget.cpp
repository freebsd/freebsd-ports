--- src/remote_widget.cpp.orig	2017-03-11 22:16:36 UTC
+++ src/remote_widget.cpp
@@ -129,7 +129,7 @@ RemoteWidget::RemoteWidget(IconCache* iconCache, const
             UseRclonePassword(&process);
             process.setProgram(GetRclone());
             process.setArguments(QStringList() << "mkdir" << GetRcloneConf() << remote + ":" + folder);
-            process.setReadChannelMode(QProcess::MergedChannels);
+            process.setProcessChannelMode(QProcess::MergedChannels);
 
             ProgressDialog progress("New Folder", "Creating...", folderMsg, &process, this);
             if (progress.exec() == QDialog::Accepted)
@@ -158,7 +158,7 @@ RemoteWidget::RemoteWidget(IconCache* iconCache, const
                                  << GetRcloneConf()
                                  << remote + ":" + path
                                  << remote + ":" + model->path(index.parent()).filePath(name));
-            process.setReadChannelMode(QProcess::MergedChannels);
+            process.setProcessChannelMode(QProcess::MergedChannels);
 
             ProgressDialog progress("Rename", "Renaming...", pathMsg, &process, this);
             if (progress.exec() == QDialog::Accepted)
@@ -182,13 +182,13 @@ RemoteWidget::RemoteWidget(IconCache* iconCache, const
             UseRclonePassword(&process);
             process.setProgram(GetRclone());
             process.setArguments(QStringList() << (model->isFolder(index) ? "purge" : "delete") << GetRcloneConf() << remote + ":" + path);
-            process.setReadChannelMode(QProcess::MergedChannels);
+            process.setProcessChannelMode(QProcess::MergedChannels);
 
             ProgressDialog progress("Delete", "Deleting...", pathMsg, &process, this);
             if (progress.exec() == QDialog::Accepted)
             {
                 QModelIndex parent = index.parent();
-                QModelIndex next = parent.child(index.row() + 1, 0);
+                QModelIndex next = parent.model()->index(index.row() + 1, 0, parent);
                 ui.tree->selectionModel()->select(next.isValid() ? next : parent, QItemSelectionModel::SelectCurrent);
                 model->removeRow(index.row(), parent);
             }
@@ -281,7 +281,7 @@ RemoteWidget::RemoteWidget(IconCache* iconCache, const
         UseRclonePassword(&process);
         process.setProgram(GetRclone());
         process.setArguments(QStringList() << "size" << GetRcloneConf() << remote + ":" + path);
-        process.setReadChannelMode(QProcess::MergedChannels);
+        process.setProcessChannelMode(QProcess::MergedChannels);
 
         ProgressDialog progress("Get Size", "Calculating...", pathMsg, &process, this, false);
         progress.expand();
@@ -314,7 +314,7 @@ RemoteWidget::RemoteWidget(IconCache* iconCache, const
             UseRclonePassword(&process);
             process.setProgram(GetRclone());
             process.setArguments(QStringList() << GetRcloneConf() << e.getOptions());
-            process.setReadChannelMode(QProcess::MergedChannels);
+            process.setProcessChannelMode(QProcess::MergedChannels);
 
             ProgressDialog progress("Export", "Exporting...", dst, &process, this);
             file->setParent(&progress);
