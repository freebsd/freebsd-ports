--- src/conky.c.orig	2010-03-25 22:27:32.000000000 +0200
+++ src/conky.c	2010-06-11 23:10:56.000000000 +0300
@@ -166,9 +166,7 @@
 #ifdef IOSTATS
 int top_io;
 #endif
-#ifdef __linux__
 int top_running;
-#endif
 int output_methods;
 static int extra_newline;
 enum x_initialiser_state x_initialised = NO;
@@ -269,9 +267,6 @@
 #ifdef IMLIB2
 		   "  * Imlib2\n"
 #endif /* IMLIB2 */
-#ifdef MIXER_IS_ALSA
-		   "  * ALSA mixer support\n"
-#endif /* MIXER_IS_ALSA */
 #ifdef APCUPSD
 		   "  * apcupsd\n"
 #endif /* APCUPSD */
@@ -463,7 +458,7 @@
 		}
 		fclose(where);
 	} else {
-		NORM_ERR("Could not open the file");
+		NORM_ERR("Could not open the file '%s'", f);
 	}
 	return ret;
 }
@@ -512,6 +507,7 @@
 	char *ps, *pe;
 	int special_index = 0; /* specials index */
 
+	if(! b) return;
 	for (ps = b, pe = b; *pe; pe++) {
 		if (*pe == '\n') {
 			*pe = '\0';
@@ -765,6 +761,8 @@
 	buff_in[0] = 0;
 #endif /* HAVE_ICONV */
 
+	if(! p) return;
+
 	p[0] = 0;
 	obj = root.next;
 	while (obj && p_max_size > 0) {
@@ -1330,7 +1328,7 @@
 					DO_JUMP;
 				} else if (spc) {
 					*spc = '\0';
-					if (check_contains(obj->data.s, spc + 1))
+					if (!check_contains(obj->data.s, spc + 1))
 						DO_JUMP;
 					*spc = ' ';
 				}
@@ -1503,6 +1501,15 @@
 			OBJ(nodename) {
 				snprintf(p, p_max_size, "%s", cur->uname_s.nodename);
 			}
+			OBJ(nodename_short) {
+				char *pos;
+				pos = strstr(cur->uname_s.nodename, ".");
+				if(pos != NULL) {
+					snprintf(p, MIN(pos-cur->uname_s.nodename+1, p_max_size), "%s", cur->uname_s.nodename);
+				} else {
+					snprintf(p, p_max_size, "%s", cur->uname_s.nodename);
+				}
+			}
 			OBJ(outlinecolor) {
 				new_outline(p, obj->data.l);
 			}
@@ -2062,9 +2069,11 @@
 			OBJ(xmms2_percent) {
 				snprintf(p, p_max_size, "%2.0f", cur->xmms2.progress * 100);
 			}
+#ifdef X11
 			OBJ(xmms2_bar) {
 				new_bar(obj, p, p_max_size, (int) (cur->xmms2.progress * 255.0f));
 			}
+#endif /* X11 */
 			OBJ(xmms2_playlist) {
 				snprintf(p, p_max_size, "%s", cur->xmms2.playlist);
 			}
@@ -2140,6 +2149,7 @@
 				snprintf(p, p_max_size, "%s",
 					cur->audacious.items[AUDACIOUS_MAIN_VOLUME]);
 			}
+#ifdef X11
 			OBJ(audacious_bar) {
 				double progress;
 
@@ -2148,6 +2158,7 @@
 					atof(cur->audacious.items[AUDACIOUS_LENGTH_SECONDS]);
 				new_bar(obj, p, p_max_size, (int) (progress * 255.0f));
 			}
+#endif /* X11 */
 #endif /* AUDACIOUS */
 
 #ifdef BMPX
@@ -2173,7 +2184,6 @@
 			/* we have four different types of top (top, top_mem,
 			 * top_time and top_io). To avoid having almost-same code four
 			 * times, we have this special handler. */
-#ifdef __linux__
 			break;
 			case OBJ_top:
 			case OBJ_top_mem:
@@ -2182,7 +2192,6 @@
 			case OBJ_top_io:
 #endif
 				print_top(obj, p, p_max_size);
-#endif /* __linux__ */
 			OBJ(tail) {
 				print_tailhead("tail", obj, p, p_max_size);
 			}
@@ -2375,13 +2384,7 @@
 #ifdef HAVE_ICONV
 			iconv_convert(&a, buff_in, p, p_max_size);
 #endif /* HAVE_ICONV */
-			if (obj->type != OBJ_text && obj->type != OBJ_execp && obj->type != OBJ_execpi
-#ifdef HAVE_LUA
-					&& obj->type != OBJ_lua && obj->type != OBJ_lua_parse
-#endif /* HAVE_LUA */
-					) {
-				substitute_newlines(p, a - 2);
-			}
+			substitute_newlines(p, a - 2);
 			p += a;
 			p_max_size -= a;
 			(*p) = 0;
@@ -3119,36 +3122,49 @@
 						if (seconds != 0) {
 							timeunits = seconds / 86400; seconds %= 86400;
 							if (timeunits > 0) {
-								asprintf(&tmp_day_str, "%dd", timeunits);
+								if (asprintf(&tmp_day_str, "%dd", timeunits) < 0) {
+									tmp_day_str = 0;
+								}
 							} else {
 								tmp_day_str = strdup("");
 							}
 							timeunits = seconds / 3600; seconds %= 3600;
 							if (timeunits > 0) {
-								asprintf(&tmp_hour_str, "%dh", timeunits);
+								if (asprintf(&tmp_hour_str, "%dh", timeunits) < 0) {
+									tmp_day_str = 0;
+								}
 							} else {
 								tmp_hour_str = strdup("");
 							}
 							timeunits = seconds / 60; seconds %= 60;
 							if (timeunits > 0) {
-								asprintf(&tmp_min_str, "%dm", timeunits);
+								if (asprintf(&tmp_min_str, "%dm", timeunits) < 0) {
+									tmp_min_str = 0;
+								}
 							} else {
 								tmp_min_str = strdup("");
 							}
 							if (seconds > 0) {
-								asprintf(&tmp_sec_str, "%ds", seconds);
+								if (asprintf(&tmp_sec_str, "%ds", seconds) < 0) {
+									tmp_sec_str = 0;
+								}
 							} else {
 								tmp_sec_str = strdup("");
 							}
-							asprintf(&tmp_str, "%s%s%s%s", tmp_day_str, tmp_hour_str, tmp_min_str, tmp_sec_str);
-							free(tmp_day_str); free(tmp_hour_str); free(tmp_min_str); free(tmp_sec_str);
+							if (asprintf(&tmp_str, "%s%s%s%s", tmp_day_str,
+										tmp_hour_str, tmp_min_str, tmp_sec_str) < 0) {
+								tmp_str = 0;
+							}
+#define FREE(a) if ((a)) free((a));
+							FREE(tmp_day_str); FREE(tmp_hour_str); FREE(tmp_min_str); FREE(tmp_sec_str);
 						} else {
-							asprintf(&tmp_str, "Range not possible"); // should never happen, but better safe then sorry
+							tmp_str = strdup("Range not possible"); /* should never happen, but better safe then sorry */
 						}
 						cur_x += (w / 2) - (font_ascent() * (strlen(tmp_str) / 2));
 						cur_y += font_h / 2;
 						draw_string(tmp_str);
-						free(tmp_str);
+						FREE(tmp_str);
+#undef FREE
 						cur_x = tmp_x;
 						cur_y = tmp_y;
 					}
@@ -3974,11 +3990,39 @@
 	initialisation(argc_copy, argv_copy);
 }
 
-void clean_up(void *memtofree1, void* memtofree2)
-{
-	int i;
+#ifdef X11
+void clean_up_x11() {
+	if(window_created == 1) {
+		XClearArea(display, window.window, text_start_x - window.border_inner_margin - window.border_outer_margin - window.border_width,
+			text_start_y - window.border_inner_margin - window.border_outer_margin - window.border_width,
+			text_width + window.border_inner_margin * 2 + window.border_outer_margin * 2 + window.border_width * 2,
+			text_height + window.border_inner_margin * 2 + window.border_outer_margin * 2 + window.border_width * 2, 0);
+	}
+	destroy_window();
+	free_fonts();
+	fonts = NULL;
+	if(x11_stuff.region) {
+		XDestroyRegion(x11_stuff.region);
+		x11_stuff.region = NULL;
+	}
+	if(display) {
+		XCloseDisplay(display);
+		display = NULL;
+	}
+	if(info.x11.desktop.all_names) {
+		free(info.x11.desktop.all_names);
+		info.x11.desktop.all_names = NULL;
+	}
+	if (info.x11.desktop.name) {
+		free(info.x11.desktop.name);
+		info.x11.desktop.name = NULL;
+	}
+	x_initialised = NO;
+}
+#endif
 
-	free_update_callbacks();
+void clean_up_without_threads(void *memtofree1, void* memtofree2) {
+	int i;
 
 #ifdef NCURSES
 	if(output_methods & TO_NCURSES) {
@@ -4001,29 +4045,7 @@
 	}
 #ifdef X11
 	if (x_initialised == YES) {
-		if(window_created == 1) {
-			XClearArea(display, window.window, text_start_x - window.border_inner_margin - window.border_outer_margin - window.border_width,
-				text_start_y - window.border_inner_margin - window.border_outer_margin - window.border_width,
-				text_width + window.border_inner_margin * 2 + window.border_outer_margin * 2 + window.border_width * 2,
-				text_height + window.border_inner_margin * 2 + window.border_outer_margin * 2 + window.border_width * 2, 0);
-		}
-		destroy_window();
-		free_fonts();
-		if(x11_stuff.region) {
-			XDestroyRegion(x11_stuff.region);
-			x11_stuff.region = NULL;
-		}
-		XCloseDisplay(display);
-		display = NULL;
-		if(info.x11.desktop.all_names) {
-			free(info.x11.desktop.all_names);
-			info.x11.desktop.all_names = NULL;
-		}
-		if (info.x11.desktop.name) {
-			free(info.x11.desktop.name);
-			info.x11.desktop.name = NULL;
-		}
-		x_initialised = NO;
+		clean_up_x11();
 	}else{
 		free(fonts);	//in set_default_configurations a font is set but not loaded
 		font_count = -1;
@@ -4097,6 +4119,12 @@
 	}
 }
 
+void clean_up(void *memtofree1, void* memtofree2)
+{
+	free_update_callbacks();
+	clean_up_without_threads(memtofree1, memtofree2);
+}
+
 static int string_to_bool(const char *s)
 {
 	if (!s) {
@@ -4200,9 +4228,7 @@
 #ifdef IOSTATS
 	top_io = 0;
 #endif
-#ifdef __linux__
 	top_running = 0;
-#endif
 #ifdef MPD
 	mpd_env_host = getenv("MPD_HOST");
 	mpd_env_port = getenv("MPD_PORT");
@@ -4252,6 +4278,9 @@
 	output_methods = TO_STDOUT;
 #endif
 #ifdef X11
+#ifdef BUILD_XFT
+	use_xft = 0;
+#endif
 	show_graph_scale = 0;
 	show_graph_range = 0;
 	draw_shades = 1;
@@ -4282,11 +4311,11 @@
 	text_alignment = BOTTOM_LEFT;
 	info.x11.monitor.number = 1;
 	info.x11.monitor.current = 0;
-	info.x11.desktop.current = 1; 
+	info.x11.desktop.current = 1;
 	info.x11.desktop.number = 1;
 	info.x11.desktop.nitems = 0;
-	info.x11.desktop.all_names = NULL; 
-	info.x11.desktop.name = NULL; 
+	info.x11.desktop.all_names = NULL;
+	info.x11.desktop.name = NULL;
 #endif /* X11 */
 
 	free_templates();
@@ -4518,13 +4547,13 @@
 		int a = string_to_alignment(value);
 
 		if (a <= 0) {
-			if(setbyconffile == true) {
+			if (setbyconffile) {
 				CONF_ERR;
 			} else NORM_ERR("'%s' is not a alignment setting", value);
 		} else {
 			*ltext_alignment = a;
 		}
-	} else if(setbyconffile == true) {
+	} else if (setbyconffile) {
 		CONF_ERR;
 	}
 }
@@ -4552,15 +4581,12 @@
 
 #ifdef X11
 		CONF2("out_to_x") {
-			/* don't listen if X is already initialised or
-			 * if we already know we don't want it */
-			if(x_initialised != YES) {
-				if (string_to_bool(value)) {
-					output_methods &= TO_X;
-				} else {
-					output_methods &= ~TO_X;
-					x_initialised = NEVER;
-				}
+			if (string_to_bool(value)) {
+				output_methods &= TO_X;
+			} else {
+				clean_up_x11();
+				output_methods &= ~TO_X;
+				x_initialised = NEVER;
 			}
 		}
 		CONF("display") {
@@ -4573,7 +4599,7 @@
 			}
 		}
 		CONF("alignment") {
-			setalignment(&text_alignment, window.type, value, f, line, true);
+			setalignment(&text_alignment, window.type, value, f, line, 1);
 		}
 		CONF("background") {
 			fork_to_background = string_to_bool(value);
@@ -4609,7 +4635,7 @@
 		CONF("border_width") {
 			if (value) {
 				window.border_width = strtol(value, 0, 0);
-				if (window.border_width < 0) window.border_width = 0;
+				if (window.border_width < 1) window.border_width = 1;
 			} else {
 				CONF_ERR;
 			}
@@ -5696,7 +5722,7 @@
 				set_first_font(optarg);
 				break;
 			case 'a':
-				setalignment(&text_alignment, window.type, optarg, NULL, 0, false);
+				setalignment(&text_alignment, window.type, optarg, NULL, 0, 0);
 				break;
 
 #ifdef OWN_WINDOW
@@ -5895,7 +5921,9 @@
 				current_config = strndup(optarg, max_user_text);
 				break;
 			case 'q':
-				freopen("/dev/null", "w", stderr);
+				if (!freopen("/dev/null", "w", stderr)) {
+					NORM_ERR("unable to redirect stderr to /dev/null");
+				}
 				break;
 			case 'h':
 				print_help(argv[0]);
@@ -5929,7 +5957,13 @@
 #endif /* XOAP */
 
 #ifdef HAVE_SYS_INOTIFY_H
-	inotify_fd = inotify_init1(IN_NONBLOCK);
+	inotify_fd = inotify_init();
+	if(inotify_fd != -1) {
+		int fl;
+
+		fl = fcntl(inotify_fd, F_GETFL);
+		fcntl(inotify_fd, F_SETFL, fl | O_NONBLOCK);
+	}
 #endif /* HAVE_SYS_INOTIFY_H */
 
 	initialisation(argc, argv);
