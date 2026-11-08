-- Fix leantar JSON stdin parsing to accept lake cache input format.
-- lake sends `--stdin --json` entries as objects (for example
-- `{"file":"...","hash":"..."}`), while older logic expected a positional
-- tuple shape and failed to parse these records reliably.
-- This patch accepts string, object, and legacy [hash,file] array entries.

--- src/tar.rs.orig	2026-06-27 14:23:24 UTC
+++ src/tar.rs
@@ -161,37 +161,77 @@ fn main() {
         assert!(!from_stdin, "two stdin inputs");
         from_stdin = true;
         if json_stdin {
-          let str = std::io::read_to_string(std::io::stdin()).unwrap();
-          for j in serde_json::from_str::<Vec<serde_json::Value>>(&str).unwrap() {
-            args_vec.push(if let serde_json::Value::String(s) = j {
-              from_file(s)
-            } else {
-              let j = j.as_object().expect("expected object");
-              let file = j["file"].as_str().expect("expected string");
-              let base = match j.get("base") {
-                None => vec![],
-                Some(b) => match b.as_array() {
-                  Some(arr) => arr
-                    .iter()
-                    .map(|v| {
-                      if v.is_null() {
-                        None::<PathBuf>
-                      } else {
-                        Some(v.as_str().expect("expected string or null").into())
-                      }
-                    })
-                    .collect(),
-                  None => vec![Some(b.as_str().expect("expected string or array").into())],
-                },
-              };
-              let hash = j.get("hash").filter(|v| !v.is_null()).map(|value| {
-                value
-                  .as_str()
+          let s = std::io::read_to_string(std::io::stdin()).unwrap_or_else(|e| {
+            eprintln!("error reading stdin: {e}");
+            std::process::exit(1);
+          });
+          let v = match serde_json::from_str::<Vec<serde_json::Value>>(&s) {
+            Ok(v) => v,
+            Err(e) => {
+              eprintln!("error parsing JSON from stdin: {e}");
+              std::process::exit(1);
+            }
+          };
+          for j in v {
+            args_vec.push(match j {
+              serde_json::Value::String(s) => from_file(s),
+              // Accept [hash, file] two-element arrays produced by lake cache commands.
+              serde_json::Value::Array(ref arr) if arr.len() == 2 => {
+                let hash = arr[0].as_str()
                   .and_then(|s| u64::from_str_radix(s, 16).ok())
-                  .expect("expected hex hash")
-              });
-              Arg { base, file: file.into(), hash }
-            })
+                  .unwrap_or_else(|| {
+                    eprintln!("json array: first element must be a hex hash string");
+                    std::process::exit(1);
+                  });
+                let file = arr[1].as_str().unwrap_or_else(|| {
+                  eprintln!("json array: second element must be a file string");
+                  std::process::exit(1);
+                });
+                Arg { base: vec![], file: file.into(), hash: Some(hash) }
+              }
+              serde_json::Value::Object(ref map) => {
+                let file = map.get("file").and_then(|v| v.as_str()).unwrap_or_else(|| {
+                  eprintln!("json object missing 'file' string field");
+                  std::process::exit(1);
+                });
+                let base = match map.get("base") {
+                  None => vec![],
+                  Some(b) => match b.as_array() {
+                    Some(arr) => arr
+                      .iter()
+                      .map(|v| {
+                        if v.is_null() {
+                          None::<PathBuf>
+                        } else {
+                          Some(v.as_str().unwrap_or_else(|| {
+                            eprintln!("json 'base' array element must be string or null");
+                            std::process::exit(1);
+                          }).into())
+                        }
+                      })
+                      .collect(),
+                    None => vec![Some(b.as_str().unwrap_or_else(|| {
+                      eprintln!("json 'base' must be string or array");
+                      std::process::exit(1);
+                    }).into())],
+                  },
+                };
+                let hash = map.get("hash").filter(|v| !v.is_null()).map(|value| {
+                  value
+                    .as_str()
+                    .and_then(|s| u64::from_str_radix(s, 16).ok())
+                    .unwrap_or_else(|| {
+                      eprintln!("json 'hash' must be a hex string");
+                      std::process::exit(1);
+                    })
+                });
+                Arg { base, file: file.into(), hash }
+              }
+              _ => {
+                eprintln!("json stdin: expected string, [hash, file] array, or object");
+                std::process::exit(1);
+              }
+            });
           }
         } else {
           for arg in std::io::stdin().lines().map(|arg| arg.unwrap()) {
