--- Telegram/SourceFiles/history/view/history_view_list_widget.cpp.orig	2018-04-15 23:31:46 UTC
+++ Telegram/SourceFiles/history/view/history_view_list_widget.cpp
@@ -2014,7 +2014,7 @@ void ListWidget::mouseActionFinish(
 	_mouseSelectType = TextSelectType::Letters;
 	//_widget->noSelectingScroll(); // #TODO select scroll
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (_selectedTextItem
 		&& _selectedTextRange.from != _selectedTextRange.to) {
 		if (const auto view = viewForItem(_selectedTextItem)) {
