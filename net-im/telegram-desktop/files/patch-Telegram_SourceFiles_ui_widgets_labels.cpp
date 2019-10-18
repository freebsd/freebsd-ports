--- Telegram/SourceFiles/ui/widgets/labels.cpp.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/ui/widgets/labels.cpp
@@ -400,13 +400,13 @@ Text::StateResult FlatLabel::dragActionFinish(const QP
 		}
 	}
 
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 	if (!_selection.empty()) {
 		TextUtilities::SetClipboardText(
 			_text.toTextForMimeData(_selection),
 			QClipboard::Selection);
 	}
-#endif // Q_OS_LINUX32 || Q_OS_LINUX64
+#endif // Q_OS_LINUX32 || Q_OS_LINUX64 || Q_OS_FREEBSD
 
 	return state;
 }
