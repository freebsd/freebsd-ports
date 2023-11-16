--- libdiscover/appstream/AppStreamUtils.cpp.orig	2023-10-24 12:55:33 UTC
+++ libdiscover/appstream/AppStreamUtils.cpp
@@ -7,11 +7,11 @@
 #include "AppStreamUtils.h"
 
 #include "utils.h"
-#include <AppStreamQt/pool.h>
-#include <AppStreamQt/release.h>
-#include <AppStreamQt/screenshot.h>
-#include <AppStreamQt/spdx.h>
-#include <AppStreamQt/version.h>
+#include <AppStreamQt5/pool.h>
+#include <AppStreamQt5/release.h>
+#include <AppStreamQt5/screenshot.h>
+#include <AppStreamQt5/spdx.h>
+#include <AppStreamQt5/version.h>
 #include <Category/Category.h>
 #include <KLocalizedString>
 #include <QDebug>
@@ -35,10 +35,20 @@ QString AppStreamUtils::changelogToHtml(const AppStrea
 
 QString AppStreamUtils::changelogToHtml(const AppStream::Component &appdata)
 {
-    if (appdata.releases().isEmpty())
+#if ASQ_CHECK_VERSION(1, 0, 0)
+    const auto releases = appdata.releasesPlain();
+#else
+    const auto releases = appdata.releases();
+#endif
+    if (releases.isEmpty()) {
         return {};
+    }
 
-    const auto release = appdata.releases().constFirst();
+#if ASQ_CHECK_VERSION(1, 0, 0)
+    const auto release = releases.indexSafe(0).value();
+#else
+    const auto release = releases.constFirst();
+#endif
     if (release.description().isEmpty())
         return {};
 
@@ -49,17 +59,19 @@ Screenshots AppStreamUtils::fetchScreenshots(const App
 
 Screenshots AppStreamUtils::fetchScreenshots(const AppStream::Component &appdata)
 {
-    const auto appdataScreenshots = appdata.screenshots();
+    const auto appdataScreenshots = appdata.screenshotsAll();
     Screenshots ret;
     ret.reserve(appdataScreenshots.size());
     for (const AppStream::Screenshot &s : appdataScreenshots) {
         const auto images = s.images();
         const QUrl thumbnail = AppStreamUtils::imageOfKind(images, AppStream::Image::KindThumbnail);
-        const QUrl plain = AppStreamUtils::imageOfKind(images, AppStream::Image::KindSource);
-        if (plain.isEmpty())
-            qWarning() << "invalid screenshot for" << appdata.name();
+        const QUrl full = AppStreamUtils::imageOfKind(images, AppStream::Image::KindSource);
+        if (full.isEmpty()) {
+            qWarning() << "AppStreamUtils: Invalid screenshot for" << appdata.name();
+        }
+        const bool isAnimated = s.mediaKind() == AppStream::Screenshot::MediaKindVideo;
 
-        ret.append(Screenshot{plain, thumbnail.isEmpty() ? plain : thumbnail, s.mediaKind() == AppStream::Screenshot::MediaKindVideo});
+        ret.append(Screenshot{thumbnail.isEmpty() ? full : thumbnail, full, isAnimated});
     }
     return ret;
 }
@@ -128,20 +140,13 @@ QString AppStreamUtils::versionString(const QString &v
 
 QString AppStreamUtils::versionString(const QString &version, const AppStream::Component &appdata)
 {
+    Q_UNUSED(appdata);
+
     if (version.isEmpty()) {
         return {};
-    } else {
-        if (appdata.releases().isEmpty())
-            return version;
-
-        auto release = appdata.releases().constFirst();
-        if (release.timestamp().isValid() && version.startsWith(release.version())) {
-            QLocale l;
-            return i18n("%1, released on %2", version, l.toString(release.timestamp().date(), QLocale::ShortFormat));
-        } else {
-            return version;
-        }
     }
+
+    return version;
 }
 
 QString AppStreamUtils::contentRatingDescription(const AppStream::Component &appdata)
@@ -238,7 +243,7 @@ uint AppStreamUtils::contentRatingMinimumAge(const App
 #endif
 }
 
-static void kRemoveDuplicates(QList<AppStream::Component> &input, AppStream::Bundle::Kind kind)
+static void kRemoveDuplicates(AppStream::ComponentBox &input, AppStream::Bundle::Kind kind)
 {
     QSet<QString> ret;
     for (auto it = input.begin(); it != input.end();) {
@@ -252,9 +257,9 @@ static void kRemoveDuplicates(QList<AppStream::Compone
     }
 }
 
-QList<AppStream::Component> AppStreamUtils::componentsByCategories(AppStream::Pool *pool, Category *cat, AppStream::Bundle::Kind kind)
+AppStream::ComponentBox AppStreamUtils::componentsByCategories(AppStream::Pool *pool, Category *cat, AppStream::Bundle::Kind kind)
 {
-    QList<AppStream::Component> ret;
+    AppStream::ComponentBox ret(AppStream::ComponentBox::FlagNoChecks);
     for (const auto &categoryName : cat->involvedCategories()) {
         ret += pool->componentsByCategories({categoryName});
     }
