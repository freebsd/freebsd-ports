# -*- encoding: utf-8 -*-
# stub: grpc 1.4.0 ruby src/ruby/lib# stub: src/ruby/ext/grpc/extconf.rb

Gem::Specification.new do |s|
  s.name = "grpc".freeze
  s.version = "1.4.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0".freeze) if s.respond_to? :required_rubygems_version=
  s.require_paths = ["src/ruby/lib".freeze, "src/ruby/bin".freeze, "src/ruby/pb".freeze]
  s.authors = ["gRPC Authors".freeze]
  s.bindir = "src/ruby/bin".freeze
  s.date = "2017-06-21"
  s.description = "Send RPCs from Ruby using GRPC".freeze
  s.email = "temiola@google.com".freeze
  s.extensions = ["src/ruby/ext/grpc/extconf.rb".freeze]
  s.files = ["src/ruby/bin/apis/google/protobuf/empty.rb".freeze, "src/ruby/bin/apis/pubsub_demo.rb".freeze, "src/ruby/bin/apis/tech/pubsub/proto/pubsub.rb".freeze, "src/ruby/bin/apis/tech/pubsub/proto/pubsub_services.rb".freeze, "src/ruby/bin/math_client.rb".freeze, "src/ruby/bin/math_pb.rb".freeze, "src/ruby/bin/math_server.rb".freeze, "src/ruby/bin/math_services_pb.rb".freeze, "src/ruby/bin/noproto_client.rb".freeze, "src/ruby/bin/noproto_server.rb".freeze, "src/ruby/ext/grpc/extconf.rb".freeze, "src/ruby/ext/grpc/rb_byte_buffer.c".freeze, "src/ruby/ext/grpc/rb_byte_buffer.h".freeze, "src/ruby/ext/grpc/rb_call.c".freeze, "src/ruby/ext/grpc/rb_call.h".freeze, "src/ruby/ext/grpc/rb_call_credentials.c".freeze, "src/ruby/ext/grpc/rb_call_credentials.h".freeze, "src/ruby/ext/grpc/rb_channel.c".freeze, "src/ruby/ext/grpc/rb_channel.h".freeze, "src/ruby/ext/grpc/rb_channel_args.c".freeze, "src/ruby/ext/grpc/rb_channel_args.h".freeze, "src/ruby/ext/grpc/rb_channel_credentials.c".freeze, "src/ruby/ext/grpc/rb_channel_credentials.h".freeze, "src/ruby/ext/grpc/rb_completion_queue.c".freeze, "src/ruby/ext/grpc/rb_completion_queue.h".freeze, "src/ruby/ext/grpc/rb_compression_options.c".freeze, "src/ruby/ext/grpc/rb_compression_options.h".freeze, "src/ruby/ext/grpc/rb_event_thread.c".freeze, "src/ruby/ext/grpc/rb_event_thread.h".freeze, "src/ruby/ext/grpc/rb_grpc.c".freeze, "src/ruby/ext/grpc/rb_grpc.h".freeze, "src/ruby/ext/grpc/rb_grpc_imports.generated.c".freeze, "src/ruby/ext/grpc/rb_grpc_imports.generated.h".freeze, "src/ruby/ext/grpc/rb_loader.c".freeze, "src/ruby/ext/grpc/rb_loader.h".freeze, "src/ruby/ext/grpc/rb_server.c".freeze, "src/ruby/ext/grpc/rb_server.h".freeze, "src/ruby/ext/grpc/rb_server_credentials.c".freeze, "src/ruby/ext/grpc/rb_server_credentials.h".freeze, "src/ruby/lib/grpc.rb".freeze, "src/ruby/lib/grpc/core/time_consts.rb".freeze, "src/ruby/lib/grpc/errors.rb".freeze, "src/ruby/lib/grpc/generic/active_call.rb".freeze, "src/ruby/lib/grpc/generic/bidi_call.rb".freeze, "src/ruby/lib/grpc/generic/client_stub.rb".freeze, "src/ruby/lib/grpc/generic/rpc_desc.rb".freeze, "src/ruby/lib/grpc/generic/rpc_server.rb".freeze, "src/ruby/lib/grpc/generic/service.rb".freeze, "src/ruby/lib/grpc/grpc.rb".freeze, "src/ruby/lib/grpc/logconfig.rb".freeze, "src/ruby/lib/grpc/notifier.rb".freeze, "src/ruby/lib/grpc/version.rb".freeze, "src/ruby/pb/README.md".freeze, "src/ruby/pb/generate_proto_ruby.sh".freeze, "src/ruby/pb/grpc/health/checker.rb".freeze, "src/ruby/pb/grpc/health/v1/health_pb.rb".freeze, "src/ruby/pb/grpc/health/v1/health_services_pb.rb".freeze, "src/ruby/pb/grpc/testing/duplicate/echo_duplicate_services_pb.rb".freeze, "src/ruby/pb/grpc/testing/metrics_pb.rb".freeze, "src/ruby/pb/grpc/testing/metrics_services_pb.rb".freeze, "src/ruby/pb/src/proto/grpc/testing/empty_pb.rb".freeze, "src/ruby/pb/src/proto/grpc/testing/messages_pb.rb".freeze, "src/ruby/pb/src/proto/grpc/testing/test_pb.rb".freeze, "src/ruby/pb/src/proto/grpc/testing/test_services_pb.rb".freeze, "src/ruby/pb/test/client.rb".freeze, "src/ruby/pb/test/server.rb".freeze, "src/ruby/spec/call_credentials_spec.rb".freeze, "src/ruby/spec/call_spec.rb".freeze, "src/ruby/spec/channel_connection_spec.rb".freeze, "src/ruby/spec/channel_credentials_spec.rb".freeze, "src/ruby/spec/channel_spec.rb".freeze, "src/ruby/spec/client_server_spec.rb".freeze, "src/ruby/spec/compression_options_spec.rb".freeze, "src/ruby/spec/error_sanity_spec.rb".freeze, "src/ruby/spec/generic/active_call_spec.rb".freeze, "src/ruby/spec/generic/client_stub_spec.rb".freeze, "src/ruby/spec/generic/rpc_desc_spec.rb".freeze, "src/ruby/spec/generic/rpc_server_pool_spec.rb".freeze, "src/ruby/spec/generic/rpc_server_spec.rb".freeze, "src/ruby/spec/generic/service_spec.rb".freeze, "src/ruby/spec/pb/duplicate/codegen_spec.rb".freeze, "src/ruby/spec/pb/health/checker_spec.rb".freeze, "src/ruby/spec/server_credentials_spec.rb".freeze, "src/ruby/spec/server_spec.rb".freeze, "src/ruby/spec/spec_helper.rb".freeze, "src/ruby/spec/testdata/README".freeze, "src/ruby/spec/testdata/ca.pem".freeze, "src/ruby/spec/testdata/server1.key".freeze, "src/ruby/spec/testdata/server1.pem".freeze, "src/ruby/spec/time_consts_spec.rb".freeze]
  s.homepage = "https://github.com/google/grpc/tree/master/src/ruby".freeze
  s.licenses = ["BSD-3-Clause".freeze]
  s.required_ruby_version = Gem::Requirement.new(">= 2.0.0".freeze)
  s.rubygems_version = "2.6.12".freeze
  s.summary = "GRPC system in Ruby".freeze
  s.test_files = ["src/ruby/spec/server_spec.rb".freeze, "src/ruby/spec/channel_spec.rb".freeze, "src/ruby/spec/testdata/README".freeze, "src/ruby/spec/testdata/ca.pem".freeze, "src/ruby/spec/testdata/server1.key".freeze, "src/ruby/spec/testdata/server1.pem".freeze, "src/ruby/spec/time_consts_spec.rb".freeze, "src/ruby/spec/channel_connection_spec.rb".freeze, "src/ruby/spec/call_spec.rb".freeze, "src/ruby/spec/generic/rpc_server_spec.rb".freeze, "src/ruby/spec/generic/rpc_desc_spec.rb".freeze, "src/ruby/spec/generic/active_call_spec.rb".freeze, "src/ruby/spec/generic/client_stub_spec.rb".freeze, "src/ruby/spec/generic/rpc_server_pool_spec.rb".freeze, "src/ruby/spec/generic/service_spec.rb".freeze, "src/ruby/spec/pb/duplicate/codegen_spec.rb".freeze, "src/ruby/spec/pb/health/checker_spec.rb".freeze, "src/ruby/spec/client_server_spec.rb".freeze, "src/ruby/spec/compression_options_spec.rb".freeze, "src/ruby/spec/server_credentials_spec.rb".freeze, "src/ruby/spec/spec_helper.rb".freeze, "src/ruby/spec/error_sanity_spec.rb".freeze, "src/ruby/spec/channel_credentials_spec.rb".freeze, "src/ruby/spec/call_credentials_spec.rb".freeze]

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<google-protobuf>.freeze, ["~> 3.1"])
      s.add_runtime_dependency(%q<googleauth>.freeze, ["~> 0.5.1"])
      s.add_development_dependency(%q<bundler>.freeze, ["~> 1.9"])
      s.add_development_dependency(%q<facter>.freeze, ["~> 2.4"])
      s.add_development_dependency(%q<logging>.freeze, ["~> 2.0"])
      s.add_development_dependency(%q<simplecov>.freeze, ["~> 0.9"])
      s.add_development_dependency(%q<rake>.freeze, ["~> 10.4"])
      s.add_development_dependency(%q<rake-compiler>.freeze, ["~> 1.0"])
      s.add_development_dependency(%q<rake-compiler-dock>.freeze, ["~> 0.5.1"])
      s.add_development_dependency(%q<rspec>.freeze, ["~> 3.2"])
      s.add_development_dependency(%q<rubocop>.freeze, ["~> 0.30.0"])
      s.add_development_dependency(%q<signet>.freeze, ["~> 0.7.0"])
    else
      s.add_dependency(%q<google-protobuf>.freeze, ["~> 3.1"])
      s.add_dependency(%q<googleauth>.freeze, ["~> 0.5.1"])
      s.add_dependency(%q<bundler>.freeze, ["~> 1.9"])
      s.add_dependency(%q<facter>.freeze, ["~> 2.4"])
      s.add_dependency(%q<logging>.freeze, ["~> 2.0"])
      s.add_dependency(%q<simplecov>.freeze, ["~> 0.9"])
      s.add_dependency(%q<rake>.freeze, ["~> 10.4"])
      s.add_dependency(%q<rake-compiler>.freeze, ["~> 1.0"])
      s.add_dependency(%q<rake-compiler-dock>.freeze, ["~> 0.5.1"])
      s.add_dependency(%q<rspec>.freeze, ["~> 3.2"])
      s.add_dependency(%q<rubocop>.freeze, ["~> 0.30.0"])
      s.add_dependency(%q<signet>.freeze, ["~> 0.7.0"])
    end
  else
    s.add_dependency(%q<google-protobuf>.freeze, ["~> 3.1"])
    s.add_dependency(%q<googleauth>.freeze, ["~> 0.5.1"])
    s.add_dependency(%q<bundler>.freeze, ["~> 1.9"])
    s.add_dependency(%q<facter>.freeze, ["~> 2.4"])
    s.add_dependency(%q<logging>.freeze, ["~> 2.0"])
    s.add_dependency(%q<simplecov>.freeze, ["~> 0.9"])
    s.add_dependency(%q<rake>.freeze, ["~> 10.4"])
    s.add_dependency(%q<rake-compiler>.freeze, ["~> 1.0"])
    s.add_dependency(%q<rake-compiler-dock>.freeze, ["~> 0.5.1"])
    s.add_dependency(%q<rspec>.freeze, ["~> 3.2"])
    s.add_dependency(%q<rubocop>.freeze, ["~> 0.30.0"])
    s.add_dependency(%q<signet>.freeze, ["~> 0.7.0"])
  end
end

