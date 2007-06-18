--- src/mainwindow.cpp.orig	Wed Jun  7 12:54:20 2006
+++ src/mainwindow.cpp	Mon Jun  4 08:56:25 2007
@@ -879,6 +879,9 @@
 
 void KeepassMainWindow::OnEditUsernameToClipboard(){
 Clipboard->setText(currentEntry()->UserName,  QClipboard::Clipboard);
+if(Clipboard->supportsSelection()){
+ Clipboard->setText(currentEntry()->UserName,  QClipboard::Selection);
+}
 ClipboardTimer.setSingleShot(true);
 ClipboardTimer.start(config.ClipboardTimeOut*1000);
 }
@@ -886,6 +889,9 @@
 void KeepassMainWindow::OnEditPasswordToClipboard(){
 currentEntry()->Password.unlock();
 Clipboard->setText(currentEntry()->Password.string(),QClipboard::Clipboard);
+if(Clipboard->supportsSelection()){
+ Clipboard->setText(currentEntry()->Password.string(),QClipboard::Selection);
+}
 ClipboardTimer.setSingleShot(true);
 ClipboardTimer.start(config.ClipboardTimeOut*1000);
 currentEntry()->Password.lock();
@@ -894,6 +900,9 @@
 
 void KeepassMainWindow::OnClipboardTimeOut(){
 Clipboard->clear(QClipboard::Clipboard);
+if(Clipboard->supportsSelection()){
+ Clipboard->clear(QClipboard::Selection);
+}
 }
 
 void KeepassMainWindow::OnEditSaveAttachment(){
