--- mozilla/MozillaPrivate.cpp.orig	Sun Oct 24 15:14:57 2004
+++ mozilla/MozillaPrivate.cpp	Sun Oct 24 15:17:17 2004
@@ -109,6 +109,7 @@
 		tmp = paperPrefix + NS_LITERAL_CSTRING("width_mm");
 		rv = pref->GetIntPref(tmp.get(), &width);
 
+#if defined(_NL_PAPER_HEIGHT) && defined(_NL_PAPER_WIDTH)
 		// mark locale default paper size so that print dialog can use
 		// it as best guess when switching printers
 		if (height == (int) (long int) nl_langinfo (_NL_PAPER_HEIGHT) &&
@@ -116,6 +117,7 @@
 		{
 			info->paper = i;
 		}
+#endif
 
 		PRBool is_inch;
 		tmp = paperPrefix + NS_LITERAL_CSTRING("is_inch");
