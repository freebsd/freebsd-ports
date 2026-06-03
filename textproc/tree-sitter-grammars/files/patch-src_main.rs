--- src/main.rs.orig	2025-08-19 16:12:37 UTC
+++ src/main.rs
@@ -88,14 +88,14 @@ fn main() -> Result<()> {
         }
     };
 
-    let helix_dir = tmp_dir.join("helix");
-    checkout_repo(
-        &helix_dir,
-        "https://github.com/helix-editor/helix",
-        "0a4432b104099534f7a25b8ea4148234db146ab6",
-    )?;
+//    let helix_dir = tmp_dir.join("helix");
+//    checkout_repo(
+//        &helix_dir,
+//        "https://github.com/helix-editor/helix",
+//        "0a4432b104099534f7a25b8ea4148234db146ab6",
+//    )?;
 
-    let Ok(languages_config) = &fs::read_to_string(helix_dir.join("languages.toml"))
+    let Ok(languages_config) = &fs::read_to_string("languages.toml")
     else {
         error!("Failed to read grammars config");
         bail!("Failed to read grammars config");
@@ -158,7 +158,7 @@ fn build_grammar(
     tmp_dir: &Path,
 ) -> Result<()> {
     let path = tmp_dir.join(format! {"tree-sitter-{}",grammar.name});
-    checkout_repo(&path, &grammar.source.git, &grammar.source.rev)?;
+//    checkout_repo(&path, &grammar.source.git, &grammar.source.rev)?;
     let path = if let Some(subpath) = grammar.source.subpath.as_ref() {
         path.join(subpath)
     } else {
@@ -171,6 +171,7 @@ fn build_tree_sitter(name: &str, path: &Path, output: 
 fn build_tree_sitter(name: &str, path: &Path, output: &Path) -> Result<()> {
     println!("-----------------------------------");
     println!("now building tree sitter for {name}");
+    std::env::set_var("XDG_CACHE_HOME", "WRKDIR/.cache");
     let output = Command::new("tree-sitter")
         .current_dir(path)
         .arg("build")
