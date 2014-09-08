--- courier/webmlmd.H.orig	2007-12-17 12:09:18 UTC
+++ courier/webmlmd.H
@@ -49,7 +49,7 @@ namespace webmlmd {
 		T t;
 
 		t.reserve(s.size() * 6 / 5);
-		class T::iterator b=s.begin(), e=s.end(), p=b;
+		typename T::iterator b=s.begin(), e=s.end(), p=b;
 
 		while (b != e)
 		{
