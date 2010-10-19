--- src/core.c.orig	2010-10-06 00:29:36.000000000 +0300
+++ src/core.c	2010-10-09 23:51:18.000000000 +0300
@@ -541,11 +541,11 @@
 		parse_platform_sensor(obj, arg);
 	END OBJ_ARG(hwmon, 0, "hwmon needs argumanets")
 		parse_hwmon_sensor(obj, arg);
-	END OBJ(addr, &update_net_stats)
-		parse_net_stat_arg(obj, arg, free_at_crash);
 	END OBJ(addrs, &update_net_stats)
 		parse_net_stat_arg(obj, arg, free_at_crash);
 #endif /* __linux__ */
+	END OBJ(addr, &update_net_stats)
+		parse_net_stat_arg(obj, arg, free_at_crash);
 	END
 	/* we have four different types of top (top, top_mem, top_time and top_io). To
 	 * avoid having almost-same code four times, we have this special
@@ -577,7 +577,7 @@
 		obj->data.s = strndup(arg, text_buffer_size);
 	END OBJ_IF_ARG(if_mounted, 0, "if_mounted needs an argument")
 		obj->data.s = strndup(arg, text_buffer_size);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 	END OBJ_IF_ARG(if_running, &update_top, "if_running needs an argument")
 		top_running = 1;
 		obj->data.s = strndup(arg, text_buffer_size);
@@ -787,9 +787,9 @@
 		obj->sub = malloc(sizeof(struct text_object));
 		extract_variable_text_internal(obj->sub, arg);
 	END OBJ(processes, &update_total_processes)
+#ifdef __linux__
 	END OBJ(running_processes, &update_top)
 		top_running = 1;
-#ifdef __linux__
 	END OBJ(threads, &update_threads)
 	END OBJ(running_threads, &update_stat)
 #else
@@ -967,8 +967,10 @@
 	END OBJ(xmms2_size, &update_xmms2)
 	END OBJ(xmms2_status, &update_xmms2)
 	END OBJ(xmms2_percent, &update_xmms2)
+#ifdef X11
 	END OBJ(xmms2_bar, &update_xmms2)
 		scan_bar(obj, arg);
+#endif
 	END OBJ(xmms2_smart, &update_xmms2)
 	END OBJ(xmms2_playlist, &update_xmms2)
 	END OBJ(xmms2_timesplayed, &update_xmms2)
@@ -994,9 +996,11 @@
 	END OBJ(audacious_playlist_length, &update_audacious)
 	END OBJ(audacious_playlist_position, &update_audacious)
 	END OBJ(audacious_main_volume, &update_audacious)
+#ifdef X11
 	END OBJ(audacious_bar, &update_audacious)
 		scan_bar(obj, arg);
 #endif
+#endif
 #ifdef BMPX
 	END OBJ(bmpx_title, &update_bmpx)
 		memset(&(info.bmpx), 0, sizeof(struct bmpx_s));
