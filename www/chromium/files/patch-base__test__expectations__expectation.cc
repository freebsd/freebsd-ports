--- base/test/expectations/expectation.cc.orig	2013-08-31 23:17:45.000000000 +0300
+++ base/test/expectations/expectation.cc	2013-08-31 23:18:59.000000000 +0300
@@ -58,6 +58,7 @@
         variant != "64") {
       return false;
     }
+  } else if (name == "FreeBSD") {
   } else if (name == "ChromeOS") {
     // TODO(rsesek): Figure out what ChromeOS needs.
   } else if (name == "iOS") {
@@ -119,6 +120,8 @@
     platform.variant = "32";
   else if (arch == "x86_64")
     platform.variant = "64";
+#elif defined(OS_FREEBSD)
+  platform.name = "FreeBSD";
 #else
   NOTREACHED();
 #endif
