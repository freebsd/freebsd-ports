--- config.def.h.orig	2015-12-19 14:59:30 UTC
+++ config.def.h
@@ -22,6 +22,10 @@ static char *cafile         = "/etc/ssl/
 static Bool strictssl       = FALSE; /* Refuse untrusted SSL connections */
 static time_t sessiontime   = 3600;
 
+#ifdef BUILTIN_DOWNLOAD
+static char *downdir        = "/tmp";
+#endif
+
 /* Webkit default features */
 static Bool enablescrollbars      = TRUE;
 static Bool enablespatialbrowsing = TRUE;
@@ -84,6 +88,51 @@ static SiteStyle styles[] = {
  */
 static Key keys[] = {
 	/* modifier             keyval      function    arg             Focus */
+#if GTK_MAJOR_VERSION >= 3
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_r,      reload,     { .b = TRUE } },
+	{ MODKEY,               GDK_KEY_r,      reload,     { .b = FALSE } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_p,      print,      { 0 } },
+
+	{ MODKEY,               GDK_KEY_p,      clipboard,  { .b = TRUE } },
+	{ MODKEY,               GDK_KEY_y,      clipboard,  { .b = FALSE } },
+
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_j,      zoom,       { .i = -1 } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_k,      zoom,       { .i = +1 } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_q,      zoom,       { .i = 0  } },
+	{ MODKEY,               GDK_KEY_minus,  zoom,       { .i = -1 } },
+	{ MODKEY,               GDK_KEY_plus,   zoom,       { .i = +1 } },
+
+	{ MODKEY,               GDK_KEY_l,      navigate,   { .i = +1 } },
+	{ MODKEY,               GDK_KEY_h,      navigate,   { .i = -1 } },
+
+	{ MODKEY,               GDK_KEY_j,      scroll_v,   { .i = +1 } },
+	{ MODKEY,               GDK_KEY_k,      scroll_v,   { .i = -1 } },
+	{ MODKEY,               GDK_KEY_b,      scroll_v,   { .i = -10000 } },
+	{ MODKEY,               GDK_KEY_space,  scroll_v,   { .i = +10000 } },
+	{ MODKEY,               GDK_KEY_i,      scroll_h,   { .i = +1 } },
+	{ MODKEY,               GDK_KEY_u,      scroll_h,   { .i = -1 } },
+
+	{ 0,                    GDK_KEY_F11,    fullscreen, { 0 } },
+	{ 0,                    GDK_KEY_Escape, stop,       { 0 } },
+	{ MODKEY,               GDK_KEY_o,      source,     { 0 } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_o,      inspector,  { 0 } },
+
+	{ MODKEY,               GDK_KEY_g,      spawn,      SETPROP("_SURF_URI", "_SURF_GO") },
+	{ MODKEY,               GDK_KEY_f,      spawn,      SETPROP("_SURF_FIND", "_SURF_FIND") },
+	{ MODKEY,               GDK_KEY_slash,  spawn,      SETPROP("_SURF_FIND", "_SURF_FIND") },
+
+	{ MODKEY,               GDK_KEY_n,      find,       { .b = TRUE } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_n,      find,       { .b = FALSE } },
+
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_c,      toggle,     { .v = "enable-caret-browsing" } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_i,      toggle,     { .v = "auto-load-images" } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_s,      toggle,     { .v = "enable-scripts" } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_v,      toggle,     { .v = "enable-plugins" } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_a,      togglecookiepolicy, { 0 } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_m,      togglestyle, { 0 } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_b,      togglescrollbars, { 0 } },
+	{ MODKEY|GDK_SHIFT_MASK,GDK_KEY_g,      togglegeolocation, { 0 } },
+#else
 	{ MODKEY|GDK_SHIFT_MASK,GDK_r,      reload,     { .b = TRUE } },
 	{ MODKEY,               GDK_r,      reload,     { .b = FALSE } },
 	{ MODKEY|GDK_SHIFT_MASK,GDK_p,      print,      { 0 } },
@@ -127,6 +176,7 @@ static Key keys[] = {
 	{ MODKEY|GDK_SHIFT_MASK,GDK_m,      togglestyle, { 0 } },
 	{ MODKEY|GDK_SHIFT_MASK,GDK_b,      togglescrollbars, { 0 } },
 	{ MODKEY|GDK_SHIFT_MASK,GDK_g,      togglegeolocation, { 0 } },
+#endif
 };
 
 /* button definitions */
