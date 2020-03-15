--- Telegram/lib_ui/ui/widgets/labels.cpp.orig	2020-02-10 08:12:05 UTC
+++ Telegram/lib_ui/ui/widgets/labels.cpp
@@ -454,13 +454,13 @@ Text::StateResult FlatLabel::dragActionFinish(const QP
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
