--- output.cc.orig	Fri Dec  8 04:01:19 2006
+++ output.cc		Mon Dec 18 15:50:13 2006
@@ -742,8 +742,8 @@
   case LOG_MACHINE:
   case LOG_SKID:
   case LOG_XML:
-#ifdef WIN32
-	  apcopy = ap;
+#if defined(WIN32) || (defined(FREEBSD) && (OSVERSION < 500000))
+    apcopy = ap;
 #else
     va_copy(apcopy, ap); /* Needed in case we need to so a second vnsprintf */
 #endif
