--- libdiscover/appstream/AppStreamUtils.h.orig	2023-10-24 12:55:33 UTC
+++ libdiscover/appstream/AppStreamUtils.h
@@ -6,9 +6,9 @@
 
 #pragma once
 
-#include <AppStreamQt/component.h>
-#include <AppStreamQt/image.h>
-#include <AppStreamQt/pool.h>
+#include <AppStreamQt5/component.h>
+#include <AppStreamQt5/image.h>
+#include <AppStreamQt5/pool.h>
 #include <QColor>
 #include <QList>
 #include <QUrl>
@@ -38,5 +38,5 @@ Q_DECL_EXPORT uint contentRatingMinimumAge(const AppSt
 Q_DECL_EXPORT AbstractResource::ContentIntensity contentRatingIntensity(const AppStream::Component &appdata);
 Q_DECL_EXPORT uint contentRatingMinimumAge(const AppStream::Component &appdata);
 
-Q_DECL_EXPORT QList<AppStream::Component> componentsByCategories(AppStream::Pool *pool, Category *cat, AppStream::Bundle::Kind kind);
+Q_DECL_EXPORT AppStream::ComponentBox componentsByCategories(AppStream::Pool *pool, Category *cat, AppStream::Bundle::Kind kind);
 }
