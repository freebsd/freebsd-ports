--- ./base/test/expectations/expectation.cc.orig	2014-04-30 22:41:42.000000000 +0200
+++ ./base/test/expectations/expectation.cc	2014-05-04 14:38:46.000000000 +0200
@@ -59,6 +59,7 @@
         variant != "64") {
       return false;
     }
+  } else if (name == "FreeBSD") {
   } else if (name == "ChromeOS") {
     // TODO(rsesek): Figure out what ChromeOS needs.
   } else if (name == "iOS") {
@@ -122,6 +123,8 @@
     platform.variant = "32";
   else if (arch == "x86_64")
     platform.variant = "64";
+#elif defined(OS_FREEBSD)
+  platform.name = "FreeBSD";
 #else
   NOTREACHED();
 #endif
