Rename encrypt to encrypt_pixmap to avoid namespace conflict with
unistd.h encrypt() on FreeBSD 10.4

--- fltk/pinwindow.cxx.orig	2018-01-15 23:08:38 UTC
+++ fltk/pinwindow.cxx
@@ -46,7 +46,7 @@ const char *PinWindow::PROMPT		= "Passph
 
 static const char *timeout_format = "%s(%d)";
 
-static Fl_Pixmap encrypt(encrypt_xpm);
+static Fl_Pixmap encrypt_pixmap(encrypt_xpm);
 static Fl_Pixmap icon(icon_xpm);
 
 PinWindow::PinWindow() : window_(NULL)
@@ -147,7 +147,7 @@ int PinWindow::init(const int cx, const 
 	window_->icon(&app);
 
 	icon_ = new Fl_Box(10, 10, 64, 64);
-	icon_->image(encrypt);
+	icon_->image(encrypt_pixmap);
 
     message_ = new Fl_Box(79, 5, cx-99, 44, PROMPT);
 	message_->align(Fl_Align(FL_ALIGN_LEFT_TOP | FL_ALIGN_WRAP | FL_ALIGN_INSIDE)); // left
