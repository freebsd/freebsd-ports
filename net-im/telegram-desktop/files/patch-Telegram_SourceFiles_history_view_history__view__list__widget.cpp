--- Telegram/SourceFiles/history/view/history_view_list_widget.cpp.orig	2019-04-13 06:46:58 UTC
+++ Telegram/SourceFiles/history/view/history_view_list_widget.cpp
@@ -2031,7 +2031,7 @@ void ListWidget::mouseActionFinish(
 	_mouseSelectType = TextSelectType::Letters;
 	//_widget->noSelectingScroll(); // #TODO select scroll
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (_selectedTextItem
 		&& _selectedTextRange.from != _selectedTextRange.to) {
 		if (const auto view = viewForItem(_selectedTextItem)) {
@@ -2040,7 +2040,7 @@ void ListWidget::mouseActionFinish(
 				QClipboard::Selection);
 }
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void ListWidget::mouseActionUpdate() {
