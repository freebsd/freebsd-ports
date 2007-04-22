--- pan/data/article.cc.orig	Sun Apr 22 15:17:04 2007
+++ pan/data/article.cc	Sun Apr 22 15:17:44 2007
@@ -153,7 +153,7 @@
 
   kc = &key.back();
   mc = &mid.back();
-  ke = key.str + 1 + std::max (int(b), (int)minlen - UCHAR_MAX);
+  ke = key.str + 1 + std::max ((char)b, (char)(minlen - UCHAR_MAX));
   while (kc>ke)
     if (*kc-- != *mc--) { ++kc; break; }
   const size_t e (&key.back() - kc);
