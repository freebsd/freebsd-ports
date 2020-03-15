--- Telegram/SourceFiles/history/view/history_view_list_widget.cpp.orig	2020-02-18 08:28:06 UTC
+++ Telegram/SourceFiles/history/view/history_view_list_widget.cpp
@@ -2066,7 +2066,7 @@ void ListWidget::mouseActionFinish(
 	_mouseSelectType = TextSelectType::Letters;
 	//_widget->noSelectingScroll(); // #TODO select scroll
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (_selectedTextItem
 		&& _selectedTextRange.from != _selectedTextRange.to) {
 		if (const auto view = viewForItem(_selectedTextItem)) {
@@ -2075,7 +2075,7 @@ void ListWidget::mouseActionFinish(
 				QClipboard::Selection);
 }
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void ListWidget::mouseActionUpdate() {
