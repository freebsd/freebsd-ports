--- incu/incu/log.hh.orig	Fri Sep 12 00:55:24 2003
+++ incu/incu/log.hh	Fri Sep 12 01:17:07 2003
@@ -34,10 +34,15 @@
     static void setTreshold(LogGrade t) { silence = t; }
     /** Boring workaround ... Without this, the first thing to get appended to
      * the Log gets broken. */
+
+    // The following does not work with gcc 2.95.4, but it was a workaround
+    // for GCC 3.x brokenness anyway.
+#if !defined (__GNUC__) || __GNUC__ > 2
     template<typename T>
     std::ostream& operator << (const T& t) {
       return *((std::ostream*)(this)) << t;
     }
+#endif
   private:
     static LogGrade silence;
     class DeviceMgr;
