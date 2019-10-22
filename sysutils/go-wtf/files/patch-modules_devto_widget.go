--- modules/devto/widget.go.orig	2019-10-11 19:16:00 UTC
+++ modules/devto/widget.go
@@ -14,7 +14,7 @@ import (
 type Widget struct {
 	view.KeyboardWidget
 	view.ScrollableWidget
-	articles []devto.ListedArticle
+	articles []devto.Article
 	settings *Settings
 	err      error
 }
@@ -59,7 +59,7 @@ func (widget *Widget) Refresh() {
 		widget.articles = nil
 		widget.SetItemCount(0)
 	} else {
-		var displayArticles []devto.ListedArticle
+		var displayArticles []devto.Article
 		var l int
 		if len(articles) < widget.settings.numberOfArticles {
 			l = len(articles)
