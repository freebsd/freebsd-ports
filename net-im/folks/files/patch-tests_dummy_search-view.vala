From 8e7b403fd1ee413c0b9c62d3835010ba95c71f5e Mon Sep 17 00:00:00 2001
From: Philip Withnall <philip.withnall@collabora.co.uk>
Date: Tue, 17 Feb 2015 09:18:53 +0000
Subject: =?UTF-8?q?tests:=20Fix=20UTF-8=20encoding=20of=20the=20letter=20?=
 =?UTF-8?q?=C3=A9nye=20in=20test=20vectors?=
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

https://bugzilla.gnome.org/show_bug.cgi?id=646808

diff --git a/tests/dummy/search-view.vala b/tests/dummy/search-view.vala
index fb10153..44f3a9b 100644
--- tests/dummy/search-view.vala
+++ tests/dummy/search-view.vala
@@ -78,8 +78,8 @@ public class SearchViewTests : DummyTest.TestCase
           { "Ál", "persona3" },
           /* Test different Unicode normalisations and transliterations. */
           { "Pan", "persona3" },
-          { "Pa\xf1", "persona3" },
-          { "Pa\x6e\x303", "persona3" },
+          { "Pa\xc3\xb1", "persona3" },
+          { "Pa\x6e\xcc\x83", "persona3" },
           /* Sort stability. */
           { "A", "persona1,persona2,persona0,persona3" },
           { "Al", "persona1,persona3" },
-- 
cgit v0.10.2

