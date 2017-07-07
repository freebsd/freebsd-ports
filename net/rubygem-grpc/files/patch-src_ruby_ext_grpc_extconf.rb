--- src/ruby/ext/grpc/extconf.rb.orig	2017-06-28 17:25:39 UTC
+++ src/ruby/ext/grpc/extconf.rb
@@ -70,9 +70,9 @@ ENV['LD'] = ENV['CC']
 
 ENV['AR'] = 'libtool -o' if RUBY_PLATFORM =~ /darwin/
 
-ENV['EMBED_OPENSSL'] = 'true'
-ENV['EMBED_ZLIB'] = 'true'
-ENV['EMBED_CARES'] = 'true'
+ENV['EMBED_OPENSSL'] = 'false'
+ENV['EMBED_ZLIB'] = 'false'
+ENV['EMBED_CARES'] = 'false'
 ENV['ARCH_FLAGS'] = RbConfig::CONFIG['ARCH_FLAG']
 ENV['ARCH_FLAGS'] = '-arch i386 -arch x86_64' if RUBY_PLATFORM =~ /darwin/
 ENV['CFLAGS'] = '-DGPR_BACKWARDS_COMPATIBILITY_MODE'
@@ -81,16 +81,16 @@ output_dir = File.expand_path(RbConfig::CONFIG['topdir
 grpc_lib_dir = File.join(output_dir, 'libs', grpc_config)
 ENV['BUILDDIR'] = output_dir
 
-unless windows
-  puts 'Building internal gRPC into ' + grpc_lib_dir
-  nproc = 4
-  nproc = Etc.nprocessors * 2 if Etc.respond_to? :nprocessors
-  system("make -j#{nproc} -C #{grpc_root} #{grpc_lib_dir}/libgrpc.a CONFIG=#{grpc_config} Q=")
-  exit 1 unless $? == 0
-end
+#unless windows
+#  puts 'Building internal gRPC into ' + grpc_lib_dir
+#  puts("gmake -C #{grpc_root} #{grpc_lib_dir}/libgrpc.a CONFIG=#{grpc_config} Q=")
+#  system("gmake -C #{grpc_root} #{grpc_lib_dir}/libgrpc.a CONFIG=#{grpc_config} Q=")
+#  exit 1 unless $? == 0
+#end
 
-$CFLAGS << ' -I' + File.join(grpc_root, 'include')
-$LDFLAGS << ' ' + File.join(grpc_lib_dir, 'libgrpc.a') unless windows
+#$CFLAGS << ' -I' + File.join(grpc_root, 'include')
+#$LDFLAGS << ' ' + File.join(grpc_lib_dir, 'libgrpc.a') unless windows
+$LDFLAGS << ' -lgrpc' unless windows
 if grpc_config == 'gcov'
   $CFLAGS << ' -O0 -fprofile-arcs -ftest-coverage'
   $LDFLAGS << ' -fprofile-arcs -ftest-coverage -rdynamic'
