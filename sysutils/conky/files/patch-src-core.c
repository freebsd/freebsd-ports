--- src/core.c.orig	2010-03-25 22:27:32.000000000 +0200
+++ src/core.c	2010-06-15 10:38:22.000000000 +0300
@@ -171,8 +171,6 @@
 			NORM_ERR("acpiacadapter: arg is only used on linux");
 #endif
 		}
-		if(! obj->data.opaque)
-			obj->data.opaque = strdup("AC");
 #endif /* !__OpenBSD__ */
 	END OBJ(freq, 0)
 		get_cpu_count();
@@ -279,8 +277,9 @@
 		obj->data.s = strndup(bat, text_buffer_size);
 	END OBJ(battery_bar, 0)
 		char bat[64];
-		if (arg) {
-			arg = scan_bar(obj, arg);
+
+		arg = scan_bar(obj, arg);
+		if (arg && strlen(arg)>0) {
 			sscanf(arg, "%63s", bat);
 		} else {
 			strcpy(bat, "BAT0");
@@ -372,18 +371,18 @@
 		scan_loadgraph_arg(obj, arg);
 #endif /* X11 */
 	END OBJ(diskio, &update_diskio)
-		parse_diskio_arg(obj, arg);
+		parse_diskio_arg(obj, dev_name(arg));
 	END OBJ(diskio_read, &update_diskio)
-		parse_diskio_arg(obj, arg);
+		parse_diskio_arg(obj, dev_name(arg));
 	END OBJ(diskio_write, &update_diskio)
-		parse_diskio_arg(obj, arg);
+		parse_diskio_arg(obj, dev_name(arg));
 #ifdef X11
 	END OBJ(diskiograph, &update_diskio)
-		parse_diskiograph_arg(obj, arg);
+		parse_diskiograph_arg(obj, dev_name(arg));
 	END OBJ(diskiograph_read, &update_diskio)
-		parse_diskiograph_arg(obj, arg);
+		parse_diskiograph_arg(obj, dev_name(arg));
 	END OBJ(diskiograph_write, &update_diskio)
-		parse_diskiograph_arg(obj, arg);
+		parse_diskiograph_arg(obj, dev_name(arg));
 #endif /* X11 */
 	END OBJ(color, 0)
 #ifdef X11
@@ -542,6 +541,11 @@
 		parse_platform_sensor(obj, arg);
 	END OBJ_ARG(hwmon, 0, "hwmon needs argumanets")
 		parse_hwmon_sensor(obj, arg);
+	END OBJ(addr, &update_net_stats)
+		parse_net_stat_arg(obj, arg, free_at_crash);
+	END OBJ(addrs, &update_net_stats)
+		parse_net_stat_arg(obj, arg, free_at_crash);
+#endif /* __linux__ */
 	END
 	/* we have four different types of top (top, top_mem, top_time and top_io). To
 	 * avoid having almost-same code four times, we have this special
@@ -552,12 +556,8 @@
 		if (!parse_top_args(s, arg, obj)) {
 			return NULL;
 		}
-	} else OBJ(addr, &update_net_stats)
-		parse_net_stat_arg(obj, arg, free_at_crash);
-	END OBJ(addrs, &update_net_stats)
-		parse_net_stat_arg(obj, arg, free_at_crash);
-#endif /* __linux__ */
-	END OBJ_ARG(tail, 0, "tail needs arguments")
+	} else
+		OBJ_ARG(tail, 0, "tail needs arguments")
 		init_tailhead("tail", arg, obj, free_at_crash);
 	END OBJ_ARG(head, 0, "head needs arguments")
 		init_tailhead("head", arg, obj, free_at_crash);
@@ -657,6 +657,7 @@
 		obj->sub = malloc(sizeof(struct text_object));
 		extract_variable_text_internal(obj->sub, arg);
 	END OBJ(nodename, 0)
+	END OBJ(nodename_short, 0)
 	END OBJ_ARG(cmdline_to_pid, 0, "cmdline_to_pid needs a command line as argument")
 		scan_cmdline_to_pid_arg(obj, arg, free_at_crash);
 	END OBJ_ARG(pid_chroot, 0, "pid_chroot needs a pid as argument")
@@ -786,9 +787,9 @@
 		obj->sub = malloc(sizeof(struct text_object));
 		extract_variable_text_internal(obj->sub, arg);
 	END OBJ(processes, &update_total_processes)
-#ifdef __linux__
 	END OBJ(running_processes, &update_top)
 		top_running = 1;
+#ifdef __linux__
 	END OBJ(threads, &update_threads)
 	END OBJ(running_threads, &update_stat)
 #else
@@ -966,8 +967,10 @@
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
@@ -993,9 +996,11 @@
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
@@ -1327,7 +1332,7 @@
 			strfold(p, 1);
 		} else if (*p == '#') {
 			char c;
-			if (remove_comment(p, &c) && p > orig_p && c == '\n') {
+			if (remove_comment(p, &c) && p >= orig_p && c == '\n') {
 				/* if remove_comment removed a newline, we need to 'back up' with p */
 				p--;
 			}
