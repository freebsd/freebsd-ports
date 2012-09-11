--- FL/Fl_Check_Browser.H.orig	2012-09-11 17:32:07.000000000 +0200
+++ FL/Fl_Check_Browser.H	2012-09-11 17:33:20.000000000 +0200
@@ -97,6 +97,7 @@
     Returns how many lines are in the browser.  The last line number is equal to
     this.
   */
+#undef nitems	// nitems was added as a macro in sys/param.h in r236486
   int nitems() const { return nitems_; }
   /**    Returns how many items are currently checked.  */
   int nchecked() const { return nchecked_; }
