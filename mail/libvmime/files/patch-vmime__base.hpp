--- ./vmime/base.hpp.orig	2010-02-06 10:12:57.000000000 -0800
+++ ./vmime/base.hpp	2013-09-05 17:05:39.233608129 -0700
@@ -252,7 +252,7 @@
 	template <class X, class Y>
 	ref <X> dynamicCast(ref <Y> y)
 	{
-		return y.dynamicCast <X>();
+		return y. template dynamicCast <X>();
 	}
 
 } // vmime
