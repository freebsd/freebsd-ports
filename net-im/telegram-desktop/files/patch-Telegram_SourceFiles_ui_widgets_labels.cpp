--- Telegram/SourceFiles/ui/widgets/labels.cpp.orig	2019-07-07 13:34:35 UTC
+++ Telegram/SourceFiles/ui/widgets/labels.cpp
@@ -391,11 +391,11 @@ Ui::Text::StateResult FlatLabel::dragActionFinish(cons
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
