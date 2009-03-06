--- widgets/misc/e-calendar-item.c.orig	2009-03-04 22:45:32.000000000 -0500
+++ widgets/misc/e-calendar-item.c	2009-03-04 22:50:13.000000000 -0500
@@ -1505,12 +1505,12 @@ e_calendar_item_draw_day_numbers (ECalen
 			if (week_num >= 10) {
 				digit = week_num / 10;
 				text_x -= calitem->week_number_digit_widths[digit];
-				num_chars += sprintf (&buffer[num_chars], "%Id", digit);
+				num_chars += sprintf (&buffer[num_chars], "%d", digit);
 			}
 
 			digit = week_num % 10;
 			text_x -= calitem->week_number_digit_widths[digit] + 6;
-			num_chars += sprintf (&buffer[num_chars], "%Id", digit);
+			num_chars += sprintf (&buffer[num_chars], "%d", digit);
 
 			cairo_save (cr);
 			gdk_cairo_set_source_color (cr, &style->text[GTK_STATE_ACTIVE]);
@@ -1618,12 +1618,12 @@ e_calendar_item_draw_day_numbers (ECalen
 				if (day_num >= 10) {
 					digit = day_num / 10;
 					day_x -= calitem->digit_widths[digit];
-					num_chars += sprintf (&buffer[num_chars], "%Id", digit);
+					num_chars += sprintf (&buffer[num_chars], "%d", digit);
 				}
 
 				digit = day_num % 10;
 				day_x -= calitem->digit_widths[digit];
-				num_chars += sprintf (&buffer[num_chars], "%Id", digit);
+				num_chars += sprintf (&buffer[num_chars], "%d", digit);
 
 				cairo_save (cr);
 				if (fg_color) {
@@ -1958,7 +1958,7 @@ e_calendar_item_recalc_sizes		(ECalendar
 		gchar locale_digit[5];
 		int locale_digit_len;
 		
-		locale_digit_len = sprintf (locale_digit, "%Id", digit);
+		locale_digit_len = sprintf (locale_digit, "%d", digit);
 
 		pango_layout_set_text (layout, locale_digit, locale_digit_len);
 		pango_layout_get_pixel_size (layout, &width, NULL);
