--- tensorflow/workspace.bzl.orig	2017-06-14 19:02:07 UTC
+++ tensorflow/workspace.bzl
@@ -147,2532 +147,832 @@ def tf_workspace(path_prefix="", tf_repo
     print("tf_repo_name was specified to tf_workspace but is no longer used " +
           "and will be removed in the future.")
 
-  native.new_http_archive(
+  native.local_repository(
       name = "eigen_archive",
-      urls = [
-          "http://mirror.bazel.build/bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
-          "https://bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
-      ],
-      sha256 = "ca7beac153d4059c02c8fc59816c82d54ea47fe58365e8aded4082ded0b820c4",
-      strip_prefix = "eigen-eigen-f3a22f35b044",
-      build_file = str(Label("//third_party:eigen.BUILD")),
+      path = "tensorflow_third_party/eigen_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "libxsmm_archive",
-      urls = [
-          "http://mirror.bazel.build/github.com/hfp/libxsmm/archive/1.8.tar.gz",
-          "https://github.com/hfp/libxsmm/archive/1.8.tar.gz",
-      ],
-      sha256 = "0330201afb5525d0950ec861fec9dd75eb40a03845ebe03d2c635cf8bfc14fea",
-      strip_prefix = "libxsmm-1.8",
-      build_file = str(Label("//third_party:libxsmm.BUILD")),
-  )
-
-  native.bind(
-      name = "xsmm_avx",
-      actual = "@libxsmm_archive//third_party:xsmm_avx",
+      path = "tensorflow_third_party/libxsmm_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "ortools_archive",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/or-tools/archive/253f7955c6a1fd805408fba2e42ac6d45b312d15.tar.gz",
-          "https://github.com/google/or-tools/archive/253f7955c6a1fd805408fba2e42ac6d45b312d15.tar.gz",
-      ],
-      sha256 = "932075525642b04ac6f1b50589f1df5cd72ec2f448b721fd32234cf183f0e755",
-      strip_prefix = "or-tools-253f7955c6a1fd805408fba2e42ac6d45b312d15/src",
-      build_file = str(Label("//third_party:ortools.BUILD")),
+      path = "tensorflow_third_party/ortools_archive"
   )
 
-  native.http_archive(
+  native.local_repository(
       name = "com_googlesource_code_re2",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/re2/archive/b94b7cd42e9f02673cd748c1ac1d16db4052514c.tar.gz",
-          "https://github.com/google/re2/archive/b94b7cd42e9f02673cd748c1ac1d16db4052514c.tar.gz",
-      ],
-      sha256 = "bd63550101e056427c9e7ff12a408c1c8b74e9803f393ca916b2926fc2c4906f",
-      strip_prefix = "re2-b94b7cd42e9f02673cd748c1ac1d16db4052514c",
+      path = "tensorflow_third_party/com_googlesource_code_re2"
   )
 
-  native.http_archive(
+  native.local_repository(
       name = "gemmlowp",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/gemmlowp/archive/a6f29d8ac48d63293f845f2253eccbf86bc28321.tar.gz",
-          "https://github.com/google/gemmlowp/archive/a6f29d8ac48d63293f845f2253eccbf86bc28321.tar.gz",
-      ],
-      sha256 = "75d40ea8e68b0d1644f052fffe8f14a410b2a73d40ccb859a95c0578d194ec26",
-      strip_prefix = "gemmlowp-a6f29d8ac48d63293f845f2253eccbf86bc28321",
+      path = "tensorflow_third_party/gemmlowp"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "farmhash_archive",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/farmhash/archive/92e897b282426729f4724d91a637596c7e2fe28f.zip",
-          "https://github.com/google/farmhash/archive/92e897b282426729f4724d91a637596c7e2fe28f.zip",
-      ],
-      sha256 = "4c626d1f306bda2c6804ab955892f803f5245f4dcaecb4979dc08b091256da54",
-      strip_prefix = "farmhash-92e897b282426729f4724d91a637596c7e2fe28f",
-      build_file = str(Label("//third_party:farmhash.BUILD")),
-  )
-
-  native.bind(
-      name = "farmhash",
-      actual = "@farmhash//:farmhash",
+      path = "tensorflow_third_party/farmhash_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "highwayhash",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/highwayhash/archive/dfcb97ca4fe9277bf9dc1802dd979b071896453b.tar.gz",
-          "https://github.com/google/highwayhash/archive/dfcb97ca4fe9277bf9dc1802dd979b071896453b.tar.gz",
-      ],
-      sha256 = "0f30a15b1566d93f146c8d149878a06e91d9bb7ec2cfd76906df62a82be4aac9",
-      strip_prefix = "highwayhash-dfcb97ca4fe9277bf9dc1802dd979b071896453b",
-      build_file = str(Label("//third_party:highwayhash.BUILD")),
+      path = "tensorflow_third_party/highwayhash"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "nasm",
-      urls = [
-          "http://mirror.bazel.build/www.nasm.us/pub/nasm/releasebuilds/2.12.02/nasm-2.12.02.tar.bz2",
-          "http://pkgs.fedoraproject.org/repo/pkgs/nasm/nasm-2.12.02.tar.bz2/d15843c3fb7db39af80571ee27ec6fad/nasm-2.12.02.tar.bz2",
-      ],
-      sha256 = "00b0891c678c065446ca59bcee64719d0096d54d6886e6e472aeee2e170ae324",
-      strip_prefix = "nasm-2.12.02",
-      build_file = str(Label("//third_party:nasm.BUILD")),
+      path = "tensorflow_third_party/nasm"
   )
 
-  temp_workaround_http_archive(
+  native.local_repository(
       name = "jpeg",
-      urls = [
-          "http://mirror.bazel.build/github.com/libjpeg-turbo/libjpeg-turbo/archive/1.5.1.tar.gz",
-          "https://github.com/libjpeg-turbo/libjpeg-turbo/archive/1.5.1.tar.gz",
-      ],
-      sha256 = "c15a9607892113946379ccea3ca8b85018301b200754f209453ab21674268e77",
-      strip_prefix = "libjpeg-turbo-1.5.1",
-      build_file = str(Label("//third_party/jpeg:jpeg.BUILD")),
-      repository = tf_repo_name,
+      path = "tensorflow_third_party/jpeg"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "png_archive",
-      urls = [
-          "http://mirror.bazel.build/github.com/glennrp/libpng/archive/v1.2.53.zip",
-          "https://github.com/glennrp/libpng/archive/v1.2.53.zip",
-      ],
-      sha256 = "c35bcc6387495ee6e757507a68ba036d38ad05b415c2553b3debe2a57647a692",
-      strip_prefix = "libpng-1.2.53",
-      build_file = str(Label("//third_party:png.BUILD")),
+      path = "tensorflow_third_party/png_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "gif_archive",
-      urls = [
-          "http://mirror.bazel.build/ufpr.dl.sourceforge.net/project/giflib/giflib-5.1.4.tar.gz",
-          "http://ufpr.dl.sourceforge.net/project/giflib/giflib-5.1.4.tar.gz",
-          "http://pilotfiber.dl.sourceforge.net/project/giflib/giflib-5.1.4.tar.gz",
-      ],
-      sha256 = "34a7377ba834397db019e8eb122e551a49c98f49df75ec3fcc92b9a794a4f6d1",
-      strip_prefix = "giflib-5.1.4",
-      build_file = str(Label("//third_party:gif.BUILD")),
+      path = "tensorflow_third_party/gif_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "six_archive",
-      urls = [
-          "http://mirror.bazel.build/pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz",
-          "http://pypi.python.org/packages/source/s/six/six-1.10.0.tar.gz",
-      ],
-      sha256 = "105f8d68616f8248e24bf0e9372ef04d3cc10104f1980f54d57b2ce73a5ad56a",
-      strip_prefix = "six-1.10.0",
-      build_file = str(Label("//third_party:six.BUILD")),
+      path = "tensorflow_third_party/six_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "org_pythonhosted_markdown",
-      urls = [
-          "http://mirror.bazel.build/pypi.python.org/packages/1d/25/3f6d2cb31ec42ca5bd3bfbea99b63892b735d76e26f20dd2dcc34ffe4f0d/Markdown-2.6.8.tar.gz",
-          "https://pypi.python.org/packages/1d/25/3f6d2cb31ec42ca5bd3bfbea99b63892b735d76e26f20dd2dcc34ffe4f0d/Markdown-2.6.8.tar.gz",
-      ],
-      strip_prefix = "Markdown-2.6.8",
-      sha256 = "0ac8a81e658167da95d063a9279c9c1b2699f37c7c4153256a458b3a43860e33",
-      build_file = str(Label("//third_party:markdown.BUILD")),
+      path = "tensorflow_third_party/org_pythonhosted_markdown"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "org_html5lib",
-      urls = [
-          "http://mirror.bazel.build/github.com/html5lib/html5lib-python/archive/0.9999999.tar.gz",
-          "https://github.com/html5lib/html5lib-python/archive/0.9999999.tar.gz",  # identical to 1.0b8
-      ],
-      sha256 = "184257f98539159a433e2a2197309657ae1283b4c44dbd9c87b2f02ff36adce8",
-      strip_prefix = "html5lib-python-0.9999999",
-      build_file = str(Label("//third_party:html5lib.BUILD")),
+      path = "tensorflow_third_party/org_html5lib"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "org_mozilla_bleach",
-      urls = [
-          "http://mirror.bazel.build/github.com/mozilla/bleach/archive/v1.5.tar.gz",
-          "https://github.com/mozilla/bleach/archive/v1.5.tar.gz",
-      ],
-      strip_prefix = "bleach-1.5",
-      sha256 = "0d68713d02ba4148c417ab1637dd819333d96929a34401d0233947bec0881ad8",
-      build_file = str(Label("//third_party:bleach.BUILD")),
+      path = "tensorflow_third_party/org_mozilla_bleach"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "org_pocoo_werkzeug",
-      urls = [
-          "http://mirror.bazel.build/pypi.python.org/packages/b7/7f/44d3cfe5a12ba002b253f6985a4477edfa66da53787a2a838a40f6415263/Werkzeug-0.11.10.tar.gz",
-          "https://pypi.python.org/packages/b7/7f/44d3cfe5a12ba002b253f6985a4477edfa66da53787a2a838a40f6415263/Werkzeug-0.11.10.tar.gz",
-      ],
-      strip_prefix = "Werkzeug-0.11.10",
-      sha256 = "cc64dafbacc716cdd42503cf6c44cb5a35576443d82f29f6829e5c49264aeeee",
-      build_file = str(Label("//third_party:werkzeug.BUILD")),
-  )
-
-  native.bind(
-      name = "six",
-      actual = "@six_archive//:six",
+      path = "tensorflow_third_party/org_pocoo_werkzeug"
   )
 
-  patched_http_archive(
+  native.local_repository(
       name = "protobuf",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/protobuf/archive/2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a.tar.gz",
-          "https://github.com/google/protobuf/archive/2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a.tar.gz",
-      ],
-      sha256 = "e5d3d4e227a0f7afb8745df049bbd4d55474b158ca5aaa2a0e31099af24be1d0",
-      strip_prefix = "protobuf-2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a",
-      # TODO: remove patching when tensorflow stops linking same protos into
-      #       multiple shared libraries loaded in runtime by python.
-      #       This patch fixes a runtime crash when tensorflow is compiled
-      #       with clang -O2 on Linux (see https://github.com/tensorflow/tensorflow/issues/8394)
-      patch_file = str(Label("//third_party/protobuf:add_noinlines.patch")),
+      path = "tensorflow_third_party/protobuf"
   )
 
-  # We need to import the protobuf library under the names com_google_protobuf
-  # and com_google_protobuf_cc to enable proto_library support in bazel.
-  # Unfortunately there is no way to alias http_archives at the moment.
-  native.http_archive(
+  native.local_repository(
       name = "com_google_protobuf",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/protobuf/archive/2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a.tar.gz",
-          "https://github.com/google/protobuf/archive/2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a.tar.gz",
-      ],
-      sha256 = "e5d3d4e227a0f7afb8745df049bbd4d55474b158ca5aaa2a0e31099af24be1d0",
-      strip_prefix = "protobuf-2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a",
+      path = "tensorflow_third_party/com_google_protobuf"
   )
 
-  native.http_archive(
+  native.local_repository(
       name = "com_google_protobuf_cc",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/protobuf/archive/2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a.tar.gz",
-          "https://github.com/google/protobuf/archive/2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a.tar.gz",
-      ],
-      sha256 = "e5d3d4e227a0f7afb8745df049bbd4d55474b158ca5aaa2a0e31099af24be1d0",
-      strip_prefix = "protobuf-2b7430d96aeff2bb624c8d52182ff5e4b9f7f18a",
+      path = "tensorflow_third_party/com_google_protobuf_cc"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "gmock_archive",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/googletest/archive/release-1.8.0.zip",
-          "https://github.com/google/googletest/archive/release-1.8.0.zip",
-      ],
-      sha256 = "f3ed3b58511efd272eb074a3a6d6fb79d7c2e6a0e374323d1e6bcbcc1ef141bf",
-      strip_prefix = "googletest-release-1.8.0",
-      build_file = str(Label("//third_party:gmock.BUILD")),
-  )
-
-  native.bind(
-      name = "gtest",
-      actual = "@gmock_archive//:gtest",
-  )
-
-  native.bind(
-      name = "gtest_main",
-      actual = "@gmock_archive//:gtest_main",
+      path = "tensorflow_third_party/gmock_archive"
   )
 
-  native.http_archive(
+  native.local_repository(
       name = "com_github_gflags_gflags",
-      urls = [
-          "http://mirror.bazel.build/github.com/gflags/gflags/archive/f8a0efe03aa69b3336d8e228b37d4ccb17324b88.tar.gz",
-          "https://github.com/gflags/gflags/archive/f8a0efe03aa69b3336d8e228b37d4ccb17324b88.tar.gz",
-      ],
-      sha256 = "4d222fab8f1ede4709cdff417d15a1336f862d7334a81abf76d09c15ecf9acd1",
-      strip_prefix = "gflags-f8a0efe03aa69b3336d8e228b37d4ccb17324b88",
-  )
-
-  native.bind(
-      name = "python_headers",
-      actual = str(Label("//util/python:python_headers")),
+      path = "tensorflow_third_party/com_github_gflags_gflags"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "pcre",
-      sha256 = "ccdf7e788769838f8285b3ee672ed573358202305ee361cfec7a4a4fb005bbc7",
-      urls = [
-          "http://mirror.bazel.build/ftp.exim.org/pub/pcre/pcre-8.39.tar.gz",
-          "http://ftp.exim.org/pub/pcre/pcre-8.39.tar.gz",
-      ],
-      strip_prefix = "pcre-8.39",
-      build_file = str(Label("//third_party:pcre.BUILD")),
+      path = "tensorflow_third_party/pcre"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "swig",
-      sha256 = "58a475dbbd4a4d7075e5fe86d4e54c9edde39847cdb96a3053d87cb64a23a453",
-      urls = [
-          "http://mirror.bazel.build/ufpr.dl.sourceforge.net/project/swig/swig/swig-3.0.8/swig-3.0.8.tar.gz",
-          "http://ufpr.dl.sourceforge.net/project/swig/swig/swig-3.0.8/swig-3.0.8.tar.gz",
-          "http://pilotfiber.dl.sourceforge.net/project/swig/swig/swig-3.0.8/swig-3.0.8.tar.gz",
-      ],
-      strip_prefix = "swig-3.0.8",
-      build_file = str(Label("//third_party:swig.BUILD")),
+      path = "tensorflow_third_party/swig"
   )
 
-  temp_workaround_http_archive(
+  native.local_repository(
       name = "curl",
-      sha256 = "ff3e80c1ca6a068428726cd7dd19037a47cc538ce58ef61c59587191039b2ca6",
-      urls = [
-          "http://mirror.bazel.build/curl.haxx.se/download/curl-7.49.1.tar.gz",
-          "https://curl.haxx.se/download/curl-7.49.1.tar.gz",
-      ],
-      strip_prefix = "curl-7.49.1",
-      build_file = str(Label("//third_party:curl.BUILD")),
-      repository = tf_repo_name
-  )
-
-  # grpc expects //external:protobuf_clib and //external:protobuf_compiler
-  # to point to the protobuf's compiler library.
-  native.bind(
-      name = "protobuf_clib",
-      actual = "@protobuf//:protoc_lib",
-  )
-
-  native.bind(
-      name = "protobuf_compiler",
-      actual = "@protobuf//:protoc_lib",
+      path = "tensorflow_third_party/curl"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "grpc",
-      urls = [
-          "http://mirror.bazel.build/github.com/grpc/grpc/archive/d7ff4ff40071d2b486a052183e3e9f9382afb745.tar.gz",
-          "https://github.com/grpc/grpc/archive/d7ff4ff40071d2b486a052183e3e9f9382afb745.tar.gz",
-      ],
-      sha256 = "a15f352436ab92c521b1ac11e729e155ace38d0856380cf25048c5d1d9ba8e31",
-      strip_prefix = "grpc-d7ff4ff40071d2b486a052183e3e9f9382afb745",
-      build_file = str(Label("//third_party:grpc.BUILD")),
-  )
-
-  # protobuf expects //external:grpc_cpp_plugin to point to grpc's
-  # C++ plugin code generator.
-  native.bind(
-      name = "grpc_cpp_plugin",
-      actual = "@grpc//:grpc_cpp_plugin",
-  )
-
-  native.bind(
-      name = "grpc_lib",
-      actual = "@grpc//:grpc++_unsecure",
+      path = "tensorflow_third_party/grpc"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "linenoise",
-      sha256 = "7f51f45887a3d31b4ce4fa5965210a5e64637ceac12720cfce7954d6a2e812f7",
-      urls = [
-          "http://mirror.bazel.build/github.com/antirez/linenoise/archive/c894b9e59f02203dbe4e2be657572cf88c4230c3.tar.gz",
-          "https://github.com/antirez/linenoise/archive/c894b9e59f02203dbe4e2be657572cf88c4230c3.tar.gz",
-      ],
-      strip_prefix = "linenoise-c894b9e59f02203dbe4e2be657572cf88c4230c3",
-      build_file = str(Label("//third_party:linenoise.BUILD")),
+      path = "tensorflow_third_party/linenoise"
   )
 
-  # TODO(phawkins): currently, this rule uses an unofficial LLVM mirror.
-  # Switch to an official source of snapshots if/when possible.
-  temp_workaround_http_archive(
+  native.local_repository(
       name = "llvm",
-      urls = [
-          "http://mirror.bazel.build/github.com/llvm-mirror/llvm/archive/c978c0ff91f7c4ea58cfbd8f378e51c6af2c2b4b.tar.gz",
-          "https://github.com/llvm-mirror/llvm/archive/c978c0ff91f7c4ea58cfbd8f378e51c6af2c2b4b.tar.gz",
-      ],
-      sha256 = "42c57d798a037d9dea692ce1da8ff4d24966ab5a40494015b374341e43411a37",
-      strip_prefix = "llvm-c978c0ff91f7c4ea58cfbd8f378e51c6af2c2b4b",
-      build_file = str(Label("//third_party/llvm:llvm.BUILD")),
-      repository = tf_repo_name,
+      path = "tensorflow_third_party/llvm"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "jsoncpp_git",
-      urls = [
-          "http://mirror.bazel.build/github.com/open-source-parsers/jsoncpp/archive/11086dd6a7eba04289944367ca82cea71299ed70.tar.gz",
-          "https://github.com/open-source-parsers/jsoncpp/archive/11086dd6a7eba04289944367ca82cea71299ed70.tar.gz",
-      ],
-      sha256 = "07d34db40593d257324ec5fb9debc4dc33f29f8fb44e33a2eeb35503e61d0fe2",
-      strip_prefix = "jsoncpp-11086dd6a7eba04289944367ca82cea71299ed70",
-      build_file = str(Label("//third_party:jsoncpp.BUILD")),
-  )
-
-  native.bind(
-      name = "jsoncpp",
-      actual = "@jsoncpp_git//:jsoncpp",
+      path = "tensorflow_third_party/jsoncpp_git"
   )
 
-  native.http_archive(
+  native.local_repository(
       name = "boringssl",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/boringssl/archive/bbcaa15b0647816b9a1a9b9e0d209cd6712f0105.tar.gz",
-          "https://github.com/google/boringssl/archive/bbcaa15b0647816b9a1a9b9e0d209cd6712f0105.tar.gz",  # 2016-07-11
-      ],
-      sha256 = "025264d6e9a7ad371f2f66d17a28b6627de0c9592dc2eb54afd062f68f1f9aa3",
-      strip_prefix = "boringssl-bbcaa15b0647816b9a1a9b9e0d209cd6712f0105",
+      path = "tensorflow_third_party/boringssl"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "nanopb_git",
-      urls = [
-          "http://mirror.bazel.build/github.com/nanopb/nanopb/archive/1251fa1065afc0d62f635e0f63fec8276e14e13c.tar.gz",
-          "https://github.com/nanopb/nanopb/archive/1251fa1065afc0d62f635e0f63fec8276e14e13c.tar.gz",
-      ],
-      sha256 = "ab1455c8edff855f4f55b68480991559e51c11e7dab060bbab7cffb12dd3af33",
-      strip_prefix = "nanopb-1251fa1065afc0d62f635e0f63fec8276e14e13c",
-      build_file = str(Label("//third_party:nanopb.BUILD")),
-  )
-
-  native.bind(
-      name = "nanopb",
-      actual = "@nanopb_git//:nanopb",
+      path = "tensorflow_third_party/nanopb_git"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "zlib_archive",
-      urls = [
-          "http://mirror.bazel.build/zlib.net/zlib-1.2.8.tar.gz",
-          "http://zlib.net/fossils/zlib-1.2.8.tar.gz",
-      ],
-      sha256 = "36658cb768a54c1d4dec43c3116c27ed893e88b02ecfcb44f2166f9c0b7f2a0d",
-      strip_prefix = "zlib-1.2.8",
-      build_file = str(Label("//third_party:zlib.BUILD")),
-  )
-
-  native.bind(
-      name = "zlib",
-      actual = "@zlib_archive//:zlib",
+      path = "tensorflow_third_party/zlib_archive"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "fft2d",
-      urls = [
-          "http://mirror.bazel.build/www.kurims.kyoto-u.ac.jp/~ooura/fft.tgz",
-          "http://www.kurims.kyoto-u.ac.jp/~ooura/fft.tgz",
-      ],
-      sha256 = "52bb637c70b971958ec79c9c8752b1df5ff0218a4db4510e60826e0cb79b5296",
-      build_file = str(Label("//third_party/fft2d:fft2d.BUILD")),
+      path = "tensorflow_third_party/fft2d"
   )
 
-  temp_workaround_http_archive(
+  native.local_repository(
       name = "snappy",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/snappy/archive/1.1.4.zip",
-          "https://github.com/google/snappy/archive/1.1.4.zip",
-      ],
-      sha256 = "6c74d2b663170d68184da353cdd71b5b7d57bc8888ef1e99b4929b5d680dba54",
-      strip_prefix = "snappy-1.1.4",
-      build_file = str(Label("//third_party:snappy.BUILD")),
-      repository = tf_repo_name,
+      path = "tensorflow_third_party/snappy"
   )
 
-  temp_workaround_http_archive(
+  native.local_repository(
       name = "nccl_archive",
-      urls = [
-          "http://mirror.bazel.build/github.com/nvidia/nccl/archive/ccfc4567dc3e2a37fb42cfbc64d10eb526e7da7b.tar.gz",
-          "https://github.com/nvidia/nccl/archive/ccfc4567dc3e2a37fb42cfbc64d10eb526e7da7b.tar.gz",
-      ],
-      sha256 = "6c34a0862d9f8ed4ad5984c6a8206b351957bb14cf6ad7822720f285f4aada04",
-      strip_prefix = "nccl-ccfc4567dc3e2a37fb42cfbc64d10eb526e7da7b",
-      build_file = str(Label("//third_party:nccl.BUILD")),
-      repository = tf_repo_name,
+      path = "tensorflow_third_party/nccl_archive"
   )
 
-  java_import_external(
+  native.local_repository(
       name = "junit",
-      jar_sha256 = "59721f0805e223d84b90677887d9ff567dc534d7c502ca903c0c2b17f05c116a",
-      jar_urls = [
-          "http://mirror.bazel.build/repo1.maven.org/maven2/junit/junit/4.12/junit-4.12.jar",
-          "http://repo1.maven.org/maven2/junit/junit/4.12/junit-4.12.jar",
-          "http://maven.ibiblio.org/maven2/junit/junit/4.12/junit-4.12.jar",
-      ],
-      licenses = ["reciprocal"],  # Common Public License Version 1.0
-      testonly_ = True,
-      deps = ["@org_hamcrest_core"],
+      path = "tensorflow_third_party/junit"
   )
 
-  java_import_external(
+  native.local_repository(
       name = "org_hamcrest_core",
-      jar_sha256 = "66fdef91e9739348df7a096aa384a5685f4e875584cce89386a7a47251c4d8e9",
-      jar_urls = [
-          "http://mirror.bazel.build/repo1.maven.org/maven2/org/hamcrest/hamcrest-core/1.3/hamcrest-core-1.3.jar",
-          "http://repo1.maven.org/maven2/org/hamcrest/hamcrest-core/1.3/hamcrest-core-1.3.jar",
-          "http://maven.ibiblio.org/maven2/org/hamcrest/hamcrest-core/1.3/hamcrest-core-1.3.jar",
-      ],
-      licenses = ["notice"],  # New BSD License
-      testonly_ = True,
+      path = "tensorflow_third_party/org_hamcrest_core"
   )
 
-  temp_workaround_http_archive(
+  native.local_repository(
       name = "jemalloc",
-      urls = [
-          "http://mirror.bazel.build/github.com/jemalloc/jemalloc/archive/4.4.0.tar.gz",
-          "https://github.com/jemalloc/jemalloc/archive/4.4.0.tar.gz",
-      ],
-      sha256 = "3c8f25c02e806c3ce0ab5fb7da1817f89fc9732709024e2a81b6b82f7cc792a8",
-      strip_prefix = "jemalloc-4.4.0",
-      build_file = str(Label("//third_party:jemalloc.BUILD")),
-      repository = tf_repo_name,
+      path = "tensorflow_third_party/jemalloc"
   )
 
-  native.new_http_archive(
+  native.local_repository(
       name = "com_google_pprof",
-      urls = [
-          "http://mirror.bazel.build/github.com/google/pprof/archive/c0fb62ec88c411cc91194465e54db2632845b650.tar.gz",
-          "https://github.com/google/pprof/archive/c0fb62ec88c411cc91194465e54db2632845b650.tar.gz",
-      ],
-      sha256 = "e0928ca4aa10ea1e0551e2d7ce4d1d7ea2d84b2abbdef082b0da84268791d0c4",
-      strip_prefix = "pprof-c0fb62ec88c411cc91194465e54db2632845b650",
-      build_file = str(Label("//third_party:pprof.BUILD")),
+      path = "tensorflow_third_party/com_google_pprof"
   )
 
-  ##############################################################################
-  # TensorBoard Build Tools
-
-  filegroup_external(
+  native.local_repository(
       name = "org_nodejs",
-      # MIT with portions licensed:
-      # - MIT
-      # - Old MIT
-      # - 2-Clause-BSD
-      # - 3-Clause-BSD
-      # - ISC
-      # - Unicode
-      # - zlib
-      # - Artistic 2.0
-      licenses = ["notice"],
-      sha256_urls_extract_macos = {
-          "47109a00cac344d80296c195451bb5eee7c21727fcef1594384ddfe1f852957a": [
-              "http://mirror.bazel.build/nodejs.org/dist/v4.3.2/node-v4.3.2-darwin-x64.tar.xz",
-              "http://nodejs.org/dist/v4.3.2/node-v4.3.2-darwin-x64.tar.xz",
-          ],
-      },
-      sha256_urls_windows = {
-          "606c44c42d17866c017c50c0afadad411d9492ac4281d2431b937f881911614e": [
-              "http://mirror.bazel.build/nodejs.org/dist/v4.3.2/win-x64/node.exe",
-              "http://nodejs.org/dist/v4.3.2/win-x64/node.exe",
-          ],
-          "451a40570099a95488d6438f175813629e0430f87f23c8659bc18dc42494820a": [
-              "http://mirror.bazel.build/nodejs.org/dist/v4.3.2/win-x64/node.lib",
-              "http://nodejs.org/dist/v4.3.2/win-x64/node.lib",
-          ],
-      },
-      sha256_urls_extract = {
-          "4350d0431b49697517c6cca5d66adf5f74eb9101c52f52ae959fa94225822d44": [
-              "http://mirror.bazel.build/nodejs.org/dist/v4.3.2/node-v4.3.2-linux-x64.tar.xz",
-              "http://nodejs.org/dist/v4.3.2/node-v4.3.2-linux-x64.tar.xz",
-          ],
-      },
-      strip_prefix = {
-          "node-v4.3.2-darwin-x64.tar.xz": "node-v4.3.2-darwin-x64",
-          "node-v4.3.2-linux-x64.tar.xz": "node-v4.3.2-linux-x64",
-      },
-      executable = [
-          "node",
-          "node.exe",
-      ],
+      path = "tensorflow_third_party/org_nodejs"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "com_microsoft_typescript",
-      licenses = ["notice"],  # Apache 2.0
-      sha256_urls = {
-          "8465342c318f9c4cf0a29b109fa63ee3742dd4dc7080d05d9fd8f604814d04cf": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/Microsoft/TypeScript/v2.3.1/lib/tsc.js",
-              "https://raw.githubusercontent.com/Microsoft/TypeScript/v2.3.1/lib/tsc.js",
-          ],
-          "a67e36da3029d232e4e938e61a0a3302f516d71e7100d54dbf5362ad8618e994": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/Microsoft/TypeScript/v2.3.1/lib/lib.es6.d.ts",
-              "https://raw.githubusercontent.com/Microsoft/TypeScript/v2.3.1/lib/lib.es6.d.ts",
-          ],
-      },
-      extra_build_file_content = "\n".join([
-          "sh_binary(",
-          "    name = \"tsc\",",
-          "    srcs = [\"tsc.sh\"],",
-          "    data = [",
-          "        \"tsc.js\",",
-          "        \"@org_nodejs\",",
-          "    ],",
-          ")",
-          "",
-          "genrule(",
-          "    name = \"tsc_sh\",",
-          "    outs = [\"tsc.sh\"],",
-          "    cmd = \"cat >$@ <<'EOF'\\n\" +",
-          "          \"#!/bin/bash\\n\" +",
-          "          \"NODE=external/org_nodejs/bin/node\\n\" +",
-          "          \"if [[ -e external/org_nodejs/node.exe ]]; then\\n\" +",
-          "          \"  NODE=external/org_nodejs/node.exe\\n\" +",
-          "          \"fi\\n\" +",
-          "          \"exec $${NODE} external/com_microsoft_typescript/tsc.js \\\"$$@\\\"\\n\" +",
-          "          \"EOF\",",
-          "    executable = True,",
-          ")",
-      ]),
+      path = "tensorflow_third_party/com_microsoft_typescript"
   )
 
-  ##############################################################################
-  # TensorBoard JavaScript Production Dependencies
-
-  web_library_external(
+  native.local_repository(
       name = "com_lodash",
-      licenses = ["notice"],  # MIT
-      sha256 = "0e88207e5f90af4ce8790d6e1e7d09d2702d81bce0bafdc253d18c0a5bf7661e",
-      urls = [
-          "http://mirror.bazel.build/github.com/lodash/lodash/archive/3.10.1.tar.gz",
-          "https://github.com/lodash/lodash/archive/3.10.1.tar.gz",
-      ],
-      strip_prefix = "lodash-3.10.1",
-      path = "/lodash",
-      srcs = ["lodash.js"],
+      path = "tensorflow_third_party/com_lodash"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "com_numericjs",
-      # no @license header
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "dfaca3b8485bee735788cc6eebca82ea25719adc1fb8911c7799c6bd5a95df3b": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/sloisel/numeric/v1.2.6/src/numeric.js",
-              "https://raw.githubusercontent.com/sloisel/numeric/v1.2.6/src/numeric.js",
-          ],
-      },
+      path = "tensorflow_third_party/com_numericjs"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "com_palantir_plottable",
-      # no @license header
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "77510d7538dbd3b59f1c8a06f68131b38562e3be546364747618d5112723e818": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/palantir/plottable/v1.16.1/plottable.css",
-              "https://raw.githubusercontent.com/palantir/plottable/v1.16.1/plottable.css",
-          ],
-          "cd46dc709b01cd361e8399f797760871a6a207bc832e08fcff385ced02ef2b43": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/palantir/plottable/v1.16.1/plottable.d.ts",
-              "https://raw.githubusercontent.com/palantir/plottable/v1.16.1/plottable.d.ts",
-          ],
-          "32647b0fb4175fa875a71e6d56c761b88d975186ed6a8820e2c7854165a8988d": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/palantir/plottable/v1.16.1/plottable.js",
-              "https://raw.githubusercontent.com/palantir/plottable/v1.16.1/plottable.js",
-          ],
-      },
+      path = "tensorflow_third_party/com_palantir_plottable"
   )
 
-  # TODO: Delete previous rule and rename this one org_palantir_plottable
-  filegroup_external(
+  native.local_repository(
       name = "com_palantir_plottable_v3",
-      # no @license header
-      licenses = ["notice"],  # MIT
-      sha256_urls_extract = {
-          # Plottable doesn't have a release tarball on GitHub. Using the
-          # sources directly from git also requires running Node tooling
-          # beforehand to generate files. NPM is the only place to get it.
-          "e3159beb279391c47433789f22b32bac88488cfcad6c0b6ec8605ce6b0081b0d": [
-              "http://mirror.bazel.build/registry.npmjs.org/plottable/-/plottable-3.1.0.tgz",
-              "https://registry.npmjs.org/plottable/-/plottable-3.1.0.tgz",
-          ],
-      },
+      path = "tensorflow_third_party/com_palantir_plottable_v3"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "io_github_cpettitt_dagre",
-      # no @license header
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "7323829ddd77924a69e2b1235ded3eac30acd990da0f037e0fbd3c8e9035b50d": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/cpettitt/dagre/v0.7.4/dist/dagre.core.js",
-              "https://raw.githubusercontent.com/cpettitt/dagre/v0.7.4/dist/dagre.core.js",
-          ],
-      },
+      path = "tensorflow_third_party/io_github_cpettitt_dagre"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "io_github_cpettitt_graphlib",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "772045d412b1513b549be991c2e1846c38019429d43974efcae943fbe83489bf": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/cpettitt/graphlib/v1.0.7/dist/graphlib.core.js",
-              "https://raw.githubusercontent.com/cpettitt/graphlib/v1.0.7/dist/graphlib.core.js",
-          ],
-      },
+      path = "tensorflow_third_party/io_github_cpettitt_graphlib"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "io_github_waylonflinn_weblas",
-      # no @license header
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "f138fce57f673ca8a633f4aee5ae5b6fcb6ad0de59069a42a74e996fd04d8fcc": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/waylonflinn/weblas/v0.9.0/dist/weblas.js",
-              "https://raw.githubusercontent.com/waylonflinn/weblas/v0.9.0/dist/weblas.js",
-          ],
-      },
+      path = "tensorflow_third_party/io_github_waylonflinn_weblas"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_d3js",
-      # no @license header
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256_urls = {
-          "bc1e38838f5c5c8e040132d41efee6bfddbef728210bd566479dc1694af1d3f5": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/d3/d3/v3.5.15/d3.js",
-              "https://raw.githubusercontent.com/d3/d3/v3.5.15/d3.js",
-          ],
-      },
+      path = "tensorflow_third_party/org_d3js"
   )
 
-  # TODO: Delete previous rule and rename this one org_d3js
-  filegroup_external(
+  native.local_repository(
       name = "org_d3js_v4",
-      # no @license header
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256_urls_extract = {
-          "b5fac5b296bc196e6aa7b59f9e33986fc44d23d59a0e211705187be9e35b943d": [
-              "http://mirror.bazel.build/github.com/d3/d3/releases/download/v4.8.0/d3.zip",
-              "https://github.com/d3/d3/releases/download/v4.8.0/d3.zip",
-          ],
-      },
-      # TODO(jart): Use srcs=["d3.js"] instead of this once supported.
-      generated_rule_name = "all_files",
-      extra_build_file_content = "\n".join([
-          "filegroup(",
-          "    name = \"org_d3js_v4\",",
-          "    srcs = [\"d3.js\"],",
-          ")",
-      ]),
+      path = "tensorflow_third_party/org_d3js_v4"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "b7da645f6e5555feb7aeede73775da0023ce2257df9c8e76c9159266035a9c0d": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/ebc69904eb78f94030d5d517b42db20867f679c0/chai/chai.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/ebc69904eb78f94030d5d517b42db20867f679c0/chai/chai.d.ts",
-          ],
-          "177293828c7a206bf2a7f725753d51396d38668311aa37c96445f91bbf8128a7": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/6e2f2280ef16ef277049d0ce8583af167d586c59/d3/d3.d.ts",  # v3
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/6e2f2280ef16ef277049d0ce8583af167d586c59/d3/d3.d.ts",  # v3
-          ],
-          "e4cd3d5de0eb3bc7b1063b50d336764a0ac82a658b39b5cf90511f489ffdee60": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/efd40e67ff323f7147651bdbef03c03ead7b1675/lodash/lodash.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/efd40e67ff323f7147651bdbef03c03ead7b1675/lodash/lodash.d.ts",
-          ],
-          "695a03dd2ccb238161d97160b239ab841562710e5c4e42886aefd4ace2ce152e": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/ebc69904eb78f94030d5d517b42db20867f679c0/mocha/mocha.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/ebc69904eb78f94030d5d517b42db20867f679c0/mocha/mocha.d.ts",
-          ],
-          "513ccd9ee1c708881120eeacd56788fc3b3da8e5c6172b20324cebbe858803fe": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/708609e0764daeb5eb64104af7aca50c520c4e6e/sinon/sinon.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/708609e0764daeb5eb64104af7aca50c520c4e6e/sinon/sinon.d.ts",
-          ],
-          "44eba36339bd1c0792072b7b204ee926fe5ffe1e9e2da916e67ac55548e3668a": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/a872802c0c84ba98ff207d5e673a1fa867c67fd6/polymer/polymer.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/a872802c0c84ba98ff207d5e673a1fa867c67fd6/polymer/polymer.d.ts",
-          ],
-          "9453c3e6bae824e90758c3b38975c1ed77e6abd79bf513bcb08368fcdb14898e": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/f5407eba29c04fb8387c86df27512bd055b195d2/threejs/three.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/f5407eba29c04fb8387c86df27512bd055b195d2/threejs/three.d.ts",
-          ],
-          "691756a6eb455f340c9e834de0d49fff269e7b8c1799c2454465dcd6a4435b80": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/46719185c564694c5583c4b7ad94dbb786ecad46/webcomponents.js/webcomponents.js.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/46719185c564694c5583c4b7ad94dbb786ecad46/webcomponents.js/webcomponents.js.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_array",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "61e7abb7b1f01fbcb0cab8cf39003392f422566209edd681fbd070eaa84ca000": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-array/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-array/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_array"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_axis",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "95f75c8dcc89850b2e72581d96a7b5f46ea4ac852f828893f141f14a597421f9": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-axis/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-axis/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_axis"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_brush",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "a2738e693ce8a8640c2d29001e77582c9c361fd23bda44db471629866b60ada7": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-brush/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-brush/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_brush"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_chord",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "c54d24756eb6d744b31e538ad9bab3a75f6d54e2288b29cc72338d4a057d3e83": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-chord/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-chord/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_chord"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_collection",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "f987667167b1d2970911247e325eb1c37ca0823646f81ccec837ae59039822f7": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-collection/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-collection/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_collection"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_color",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "9580c81f38ddcce7be0ac9bd3d0d083adebc34e17441709f90b9e4dcd1c19a56": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-color/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-color/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_color"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_dispatch",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "169f80b4cceca8e2e9ed384d81a5db0624cc01a26451dfb5a7e0cec6ea9cfb06": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-dispatch/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-dispatch/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_dispatch"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_drag",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "08d35d139dde58c2722be98d718d01204fd6167d310f09b379e832f3c741489d": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-drag/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-drag/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_drag"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_dsv",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "62594d00cf9e4bb895339c8e56f64330e202a5eb2a0fa580a1f6e6336f2c93ce": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-dsv/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-dsv/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_dsv"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_ease",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "d1cf8f99b7bf758c2ba3c0a4ce553e151d4d9b4cf45a6e8bd0edec7ce90f725b": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-ease/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-ease/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_ease"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_force",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "288421e2008668d2076a4684657dd3d29b992832ef02c552981eb94a91042553": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-force/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-force/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_force"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_format",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "b42cb17e580c1fd0b64d478f7bd80ca806efaefda24426a833cf1f30a7275bca": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-format/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-format/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_format"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_hierarchy",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "a5683f5835d8716c6b89c075235078438cfab5897023ed720bfa492e244e969e": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-hierarchy/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-hierarchy/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_hierarchy"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_interpolate",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "590a71b741323ac3139b333ec8b743e24717fdd5b32bcff48ee521162a9dfe1c": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-interpolate/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-interpolate/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_interpolate"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_path",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "96f35ba041bcaa265e2b373ee675177410d44d31c980e4f7fbeefd4bcba15b00": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-path/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-path/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_path"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_polygon",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "ce453451e8105cac6a4f4a4263ca2142ebb4bf442e342f470a81da691f220fcb": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-polygon/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-polygon/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_polygon"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_quadtree",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "238e278f1be5d6985a19800800cffee80f81199f71d848e3bbc288d1791a6f90": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-quadtree/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-quadtree/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_quadtree"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_queue",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "e6ae19aad83495475653578de64fb9d6bf9764eda6c84d70f7935ec84bcc482e": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-queue/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-queue/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_queue"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_random",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "d31b92ed86c23ec0a4776f99fa81ff033c95b96c8304d8aa9baf3b94af779aa8": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-random/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-random/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_random"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_request",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "44bb7b07d977028e6567540a3303b06fc9b33fb0960bc75c520e0733c840d89f": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-request/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-request/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_request"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_scale",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "02ce7c644ba34bd1abb84da2e832f248b048b6a23812be4365bd837f186c9f1f": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-scale/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-scale/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_scale"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_selection",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "699043ddb28dfa5e46d87bc6a24cfc6d604237f298259d3fb3c7066e05e8c86e": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-selection/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-selection/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_selection"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_shape",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "62668a7aaaf6232762b544f9f89c0f557ca7cfb0cd343a358dda7ecbe26f5739": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-shape/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-shape/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_shape"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_time",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "0502490ce682fd9265fb1d5d693ce6cd82e3b05e5f5ee3433731266ecb03d5fc": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-time/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-time/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_time"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_timer",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "6f191f9aea704aa64b1defa40dfdff1447a6e6bb815feff1660f894500a9c94d": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-timer/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-timer/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_timer"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_transition",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "a0a7c0c9bfb5c7d6d9d22a8d16b4484b66d13f2ed226954037546cb3da4098ba": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-transition/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-transition/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_transition"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_voronoi",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "c6bd5f229f915151d0ef678fe50b1aa6a62334ea0a8c6fc0effbac9f7032efc7": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-voronoi/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-voronoi/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_voronoi"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_definitelytyped_types_d3_zoom",
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "a25dc17fbd304cf7a0e5e7bbb8339c930d464eb40c4d6e5f839ce9c0191f4110": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-zoom/index.d.ts",
-              "https://raw.githubusercontent.com/DefinitelyTyped/DefinitelyTyped/1550dfd1b8e38d9bf104b3fd16ea9bf98a2b358e/types/d3-zoom/index.d.ts",
-          ],
-      },
+      path = "tensorflow_third_party/org_definitelytyped_types_d3_zoom"
   )
 
-  filegroup_external(
+  native.local_repository(
       name = "org_threejs",
-      # no @license header
-      licenses = ["notice"],  # MIT
-      sha256_urls = {
-          "7aff264bd84c90bed3c72a4dc31db8c19151853c6df6980f52b01d3e9872c82d": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/mrdoob/three.js/ad419d40bdaab80abbb34b8f359b4ee840033a02/build/three.js",
-              "https://raw.githubusercontent.com/mrdoob/three.js/ad419d40bdaab80abbb34b8f359b4ee840033a02/build/three.js",
-          ],
-          "0e98ded15bb7fe398a655667e76b39909d36c0973a8950d01c62f65f93161c27": [
-              "http://mirror.bazel.build/raw.githubusercontent.com/mrdoob/three.js/ad419d40bdaab80abbb34b8f359b4ee840033a02/examples/js/controls/OrbitControls.js",
-              "https://raw.githubusercontent.com/mrdoob/three.js/ad419d40bdaab80abbb34b8f359b4ee840033a02/examples/js/controls/OrbitControls.js",
-          ],
-      },
+      path = "tensorflow_third_party/org_threejs"
   )
 
-  ##############################################################################
-  # TensorBoard Polymer Dependencies
-
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_font_roboto",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "fae51429b56a4a4c15f1f0c23b733c7095940cc9c04c275fa7adb3bf055b23b3",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/font-roboto/archive/v1.0.1.tar.gz",
-          "https://github.com/PolymerElements/font-roboto/archive/v1.0.1.tar.gz",
-      ],
-      strip_prefix = "font-roboto-1.0.1",
-      path = "/font-roboto",
-      srcs = ["roboto.html"],
+      path = "tensorflow_third_party/org_polymer_font_roboto"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_hydrolysis",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "703b50f6b00f9e0546b5a3451da57bb20f77a166e27e4967923b9e835bab9b80",
-      urls = [
-          "http://mirror.bazel.build/github.com/Polymer/polymer-analyzer/archive/v1.19.3.tar.gz",
-          "https://github.com/Polymer/polymer-analyzer/archive/v1.19.3.tar.gz",
-      ],
-      strip_prefix = "polymer-analyzer-1.19.3",
-      path = "/hydrolysis",
-      srcs = [
-          "hydrolysis-analyzer.html",
-          "hydrolysis.html",
-          "hydrolysis.js",
-      ],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_hydrolysis"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_a11y_announcer",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "6bce143db7a374a68535ec8b861a5f30e81f2f1e4ee36a55bda2a891f6fd2818",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-a11y-announcer/archive/v1.0.5.tar.gz",
-          "https://github.com/PolymerElements/iron-a11y-announcer/archive/v1.0.5.tar.gz",
-      ],
-      strip_prefix = "iron-a11y-announcer-1.0.5",
-      path = "/iron-a11y-announcer",
-      srcs = ["iron-a11y-announcer.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_a11y_announcer"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_a11y_keys_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "6823efc47a83208fd51d39c5a1d3eb0c0bebc705df1ce01310509da22a13ebd2",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-a11y-keys-behavior/archive/v1.1.8.tar.gz",
-          "https://github.com/PolymerElements/iron-a11y-keys-behavior/archive/v1.1.8.tar.gz",
-      ],
-      strip_prefix = "iron-a11y-keys-behavior-1.1.8",
-      path = "/iron-a11y-keys-behavior",
-      srcs = ["iron-a11y-keys-behavior.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_a11y_keys_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_ajax",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "9162d8af4611e911ac3ebbfc08bb7038ac04f6e79a9287b1476fe36ad6770bc5",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-ajax/archive/v1.2.0.tar.gz",
-          "https://github.com/PolymerElements/iron-ajax/archive/v1.2.0.tar.gz",
-      ],
-      strip_prefix = "iron-ajax-1.2.0",
-      path = "/iron-ajax",
-      srcs = [
-          "iron-ajax.html",
-          "iron-request.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_promise_polyfill",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_ajax"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_autogrow_textarea",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "50bbb901d2c8f87462e3552e3d671a552faa12c37c485e548d7a234ebffbc427",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-autogrow-textarea/archive/v1.0.12.tar.gz",
-          "https://github.com/PolymerElements/iron-autogrow-textarea/archive/v1.0.12.tar.gz",
-      ],
-      strip_prefix = "iron-autogrow-textarea-1.0.12",
-      path = "/iron-autogrow-textarea",
-      srcs = ["iron-autogrow-textarea.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_form_element_behavior",
-          "@org_polymer_iron_validatable_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_autogrow_textarea"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_behaviors",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "a1e8d4b7a13f3d36beba9c2a6b186ed33a53e6af2e79f98c1fcc7e85e7b53f89",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-behaviors/archive/v1.0.17.tar.gz",
-          "https://github.com/PolymerElements/iron-behaviors/archive/v1.0.17.tar.gz",
-      ],
-      strip_prefix = "iron-behaviors-1.0.17",
-      path = "/iron-behaviors",
-      srcs = [
-          "iron-button-state.html",
-          "iron-control-state.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_behaviors"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_checked_element_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "539a0e1c4df0bc702d3bd342388e4e56c77ec4c2066cce69e41426a69f92e8bd",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-checked-element-behavior/archive/v1.0.4.tar.gz",
-          "https://github.com/PolymerElements/iron-checked-element-behavior/archive/v1.0.4.tar.gz",
-      ],
-      strip_prefix = "iron-checked-element-behavior-1.0.4",
-      path = "/iron-checked-element-behavior",
-      srcs = ["iron-checked-element-behavior.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_form_element_behavior",
-          "@org_polymer_iron_validatable_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_checked_element_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_component_page",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "3636e8b9a1f229fc33b5aad3933bd02a9825f66e679a0be31855d7c8245c4b4b",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-component-page/archive/v1.1.4.tar.gz",
-          "https://github.com/PolymerElements/iron-component-page/archive/v1.1.4.tar.gz",
-      ],
-      strip_prefix = "iron-component-page-1.1.4",
-      path = "/iron-component-page",
-      srcs = ["iron-component-page.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_hydrolysis",
-          "@org_polymer_iron_ajax",
-          "@org_polymer_iron_doc_viewer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_icons",
-          "@org_polymer_iron_selector",
-          "@org_polymer_paper_header_panel",
-          "@org_polymer_paper_styles",
-          "@org_polymer_paper_toolbar",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_component_page"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_collapse",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "275808994a609a2f9923e2dd2db1957945ab141ba840eadc33f19e1f406d600e",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-collapse/archive/v1.0.8.tar.gz",
-          "https://github.com/PolymerElements/iron-collapse/archive/v1.0.8.tar.gz",
-      ],
-      strip_prefix = "iron-collapse-1.0.8",
-      path = "/iron-collapse",
-      srcs = ["iron-collapse.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_resizable_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_collapse"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_demo_helpers",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "aa7458492a6ac3d1f6344640a4c2ab07bce64e7ad0422b83b5d665707598cce6",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-demo-helpers/archive/v1.1.0.tar.gz",
-          "https://github.com/PolymerElements/iron-demo-helpers/archive/v1.1.0.tar.gz",
-      ],
-      strip_prefix = "iron-demo-helpers-1.1.0",
-      path = "/iron-demo-helpers",
-      srcs = [
-          "demo-pages-shared-styles.html",
-          "demo-snippet.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_icons",
-          "@org_polymer_marked_element",
-          "@org_polymer_paper_icon_button",
-          "@org_polymer_paper_styles",
-          "@org_polymer_prism_element",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_demo_helpers"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_doc_viewer",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "f0e9dfbbcd94d7e88ce82cb61e615406ace63c185fee9396f7f182206ca5cc9a",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-doc-viewer/archive/v1.0.12.tar.gz",
-          "https://github.com/PolymerElements/iron-doc-viewer/archive/v1.0.12.tar.gz",
-      ],
-      strip_prefix = "iron-doc-viewer-1.0.12",
-      path = "/iron-doc-viewer",
-      srcs = [
-          "iron-doc-property-styles.html",
-          "iron-doc-property.html",
-          "iron-doc-viewer-styles.html",
-          "iron-doc-viewer.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_marked_element",
-          "@org_polymer_paper_button",
-          "@org_polymer_paper_styles",
-          "@org_polymer_prism_element",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_doc_viewer"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_dropdown",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "f7e4a31d096d10d8af1920397695cb17f3eb1cbe5e5ff91a861dabfcc085f376",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-dropdown/archive/v1.4.0.tar.gz",
-          "https://github.com/PolymerElements/iron-dropdown/archive/v1.4.0.tar.gz",
-      ],
-      strip_prefix = "iron-dropdown-1.4.0",
-      path = "/iron-dropdown",
-      srcs = [
-          "iron-dropdown.html",
-          "iron-dropdown-scroll-manager.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_overlay_behavior",
-          "@org_polymer_iron_resizable_behavior",
-          "@org_polymer_neon_animation",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_dropdown"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_fit_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "10132a2ea309a37c4c07b8fead71f64abc588ee6107931e34680f5f36dd8291e",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-fit-behavior/archive/v1.2.5.tar.gz",
-          "https://github.com/PolymerElements/iron-fit-behavior/archive/v1.2.5.tar.gz",
-      ],
-      strip_prefix = "iron-fit-behavior-1.2.5",
-      path = "/iron-fit-behavior",
-      srcs = ["iron-fit-behavior.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_fit_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_flex_layout",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "79287f6ca1c2d4e003f68b88fe19d03a1b6a0011e2b4cae579fe4d1474163a2e",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-flex-layout/archive/v1.3.0.tar.gz",
-          "https://github.com/PolymerElements/iron-flex-layout/archive/v1.3.0.tar.gz",
-      ],
-      strip_prefix = "iron-flex-layout-1.3.0",
-      path = "/iron-flex-layout",
-      srcs = [
-          "classes/iron-flex-layout.html",
-          "classes/iron-shadow-flex-layout.html",
-          "iron-flex-layout.html",
-          "iron-flex-layout-classes.html",
-      ],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_flex_layout"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_form_element_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "1dd9371c638e5bc2ecba8a64074aa680dfb8712198e9612f9ed24d387efc8f26",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-form-element-behavior/archive/v1.0.6.tar.gz",
-          "https://github.com/PolymerElements/iron-form-element-behavior/archive/v1.0.6.tar.gz",
-      ],
-      strip_prefix = "iron-form-element-behavior-1.0.6",
-      path = "/iron-form-element-behavior",
-      srcs = ["iron-form-element-behavior.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_form_element_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_icon",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "9ed58a69159a02c07a6050d242e6d4e585a29f3245b8c8c390cfd52ddb786dc4",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-icon/archive/v1.0.11.tar.gz",
-          "https://github.com/PolymerElements/iron-icon/archive/v1.0.11.tar.gz",
-      ],
-      strip_prefix = "iron-icon-1.0.11",
-      path = "/iron-icon",
-      srcs = ["iron-icon.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_meta",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_icon"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_icons",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "3b18542c147c7923dc3a36b1a51984a73255d610f297d43c9aaccc52859bd0d0",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-icons/archive/v1.1.3.tar.gz",
-          "https://github.com/PolymerElements/iron-icons/archive/v1.1.3.tar.gz",
-      ],
-      strip_prefix = "iron-icons-1.1.3",
-      path = "/iron-icons",
-      srcs = [
-          "av-icons.html",
-          "communication-icons.html",
-          "device-icons.html",
-          "editor-icons.html",
-          "hardware-icons.html",
-          "image-icons.html",
-          "iron-icons.html",
-          "maps-icons.html",
-          "notification-icons.html",
-          "places-icons.html",
-          "social-icons.html",
-      ],
-      deps = [
-          "@org_polymer_iron_icon",
-          "@org_polymer_iron_iconset_svg",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_icons"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_iconset_svg",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "7e3925b7e63a7d22524c4b43ce16ab80d06a576649644783643c11a003284368",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-iconset-svg/archive/v1.1.0.tar.gz",
-          "https://github.com/PolymerElements/iron-iconset-svg/archive/v1.1.0.tar.gz",
-      ],
-      strip_prefix = "iron-iconset-svg-1.1.0",
-      path = "/iron-iconset-svg",
-      srcs = ["iron-iconset-svg.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_meta",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_iconset_svg"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_input",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "c505101ead08ab25526b1f49baecc8c28b4221b92a65e7334c783bdc81553c36",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-input/archive/1.0.10.tar.gz",
-          "https://github.com/PolymerElements/iron-input/archive/1.0.10.tar.gz",
-      ],
-      strip_prefix = "iron-input-1.0.10",
-      path = "/iron-input",
-      srcs = ["iron-input.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_announcer",
-          "@org_polymer_iron_validatable_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_input"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_list",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "72a6530b9f0ad5557f5d287845792a0ada74d8b159198e27f940e226313dc116",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-list/archive/v1.3.9.tar.gz",
-          "https://github.com/PolymerElements/iron-list/archive/v1.3.9.tar.gz",
-      ],
-      strip_prefix = "iron-list-1.3.9",
-      path = "/iron-list",
-      srcs = ["iron-list.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_resizable_behavior",
-          "@org_polymer_iron_scroll_target_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_list"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_menu_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "ad27889343bc9a709258b073f69abc028bb1ffd3fdb975cd2d3939f7f5d7bb6c",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-menu-behavior/archive/v1.1.10.tar.gz",
-          "https://github.com/PolymerElements/iron-menu-behavior/archive/v1.1.10.tar.gz",
-      ],
-      strip_prefix = "iron-menu-behavior-1.1.10",
-      path = "/iron-menu-behavior",
-      srcs = [
-          "iron-menu-behavior.html",
-          "iron-menubar-behavior.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_selector",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_menu_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_meta",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "fb05e6031bae6b4effe5f15d44b3f548d5807f9e3b3aa2442ba17cf4b8b84361",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-meta/archive/v1.1.1.tar.gz",
-          "https://github.com/PolymerElements/iron-meta/archive/v1.1.1.tar.gz",
-      ],
-      strip_prefix = "iron-meta-1.1.1",
-      path = "/iron-meta",
-      srcs = ["iron-meta.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_meta"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_overlay_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "3df5b54ff2e0510c87a2aff8c9d730d3fe83d3d11277cc1a49fa29b549acb46c",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-overlay-behavior/archive/v1.10.1.tar.gz",
-          "https://github.com/PolymerElements/iron-overlay-behavior/archive/v1.10.1.tar.gz",
-      ],
-      strip_prefix = "iron-overlay-behavior-1.10.1",
-      path = "/iron-overlay-behavior",
-      srcs = [
-          "iron-focusables-helper.html",
-          "iron-overlay-backdrop.html",
-          "iron-overlay-behavior.html",
-          "iron-overlay-manager.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_fit_behavior",
-          "@org_polymer_iron_resizable_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_overlay_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_range_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "b2f2b6d52284542330bd30b586e217926eb0adec5e13934a3cef557717c22dc2",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-range-behavior/archive/v1.0.4.tar.gz",
-          "https://github.com/PolymerElements/iron-range-behavior/archive/v1.0.4.tar.gz",
-      ],
-      strip_prefix = "iron-range-behavior-1.0.4",
-      path = "/iron-range-behavior",
-      srcs = ["iron-range-behavior.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_range_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_resizable_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "a87a78ee9223c2f6afae7fc94a3ff91cbce6f7e2a7ed3f2979af7945c9281616",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-resizable-behavior/archive/v1.0.3.tar.gz",
-          "https://github.com/PolymerElements/iron-resizable-behavior/archive/v1.0.3.tar.gz",
-      ],
-      strip_prefix = "iron-resizable-behavior-1.0.3",
-      path = "/iron-resizable-behavior",
-      srcs = ["iron-resizable-behavior.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_resizable_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_scroll_target_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "d0de0c804b1ec91d814754144afd9da1cdb082690de88bd5e47fd5f41990746f",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-scroll-target-behavior/archive/v1.0.3.tar.gz",
-          "https://github.com/PolymerElements/iron-scroll-target-behavior/archive/v1.0.3.tar.gz",
-      ],
-      strip_prefix = "iron-scroll-target-behavior-1.0.3",
-      path = "/iron-scroll-target-behavior",
-      srcs = ["iron-scroll-target-behavior.html"],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_scroll_target_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_selector",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "ba28a47443bad3b744611c9d7a79fb21dbdf2e35edc5ef8f812e2dcd72b16747",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-selector/archive/v1.5.2.tar.gz",
-          "https://github.com/PolymerElements/iron-selector/archive/v1.5.2.tar.gz",
-      ],
-      strip_prefix = "iron-selector-1.5.2",
-      path = "/iron-selector",
-      srcs = [
-          "iron-multi-selectable.html",
-          "iron-selectable.html",
-          "iron-selection.html",
-          "iron-selector.html",
-      ],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_iron_selector"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_iron_validatable_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "aef4901e68043824f36104799269573dd345ffaac494186e466fdc79c06fdb63",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/iron-validatable-behavior/archive/v1.1.1.tar.gz",
-          "https://github.com/PolymerElements/iron-validatable-behavior/archive/v1.1.1.tar.gz",
-      ],
-      strip_prefix = "iron-validatable-behavior-1.1.1",
-      path = "/iron-validatable-behavior",
-      srcs = ["iron-validatable-behavior.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_meta",
-      ],
+      path = "tensorflow_third_party/org_polymer_iron_validatable_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_marked",
-      licenses = ["notice"],  # MIT
-      sha256 = "93d30bd593736ca440938d77808b7ef5972da0f3fcfe4ae63ae7b4ce117da2cb",
-      urls = [
-          "http://mirror.bazel.build/github.com/chjj/marked/archive/v0.3.2.zip",
-          "https://github.com/chjj/marked/archive/v0.3.2.zip",
-      ],
-      strip_prefix = "marked-0.3.2",
-      path = "/marked",
-      srcs = ["lib/marked.js"],
+      path = "tensorflow_third_party/org_polymer_marked"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_marked_element",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "7547616df95f8b903757e6afbabfcdba5322c2bcec3f17c726b8bba5adf4bc5f",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/marked-element/archive/v1.1.3.tar.gz",
-          "https://github.com/PolymerElements/marked-element/archive/v1.1.3.tar.gz",
-      ],
-      strip_prefix = "marked-element-1.1.3",
-      path = "/marked-element",
-      srcs = [
-          "marked-element.html",
-          "marked-import.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_marked",
-      ],
+      path = "tensorflow_third_party/org_polymer_marked_element"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_neon_animation",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "8800c314a76b2da190a2b203259c1091f6d38e0057ed37c2a3d0b734980fa9a5",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/neon-animation/archive/v1.2.2.tar.gz",
-          "https://github.com/PolymerElements/neon-animation/archive/v1.2.2.tar.gz",
-      ],
-      strip_prefix = "neon-animation-1.2.2",
-      path = "/neon-animation",
-      srcs = [
-          "animations/cascaded-animation.html",
-          "animations/fade-in-animation.html",
-          "animations/fade-out-animation.html",
-          "animations/hero-animation.html",
-          "animations/opaque-animation.html",
-          "animations/reverse-ripple-animation.html",
-          "animations/ripple-animation.html",
-          "animations/scale-down-animation.html",
-          "animations/scale-up-animation.html",
-          "animations/slide-down-animation.html",
-          "animations/slide-from-bottom-animation.html",
-          "animations/slide-from-left-animation.html",
-          "animations/slide-from-right-animation.html",
-          "animations/slide-from-top-animation.html",
-          "animations/slide-left-animation.html",
-          "animations/slide-right-animation.html",
-          "animations/slide-up-animation.html",
-          "animations/transform-animation.html",
-          "neon-animatable.html",
-          "neon-animatable-behavior.html",
-          "neon-animated-pages.html",
-          "neon-animation.html",
-          "neon-animation-behavior.html",
-          "neon-animation-runner-behavior.html",
-          "neon-animations.html",
-          "neon-shared-element-animatable-behavior.html",
-          "neon-shared-element-animation-behavior.html",
-          "web-animations.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_meta",
-          "@org_polymer_iron_resizable_behavior",
-          "@org_polymer_iron_selector",
-          "@org_polymer_web_animations_js",
-      ],
+      path = "tensorflow_third_party/org_polymer_neon_animation"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_behaviors",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "7cfcb9082ef9909da262df6b5c120bc62dbeaff278cb563e8fc60465ddd387e5",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-behaviors/archive/v1.0.12.tar.gz",
-          "https://github.com/PolymerElements/paper-behaviors/archive/v1.0.12.tar.gz",
-      ],
-      strip_prefix = "paper-behaviors-1.0.12",
-      path = "/paper-behaviors",
-      srcs = [
-          "paper-button-behavior.html",
-          "paper-checked-element-behavior.html",
-          "paper-inky-focus-behavior.html",
-          "paper-ripple-behavior.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_checked_element_behavior",
-          "@org_polymer_paper_ripple",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_behaviors"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_button",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "896c0a7e34bfcce63fc23c63e105ed9c4d62fa3a6385b7161e1e5cd4058820a6",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-button/archive/v1.0.11.tar.gz",
-          "https://github.com/PolymerElements/paper-button/archive/v1.0.11.tar.gz",
-      ],
-      strip_prefix = "paper-button-1.0.11",
-      path = "/paper-button",
-      srcs = ["paper-button.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_material",
-          "@org_polymer_paper_ripple",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_button"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_checkbox",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "6828a6954a048b1230fbd2606faffbae950ba1d042175b96ec50ae355786a166",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-checkbox/archive/v1.4.0.tar.gz",
-          "https://github.com/PolymerElements/paper-checkbox/archive/v1.4.0.tar.gz",
-      ],
-      strip_prefix = "paper-checkbox-1.4.0",
-      path = "/paper-checkbox",
-      srcs = ["paper-checkbox.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_checkbox"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_dialog",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "c6a9709e7f528d03dcd574503c18b72d4751ca30017346d16e6a791d37ed9259",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-dialog/archive/v1.0.4.tar.gz",
-          "https://github.com/PolymerElements/paper-dialog/archive/v1.0.4.tar.gz",
-      ],
-      strip_prefix = "paper-dialog-1.0.4",
-      path = "/paper-dialog",
-      srcs = ["paper-dialog.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_neon_animation",
-          "@org_polymer_paper_dialog_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_dialog"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_dialog_behavior",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "a7e0e27ce63554bc14f384cf94bcfa24da8dc5f5120dfd565f45e166261aee40",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-dialog-behavior/archive/v1.2.5.tar.gz",
-          "https://github.com/PolymerElements/paper-dialog-behavior/archive/v1.2.5.tar.gz",
-      ],
-      strip_prefix = "paper-dialog-behavior-1.2.5",
-      path = "/paper-dialog-behavior",
-      srcs = [
-          "paper-dialog-behavior.html",
-          "paper-dialog-common.css",
-          "paper-dialog-shared-styles.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_overlay_behavior",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_dialog_behavior"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_dialog_scrollable",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "a2e69283e7674f782c44d811387a0f8da2d01fac0172743d1add65e253e6b5ff",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-dialog-scrollable/archive/1.1.5.tar.gz",
-          "https://github.com/PolymerElements/paper-dialog-scrollable/archive/1.1.5.tar.gz",
-      ],
-      strip_prefix = "paper-dialog-scrollable-1.1.5",
-      path = "/paper-dialog-scrollable",
-      srcs = ["paper-dialog-scrollable.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_paper_dialog_behavior",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_dialog_scrollable"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_dropdown_menu",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "9d88f654ec03ee9be211df9e69bede9e8a22b51bf1dbcc63b79762e4256d81ad",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-dropdown-menu/archive/v1.4.0.tar.gz",
-          "https://github.com/PolymerElements/paper-dropdown-menu/archive/v1.4.0.tar.gz",
-      ],
-      strip_prefix = "paper-dropdown-menu-1.4.0",
-      path = "/paper-dropdown-menu",
-      srcs = [
-          "paper-dropdown-menu.html",
-          "paper-dropdown-menu-icons.html",
-          "paper-dropdown-menu-light.html",
-          "paper-dropdown-menu-shared-styles.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_form_element_behavior",
-          "@org_polymer_iron_icon",
-          "@org_polymer_iron_iconset_svg",
-          "@org_polymer_iron_validatable_behavior",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_input",
-          "@org_polymer_paper_menu_button",
-          "@org_polymer_paper_ripple",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_dropdown_menu"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_header_panel",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "0db4bd8a4bf6f20dcd0dffb4f907b31c93a8647c9c021344239cf30b40b87075",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-header-panel/archive/v1.1.4.tar.gz",
-          "https://github.com/PolymerElements/paper-header-panel/archive/v1.1.4.tar.gz",
-      ],
-      strip_prefix = "paper-header-panel-1.1.4",
-      path = "/paper-header-panel",
-      srcs = ["paper-header-panel.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_header_panel"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_icon_button",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "9cba5bcfd6aeb4c41581c1392c678cf2278d360e9d122f4d9db54a9ebb404496",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-icon-button/archive/v1.1.3.tar.gz",
-          "https://github.com/PolymerElements/paper-icon-button/archive/v1.1.3.tar.gz",
-      ],
-      strip_prefix = "paper-icon-button-1.1.3",
-      path = "/paper-icon-button",
-      srcs = [
-          "paper-icon-button.html",
-          "paper-icon-button-light.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_icon",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_icon_button"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_input",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "17c3dea9bb1c2026cc61324696c6c774214a0dc37686b91ca214a6af550994db",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-input/archive/v1.1.18.tar.gz",
-          "https://github.com/PolymerElements/paper-input/archive/v1.1.18.tar.gz",
-      ],
-      strip_prefix = "paper-input-1.1.18",
-      path = "/paper-input",
-      srcs = [
-          "paper-input.html",
-          "paper-input-addon-behavior.html",
-          "paper-input-behavior.html",
-          "paper-input-char-counter.html",
-          "paper-input-container.html",
-          "paper-input-error.html",
-          "paper-textarea.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_autogrow_textarea",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_form_element_behavior",
-          "@org_polymer_iron_input",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_input"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_item",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "12ee0dcb61b0d5721c5988571f6974d7b2211e97724f4195893fbcc9058cdac8",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-item/archive/v1.1.4.tar.gz",
-          "https://github.com/PolymerElements/paper-item/archive/v1.1.4.tar.gz",
-      ],
-      strip_prefix = "paper-item-1.1.4",
-      path = "/paper-item",
-      srcs = [
-          "paper-icon-item.html",
-          "paper-item.html",
-          "paper-item-behavior.html",
-          "paper-item-body.html",
-          "paper-item-shared-styles.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_item"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_listbox",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "3cb35f4fe9a3f15185a9e91711dba8f27e9291c8cd371ebf1be21b8f1d5f65fb",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-listbox/archive/v1.1.2.tar.gz",
-          "https://github.com/PolymerElements/paper-listbox/archive/v1.1.2.tar.gz",
-      ],
-      strip_prefix = "paper-listbox-1.1.2",
-      path = "/paper-listbox",
-      srcs = ["paper-listbox.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_menu_behavior",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_listbox"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_material",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "09f6c8bd6ddbea2be541dc86306efe41cdfb31bec0b69d35a5dc29772bbc8506",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-material/archive/v1.0.6.tar.gz",
-          "https://github.com/PolymerElements/paper-material/archive/v1.0.6.tar.gz",
-      ],
-      strip_prefix = "paper-material-1.0.6",
-      path = "/paper-material",
-      srcs = [
-          "paper-material.html",
-          "paper-material-shared-styles.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_material"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_menu",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "a3cee220926e315f7412236b3628288774694447c0da4428345f36d0f127ba3b",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-menu/archive/v1.2.2.tar.gz",
-          "https://github.com/PolymerElements/paper-menu/archive/v1.2.2.tar.gz",
-      ],
-      strip_prefix = "paper-menu-1.2.2",
-      path = "/paper-menu",
-      srcs = [
-          "paper-menu.html",
-          "paper-menu-shared-styles.html",
-          "paper-submenu.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_collapse",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_menu_behavior",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_menu"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_menu_button",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "be3290c288a2bd4f9887213db22c75add99cc29ff4d088100c0bc4eb0e57997b",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-menu-button/archive/v1.5.1.tar.gz",
-          "https://github.com/PolymerElements/paper-menu-button/archive/v1.5.1.tar.gz",
-      ],
-      strip_prefix = "paper-menu-button-1.5.1",
-      path = "/paper-menu-button",
-      srcs = [
-          "paper-menu-button.html",
-          "paper-menu-button-animations.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_dropdown",
-          "@org_polymer_neon_animation",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_menu_button"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_progress",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "2b6776b2f023c1f344feea17ba29b58d879e46f8ed43b7256495054b5183fff6",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-progress/archive/v1.0.9.tar.gz",
-          "https://github.com/PolymerElements/paper-progress/archive/v1.0.9.tar.gz",
-      ],
-      strip_prefix = "paper-progress-1.0.9",
-      path = "/paper-progress",
-      srcs = ["paper-progress.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_range_behavior",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_progress"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_radio_button",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "6e911d0c308aa388136b3af79d1bdcbe5a1f4159cbc79d71efb4ff3b6c0b4e91",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-radio-button/archive/v1.1.2.tar.gz",
-          "https://github.com/PolymerElements/paper-radio-button/archive/v1.1.2.tar.gz",
-      ],
-      strip_prefix = "paper-radio-button-1.1.2",
-      path = "/paper-radio-button",
-      srcs = ["paper-radio-button.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_radio_button"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_radio_group",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "7885ad1f81e9dcc03dcea4139b54a201ff55c18543770cd44f94530046c9e163",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-radio-group/archive/v1.0.9.tar.gz",
-          "https://github.com/PolymerElements/paper-radio-group/archive/v1.0.9.tar.gz",
-      ],
-      strip_prefix = "paper-radio-group-1.0.9",
-      path = "/paper-radio-group",
-      srcs = ["paper-radio-group.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_selector",
-          "@org_polymer_paper_radio_button",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_radio_group"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_ripple",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "ba76bfb1c737260a8a103d3ca97faa1f7c3288c7db9b2519f401b7a782147c09",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-ripple/archive/v1.0.5.tar.gz",
-          "https://github.com/PolymerElements/paper-ripple/archive/v1.0.5.tar.gz",
-      ],
-      strip_prefix = "paper-ripple-1.0.5",
-      path = "/paper-ripple",
-      srcs = ["paper-ripple.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_ripple"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_slider",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "08e7c541dbf5d2e959208810bfc03188e82ced87e4d30d325172967f67962c3c",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-slider/archive/v1.0.10.tar.gz",
-          "https://github.com/PolymerElements/paper-slider/archive/v1.0.10.tar.gz",
-      ],
-      strip_prefix = "paper-slider-1.0.10",
-      path = "/paper-slider",
-      srcs = ["paper-slider.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_keys_behavior",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_form_element_behavior",
-          "@org_polymer_iron_range_behavior",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_input",
-          "@org_polymer_paper_progress",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_slider"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_spinner",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "6a752907fab7899cbeed15b478e7b9299047c15fbf9d1561d6eb4d204bdbd178",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-spinner/archive/v1.1.1.tar.gz",
-          "https://github.com/PolymerElements/paper-spinner/archive/v1.1.1.tar.gz",
-      ],
-      strip_prefix = "paper-spinner-1.1.1",
-      path = "/paper-spinner",
-      srcs = [
-          "paper-spinner.html", "paper-spinner-behavior.html",
-          "paper-spinner-lite.html", "paper-spinner-styles.html"
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_spinner"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_styles",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "6d26b0a4c286402098853dc7388f6b22f30dfb7a74e47b34992ac03380144bb2",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-styles/archive/v1.1.4.tar.gz",
-          "https://github.com/PolymerElements/paper-styles/archive/v1.1.4.tar.gz",
-      ],
-      strip_prefix = "paper-styles-1.1.4",
-      path = "/paper-styles",
-      srcs = [
-          "classes/global.html",
-          "classes/shadow.html",
-          "classes/shadow-layout.html",
-          "classes/typography.html",
-          "color.html",
-          "default-theme.html",
-          "demo.css",
-          "demo-pages.html",
-          "paper-styles.html",
-          "paper-styles-classes.html",
-          "shadow.html",
-          "typography.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_font_roboto",
-          "@org_polymer_iron_flex_layout",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_styles"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_tabs",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "c23b6a5221db35e5b1ed3eb8e8696b952572563e285adaec96aba1e3134db825",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-tabs/archive/v1.7.0.tar.gz",
-          "https://github.com/PolymerElements/paper-tabs/archive/v1.7.0.tar.gz",
-      ],
-      strip_prefix = "paper-tabs-1.7.0",
-      path = "/paper-tabs",
-      srcs = [
-          "paper-tab.html",
-          "paper-tabs.html",
-          "paper-tabs-icons.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_behaviors",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_iron_icon",
-          "@org_polymer_iron_iconset_svg",
-          "@org_polymer_iron_menu_behavior",
-          "@org_polymer_iron_resizable_behavior",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_icon_button",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_tabs"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_toast",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "55f623712ed1f2bae6d6fadc522a2458e083ccd44cc0a907672547e7b10758a9",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-toast/archive/v1.3.0.tar.gz",
-          "https://github.com/PolymerElements/paper-toast/archive/v1.3.0.tar.gz",
-      ],
-      strip_prefix = "paper-toast-1.3.0",
-      path = "/paper-toast",
-      srcs = ["paper-toast.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_a11y_announcer",
-          "@org_polymer_iron_overlay_behavior",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_toast"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_toggle_button",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "4aa7cf0396fa2994a8bc2ac6e8428f48b07b945bb7c41bd52041ef5827b45de3",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-toggle-button/archive/v1.2.0.tar.gz",
-          "https://github.com/PolymerElements/paper-toggle-button/archive/v1.2.0.tar.gz",
-      ],
-      strip_prefix = "paper-toggle-button-1.2.0",
-      path = "/paper-toggle-button",
-      srcs = ["paper-toggle-button.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_paper_behaviors",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_toggle_button"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_toolbar",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "dbddffc0654d9fb5fb48843087eebe16bf7a134902495a664c96c11bf8a2c63d",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-toolbar/archive/v1.1.4.tar.gz",
-          "https://github.com/PolymerElements/paper-toolbar/archive/v1.1.4.tar.gz",
-      ],
-      strip_prefix = "paper-toolbar-1.1.4",
-      path = "/paper-toolbar",
-      srcs = ["paper-toolbar.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_iron_flex_layout",
-          "@org_polymer_paper_styles",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_toolbar"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_paper_tooltip",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "4c6667acf01f73da14c3cbc0aa574bf14280304567987ee0314534328377d2ad",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/paper-tooltip/archive/v1.1.2.tar.gz",
-          "https://github.com/PolymerElements/paper-tooltip/archive/v1.1.2.tar.gz",
-      ],
-      strip_prefix = "paper-tooltip-1.1.2",
-      path = "/paper-tooltip",
-      srcs = ["paper-tooltip.html"],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_neon_animation",
-      ],
+      path = "tensorflow_third_party/org_polymer_paper_tooltip"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "07a9e62ffb52193da3af09adda2fbac5cc690439978520e2d03e783863f65f91",
-      strip_prefix = "polymer-1.7.0",
-      urls = [
-          "http://mirror.bazel.build/github.com/polymer/polymer/archive/v1.7.0.tar.gz",
-          "https://github.com/polymer/polymer/archive/v1.7.0.tar.gz",
-      ],
-      path = "/polymer",
-      srcs = [
-          "polymer.html",
-          "polymer-micro.html",
-          "polymer-mini.html",
-      ],
+      path = "tensorflow_third_party/org_polymer"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_prism",
-      licenses = ["notice"],  # MIT
-      sha256 = "e06eb54f2a80e6b3cd0bd4d59f900423bcaee53fc03998a056df63740c684683",
-      urls = [
-          "http://mirror.bazel.build/github.com/PrismJS/prism/archive/abee2b7587f1925e57777044270e2a1860810994.tar.gz",
-          "https://github.com/PrismJS/prism/archive/abee2b7587f1925e57777044270e2a1860810994.tar.gz",
-      ],
-      strip_prefix = "prism-abee2b7587f1925e57777044270e2a1860810994",
-      path = "/prism",
-      srcs = [
-          "prism.js",
-          "themes/prism.css",
-      ],
+      path = "tensorflow_third_party/org_polymer_prism"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_prism_element",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "ad70bf9cd5bbdf525d465e1b0658867ab4022193eb9c74087a839044b46312b4",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/prism-element/archive/1.0.4.tar.gz",
-          "https://github.com/PolymerElements/prism-element/archive/1.0.4.tar.gz",
-      ],
-      strip_prefix = "prism-element-1.0.4",
-      path = "/prism-element",
-      srcs = [
-          "prism-highlighter.html",
-          "prism-import.html",
-      ],
-      deps = [
-          "@org_polymer",
-          "@org_polymer_prism",
-      ],
+      path = "tensorflow_third_party/org_polymer_prism_element"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_promise_polyfill",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "4495450e5d884c3e16b537b43afead7f84d17c7dc061bcfcbf440eac083e4ef5",
-      strip_prefix = "promise-polyfill-1.0.0",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerLabs/promise-polyfill/archive/v1.0.0.tar.gz",
-          "https://github.com/PolymerLabs/promise-polyfill/archive/v1.0.0.tar.gz",
-      ],
-      path = "/promise-polyfill",
-      srcs = [
-          "Promise.js",
-          "Promise-Statics.js",
-          "promise-polyfill.html",
-          "promise-polyfill-lite.html"
-      ],
-      deps = ["@org_polymer"],
+      path = "tensorflow_third_party/org_polymer_promise_polyfill"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_web_animations_js",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "f8bd760cbdeba131f6790bd5abe170bcbf7b1755ff58ed16d0b82fa8a7f34a7f",
-      urls = [
-          "http://mirror.bazel.build/github.com/web-animations/web-animations-js/archive/2.2.1.tar.gz",
-          "https://github.com/web-animations/web-animations-js/archive/2.2.1.tar.gz",
-      ],
-      strip_prefix = "web-animations-js-2.2.1",
-      path = "/web-animations-js",
-      srcs = ["web-animations-next-lite.min.js"],
+      path = "tensorflow_third_party/org_polymer_web_animations_js"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_webcomponentsjs",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "138c43306ee0a6d699ddca9b3c6b0f4982974ea8b7bdad291ea7276c72301df9",
-      urls = [
-          "http://mirror.bazel.build/github.com/webcomponents/webcomponentsjs/archive/v0.7.22.tar.gz",
-          "https://github.com/webcomponents/webcomponentsjs/archive/v0.7.22.tar.gz",
-      ],
-      strip_prefix = "webcomponentsjs-0.7.22",
-      path = "/webcomponentsjs",
-      srcs = [
-          "CustomElements.js",
-          "CustomElements.min.js",
-          "HTMLImports.js",
-          "HTMLImports.min.js",
-          "MutationObserver.js",
-          "MutationObserver.min.js",
-          "ShadowDOM.js",
-          "ShadowDOM.min.js",
-          "webcomponents.js",
-          "webcomponents.min.js",
-          "webcomponents-lite.js",
-          "webcomponents-lite.min.js",
-      ],
+      path = "tensorflow_third_party/org_polymer_webcomponentsjs"
   )
 
-  ##############################################################################
-  # TensorBoard Testing Dependencies
-
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_accessibility_developer_tools",
-      licenses = ["notice"],  # Apache License 2.0
-      sha256 = "1d6a72f401c9d53f68238c617dd43a05cd85ca5aa2e676a5b3c352711448e093",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/accessibility-developer-tools/-/accessibility-developer-tools-2.10.0.tgz",
-          "https://registry.npmjs.org/accessibility-developer-tools/-/accessibility-developer-tools-2.10.0.tgz",
-      ],
-      strip_prefix = "package",
-      path = "/accessibility-developer-tools",
-      suppress = ["strictDependencies"],
+      path = "tensorflow_third_party/org_npmjs_registry_accessibility_developer_tools"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_async",
-      licenses = ["notice"],  # MIT
-      sha256 = "08655255ae810bf4d1cb1642df57658fcce823776d3ba8f4b46f4bbff6c87ece",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/async/-/async-1.5.0.tgz",
-          "https://registry.npmjs.org/async/-/async-1.5.0.tgz",
-      ],
-      strip_prefix = "package",
-      path = "/async",
+      path = "tensorflow_third_party/org_npmjs_registry_async"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_chai",
-      licenses = ["notice"],  # MIT
-      sha256 = "aca8137bed5bb295bd7173325b7ad604cd2aeb341d739232b4f9f0b26745be90",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/chai/-/chai-3.5.0.tgz",
-          "https://registry.npmjs.org/chai/-/chai-3.5.0.tgz",
-      ],
-      strip_prefix = "package",
-      path = "/chai",
+      path = "tensorflow_third_party/org_npmjs_registry_chai"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_mocha",
-      licenses = ["notice"],  # MIT
-      sha256 = "13ef37a071196a2fba680799b906555d3f0ab61e80a7e8f73f93e77914590dd4",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/mocha/-/mocha-2.5.3.tgz",
-          "https://registry.npmjs.org/mocha/-/mocha-2.5.3.tgz",
-      ],
-      suppress = ["strictDependencies"],
-      strip_prefix = "package",
-      path = "/mocha",
+      path = "tensorflow_third_party/org_npmjs_registry_mocha"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_sinon",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "49edb057695fc9019aae992bf7e677a07de7c6ce2bf9f9facde4a245045d1532",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/sinon/-/sinon-1.17.4.tgz",
-          "https://registry.npmjs.org/sinon/-/sinon-1.17.4.tgz",
-      ],
-      strip_prefix = "package/lib",
-      path = "/sinonjs",
+      path = "tensorflow_third_party/org_npmjs_registry_sinon"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_sinon_chai",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "b85fc56f713832960b56fe9269ee4bb2cd41edd2ceb130b0936e5bdbed5dea63",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/sinon-chai/-/sinon-chai-2.8.0.tgz",
-          "https://registry.npmjs.org/sinon-chai/-/sinon-chai-2.8.0.tgz",
-      ],
-      strip_prefix = "package",
-      path = "/sinon-chai",
+      path = "tensorflow_third_party/org_npmjs_registry_sinon_chai"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_stacky",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "c659e60f7957d9d80c23a7aacc4d71b19c6421a08f91174c0062de369595acae",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/stacky/-/stacky-1.3.1.tgz",
-          "https://registry.npmjs.org/stacky/-/stacky-1.3.1.tgz",
-      ],
-      strip_prefix = "package",
-      path = "/stacky",
+      path = "tensorflow_third_party/org_npmjs_registry_stacky"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_npmjs_registry_web_component_tester",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "9d4ebd4945df8a936916d4d32b7f280f2a3afa35f79e7ca8ad3ed0a42770c537",
-      urls = [
-          "http://mirror.bazel.build/registry.npmjs.org/web-component-tester/-/web-component-tester-4.3.6.tgz",
-          "https://registry.npmjs.org/web-component-tester/-/web-component-tester-4.3.6.tgz",
-      ],
-      strip_prefix = "package",
-      path = "/web-component-tester",
-      suppress = [
-          "absolutePaths",
-          "strictDependencies",
-      ],
-      deps = [
-          "@com_lodash",
-          "@org_npmjs_registry_accessibility_developer_tools",
-          "@org_npmjs_registry_async",
-          "@org_npmjs_registry_chai",
-          "@org_npmjs_registry_mocha",
-          "@org_npmjs_registry_sinon",
-          "@org_npmjs_registry_sinon_chai",
-          "@org_npmjs_registry_stacky",
-          "@org_polymer_test_fixture",
-      ],
+      path = "tensorflow_third_party/org_npmjs_registry_web_component_tester"
   )
 
-  web_library_external(
+  native.local_repository(
       name = "org_polymer_test_fixture",
-      licenses = ["notice"],  # BSD-3-Clause
-      sha256 = "59d6cfb1187733b71275becfea181fe0aa1f734df5ff77f5850c806bbbf9a0d9",
-      strip_prefix = "test-fixture-2.0.1",
-      urls = [
-          "http://mirror.bazel.build/github.com/PolymerElements/test-fixture/archive/v2.0.1.tar.gz",
-          "https://github.com/PolymerElements/test-fixture/archive/v2.0.1.tar.gz",
-      ],
-      path = "/test-fixture",
-      exclude = ["test/**"],
+      path = "tensorflow_third_party/org_polymer_test_fixture"
+  )
+
+  native.bind(
+      name = "xsmm_avx",
+      actual = "@libxsmm_archive//third_party:xsmm_avx",
+  )
+
+  native.bind(
+      name = "farmhash",
+      actual = "@farmhash//:farmhash",
+  )
+
+  native.bind(
+      name = "six",
+      actual = "@six_archive//:six",
+  )
+
+  native.bind(
+      name = "gtest",
+      actual = "@gmock_archive//:gtest",
+  )
+
+  native.bind(
+      name = "gtest_main",
+      actual = "@gmock_archive//:gtest_main",
+  )
+
+  native.bind(
+      name = "python_headers",
+      actual = str(Label("//util/python:python_headers")),
+  )
+
+  native.bind(
+      name = "protobuf_clib",
+      actual = "@protobuf//:protoc_lib",
+  )
+
+  native.bind(
+      name = "protobuf_compiler",
+      actual = "@protobuf//:protoc_lib",
+  )
+
+  native.bind(
+      name = "grpc_cpp_plugin",
+      actual = "@grpc//:grpc_cpp_plugin",
+  )
+
+  native.bind(
+      name = "grpc_lib",
+      actual = "@grpc//:grpc++_unsecure",
+  )
+
+  native.bind(
+      name = "jsoncpp",
+      actual = "@jsoncpp_git//:jsoncpp",
+  )
+
+  native.bind(
+      name = "nanopb",
+      actual = "@nanopb_git//:nanopb",
+  )
+
+  native.bind(
+      name = "zlib",
+      actual = "@zlib_archive//:zlib",
   )
