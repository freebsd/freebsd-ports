--- pan/data/article.cc.orig	Mon Apr 23 16:21:51 2007
+++ pan/data/article.cc	Mon Apr 23 16:23:29 2007
@@ -153,7 +153,8 @@
 
   kc = &key.back();
   mc = &mid.back();
-  ke = key.str + 1 + std::max (int(b), (int)minlen - UCHAR_MAX);
+  ke = std::max (key.str + b + 1,
+                 key.str + key.len - UCHAR_MAX);
   while (kc>ke)
     if (*kc-- != *mc--) { ++kc; break; }
   const size_t e (&key.back() - kc);
