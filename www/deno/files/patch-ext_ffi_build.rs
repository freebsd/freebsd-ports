ONE_SOURCE=yes is required because the Makefile doesn't work
well

--- ext/ffi/build.rs.orig	2022-07-21 01:28:00.000000000 +0200
+++ ext/ffi/build.rs	2022-07-26 14:20:50.502353000 +0200
@@ -30,18 +30,19 @@ fn build_tcc() {
     let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
     let mut configure = Command::new(tcc_src.join("configure"));
     configure.current_dir(&out_dir);
-    configure.args(&["--enable-static", "--extra-cflags=-fPIC -O3 -g -static"]);
+    configure.args(&["--enable-static", "--cc=cc", "--extra-cflags=-fPIC -O3 -g -static"]);
     let status = configure.status().unwrap();
     if !status.success() {
       eprintln!("Fail to configure: {:?}", status);
       exit(1);
     }
 
-    let mut make = Command::new("make");
+    let mut make = Command::new("gmake");
     make.current_dir(&out_dir).arg(format!(
       "-j{}",
       env::var("NUM_JOBS").unwrap_or_else(|_| String::from("1"))
     ));
+    make.args(&["ONE_SOURCE=yes"]);
     make.args(&["libtcc.a"]);
     let status = make.status().unwrap();
 
