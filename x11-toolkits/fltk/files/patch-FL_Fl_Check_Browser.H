--- FL/Fl_Check_Browser.H.orig	2012-11-07 18:19:01.000000000 +0100
+++ FL/Fl_Check_Browser.H	2012-11-07 18:19:16.000000000 +0100
@@ -88,6 +88,7 @@
     Returns how many lines are in the browser.  The last line number is equal to
     this.
   */
+#undef nitems // nitems was added as a macro in sys/param.h in r236486
   int nitems() const { return nitems_; }
   /**    Returns how many items are currently checked.  */
   int nchecked() const { return nchecked_; }
