Fix build with Qt 6.8.x. This reverts [1].

/wrkdirs/usr/ports/net-im/telegram-desktop/work-qt6/tdesktop-5.9.0-full/Telegram/SourceFiles/payments/ui/payments_reaction_box.cpp:45:10:
note: defaulted 'operator<=>' is implicitly deleted because there is no viable three-way comparison function for member 'name'
   45 |         QString name;

[1] https://github.com/desktop-app/lib_base/commit/601c20431cc3f91de01e1b13a033e0a41cd36353

--- Telegram/lib_base/base/qt/qt_compare.h.orig	2024-11-05 09:17:02 UTC
+++ Telegram/lib_base/base/qt/qt_compare.h
@@ -21,13 +21,11 @@ template <typename P>
 	return a.get() <=> b.get();
 }
 
-#if QT_VERSION < QT_VERSION_CHECK(6, 8, 0)
 [[nodiscard]] inline std::strong_ordering operator<=>(
 		const QString &a,
 		const QString &b) noexcept {
 	return a.compare(b) <=> 0;
 }
-#endif // Qt < 6.8.0
 
 template <typename T>
 [[nodiscard]] inline std::strong_ordering operator<=>(
