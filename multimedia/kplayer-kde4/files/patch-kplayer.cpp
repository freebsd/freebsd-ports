--- kplayer/kplayer.cpp~	Wed Mar 26 12:14:07 2003
+++ kplayer/kplayer.cpp	Fri Apr 11 09:35:05 2003
@@ -824,6 +824,15 @@
   kPlayerProcess() -> stop();
 }
 
+#ifdef __FreeBSD__
+int roundf(double number)
+{
+  if (number > 0.0)
+    return (int)(number + 0.5);
+  return (int)(number -0.5);
+}
+#endif
+
 void KPlayer::onPlayerForward (void)
 {
   int seek = kPlayerProcess() -> length() == 0 ? 10 :
