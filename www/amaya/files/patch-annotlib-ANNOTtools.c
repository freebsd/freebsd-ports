--- ../annotlib/ANNOTtools.c.orig	2008-02-05 02:44:09.000000000 +0000
+++ ../annotlib/ANNOTtools.c	2008-02-05 02:44:37.000000000 +0000
@@ -2275,7 +2275,7 @@
 #ifdef _WINGUI
   UTCoffset = _timezone;	/* global, set by localtime() */
 #else
-  UTCoffset = (int)timezone;		/* global, set by localtime() */
+  UTCoffset = (long)timezone;		/* global, set by localtime() */
 #endif /* _WINGUI */
 
   UTChourOffset = UTCminOffset = abs(UTCoffset)/60; /* UTCoffset is seconds */
@@ -2378,7 +2378,7 @@
 #ifdef _WINGUI
       UTCoffset = _timezone;	/* global, set by localtime() */
 #else
-      UTCoffset = (int)timezone;	/* global, set by localtime() */
+      UTCoffset = (long)timezone;	/* global, set by localtime() */
 #endif /* _WINGUI */
 
       cal_date -= UTCoffset;
