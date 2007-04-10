--- src/blob.cc.orig	Wed Apr 11 01:47:27 2007
+++ src/blob.cc	Wed Apr 11 01:48:10 2007
@@ -503,7 +503,7 @@
 blob::print()
 {
 	ENTRY_TRACE(__FILE__,__LINE__);
-	cout << O_("blob: ") << (unsigned)this << O_(" x=") << x_ << O_(" step=") << x_step_ << O_(" num=") << num_ << O_(":");
+	cout << O_("blob: ") << (uintptr_t)this << O_(" x=") << x_ << O_(" step=") << x_step_ << O_(" num=") << num_ << O_(":");
 	for (int i = 0; i < num_; i++) {
 		cout << O_(" ") << y_lows_[i] << O_("-") << y_highs_[i];
 	};
