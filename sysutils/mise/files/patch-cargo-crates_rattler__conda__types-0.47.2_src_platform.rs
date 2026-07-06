--- cargo-crates/rattler_conda_types-0.47.2/src/platform.rs.orig
+++ cargo-crates/rattler_conda_types-0.47.2/src/platform.rs
@@ -35,6 +35,8 @@
     FreeBsd32,
     FreeBsd64,
     FreeBsdArm64,
+    FreeBsdPpc64le,
+    FreeBsdPpc64,
 
     Osx64,
     OsxArm64,
@@ -153,8 +153,19 @@
 
             #[cfg(target_arch = "aarch64")]
             return Platform::FreeBsdArm64;
+
+            #[cfg(all(target_arch = "powerpc64", target_endian = "little"))]
+            return Platform::FreeBsdPpc64le;
+
+            #[cfg(all(target_arch = "powerpc64", target_endian = "big"))]
+            return Platform::FreeBsdPpc64;
 
-            #[cfg(not(any(target_arch = "x86", target_arch = "x86_64", target_arch = "aarch64")))]
+            #[cfg(not(any(
+                target_arch = "x86",
+                target_arch = "x86_64",
+                target_arch = "aarch64",
+                target_arch = "powerpc64"
+            )))]
             compile_error!("unsupported freebsd architecture");
         }
         #[cfg(windows)]
@@ -230,6 +230,8 @@
                     | Platform::FreeBsd32
                     | Platform::FreeBsd64
                     | Platform::FreeBsdArm64
+                    | Platform::FreeBsdPpc64le
+                    | Platform::FreeBsdPpc64
             )
     }
 
@@ -273,7 +273,11 @@
             | Platform::LinuxS390X
             | Platform::LinuxRiscv32
             | Platform::LinuxRiscv64 => Some("linux"),
-            Platform::FreeBsd32 | Platform::FreeBsd64 | Platform::FreeBsdArm64 => Some("freebsd"),
+            Platform::FreeBsd32
+            | Platform::FreeBsd64
+            | Platform::FreeBsdArm64
+            | Platform::FreeBsdPpc64le
+            | Platform::FreeBsdPpc64 => Some("freebsd"),
             Platform::Osx64 | Platform::OsxArm64 => Some("osx"),
             Platform::Win32 | Platform::Win64 | Platform::WinArm64 => Some("win"),
             Platform::EmscriptenWasm32 => Some("emscripten"),
@@ -322,6 +322,8 @@
             "freebsd-32" => Platform::FreeBsd32,
             "freebsd-64" => Platform::FreeBsd64,
             "freebsd-arm64" => Platform::FreeBsdArm64,
+            "freebsd-ppc64le" => Platform::FreeBsdPpc64le,
+            "freebsd-ppc64" => Platform::FreeBsdPpc64,
             "osx-64" => Platform::Osx64,
             "osx-arm64" => Platform::OsxArm64,
             "win-32" => Platform::Win32,
@@ -358,6 +358,8 @@
             Platform::FreeBsd32 => "freebsd-32",
             Platform::FreeBsd64 => "freebsd-64",
             Platform::FreeBsdArm64 => "freebsd-arm64",
+            Platform::FreeBsdPpc64le => "freebsd-ppc64le",
+            Platform::FreeBsdPpc64 => "freebsd-ppc64",
             Platform::Osx64 => "osx-64",
             Platform::OsxArm64 => "osx-arm64",
             Platform::Win32 => "win-32",
@@ -382,8 +382,8 @@
             Platform::LinuxArmV6l => Some(Arch::ArmV6l),
             Platform::LinuxArmV7l => Some(Arch::ArmV7l),
             Platform::LinuxLoongArch64 => Some(Arch::LoongArch64),
-            Platform::LinuxPpc64le => Some(Arch::Ppc64le),
-            Platform::LinuxPpc64 => Some(Arch::Ppc64),
+            Platform::LinuxPpc64le | Platform::FreeBsdPpc64le => Some(Arch::Ppc64le),
+            Platform::LinuxPpc64 | Platform::FreeBsdPpc64 => Some(Arch::Ppc64),
             Platform::LinuxPpc => Some(Arch::Ppc),
             Platform::LinuxS390X => Some(Arch::S390X),
             Platform::LinuxRiscv32 => Some(Arch::Riscv32),
@@ -552,6 +552,14 @@
             "freebsd-arm64".parse::<Platform>().unwrap(),
             Platform::FreeBsdArm64
         );
+        assert_eq!(
+            "freebsd-ppc64le".parse::<Platform>().unwrap(),
+            Platform::FreeBsdPpc64le
+        );
+        assert_eq!(
+            "freebsd-ppc64".parse::<Platform>().unwrap(),
+            Platform::FreeBsdPpc64
+        );
         assert_eq!("win-arm64".parse::<Platform>().unwrap(), Platform::WinArm64);
         assert_eq!(
             "emscripten-wasm32".parse::<Platform>().unwrap(),
@@ -596,6 +596,8 @@
         assert_eq!(Platform::FreeBsd32.arch(), Some(Arch::X86));
         assert_eq!(Platform::FreeBsd64.arch(), Some(Arch::X86_64));
         assert_eq!(Platform::FreeBsdArm64.arch(), Some(Arch::Arm64));
+        assert_eq!(Platform::FreeBsdPpc64le.arch(), Some(Arch::Ppc64le));
+        assert_eq!(Platform::FreeBsdPpc64.arch(), Some(Arch::Ppc64));
         assert_eq!(Platform::Osx64.arch(), Some(Arch::X86_64));
         assert_eq!(Platform::OsxArm64.arch(), Some(Arch::Arm64));
         assert_eq!(Platform::Win32.arch(), Some(Arch::X86));
