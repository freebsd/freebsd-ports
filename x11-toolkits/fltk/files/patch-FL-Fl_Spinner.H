--- FL/Fl_Spinner.H.orig	Sun Jan 14 12:57:46 2007
+++ FL/Fl_Spinner.H	Sun Jan 14 12:58:41 2007
@@ -127,9 +127,9 @@
 
   const char	*format() { return (format_); }
   void		format(const char *f) { format_ = f; update(); }
-  double	maxinum() const { return (maximum_); }
+  double	maximum() const { return (maximum_); }
   void		maximum(double m) { maximum_ = m; }
-  double	mininum() const { return (minimum_); }
+  double	minimum() const { return (minimum_); }
   void		minimum(double m) { minimum_ = m; }
   void		range(double a, double b) { minimum_ = a; maximum_ = b; }
   void		resize(int X, int Y, int W, int H) {
