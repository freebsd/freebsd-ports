--- medfilt1.cc.orig	2018-05-07 14:01:24 UTC
+++ medfilt1.cc
@@ -37,7 +37,7 @@ Created: 2015-12-13
 #include "ov.h"
 
 enum nan_handling { include_nan, omit_nan };
-enum pad_type { zero_pad, truncate };
+enum pad_type { zero_pad, truncate2 };
 
 // Keep a sorted sliding window of values.
 // There is no error checking, to keep things fast.
@@ -323,7 +323,7 @@ to bring them up to size @var{n}.\n\
       if (! strcasecmp (s.c_str (), "omitnan"))
         nan_flag = omit_nan;
       else if (! strcasecmp (s.c_str (), "truncate"))
-        padding = truncate;
+        padding = truncate2;
       else if (strcasecmp (s.c_str (), "includenan")
                && strcasecmp (s.c_str (), "zeropad"))  // the defaults
         error ("medfilt1: Invalid NAN_FLAG or PADDING value '%s'", s.c_str ());
