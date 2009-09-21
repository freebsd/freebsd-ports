The ST_SAMPLE_TO_SIGNED_WORD macro in sox 14.3.0 uses a temporary variable
that it doesn't declare itself, and requires you to declare it yourself with
an undocumented macro.

--- src/modules/sox/filter_sox.c	2009-06-30 17:24:23.000000000 -0500
+++ src/modules/sox/filter_sox.c	2009-09-20 19:30:21.230804810 -0500
@@ -49,6 +49,7 @@
 #		define ST_SSIZE_MIN SOX_SSIZE_MIN
 #	endif
 #		define ST_SAMPLE_TO_SIGNED_WORD(d,clips) SOX_SAMPLE_TO_SIGNED_16BIT(d,clips)
+	SOX_SAMPLE_LOCALS;
 #else
 #	include <st.h>
 #endif
