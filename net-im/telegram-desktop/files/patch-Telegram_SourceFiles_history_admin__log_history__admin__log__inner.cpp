--- Telegram/SourceFiles/history/admin_log/history_admin_log_inner.cpp.orig	2018-04-08 17:34:33 UTC
+++ Telegram/SourceFiles/history/admin_log/history_admin_log_inner.cpp
@@ -1388,13 +1388,13 @@ void InnerWidget::mouseActionFinish(cons
 	_mouseSelectType = TextSelectType::Letters;
 	//_widget->noSelectingScroll(); // TODO
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (_selectedItem && _selectedText.from != _selectedText.to) {
 		SetClipboardWithEntities(
 			_selectedItem->selectedText(_selectedText),
 			QClipboard::Selection);
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void InnerWidget::updateSelected() {
