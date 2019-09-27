From 3c98d22c5de3b696bf1fde2b6c90069812312aa6 Mon Sep 17 00:00:00 2001
From: Simon Sapin <simon.sapin@exyr.org>
Date: Tue, 23 Apr 2019 13:47:25 +0200
Subject: [PATCH] Fix a future-compat warning

```
warning[E0506]: cannot assign to `self.input.cached_token` because it is borrowed
   --> src/parser.rs:591:17
    |
566 |     pub fn next_including_whitespace_and_comments(&mut self) -> Result<&Token<'i>, BasicParseError<'i>> {
    |                                                   - let's call the lifetime of this reference `'1`
...
579 |             Some(ref cached_token)
    |                  ---------------- borrow of `self.input.cached_token` occurs here
...
591 |                 self.input.cached_token = Some(CachedToken {
    |                 ^^^^^^^^^^^^^^^^^^^^^^^ assignment to borrowed `self.input.cached_token` occurs here
...
603 |         Ok(token)
    |         --------- returning this value requires that `self.input.cached_token.0` is borrowed for `'1`
    |
    = warning: this error has been downgraded to a warning for backwards compatibility with previous releases
    = warning: this represents potential undefined behavior in your code and this warning will become a hard error in the future
```
--- third_party/rust/cssparser/.cargo-checksum.json.orig	2019-08-26 16:52:35 UTC
+++ third_party/rust/cssparser/.cargo-checksum.json
@@ -1 +1 @@
-{"files":{"Cargo.toml":"150d450e43bcb9e523941408be883997ecffce7ff5f224329372edfe56334a55","LICENSE":"fab3dd6bdab226f1c08630b1dd917e11fcb4ec5e1e020e2c16f83a0a13863e85","README.md":"b9d6c5dc56ccc267db9e0e2389061dc2524daefa4baed88b36c98efc7a51c2a9","build.rs":"310d6d7b1931ff783a8aa1a4c6baee87b4c9130c858e4694ef69cc96df5e38dc","build/match_byte.rs":"6f7ec4235c9f2da403ea0be9339661ecd8e1f5e1c788cf88a41448b1080c59b8","docs/404.html":"025861f76f8d1f6d67c20ab624c6e418f4f824385e2dd8ad8732c4ea563c6a2e","docs/index.html":"025861f76f8d1f6d67c20ab624c6e418f4f824385e2dd8ad8732c4ea563c6a2e","src/color.rs":"43f996fbd8da54bd8ffa870f5e3610e5ba6e61543f92a129fa6c850e9b10db7e","src/cow_rc_str.rs":"541216f8ef74ee3cc5cbbc1347e5f32ed66588c401851c9a7d68b867aede1de0","src/from_bytes.rs":"331fe63af2123ae3675b61928a69461b5ac77799fff3ce9978c55cf2c558f4ff","src/lib.rs":"a474ee88ef8f73fcb7b7272d426e5eafb4ad10d104797a5a188d1676c8180972","src/macros.rs":"adb9773c157890381556ea83d7942dcc676f99eea71abbb6afeffee1e3f28960","src/nth.rs":"5c70fb542d1376cddab69922eeb4c05e4fcf8f413f27563a2af50f72a47c8f8c","src/parser.rs":"22067562160a1294fa92779b66c25cbccf259a2ef7dcf687c791fecdd020ce7f","src/rules_and_declarations.rs":"622ce07c117a511d40ce595602d4f4730659a59273388f28553d1a2b0fac92ce","src/serializer.rs":"3e2dfc60613f885cb6f99abfc854fde2a1e00de507431bd2e51178b61abfd69b","src/size_of_tests.rs":"385a0d77fbd6f86cb8013fd8d7541886980876a9da1da714bf175954c0e726cf","src/tests.rs":"9d08b3943d453664e01d58e307f79345e240f9f9ce6f8d36a842eff37155563e","src/tokenizer.rs":"adcf5811955e8df57a519e3d1e44fe3afeb5afeb1076daeb8d36fed1abcf1327","src/unicode_range.rs":"ae159d2ebe4123a6666e18dc0362f89b475240a6b7ed5fb6fe21b9e7a4139da8"},"package":"ba1ab4e1814be64bf6b6064ff532db0e34087f11b37706d6c96a21d32478761d"}
\ No newline at end of file
+{"files":{},"package":"ba1ab4e1814be64bf6b6064ff532db0e34087f11b37706d6c96a21d32478761d"}
--- third_party/rust/cssparser/src/parser.rs.orig	2019-08-26 16:52:35 UTC
+++ third_party/rust/cssparser/src/parser.rs
@@ -556,39 +556,47 @@ impl<'i: 't, 't> Parser<'i, 't> {
     /// where comments are preserved.
     /// When parsing higher-level values, per the CSS Syntax specification,
     /// comments should always be ignored between tokens.
-    pub fn next_including_whitespace_and_comments(&mut self) -> Result<&Token<'i>, BasicParseError<'i>> {
+    pub fn next_including_whitespace_and_comments(
+        &mut self
+    ) -> Result<&Token<'i>, BasicParseError<'i>> {
         if let Some(block_type) = self.at_start_of.take() {
             consume_until_end_of_block(block_type, &mut self.input.tokenizer);
         }
 
         let byte = self.input.tokenizer.next_byte();
         if self.stop_before.contains(Delimiters::from_byte(byte)) {
-            return Err(self.new_basic_error(BasicParseErrorKind::EndOfInput))
+            return Err(self.new_basic_error(BasicParseErrorKind::EndOfInput));
         }
 
         let token_start_position = self.input.tokenizer.position();
-        let token;
-        match self.input.cached_token {
-            Some(ref cached_token)
-            if cached_token.start_position == token_start_position => {
-                self.input.tokenizer.reset(&cached_token.end_state);
-                match cached_token.token {
-                    Token::Function(ref name) => self.input.tokenizer.see_function(name),
-                    _ => {}
-                }
-                token = &cached_token.token
+        let using_cached_token = self
+            .input
+            .cached_token
+            .as_ref()
+            .map_or(false, |cached_token| {
+                cached_token.start_position == token_start_position
+            });
+        let token = if using_cached_token {
+            let cached_token = self.input.cached_token.as_ref().unwrap();
+            self.input.tokenizer.reset(&cached_token.end_state);
+            match cached_token.token {
+                Token::Function(ref name) => self.input.tokenizer.see_function(name),
+                _ => {}
             }
-            _ => {
-                let new_token = self.input.tokenizer.next()
-                    .map_err(|()| self.new_basic_error(BasicParseErrorKind::EndOfInput))?;
-                self.input.cached_token = Some(CachedToken {
-                    token: new_token,
-                    start_position: token_start_position,
-                    end_state: self.input.tokenizer.state(),
-                });
-                token = self.input.cached_token_ref()
-            }
-        }
+            &cached_token.token
+        } else {
+            let new_token = self
+                .input
+                .tokenizer
+                .next()
+                .map_err(|()| self.new_basic_error(BasicParseErrorKind::EndOfInput))?;
+            self.input.cached_token = Some(CachedToken {
+                token: new_token,
+                start_position: token_start_position,
+                end_state: self.input.tokenizer.state(),
+            });
+            self.input.cached_token_ref()
+        };
 
         if let Some(block_type) = BlockType::opening(token) {
             self.at_start_of = Some(block_type);
