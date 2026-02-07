--- libraries/libmbwrap/wraptest.cc.orig	2020-02-17 19:20:23 UTC
+++ libraries/libmbwrap/wraptest.cc
@@ -321,9 +321,7 @@ static inline unsigned long long rd_CPU_ts(void)
 		"\tbne     0b         \n"
 		: "=r"(upper),"=r"(lower),"=r"(tmp)
 	);
-	time = upper;
-	time = result << 32;
-	time = result|lower;
+	time = (upper << 32) | lower;
 #endif
 	return time;
 }
