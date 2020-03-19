--- Telegram/SourceFiles/history/history_inner_widget.cpp.orig	2020-03-16 18:49:16 UTC
+++ Telegram/SourceFiles/history/history_inner_widget.cpp
@@ -1420,7 +1420,7 @@ void HistoryInner::mouseActionFinish(
 	_widget->noSelectingScroll();
 	_widget->updateTopBarSelection();
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (!_selected.empty() && _selected.cbegin()->second != FullSelection) {
 		const auto [item, selection] = *_selected.cbegin();
 		if (const auto view = item->mainView()) {
@@ -1429,7 +1429,7 @@ void HistoryInner::mouseActionFinish(
 				QClipboard::Selection);
 		}
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void HistoryInner::mouseReleaseEvent(QMouseEvent *e) {
