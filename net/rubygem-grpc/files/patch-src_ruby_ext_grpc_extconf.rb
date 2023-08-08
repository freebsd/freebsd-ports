--- src/ruby/ext/grpc/extconf.rb.orig	2023-02-26 18:56:37 UTC
+++ src/ruby/ext/grpc/extconf.rb
@@ -69,11 +69,11 @@ if apple_toolchain && !cross_compiling
 end
 
 # Don't embed on TruffleRuby (constant-time crypto is unsafe with Sulong, slow build times)
-ENV['EMBED_OPENSSL'] = (RUBY_ENGINE != 'truffleruby').to_s
+ENV['EMBED_OPENSSL'] =  'false'
 # Don't embed on TruffleRuby (the system zlib is already linked for the zlib C extension, slow build times)
-ENV['EMBED_ZLIB'] = (RUBY_ENGINE != 'truffleruby').to_s
+ENV['EMBED_ZLIB'] = 'false'
 
-ENV['EMBED_CARES'] = 'true'
+ENV['EMBED_CARES'] = 'false'
 
 ENV['ARCH_FLAGS'] = RbConfig::CONFIG['ARCH_FLAG']
 if apple_toolchain && !cross_compiling
@@ -94,25 +94,6 @@ output_dir = File.expand_path(RbConfig::CONFIG['topdir
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
-$CFLAGS << ' -DGRPC_RUBY_WINDOWS_UCRT' if windows_ucrt
-$CFLAGS << ' -I' + File.join(grpc_root, 'include')
-
 def have_ruby_abi_version()
   return true if RUBY_ENGINE == 'truffleruby'
   # ruby_abi_version is only available in development versions: https://github.com/ruby/ruby/pull/6231
@@ -141,10 +122,8 @@ def ext_export_filename()
 end
 
 ext_export_file = File.join(grpc_root, 'src', 'ruby', 'ext', 'grpc', ext_export_filename())
-$LDFLAGS << ' -Wl,--version-script="' + ext_export_file + '.gcc"' if linux
-$LDFLAGS << ' -Wl,-exported_symbols_list,"' + ext_export_file + '.clang"' if apple_toolchain
 
-$LDFLAGS << ' ' + File.join(grpc_lib_dir, 'libgrpc.a') unless windows
+$LDFLAGS << ' -lgrpc' unless windows
 if grpc_config == 'gcov'
   $CFLAGS << ' -O0 -fprofile-arcs -ftest-coverage'
   $LDFLAGS << ' -fprofile-arcs -ftest-coverage -rdynamic'
