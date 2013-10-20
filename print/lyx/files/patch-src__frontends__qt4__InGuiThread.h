From 2b0a7a5e01c71bd0c809844e0c6779f43870077b Mon Sep 17 00:00:00 2001
From: Vincent van Ravesteijn <vfr@lyx.org>
Date: Mon, 8 Oct 2012 21:28:55 +0200
Subject: [PATCH] Disambiguate std::bind, boost::bind, std::ref, boost::ref

This fixes compilation with MSVC2012.
---
 src/frontends/qt4/InGuiThread.h | 22 ++++++++++++----------
 1 file changed, 12 insertions(+), 10 deletions(-)

diff --git a/src/frontends/qt4/InGuiThread.h b/src/frontends/qt4/InGuiThread.h
index ea5d64b..0609cb0 100644
--- src/frontends/qt4/InGuiThread.h
+++ src/frontends/qt4/InGuiThread.h
@@ -69,25 +69,25 @@ public:
 	template<class F, class P1>
 	R call(F f, P1& p1)
 	{
-		return call(bind(f, ref(p1)));
+		return call(lyx::bind(f, lyx::ref(p1)));
 	}
 
 	template<class F, class P1, class P2>
 	R call(F f, P1& p1, P2& p2)
 	{
-		return call(bind(f, ref(p1), ref(p2)));
+		return call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2)));
 	}
 
 	template<class F, class P1, class P2, class P3>
 	R call(F f, P1& p1, P2& p2, P3& p3)
 	{
-		return call(bind(f, ref(p1), ref(p2), ref(p3)));
+		return call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2), lyx::ref(p3)));
 	}
 
 	template<class F, class P1, class P2, class P3, class P4>
 	R call(F f, P1& p1, P2& p2, P3& p3, P4& p4)
 	{
-		return call(bind(f, ref(p1), ref(p2), ref(p3), ref(p4)));
+		return call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2), lyx::ref(p3), lyx::ref(p4)));
 	}
 
 	/*
@@ -97,7 +97,8 @@ public:
 	template<class F, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8>
 	R call(F f, P1& p1, P2& p2, P3& p3, P4& p4, P5& p5, P6& p6, P7& p7, P8& p8)
 	{
-		return call(bind(f, ref(p1), ref(p2), ref(p3), ref(p4), ref(p5), ref(p6), ref(p7), ref(p8)));
+		return call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2), lyx::ref(p3), lyx::ref(p4), 
+			lyx::ref(p5), lyx::ref(p6), lyx::ref(p7), lyx::ref(p8)));
 	}
 
 private:
@@ -131,25 +132,25 @@ public:
 	template<class F, class P1>
 	void call(F f, P1& p1)
 	{
-		call(bind(f, ref(p1)));
+		call(lyx::bind(f, lyx::ref(p1)));
 	}
 
 	template<class F, class P1, class P2>
 	void call(F f, P1& p1, P2& p2)
 	{
-		call(bind(f, ref(p1), ref(p2)));
+		call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2)));
 	}
 
 	template<class F, class P1, class P2, class P3>
 	void call(F f, P1& p1, P2& p2, P3& p3)
 	{
-		call(bind(f, ref(p1), ref(p2), ref(p3)));
+		call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2), lyx::ref(p3)));
 	}
 
 	template<class F, class P1, class P2, class P3, class P4>
 	void call(F f, P1& p1, P2& p2, P3& p3, P4& p4)
 	{
-		call(bind(f, ref(p1), ref(p2), ref(p3), ref(p4)));
+		call(lyx::bind(f, lyx::ref(p1), lyx::ref(p2), lyx::ref(p3), lyx::ref(p4)));
 	}
 
 	/*
@@ -159,7 +160,8 @@ public:
 	template<class F, class P1, class P2, class P3, class P4, class P5, class P6, class P7, class P8>
 	void call(F f, P1& p1, P2& p2, P3& p3, P4& p4, P5& p5, P6& p6, P7& p7, P8& p8)
 	{
-		call(bind(f, ref(p1), ref(p2), ref(p3), ref(p4), ref(p5), ref(p6), ref(p7), ref(p8)));
+		call(bind(f, lyx::ref(p1), lyx::ref(p2), lyx::ref(p3), lyx::ref(p4), lyx::ref(p5),
+			lyx::ref(p6), lyx::ref(p7), lyx::ref(p8)));
 	}
 
 private:
-- 
1.8.4.1

