--- dockapp.c.orig	2003-03-22 18:30:01 UTC
+++ dockapp.c
@@ -41,7 +41,7 @@
 #define WINDOW_HEIGHT 64
 
 Display *display;
-int      screen;
+int      screen, x11fd;
 Window   iconwindow, window, mapwindow;
 Colormap colormap;
 GC       gc;
@@ -114,6 +114,7 @@ void make_window()
   fprintf(stderr, "Could not open display %s\n", opt_display);
   exit(1);
  }
+ x11fd = ConnectionNumber(display);
  screen = DefaultScreen(display);
  screenwidth = DisplayWidth(display, screen);
  screenheight = DisplayHeight(display, screen);
@@ -254,6 +255,19 @@ void process_events()
  XEvent event;
  int winx, winy;
 
+ XSync(display, False);
+ if(!XPending(display))
+ {
+  struct timeval timeout;
+  fd_set readset;
+  const int milliseconds = 200;
+  timeout.tv_sec = milliseconds / 1000;
+  timeout.tv_usec = (milliseconds % 1000) * 1000;
+  FD_ZERO(&readset);
+  FD_SET(x11fd, &readset);
+  if(select(x11fd + 1, &readset, NULL, NULL, &timeout) <= 0)
+   return;
+ }
  XNextEvent(display, &event);
  switch(event.type)
  {
