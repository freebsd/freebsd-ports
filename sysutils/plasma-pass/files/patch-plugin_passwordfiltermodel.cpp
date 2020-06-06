Obtained from: https://github.com/KDE/plasma-pass/commit/3fb633159ca4a1db166d5c54bbc025f71aba1652

--- plugin/passwordfiltermodel.cpp.orig	2020-06-06 09:37:44 UTC
+++ plugin/passwordfiltermodel.cpp
@@ -79,7 +79,11 @@ void PasswordFilterModel::delayedUpdateFilter()
     Q_ASSERT(sender() == &mUpdateTimer);
 
     mFilter = mUpdateTimer.property(newFilterProperty).toString();
+#if QT_VERSION < QT_VERSION_CHECK(5, 15, 0)
     mParts = mFilter.splitRef(QLatin1Char('/'), QString::SkipEmptyParts);
+#else
+    mParts = mFilter.splitRef(QLatin1Char('/'), Qt::SkipEmptyParts);
+#endif
     Q_EMIT passwordFilterChanged();
     mSortingLookup.clear();
     invalidate();
