*** panel-plugin/weather.c	Sun Feb 29 22:10:53 2004
--- weather.c	Fri Apr  2 16:00:39 2004
***************
*** 375,380 ****
--- 375,382 ----
  
  void start_draw_up(xfceweather_data *data) {
          gint width, height;
+ 		GdkRectangle update_rect = {0, 0, data->drawable_label->allocation.width,
+                         data->drawable_label->allocation.height};
          
          /* if only one pixmap don't start the callback */
          if (!data->xmldata_pixmaps || data->xmldata_pixmaps->len == 0)
***************
*** 383,391 ****
          if (data->xmldata_pixmaps->len == 1) {
                  data->drawable_pixmap = (GdkPixmap *)g_ptr_array_index(data->xmldata_pixmaps, 0);
                  data->drawable_offset = 0;
- 
-                 GdkRectangle update_rect = {0, 0, data->drawable_label->allocation.width,
-                         data->drawable_label->allocation.height};
  
                  gtk_widget_draw(data->drawable_label, &update_rect);
                  return;
--- 385,390 ----
