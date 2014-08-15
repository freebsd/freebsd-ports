--- ./base/test/expectations/expectation.cc.orig	2014-08-12 21:01:28.000000000 +0200
+++ ./base/test/expectations/expectation.cc	2014-08-13 09:56:56.000000000 +0200
@@ -60,6 +60,7 @@
         variant != "64") {
       return false;
     }
+  } else if (name == "FreeBSD") {
   } else if (name == "ChromeOS") {
     // TODO(rsesek): Figure out what ChromeOS needs.
   } else if (name == "iOS") {
@@ -125,6 +126,8 @@
     platform.variant = "32";
   else if (arch == "x86_64")
     platform.variant = "64";
+#elif defined(OS_FREEBSD)
+  platform.name = "FreeBSD";
 #else
   NOTREACHED();
 #endif
