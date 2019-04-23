--- Telegram/SourceFiles/ui/widgets/labels.cpp.orig	2019-04-13 06:46:58 UTC
+++ Telegram/SourceFiles/ui/widgets/labels.cpp
@@ -361,11 +361,11 @@ Text::StateResult FlatLabel::dragActionFinish(const QP
 		}
 	}
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (!_selection.empty()) {
 		SetClipboardText(_text.toTextForMimeData(_selection), QClipboard::Selection);
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 
 	return state;
 }
