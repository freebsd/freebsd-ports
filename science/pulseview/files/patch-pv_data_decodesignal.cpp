--- pv/data/decodesignal.cpp.orig	2020-03-31 23:41:18.000000000 +0300
+++ pv/data/decodesignal.cpp	2024-11-08 15:04:00.844432000 +0200
@@ -251,11 +251,8 @@
 
 void DecodeSignal::resume_decode()
 {
-	// Manual unlocking is done before notifying, to avoid waking up the
-	// waiting thread only to block again (see notify_one for details)
-	decode_pause_mutex_.unlock();
-	decode_pause_cond_.notify_one();
 	decode_paused_ = false;
+	decode_pause_cond_.notify_one();
 }
 
 bool DecodeSignal::is_paused() const
