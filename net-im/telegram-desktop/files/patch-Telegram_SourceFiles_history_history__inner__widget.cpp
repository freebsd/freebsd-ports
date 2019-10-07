--- Telegram/SourceFiles/history/history_inner_widget.cpp.orig	2019-09-27 17:04:25 UTC
+++ Telegram/SourceFiles/history/history_inner_widget.cpp
@@ -1394,7 +1394,7 @@ void HistoryInner::mouseActionFinish(
 	_widget->noSelectingScroll();
 	_widget->updateTopBarSelection();
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (!_selected.empty() && _selected.cbegin()->second != FullSelection) {
 		const auto [item, selection] = *_selected.cbegin();
 		if (const auto view = item->mainView()) {
@@ -1403,7 +1403,7 @@ void HistoryInner::mouseActionFinish(
 				QClipboard::Selection);
 		}
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 }
 
 void HistoryInner::mouseReleaseEvent(QMouseEvent *e) {
