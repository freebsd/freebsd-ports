--- cargo-crates/lindera-dictionary-0.43.3/src/assets.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/lindera-dictionary-0.43.3/src/assets.rs
@@ -207,33 +207,8 @@ pub async fn fetch(
         dummy_matrix_def.write_all(b"0 1 0\n")?;
     } else {
         // Source file path for build package
-        let source_path_for_build = &build_dir.join(params.file_name);
+        let source_path_for_build = Path::new("%%DISTDIR%%").join(params.file_name);

-        // Download source file to build directory
-        let tmp_path = Path::new(&build_dir).join(params.file_name.to_owned() + ".download");
-
-        // Download a tarball
-        let client = Client::builder()
-            .user_agent(format!("Lindera/{}", env!("CARGO_PKG_VERSION")))
-            .build()?;
-
-        debug!("Downloading {:?}", params.download_urls);
-        let mut dest = File::create(tmp_path.as_path())?;
-        let content = download_with_retry(
-            &client,
-            params.download_urls.to_vec(),
-            MAX_ROUND,
-            params.md5_hash,
-        )
-        .await?;
-
-        io::copy(&mut Cursor::new(content.as_slice()), &mut dest)?;
-        dest.flush()?;
-
-        debug!("Content-Length: {}", content.len());
-        debug!("Downloaded to {}", tmp_path.display());
-        rename(tmp_path.clone(), source_path_for_build).expect("Failed to rename temporary file");
-
         // Decompress a tar.gz file
         let tmp_extract_path =
             Path::new(&build_dir).join(format!("tmp-archive-{}", params.input_dir));
@@ -277,8 +252,6 @@ pub async fn fetch(
         }

         let _ = std::fs::remove_dir_all(&tmp_extract_path);
-        drop(dest);
-        let _ = std::fs::remove_file(source_path_for_build);
     }

     let tmp_path = build_dir.join(format!("tmp-output-{}", params.output_dir));
