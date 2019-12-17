From dba110e8ad255f7327d9f70cd7565917a303df12 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Sebastian=20Dr=C3=B6ge?= <sebastian@centricular.com>
Date: Wed, 8 Aug 2018 09:16:18 +0200
Subject: [PATCH] Fix build with two-phase-borrows/NLL

---
 gstreamer/src/iterator.rs | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

--- cargo-crates/gstreamer-0.11.2/src/iterator.rs.orig	2019-12-17 06:25:59 UTC
+++ cargo-crates/gstreamer-0.11.2/src/iterator.rs
@@ -432,7 +432,7 @@ where
     callback_guard!();
     let value = value as *const gobject_ffi::GValue;
 
-    let func = func as *const &mut (FnMut(T) -> bool);
+    let func = func as *mut &mut (FnMut(T) -> bool);
     let value = &*(value as *const glib::Value);
     let value = value.get::<T>().unwrap();
 
@@ -448,7 +448,7 @@ where
     for<'a> T: FromValueOptional<'a> + 'static,
 {
     callback_guard!();
-    let func = func as *const &mut (FnMut(T));
+    let func = func as *mut &mut (FnMut(T));
     let value = &*(value as *const glib::Value);
     let value = value.get::<T>().unwrap();
 
@@ -464,7 +464,7 @@ where
     for<'a> T: FromValueOptional<'a> + 'static,
 {
     callback_guard!();
-    let func = func as *const &mut (FnMut(U, T) -> Result<U, U>);
+    let func = func as *mut &mut (FnMut(U, T) -> Result<U, U>);
     let value = &*(value as *const glib::Value);
     let value = value.get::<T>().unwrap();
 
