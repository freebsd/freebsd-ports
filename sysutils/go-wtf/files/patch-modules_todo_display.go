--- modules/todo/display.go.orig	1979-11-29 16:00:00 UTC
+++ modules/todo/display.go
@@ -122,7 +122,11 @@ func (widget *Widget) RowColor(idx int, hidden int, ch
 	}
 
 	if checked {
-		return widget.settings.Colors.Checked
+		return fmt.Sprintf(
+			"%s:%s",
+			widget.settings.Colors.Checked,
+			widget.CommonSettings().Colors.Background,
+		)
 	} else {
 		return widget.CommonSettings().RowColor(idx - hidden)
 	}
@@ -133,7 +137,7 @@ func (widget *Widget) formattedItemLine(idx int, hidde
 
 	todoDate := currItem.Date
 	row := fmt.Sprintf(
-		` [%s]|%s| `,
+		`[%s]|%s| `,
 		rowColor,
 		currItem.CheckMark(),
 	)
