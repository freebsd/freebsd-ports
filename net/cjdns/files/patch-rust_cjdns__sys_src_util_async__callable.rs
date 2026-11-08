-- Ignore the broken doctest for the private AsyncCallable constructor.
-- The example referenced internal symbols and a `super` path that does not
-- exist when compiled as a user-facing doctest; mark it ignored so `cargo test` passes.
-- Upstreamed: https://github.com/cjdelisle/cjdns/pull/1281

--- rust/cjdns_sys/src/util/async_callable.rs.orig	2026-09-27 19:37:09 UTC
+++ rust/cjdns_sys/src/util/async_callable.rs
@@ -52,13 +52,19 @@ impl<T: Arg, O: Out> dyn AsyncCallable<T, O> {
     /// Args:
     ///   ctx: The context (Ctx)
     ///   f: The function
-    /// ```rust
+    /// ```ignore
+    /// use cjdns_sys::util::async_callable::AsyncCallable;
+    ///
+    /// #[derive(Clone)]
+    /// struct Ctx { num: usize }
+    ///
     /// async fn xxx(ctx: Ctx, msg: String) {
     ///     println!("num = {}, msg = {}", ctx.num, msg);
     /// }
+    ///
     /// async fn test_fn() {
-    ///     let ctx = Ctx{ num: 3};
-    ///     let callable = super::new(ctx, xxx);
+    ///     let ctx = Ctx { num: 3 };
+    ///     let callable = AsyncCallable::new(ctx, xxx);
     ///     callable.call("hi".into()).await;
     /// }
     /// ```
