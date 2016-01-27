--- surf.c.orig	2015-12-19 14:59:30 UTC
+++ surf.c
@@ -6,6 +6,9 @@
 #include <X11/X.h>
 #include <X11/Xatom.h>
 #include <gtk/gtk.h>
+#if GTK_MAJOR_VERSION >= 3
+#include <gtk/gtkx.h>
+#endif
 #include <gdk/gdkx.h>
 #include <gdk/gdk.h>
 #include <gdk/gdkkeysyms.h>
@@ -99,7 +102,11 @@ typedef struct {
 static Display *dpy;
 static Atom atoms[AtomLast];
 static Client *clients = NULL;
+#if GTK_MAJOR_VERSION >= 3
+static Window embed = 0;
+#else
 static GdkNativeWindow embed = 0;
+#endif
 static gboolean showxid = FALSE;
 static char winid[64];
 static gboolean usingproxy = 0;
@@ -213,6 +220,10 @@ static void windowobjectcleared(GtkWidge
                                 JSContextRef js, JSObjectRef win, Client *c);
 static void zoom(Client *c, const Arg *arg);
 
+#ifdef BUILTIN_DOWNLOAD
+static void download(WebKitDownload *o, GParamSpec *pspec, Client *c);
+#endif
+
 /* configuration, allows nested code to access above variables */
 #include "config.h"
 
@@ -451,6 +462,52 @@ cookiepolicy_set(const SoupCookieJarAcce
 	return 'A';
 }
 
+#ifdef BUILTIN_DOWNLOAD
+struct client_size_tuple {
+	Client* c;
+	gint s;
+};
+
+static void
+late_download_update(WebKitWebView* view, GParamSpec *pspec, struct client_size_tuple* t){
+	char script[1024]; char* s= script;
+	snprintf(script, 1024, "c(%d, %d)", t->s, t->s);
+	const Arg a= {.v = (void*) &s};
+	eval(t->c, &a);
+	free(t);
+}
+
+static void
+download(WebKitDownload *o, GParamSpec *pspec, Client *c) {
+	WebKitDownloadStatus status;
+	char script[2048]; char* s= script;
+
+	status = webkit_download_get_status(o);
+	if(status == WEBKIT_DOWNLOAD_STATUS_STARTED || status == WEBKIT_DOWNLOAD_STATUS_CREATED) {
+		snprintf(script, 2048, "u(%d, %d, %d)",
+			(gint)webkit_download_get_current_size(o),
+			(gint)webkit_download_get_total_size(o),
+			(gint)(webkit_download_get_progress(o) * 100));
+		const Arg a= {.v = (void*) &s};
+		eval(c, &a);
+	}
+	else if (status == WEBKIT_DOWNLOAD_STATUS_FINISHED){
+		if( webkit_web_view_get_load_status(c->view) == WEBKIT_LOAD_FINISHED ){
+			snprintf(script, 2048, "c(%d, %d)",
+				(gint)webkit_download_get_current_size(o),
+				(gint)webkit_download_get_total_size(o));
+			const Arg a= {.v = (void*) &s};
+			eval(c, &a);
+		}
+		else {
+			struct client_size_tuple* t= calloc(1, sizeof(struct client_size_tuple));
+			t->c= c; t->s= (gint)webkit_download_get_current_size(o);
+			g_signal_connect(c->view, "document-load-finished", G_CALLBACK(late_download_update), t);
+		}
+	}
+}
+#endif
+
 void
 evalscript(JSContextRef js, char *script, char* scriptname)
 {
@@ -625,7 +682,11 @@ getatom(Client *c, int a)
 	unsigned long ldummy;
 	unsigned char *p = NULL;
 
+#if GTK_MAJOR_VERSION >= 3
+	XGetWindowProperty(dpy, GDK_WINDOW_XID(gtk_widget_get_window(GTK_WIDGET(c->win))),
+#else
 	XGetWindowProperty(dpy, GDK_WINDOW_XID(GTK_WIDGET(c->win)->window),
+#endif
 	                   atoms[a], 0L, BUFSIZ, False, XA_STRING,
 	                   &adummy, &idummy, &ldummy, &ldummy, &p);
 	if (p)
@@ -685,12 +746,114 @@ handleplumb(Client *c, WebKitWebView *w,
 gboolean
 initdownload(WebKitWebView *view, WebKitDownload *o, Client *c)
 {
+#ifdef BUILTIN_DOWNLOAD
+	gchar *uri, *path;
+	const gchar *filename;
+	Client *n;
+	const char template[] =
+"<html>" \
+"<head>" \
+"<title>Download - %s</title>" \
+"<script>" \
+"function formText(x){" \
+"  if(x >= 1073741824)  { return (Math.floor(x/10737418.24)/100) + \"G\"; }" \
+"  else if(x >= 1048576){ return (Math.floor(x/10485.76)/100) + \"M\"; }" \
+"  else if(x >= 1024)   { return (Math.floor(x/10.24)/100) + \"k\"; }" \
+"  else                 { return x+\"b\"; }" \
+"}" \
+"function updateText(c,t){" \
+"  txt= formText(c) + \"/\" + formText(t);" \
+"  DLTEXT.textContent= txt;" \
+"  /* center text in bar */" \
+"  DLTEXT.setAttribute('x', 102-4.4*txt.length)" \
+"}" \
+"function c(c, t){" \
+"  DLGRAD.setAttribute('x2', 230);" \
+"  DLGRAD.setAttribute('x1', 205);" \
+"  updateText(c,t);" \
+"  document.getElementById('stop1').setAttribute('style', \"stop-color:#2020ff;\");" \
+"}" \
+"function u(c,t,p){" \
+"  DLGRAD.setAttribute('x2', Math.floor(p*205/100) + 25);" \
+"  DLGRAD.setAttribute('x1', Math.floor(p*205/100));" \
+"  updateText(c,t);" \
+"}" \
+"</script>" \
+"</head>" \
+"<body>" \
+"<center>" \
+"<h2>Downloading</h2>" \
+"<h3>%s</h3>" \
+"to %s<br/>" \
+"<svg" \
+"   xmlns:cc=\"http://creativecommons.org/ns#\"" \
+"   xmlns:svg=\"http://www.w3.org/2000/svg\"" \
+"   xmlns=\"http://www.w3.org/2000/svg\"" \
+"   xmlns:xlink=\"http://www.w3.org/1999/xlink\"" \
+"   width=\"210\"" \
+"   height=\"60\"" \
+"   id=\"download\">" \
+"  <defs>" \
+"    <linearGradient" \
+"       id=\"dlgradient\"" \
+"       x1=\"0\"" \
+"       y1=\"0\"" \
+"       x2=\"25\"" \
+"       y2=\"0\"" \
+"       gradientUnits=\"userSpaceOnUse\">" \
+"      <stop style=\"stop-color:#00ff00;\" offset=\"0\" id=\"stop1\" />" \
+"      <stop style=\"stop-color:#00ff00;stop-opacity:0;\" offset=\"1\" id=\"stop2\" />" \
+"    </linearGradient>" \
+"  </defs>" \
+"    <rect" \
+"       style=\"fill:url(#dlgradient);stroke:#000000;stroke-width:3\"" \
+"       id=\"rect2985\"" \
+"       width=\"200\"" \
+"       height=\"50\"" \
+"       x=\"5\"" \
+"       y=\"5\"" \
+"       ry=\"25\" />" \
+"    <text id=\"dltext\" x=\"92\" y=\"35\">0/0</text>" \
+"</svg>" \
+"</center>" \
+"<script>" \
+"DLGRAD= document.getElementById('dlgradient');" \
+"DLTEXT= document.getElementById('dltext');" \
+"</script>" \
+"</body>" \
+"</html>";
+	char html[sizeof(template)+2048];
+	filename = webkit_download_get_suggested_filename(o);
+
+	path = g_build_filename(downdir, filename, NULL);
+	uri = g_filename_to_uri(path, NULL, NULL);
+
+	webkit_download_set_destination_uri(o, uri);
+	webkit_download_start(o);
+
+	n = newclient();
+	snprintf(html, sizeof(template)+2048, template, filename, filename, path);
+	webkit_web_view_load_string(n->view, html, NULL, NULL, NULL);
+
+	g_signal_connect(o, "notify::progress", G_CALLBACK(download), n);
+	g_signal_connect(o, "notify::status", G_CALLBACK(download), n);
+
+	n->title = g_strdup_printf("Downloading %s", filename);
+	n->progress = 0;
+	updatetitle(n);
+
+	g_free(path);
+	g_free(uri);
+ 
+	return TRUE;
+#else
 	Arg arg;
 
 	updatewinid(c);
 	arg = (Arg)DOWNLOAD((char *)webkit_download_get_uri(o), geturi(c));
 	spawn(c, &arg);
 	return FALSE;
+#endif
 }
 
 void
@@ -873,6 +1036,9 @@ newclient(void)
 	GdkScreen *screen;
 	gdouble dpi;
 	char *ua;
+#if GTK_MAJOR_VERSION >= 3
+	GdkWindow *window;
+#endif
 
 	if (!(c = calloc(1, sizeof(Client))))
 		die("Cannot malloc!\n");
@@ -900,6 +1066,10 @@ newclient(void)
 		 */
 		gtk_window_set_role(GTK_WINDOW(c->win), "Surf");
 	}
+#if GTK_MAJOR_VERSION >= 3
+	gtk_widget_realize(GTK_WIDGET(c->win));
+	window = gtk_widget_get_window(GTK_WIDGET(c->win));
+#endif
 	gtk_window_set_default_size(GTK_WINDOW(c->win), 800, 600);
 	g_signal_connect(G_OBJECT(c->win),
 	                 "destroy",
@@ -912,10 +1082,18 @@ newclient(void)
 		addaccelgroup(c);
 
 	/* Pane */
+#if GTK_MAJOR_VERSION >= 3
+	c->pane = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
+#else
 	c->pane = gtk_vpaned_new();
+#endif
 
 	/* VBox */
+#if GTK_MAJOR_VERSION >= 3
+	c->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
+#else
 	c->vbox = gtk_vbox_new(FALSE, 0);
+#endif
 	gtk_paned_pack1(GTK_PANED(c->pane), c->vbox, TRUE, TRUE);
 
 	/* Webview */
@@ -997,8 +1175,13 @@ newclient(void)
 	gtk_widget_show(c->win);
 	gtk_window_set_geometry_hints(GTK_WINDOW(c->win), NULL, &hints,
 	                              GDK_HINT_MIN_SIZE);
+#if GTK_MAJOR_VERSION >= 3
+	gdk_window_set_events(window, GDK_ALL_EVENTS_MASK);
+	gdk_window_add_filter(window, processx, c);
+#else
 	gdk_window_set_events(GTK_WIDGET(c->win)->window, GDK_ALL_EVENTS_MASK);
 	gdk_window_add_filter(GTK_WIDGET(c->win)->window, processx, c);
+#endif
 	webkit_web_view_set_full_content_zoom(c->view, TRUE);
 
 	runscript(frame);
@@ -1032,7 +1215,11 @@ newclient(void)
 	 * It is equivalent to firefox's "layout.css.devPixelsPerPx" setting.
 	 */
 	if (zoomto96dpi) {
+#if GTK_MAJOR_VERSION >= 3
+		screen = gdk_window_get_screen(window);
+#else
 		screen = gdk_window_get_screen(GTK_WIDGET(c->win)->window);
+#endif
 		dpi = gdk_screen_get_resolution(screen);
 		if (dpi != -1) {
 			g_object_set(G_OBJECT(settings),
@@ -1071,7 +1258,11 @@ newclient(void)
 	if (showxid) {
 		gdk_display_sync(gtk_widget_get_display(c->win));
 		printf("%u\n",
+#if GTK_MAJOR_VERSION >= 3
+		       (guint)GDK_WINDOW_XID(window));
+#else
 		       (guint)GDK_WINDOW_XID(GTK_WIDGET(c->win)->window));
+#endif
 		fflush(NULL);
                 if (fclose(stdout) != 0) {
 			die("Error closing stdout");
@@ -1282,7 +1473,11 @@ void
 setatom(Client *c, int a, const char *v)
 {
 	XSync(dpy, False);
+#if GTK_MAJOR_VERSION >= 3
+	XChangeProperty(dpy, GDK_WINDOW_XID(gtk_widget_get_window(GTK_WIDGET(c->win))),
+#else
 	XChangeProperty(dpy, GDK_WINDOW_XID(GTK_WIDGET(c->win)->window),
+#endif
 	                atoms[a], XA_STRING, 8, PropModeReplace,
 	                (unsigned char *)v, strlen(v) + 1);
 }
@@ -1301,7 +1496,11 @@ setup(void)
 	sigchld(0);
 	gtk_init(NULL, NULL);
 
+#if GTK_MAJOR_VERSION >= 3
+	dpy = GDK_DISPLAY_XDISPLAY(gdk_display_get_default());
+#else
 	dpy = GDK_DISPLAY();
+#endif
 
 	/* atoms */
 	atoms[AtomFind] = XInternAtom(dpy, "_SURF_FIND", False);
@@ -1624,7 +1823,11 @@ void
 updatewinid(Client *c)
 {
 	snprintf(winid, LENGTH(winid), "%u",
+#if GTK_MAJOR_VERSION >= 3
+	         (int)GDK_WINDOW_XID(gtk_widget_get_window(GTK_WIDGET(c->win))));
+#else
 	         (int)GDK_WINDOW_XID(GTK_WIDGET(c->win)->window));
+#endif
 }
 
 void
