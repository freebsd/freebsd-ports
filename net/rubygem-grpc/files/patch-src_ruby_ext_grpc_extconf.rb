--- src/ruby/ext/grpc/extconf.rb.orig	2022-07-30 16:45:00 UTC
+++ src/ruby/ext/grpc/extconf.rb
@@ -68,11 +68,11 @@ if apple_toolchain && !cross_compiling
 end
 
 # Don't embed on TruffleRuby (constant-time crypto is unsafe with Sulong, slow build times)
-ENV['EMBED_OPENSSL'] = (RUBY_ENGINE != 'truffleruby').to_s
+ENV['EMBED_OPENSSL'] = 'false'
 # Don't embed on TruffleRuby (the system zlib is already linked for the zlib C extension, slow build times)
-ENV['EMBED_ZLIB'] = (RUBY_ENGINE != 'truffleruby').to_s
+ENV['EMBED_ZLIB'] = 'false'
 
-ENV['EMBED_CARES'] = 'true'
+ENV['EMBED_CARES'] = 'false'
 
 ENV['ARCH_FLAGS'] = RbConfig::CONFIG['ARCH_FLAG']
 if apple_toolchain && !cross_compiling
@@ -93,30 +93,10 @@ output_dir = File.expand_path(RbConfig::CONFIG['topdir
 grpc_lib_dir = File.join(output_dir, 'libs', grpc_config)
 ENV['BUILDDIR'] = output_dir
 
-unless windows
-  puts 'Building internal gRPC into ' + grpc_lib_dir
-  nproc = 4
-  nproc = Etc.nprocessors if Etc.respond_to? :nprocessors
-  nproc_override = ENV['GRPC_RUBY_BUILD_PROCS']
-  unless nproc_override.nil? or nproc_override.size == 0
-    nproc = nproc_override
-    puts "Overriding make parallelism to #{nproc}"
-  end
-  make = bsd ? 'gmake' : 'make'
-  cmd = "#{make} -j#{nproc} -C #{grpc_root} #{grpc_lib_dir}/libgrpc.a CONFIG=#{grpc_config} Q="
-  puts "Building grpc native library: #{cmd}"
-  system(cmd)
-  exit 1 unless $? == 0
-end
-
-$CFLAGS << ' -I' + File.join(grpc_root, 'include')
-
 ext_export_file = File.join(grpc_root, 'src', 'ruby', 'ext', 'grpc', 'ext-export')
 ext_export_file += '-truffleruby' if RUBY_ENGINE == 'truffleruby'
-$LDFLAGS << ' -Wl,--version-script="' + ext_export_file + '.gcc"' if linux
-$LDFLAGS << ' -Wl,-exported_symbols_list,"' + ext_export_file + '.clang"' if apple_toolchain
 
-$LDFLAGS << ' ' + File.join(grpc_lib_dir, 'libgrpc.a') unless windows
+$LDFLAGS << ' -lgrpc' unless windows
 if grpc_config == 'gcov'
   $CFLAGS << ' -O0 -fprofile-arcs -ftest-coverage'
   $LDFLAGS << ' -fprofile-arcs -ftest-coverage -rdynamic'
