PORTNAME=	pomerium-envoy-custom
DISTVERSIONPREFIX=	v
DISTVERSION=	1.36.5-p1
CATEGORIES=	www
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Pomerium's custom Envoy build for use with pomerium
WWW=		https://pomerium.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ENVOY_SRC_COMMIT=	41749943780b54b70b510b1b1a4805ae529e174a
ENVOY_API_COMMIT=	f8b75d1efa92bbf534596a013d9ca5873f79dd30

USES=		cmake:indirect compiler:c++20-lang gmake go:no_targets java \
		ninja:build python:build

BUILD_DEPENDS=	${LOCALBASE}/bin/buf:devel/buf \
		${LOCALBASE}/bin/yq:textproc/go-yq \
		${LOCALBASE}/include/fmt/format.h:devel/libfmt \
		${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json \
		${LOCALBASE}/include/spdlog/spdlog.h:devel/spdlog \
		${LOCALBASE}/include/tclap/CmdLine.h:devel/tclap12 \
		${LOCALBASE}/include/flatbuffers/flatbuffers.h:devel/flatbuffers \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${UNZIP_CMD}:archivers/unzip \
		autoconf>=2.71:devel/autoconf \
		automake>=1.16:devel/automake \
		bash:shells/bash \
		bazel:devel/bazel7 \
		git:devel/git \
		m4:devel/m4 \
		zip:archivers/zip

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libmaxminddb.so:net/libmaxminddb \
		libnghttp2.so:www/libnghttp2 \
		libre2.so:devel/re2 \
		libxxhash.so:devel/xxhash \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

JAVA_VERSION=	21
ZLIBBASE=	${LOCALBASE:H}

SUB_LIST+=	WRKSRC=${WRKSRC} \
		PYTHON_CMD=${PYTHON_CMD}
SUB_FILES+=	workspace_status.sh \
		rules_python_py_runtime_info_freebsd.patch \
		rules_python_py_executable_freebsd.patch \
		rules_python_runtime_env_toolchain_freebsd.patch

USE_GITHUB=	yes
GH_ACCOUNT=	pomerium
GH_PROJECT=	envoy-custom

# Top-level WORKSPACE archives fetched directly by Bazel.
# These are not covered by repository_locations.bzl, so they must be vendored
# explicitly for offline builds.
DISTFILES+=	${ENVOY_SRC_COMMIT}.zip:envoy_src
MASTER_SITES+=	https://github.com/envoyproxy/envoy/archive/:envoy_src
DISTFILES+=	V_10_2_P1.zip:openssh_portable
MASTER_SITES+=	https://github.com/openssh/openssh-portable/archive/:openssh_portable
DISTFILES+=	a413fcc9c46a020a746907136a384c227f3cd095.zip:magic_enum
MASTER_SITES+=	https://github.com/Neargye/magic_enum/archive/:magic_enum
DISTFILES+=	v1.0.7.zip:readerwriterqueue
MASTER_SITES+=	https://github.com/cameron314/readerwriterqueue/archive/:readerwriterqueue

# Envoy API repository_locations.bzl exact versions used by this wrapper build.
DISTFILES+=	bazel-skylib-1.7.1.tar.gz:envoy_api_bazel_skylib
MASTER_SITES+=	https://github.com/bazelbuild/bazel-skylib/releases/download/1.7.1/:envoy_api_bazel_skylib
DISTFILES+=	v1.0.4.zip:envoy_api_pgv
MASTER_SITES+=	https://github.com/bufbuild/protoc-gen-validate/archive/refs/tags/:envoy_api_pgv
DISTFILES+=	rules_jvm_external-6.1.tar.gz:envoy_api_rules_jvm_external
MASTER_SITES+=	https://github.com/bazelbuild/rules_jvm_external/releases/download/6.1/:envoy_api_rules_jvm_external
DISTFILES+=	114a745b2841a044e98cdbb19358ed29fcf4a5f1.tar.gz:envoy_api_googleapis
MASTER_SITES+=	https://github.com/googleapis/googleapis/archive/:envoy_api_googleapis
DISTFILES+=	v0.4.1.tar.gz:envoy_api_opencensus_proto
MASTER_SITES+=	https://github.com/census-instrumentation/opencensus-proto/archive/:envoy_api_opencensus_proto
DISTFILES+=	v0.6.1.tar.gz:envoy_api_prometheus_metrics_model
MASTER_SITES+=	https://github.com/prometheus/client_model/archive/:envoy_api_prometheus_metrics_model
DISTFILES+=	5.3.0-21.7.tar.gz:envoy_api_rules_proto
MASTER_SITES+=	https://github.com/bazelbuild/rules_proto/archive/refs/tags/:envoy_api_rules_proto
DISTFILES+=	buf-Linux-x86_64.tar.gz:envoy_api_buf
MASTER_SITES+=	https://github.com/bufbuild/buf/releases/download/v1.32.2/:envoy_api_buf
DISTFILES+=	v0.15.0.tar.gz:envoy_api_dev_cel
MASTER_SITES+=	https://github.com/google/cel-spec/archive/:envoy_api_dev_cel
DISTFILES+=	bazel-v0.1.3.tar.gz:envoy_api_toolshed
MASTER_SITES+=	https://github.com/envoyproxy/toolshed/archive/:envoy_api_toolshed

# Bazel-managed dependencies (GitHub archive format).
# These are fetched by Bazel as http_archive during the build, sourced from
# the codeload.github.com CDN, which produces the same sha256 as GitHub's
# archive download.
GH_TUPLE+=	aspect-build:bazel-lib:v2.16.0:aspect_bazel_lib \
		grailbio:bazel-compilation-database:40864791135333e1446a04553b63cbe744d358d0:bazel_compdb \
		bazelbuild:bazel-toolchains:v5.1.2:bazel_toolchains \
		google:boringssl:0.20250514.0:boringssl \
		civetweb:civetweb:v1.16:civetweb \
		Kitware:CMake:v3.23.2:cmake_src \
		aignas:rules_shellcheck:0.4.0:com_github_aignas_rules_shellcheck \
		alibaba:hessian2-codec:6f5a64770f0374a761eece13c8863b80dc5adcd8:com_github_alibaba_hessian2_codec \
		awslabs:aws-c-auth:v0.9.1:com_github_awslabs_aws_c_auth \
		bazelbuild:buildtools:v8.2.1:com_github_bazelbuild_buildtools \
		cncf:xds:8bfbf64dc13ee1a570be4fbdcfccbdd8532463f0:com_github_cncf_xds \
		curl:curl:curl-8_5_0:com_github_curl \
		DataDog:dd-trace-cpp:v0.2.2:com_github_datadog_dd_trace_cpp \
		envoyproxy:sql-parser:3b40ba2d106587bdf053a292f7e3bb17e818a57f:com_github_envoyproxy_sqlparser \
		FDio:vpp:8ca922e1d6d0fe8af28e539505d3c3a211642a91:com_github_fdio_vpp_vcl \
		google:jwt_verify_lib:b59e8075d4a4f975ba6f109e1916d6e60aeb5613:com_github_google_jwt_verify \
		google:libsxg:beaa3939b76f8644f6833267e9f2462760838f18:com_github_google_libsxg \
		google:perfetto:v52.0:com_github_google_perfetto \
		google:quiche:9d155f645b33e283ca741ba16002a71ed382cbf0:com_github_google_quiche \
		google:tcmalloc:0c3faab546c22d67e11327c6c6c7c34c1707c5db:com_github_google_tcmalloc \
		grpc:grpc:v1.72.0:com_github_grpc_grpc \
		libevent:libevent:62c152d9a7cd264b993dad730c4163c6ede2e0a3:com_github_libevent_libevent \
		LuaJIT:LuaJIT:871db2c84ecefd70a850e03a6c340214a81739f0:com_github_luajit_luajit \
		ncopa:su-exec:v0.3:com_github_ncopa_suexec \
		openhistogram:libcircllhist:39f9db724a81ba78f5d037f1cae79c5a07107c8e:com_github_openhistogram_libcircllhist \
		openzipkin:zipkin-api:1.0.0:com_github_openzipkin_zipkinapi \
		SkyAPM:cpp2sky:v0.6.0:com_github_skyapm_cpp2sky \
		unicode-org:icu:release-77-1:com_github_unicode_org_icu \
		zlib-ng:zlib-ng:2.2.5:com_github_zlib_ng_zlib_ng \
		abseil:abseil-cpp:20250814.1:com_google_absl \
		google:cel-cpp:v0.13.0:com_google_cel_cpp \
		google:cel-spec:v0.24.0:com_google_cel_spec \
		googleapis:googleapis:fd52b5754b2b268bc3a22a10f29844f206abb327:com_google_googleapis \
		confluentinc:librdkafka:v2.6.0:confluentinc_librdkafka \
		cython:cython:0.29.35:cython \
		envoyproxy:examples:v0.1.2:envoy_examples \
		envoyproxy:data-plane-api:f8b75d1efa92bbf534596a013d9ca5873f79dd30:envoy_api \
		envoyproxy:toolshed:bazel-v0.3.3:envoy_toolshed \
		fastfloat:fast_float:v7.0.0:fast_float \
		ninja-build:ninja:v1.13.1:fips_ninja \
		google:gurl:dd4080fec0b443296c0ed0036e1e776df8813aa7:googleurl \
		grpc-ecosystem:grpc-httpjson-transcoding:a6e226f9a2e656a973df3ad48f0ee5efacce1a28:grpc_httpjson_transcoding \
		google:highway:1.2.0:highway \
		open-telemetry:opentelemetry-cpp:v1.23.0:io_opentelemetry_cpp \
		ninja-build:ninja:v1.11.1:ninja_build_src \
		numactl:numactl:v2.0.19:numactl \
		open-telemetry:opentelemetry-proto:v1.9.0:opentelemetry_proto \
		prometheus:client_model:v0.6.2:prometheus_metrics_model \
		proxy-wasm:proxy-wasm-cpp-host:65bb78fbf8beb6d3670701d35711e691c0c4c4ce:proxy_wasm_cpp_host \
		proxy-wasm:proxy-wasm-cpp-sdk:dc4f37efacd2ff7bf2e8f36632f22e1e99347f3e:proxy_wasm_cpp_sdk \
		bufbuild:rules_buf:v0.5.2:rules_buf \
		bazelbuild:rules_foreign_cc:0.15.1:rules_foreign_cc \
		bazelbuild:rules_fuzzing:v0.6.0:rules_fuzzing \
		bazelbuild:rules_python:1.6.3:rules_python \
		protocolbuffers:rules_ruby:37cf5900d0b0e44fa379c0ea3f5fcee0035d77ca:rules_ruby \
		apache:skywalking-data-collect-protocol:v10.2.0:skywalking_data_collect_protocol \
		apache:thrift:v0.22.0:thrift \
		census-instrumentation:opencensus-cpp:5501a1a255805e0be83a41348bb5f2630d5ed6b3:io_opencensus_cpp \
		census-instrumentation:opencensus-proto:v0.3.0:opencensus_proto \
		Linaro:uadk:v2.9:uadk \
		protocolbuffers:utf8_range:de0b4a8ff9b5d4c98108bdfe723291a33c52c54f:utf8_range \
		v8:v8:13.8.258.26:v8 \
		bytecodealliance:wasm-micro-runtime:WAMR-2.2.0:com_github_wamr \
		bytecodealliance:wasmtime:v24.0.4:com_github_wasmtime \
		intel:ittapi:a3911fff01a775023a06af8754f9ec1e5977dd97:intel_ittapi

# Non-GitHub Bazel dependencies (not expressible via GH_TUPLE).
# These use releases/download or .zip archives; GH_TUPLE downloads codeload
# archives with different SHA256 values that would not match the checksums
# in repository_locations.bzl.
DISTFILES+=	bazel_features-v1.36.0.tar.gz:bazel_features
MASTER_SITES+=	https://github.com/bazel-contrib/bazel_features/releases/download/v1.36.0/:bazel_features
DISTFILES+=	bazel-gazelle-v0.45.0.tar.gz:bazel_gazelle
MASTER_SITES+=	https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.45.0/:bazel_gazelle
# package_metadata: registered by gazelle_dependencies() in bazel_gazelle/deps.bzl (not in repository_locations.bzl)
DISTFILES+=	supply-chain-v0.0.5.tar.gz:package_metadata
MASTER_SITES+=	https://github.com/bazel-contrib/supply-chain/releases/download/v0.0.5/:package_metadata
DISTFILES+=	bazel-skylib-1.8.2.tar.gz:bazel_skylib
MASTER_SITES+=	https://github.com/bazelbuild/bazel-skylib/releases/download/1.8.2/:bazel_skylib
DISTFILES+=	msgpack-cxx-6.1.0.tar.gz:com_github_msgpack_cpp
MASTER_SITES+=	https://github.com/msgpack/msgpack-c/releases/download/cpp-6.1.0/:com_github_msgpack_cpp
DISTFILES+=	googletest-1.17.0.tar.gz:com_google_googletest
MASTER_SITES+=	https://github.com/google/googletest/releases/download/v1.17.0/:com_google_googletest
DISTFILES+=	gperftools-2.17.2.tar.gz:gperftools
MASTER_SITES+=	https://github.com/gperftools/gperftools/releases/download/gperftools-2.17.2/:gperftools
DISTFILES+=	rules_go-v0.59.0.zip:io_bazel_rules_go
MASTER_SITES+=	https://github.com/bazelbuild/rules_go/releases/download/v0.59.0/:io_bazel_rules_go
DISTFILES+=	rules_cc-0.2.8.tar.gz:rules_cc
MASTER_SITES+=	https://github.com/bazelbuild/rules_cc/releases/download/0.2.8/:rules_cc
DISTFILES+=	rules_java-7.12.5.tar.gz:rules_java
MASTER_SITES+=	https://github.com/bazelbuild/rules_java/releases/download/7.12.5/:rules_java
# remote_java_tools: registered by rules_java_builtin (Bazel-embedded) via DEFAULT.WORKSPACE.SUFFIX
# Bazel 7.7.1 embeds rules_java using java_tools v13.6.1 (not v13.9 from rules_java-7.12.5)
DISTFILES+=	java_tools-v13.6.1.zip:remote_java_tools
MASTER_SITES+=	https://github.com/bazelbuild/java_tools/releases/download/java_13.6.1/:remote_java_tools
DISTFILES+=	rules_license-1.0.0.tar.gz:rules_license
MASTER_SITES+=	https://github.com/bazelbuild/rules_license/releases/download/1.0.0/:rules_license
# rules_proto: used via api/bazel/repository_locations.bzl with refs/tags URL (sha differs from GH_TUPLE codeload)
DISTFILES+=	7.1.0.tar.gz:rules_proto_src
MASTER_SITES+=	https://github.com/bazelbuild/rules_proto/archive/refs/tags/:rules_proto_src
DISTFILES+=	rules_proto_grpc-4.6.0.tar.gz:rules_proto_grpc
MASTER_SITES+=	https://github.com/rules-proto-grpc/rules_proto_grpc/releases/download/4.6.0/:rules_proto_grpc
DISTFILES+=	rules_rust-0.56.0.tar.gz:rules_rust
MASTER_SITES+=	https://github.com/bazelbuild/rules_rust/releases/download/0.56.0/:rules_rust
DISTFILES+=	rules_shell-v0.6.1.tar.gz:rules_shell
MASTER_SITES+=	https://github.com/bazelbuild/rules_shell/releases/download/v0.6.1/:rules_shell
DISTFILES+=	singleheader.zip:simdutf
MASTER_SITES+=	https://github.com/simdutf/simdutf/releases/download/v7.3.4/:simdutf
DISTFILES+=	toolchains_llvm-v1.6.0.tar.gz:toolchains_llvm
MASTER_SITES+=	https://github.com/bazel-contrib/toolchains_llvm/releases/download/v1.6.0/:toolchains_llvm
DISTFILES+=	v1.3.0.zip:com_envoyproxy_protoc_gen_validate
MASTER_SITES+=	https://github.com/bufbuild/protoc-gen-validate/archive/refs/tags/:com_envoyproxy_protoc_gen_validate
DISTFILES+=	7680e4998426e62b6896995ff73d4d91cc5fb13c.zip:com_github_chrusty_protoc_gen_jsonschema
MASTER_SITES+=	https://github.com/norbjd/protoc-gen-jsonschema/archive/:com_github_chrusty_protoc_gen_jsonschema
# packages with conflicting URL basenames: use releases/download for unique filenames
DISTFILES+=	1.1.0.tar.gz:rules_pkg
MASTER_SITES+=	https://github.com/bazelbuild/rules_pkg/archive/:rules_pkg
# platforms (1.0.0.tar.gz) conflicts with com_github_openzipkin_zipkinapi (1.0.0.tar.gz)
DISTFILES+=	platforms-1.0.0.tar.gz:platforms
MASTER_SITES+=	https://github.com/bazelbuild/platforms/releases/download/1.0.0/:platforms
DISTFILES+=	protobuf-29.3.tar.gz:com_google_protobuf
MASTER_SITES+=	https://github.com/protocolbuffers/protobuf/releases/download/v29.3/:com_google_protobuf
DISTFILES+=	glib-2.26.1.tar.gz:glib_src
MASTER_SITES+=	https://download.gnome.org/sources/glib/2.26/:glib_src
DISTFILES+=	pkg-config-0.29.2.tar.gz:pkgconfig_src
MASTER_SITES+=	https://pkgconfig.freedesktop.org/releases/:pkgconfig_src
# GitHub packages using .zip format in repository_locations.bzl (not compatible with
# GH_TUPLE which always downloads codeload tar.gz with a different SHA256)
DISTFILES+=	1db76535b86b80aa97489a1edcc7009e18b67ab7.zip:com_google_protoconverter
MASTER_SITES+=	https://github.com/grpc-ecosystem/proto-converter/archive/:com_google_protoconverter
DISTFILES+=	d5d39f0373e9b6691c32c85929838b1006bcb3fb.zip:com_google_protofieldextraction
MASTER_SITES+=	https://github.com/grpc-ecosystem/proto-field-extraction/archive/:com_google_protofieldextraction
DISTFILES+=	279353cfab372ac7f268ae529df29c4d546ca18d.zip:com_google_protoprocessinglib
MASTER_SITES+=	https://github.com/grpc-ecosystem/proto_processing_lib/archive/:com_google_protoprocessinglib
DISTFILES+=	6c7c925b571d54486b9ffae8d9d18a822801cbda.zip:dragonbox
MASTER_SITES+=	https://github.com/jk-jeon/dragonbox/archive/:dragonbox
DISTFILES+=	0a92994d729ff76a58f692d3028ca1b64b145d91.zip:fp16
MASTER_SITES+=	https://github.com/Maratyszcza/FP16/archive/:fp16
DISTFILES+=	e965ac0ac6db6686169678e2a6c77ede904fa82c.zip:ocp
MASTER_SITES+=	https://github.com/opencomputeproject/ocp-diag-core/archive/:ocp
DISTFILES+=	3.9.1.zip:kafka_source
MASTER_SITES+=	https://github.com/apache/kafka/archive/:kafka_source
# antlr4_jar: http_jar in cel-cpp/bazel/deps.bzl; the first distfiles loop symlinks by basename
DISTFILES+=	antlr-4.13.1-complete.jar:antlr4_jar
MASTER_SITES+=	https://www.antlr.org/download/:antlr4_jar
# antlr4_runtimes: defined inline in cel-cpp/bazel/deps.bzl, not in repository_locations.bzl
# The pre-build distfiles loop auto-symlinks it as 4.13.1.zip in bazel-distdir
DISTFILES+=	4.13.1.zip:antlr4_runtimes
MASTER_SITES+=	https://github.com/antlr/antlr4/archive/refs/tags/:antlr4_runtimes

# Go module dependencies (go_repository rules in bazel/dependency_imports.bzl).
# proxy.golang.org always serves these as v{version}.zip; basenames are unique.
# genproto/api and genproto/rpc share a pseudo-version → single GitHub commit
# archive serves both (different strip_prefix in each go_repository rule).
# Go protoc-gen-validate uses .tar.gz to avoid conflict with C++ v1.3.0.zip.
DISTFILES+=	v1.68.0.zip:org_golang_google_grpc
MASTER_SITES+=	https://proxy.golang.org/google.golang.org/grpc/@v/:org_golang_google_grpc
DISTFILES+=	v0.34.0.zip:org_golang_x_net
MASTER_SITES+=	https://proxy.golang.org/golang.org/x/net/@v/:org_golang_x_net
DISTFILES+=	v0.21.0.zip:org_golang_x_text
MASTER_SITES+=	https://proxy.golang.org/golang.org/x/text/@v/:org_golang_x_text
# genproto/api and genproto/rpc both live in the go-genproto monorepo at this commit
DISTFILES+=	ab9386a59fda.zip:org_golang_google_genproto
MASTER_SITES+=	https://github.com/googleapis/go-genproto/archive/:org_golang_google_genproto
DISTFILES+=	v1.36.10.zip:org_golang_google_protobuf
MASTER_SITES+=	https://proxy.golang.org/google.golang.org/protobuf/@v/:org_golang_google_protobuf
DISTFILES+=	v0.0.0-20251110193048-8bfbf64dc13e.zip:com_github_cncf_xds_go
MASTER_SITES+=	https://proxy.golang.org/github.com/cncf/xds/go/@v/:com_github_cncf_xds_go
DISTFILES+=	v0.25.1.zip:dev_cel_expr
MASTER_SITES+=	https://proxy.golang.org/cel.dev/expr/@v/:dev_cel_expr
DISTFILES+=	v1.10.0.zip:com_github_spf13_afero
MASTER_SITES+=	https://proxy.golang.org/github.com/spf13/afero/@v/:com_github_spf13_afero
DISTFILES+=	v2.0.4-0.20230330145011-496ad1ac90a4.zip:com_github_lyft_protoc_gen_star_v2
MASTER_SITES+=	https://proxy.golang.org/github.com/lyft/protoc-gen-star/v2/@v/:com_github_lyft_protoc_gen_star_v2
DISTFILES+=	v0.3.0.zip:com_github_iancoleman_strcase
MASTER_SITES+=	https://proxy.golang.org/github.com/iancoleman/strcase/@v/:com_github_iancoleman_strcase
DISTFILES+=	v0.6.1-0.20240409071808-615f978279ca.zip:com_github_planetscale_vtprotobuf
MASTER_SITES+=	https://proxy.golang.org/github.com/planetscale/vtprotobuf/@v/:com_github_planetscale_vtprotobuf
DISTFILES+=	v1.5.0.zip:com_github_golang_protobuf
MASTER_SITES+=	https://proxy.golang.org/github.com/golang/protobuf/@v/:com_github_golang_protobuf
# .tar.gz avoids conflict with C++ protoc-gen-validate v1.3.0.zip
DISTFILES+=	v1.3.0.tar.gz:com_github_envoyproxy_protoc_gen_validate_go
MASTER_SITES+=	https://github.com/envoyproxy/protoc-gen-validate/archive/refs/tags/:com_github_envoyproxy_protoc_gen_validate_go
# chrusty/protoc-gen-jsonschema transitive Go dependencies (go_repository rules in deps.bzl).
# Conflicting basenames resolved by adding only the non-test module of each pair:
#   v1.1.1.zip: go-spew (keep) vs kr/pty (skip; test-only)
#   v1.0.0.zip: fatih/camelcase (keep) vs pmezard/go-difflib (skip; test-only)
#   v0.1.0.zip: kr/pretty + kr/text (both skip; test-only)
#   v0.7.0.zip: golang.org/x/sys (keep) vs golang.org/x/tools (skip; not imported by plugin binary)
DISTFILES+=	v0.0.0-20210918223802-a1d3f4b43d7b.zip:com_github_alecthomas_jsonschema
MASTER_SITES+=	https://proxy.golang.org/github.com/alecthomas/jsonschema/@v/:com_github_alecthomas_jsonschema
DISTFILES+=	v1.1.1.zip:com_github_davecgh_go_spew
MASTER_SITES+=	https://proxy.golang.org/github.com/davecgh/go-spew/@v/:com_github_davecgh_go_spew
DISTFILES+=	v1.0.0.zip:com_github_fatih_camelcase
MASTER_SITES+=	https://proxy.golang.org/github.com/fatih/camelcase/@v/:com_github_fatih_camelcase
DISTFILES+=	v0.5.5.zip:com_github_google_go_cmp
MASTER_SITES+=	https://proxy.golang.org/github.com/google/go-cmp/@v/:com_github_google_go_cmp
DISTFILES+=	v0.2.0.zip:com_github_iancoleman_orderedmap
MASTER_SITES+=	https://proxy.golang.org/github.com/iancoleman/orderedmap/@v/:com_github_iancoleman_orderedmap
DISTFILES+=	v1.4.2.zip:com_github_sirupsen_logrus
MASTER_SITES+=	https://proxy.golang.org/github.com/sirupsen/logrus/@v/:com_github_sirupsen_logrus
DISTFILES+=	v0.1.1.zip:com_github_stretchr_objx
MASTER_SITES+=	https://proxy.golang.org/github.com/stretchr/objx/@v/:com_github_stretchr_objx
DISTFILES+=	v1.6.1.zip:com_github_stretchr_testify
MASTER_SITES+=	https://proxy.golang.org/github.com/stretchr/testify/@v/:com_github_stretchr_testify
DISTFILES+=	v0.0.0-20190809123943-df4f5c81cb3b.zip:com_github_xeipuuv_gojsonpointer
MASTER_SITES+=	https://proxy.golang.org/github.com/xeipuuv/gojsonpointer/@v/:com_github_xeipuuv_gojsonpointer
DISTFILES+=	v0.0.0-20180127040603-bd5ef7bd5415.zip:com_github_xeipuuv_gojsonreference
MASTER_SITES+=	https://proxy.golang.org/github.com/xeipuuv/gojsonreference/@v/:com_github_xeipuuv_gojsonreference
DISTFILES+=	v1.2.0.zip:com_github_xeipuuv_gojsonschema
MASTER_SITES+=	https://proxy.golang.org/github.com/xeipuuv/gojsonschema/@v/:com_github_xeipuuv_gojsonschema
DISTFILES+=	v1.0.0-20180628173108-788fd7840127.zip:gopkg_in_check_v1
MASTER_SITES+=	https://proxy.golang.org/gopkg.in/check.v1/@v/:gopkg_in_check_v1
DISTFILES+=	v3.0.0-20200313102051-9f266ea9e77c.zip:gopkg_in_yaml_v3
MASTER_SITES+=	https://proxy.golang.org/gopkg.in/yaml.v3/@v/:gopkg_in_yaml_v3
DISTFILES+=	v0.0.0-20210508222113-6edffad5e616.zip:org_golang_x_lint
MASTER_SITES+=	https://proxy.golang.org/golang.org/x/lint/@v/:org_golang_x_lint
DISTFILES+=	v0.9.0.zip:org_golang_x_mod
MASTER_SITES+=	https://proxy.golang.org/golang.org/x/mod/@v/:org_golang_x_mod
DISTFILES+=	v0.7.0.zip:org_golang_x_sys
MASTER_SITES+=	https://proxy.golang.org/golang.org/x/sys/@v/:org_golang_x_sys
DISTFILES+=	v0.0.0-20191204190536-9bdfabe68543.zip:org_golang_x_xerrors
MASTER_SITES+=	https://proxy.golang.org/golang.org/x/xerrors/@v/:org_golang_x_xerrors

PLIST_FILES=	libexec/pomerium-envoy

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
BAZEL_CPU=	freebsd_x86_64
BUILD_DEPENDS+=	${LOCALBASE}/include/hs/hs.h:devel/hyperscan
.elif ${ARCH} == aarch64
BAZEL_CPU=	freebsd_aarch64
BUILD_DEPENDS+=	${LOCALBASE}/include/hs/hs.h:devel/vectorscan
.endif

BAZEL_STARTUP_OPTS=	--output_base=${WRKDIR}/bazel-out

BAZEL_BUILD_OPTS=	--distdir=${WRKDIR}/bazel-distdir \
			--repository_disable_download \
			--java_runtime_version=local_jdk \
			--tool_java_runtime_version=local_jdk \
			--repo_env=JAVA_HOME=${JAVA_HOME} \
			--action_env=JAVA_HOME=${JAVA_HOME} \
			--action_env=PATH=${WRKDIR}/bin:${LOCALBASE}/bin:/usr/bin:/bin \
			--action_env=CC=${CC} --action_env=CXX=${CXX} \
			--action_env=PYTHONPATH=${PYTHON_SITELIBDIR} \
			--host_action_env=JAVA_HOME=${JAVA_HOME} \
			--host_action_env=PATH=${WRKDIR}/bin:${LOCALBASE}/bin:/usr/bin:/bin \
			--host_action_env=PYTHONPATH=${PYTHON_SITELIBDIR} \
			--override_repository=com_github_fmtlib_fmt=${WRKDIR}/sys_repos/fmt \
			--override_repository=com_github_mirror_tclap=${WRKDIR}/sys_repos/tclap \
			--override_repository=com_github_nlohmann_json=${WRKDIR}/sys_repos/nlohmann-json \
			--override_repository=com_github_gabime_spdlog=${WRKDIR}/sys_repos/spdlog \
			--override_repository=com_github_cyan4973_xxhash=${WRKDIR}/sys_repos/xxhash \
			--override_repository=com_github_cares_cares=${WRKDIR}/sys_repos/c-ares \
			--override_repository=com_github_jbeder_yaml_cpp=${WRKDIR}/sys_repos/yaml-cpp \
			--override_repository=com_googlesource_code_re2=${WRKDIR}/sys_repos/re2 \
			--override_repository=zstd=${WRKDIR}/sys_repos/zstd \
			--override_repository=org_brotli=${WRKDIR}/sys_repos/brotli \
			--override_repository=com_github_google_flatbuffers=${WRKDIR}/sys_repos/flatbuffers \
			--override_repository=zlib=${WRKDIR}/sys_repos/zlib \
			--override_repository=net_zlib=${WRKDIR}/sys_repos/zlib \
			--override_repository=com_github_nghttp2_nghttp2=${WRKDIR}/sys_repos/nghttp2 \
			--override_repository=com_github_maxmind_libmaxminddb=${WRKDIR}/sys_repos/libmaxminddb \
			--override_repository=build_bazel_rules_apple=${WRKDIR}/sys_repos/apple_stub \
			--override_repository=base_pip3=${WRKDIR}/sys_repos/base_pip3 \
			--override_repository=io_hyperscan=${WRKDIR}/sys_repos/hyperscan \
			--override_repository=io_vectorscan=${WRKDIR}/sys_repos/vectorscan \
			--override_repository=com_github_c_ares_c_ares=${WRKDIR}/sys_repos/c-ares \
			--override_repository=com_github_facebook_zstd=${WRKDIR}/sys_repos/zstd \
			--override_repository=emsdk=${WRKDIR}/sys_repos/emsdk \
			--override_repository=proxy_wasm_rust_sdk=${WRKDIR}/sys_repos/proxy_wasm_rust_sdk \
			--override_repository=com_github_axboe_liburing=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=fips_cmake_linux_aarch64=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=fips_cmake_linux_x86_64=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=fips_go_linux_amd64=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=fips_go_linux_arm64=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=intel_dlb=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=kafka_server_binary=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=libpfm=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=org_llvm_releases_compiler_rt=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=aws_lc=${WRKDIR}/sys_repos/empty_stub \
			--override_repository=libinotify=${WRKDIR}/sys_repos/libinotify \
			--override_repository=platforms=${WRKDIR}/sys_repos/platforms \
			--override_repository=com_github_golang_protobuf=${WRKDIR}/sys_repos/com_github_golang_protobuf \
			--override_repository=com_github_cncf_xds=${WRKDIR}/sys_repos/com_github_cncf_xds \
			--override_repository=com_github_iancoleman_strcase=${WRKDIR}/sys_repos/com_github_iancoleman_strcase \
			--override_repository=prometheus_metrics_model=${WRKDIR}/sys_repos/prometheus_metrics_model \
			--override_repository=rules_fuzzing=${WRKDIR}/sys_repos/rules_fuzzing \
			--override_repository=rules_buf=${WRKDIR}/sys_repos/rules_buf \
			--override_repository=opentelemetry_proto=${WRKDIR}/sys_repos/opentelemetry_proto \
			--override_repository=ninja_build_src=${WRKDIR}/sys_repos/ninja_build_src \
			--override_repository=envoy_toolshed=${WRKDIR}/sys_repos/envoy_toolshed \
			--override_repository=com_google_googleapis=${WRKDIR}/sys_repos/com_google_googleapis \
			--override_repository=org_golang_google_protobuf=${WRKDIR}/sys_repos/org_golang_google_protobuf \
			--override_repository=org_golang_x_text=${WRKDIR}/sys_repos/org_golang_x_text \
			--override_repository=python3_11=${WRKDIR}/sys_repos/python3_11 \
			--override_repository=pip3=${WRKDIR}/sys_repos/pip3_stub \
			--override_repository=dev_pip3=${WRKDIR}/sys_repos/pip3_stub \
			--override_repository=fuzzing_pip3=${WRKDIR}/sys_repos/pip3_stub \
			--override_repository=io_bazel_rules_go=${WRKDIR}/sys_repos/io_bazel_rules_go \
			--override_repository=com_google_absl=${WRKDIR}/sys_repos/com_google_absl \
			--action_env=MAKE=${GMAKE} --host_linkopt=-lm \
			--linkopt=-lm --linkopt=-L${LOCALBASE}/lib \
			--cxxopt=-Wno-nullability-completeness \
			--host_cxxopt=-Wno-nullability-completeness \
			--copt=-fPIC --cxxopt=-fPIC --host_copt=-fPIC \
			--host_cxxopt=-fPIC --define tcmalloc=gperftools \
			--define hot_restart=disabled \
			--repo_env=GOPROXY=file://${WRKDIR}/goproxy,off \
			--repo_env=GONOSUMDB=* \
			--workspace_status_command=${WRKDIR}/workspace_status.sh \
			-c opt

BAZEL_ENV=	HOME=${WRKDIR}/.home XDG_CACHE_HOME=${WRKDIR}/.cache

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500051
BUILD_DEPENDS+=	${LOCALBASE}/include/sys/inotify.h:devel/libinotify
LIB_DEPENDS+=	libinotify.so:devel/libinotify
LIBINOTIFY_IS_REAL=	yes
.endif

post-patch:
	${CP} ${FILESDIR}/rules_buf_freebsd.patch \
		${WRKSRC}/bazel/rules_buf.patch
	${CP} ${FILESDIR}/rules_foreign_cc_freebsd.patch \
		${WRKSRC}/bazel/rules_foreign_cc.patch
	${CP} ${FILESDIR}/protoc_gen_validate_freebsd.patch \
		${WRKSRC}/bazel/protoc_gen_validate_freebsd.patch
# FreeBSD: patch dependency_imports.bzl inside @envoy to use the host Go toolchain
# and preinstalled foreign_cc tools instead of downloading/building them.  The
# patch file lives in patches/envoy/ (which is part of the pomerium-envoy-custom
# source) and is referenced by the @envoy http_archive patches list in WORKSPACE.
	${CP} ${FILESDIR}/envoy_freebsd-dependency-imports.patch \
		${WRKSRC}/patches/envoy/freebsd-dependency-imports.patch
	for f in go-sdk \
	    foreign-cc-ares \
	    foreign-cc-zlib \
	    foreign-cc-zstd \
	    foreign-cc-nghttp2 \
	    foreign-cc-maxmind \
	    maxmind-extension \
	    foreign-cc-luajit \
	    luajit \
	    platform \
	    terminate-thread \
	    thread-impl \
	    address-impl \
	    io-socket-handle-impl-h \
	    io-socket-handle-impl-cc \
	    lz4-qat-removal \
	    inotify \
	    rules-foreign-cc \
	    envoy-cmake-generate-args; do \
	    ${CP} ${FILESDIR}/patches_envoy_freebsd-$$f.patch \
	        ${WRKSRC}/patches/envoy/freebsd-$$f.patch; \
	done

pre-build:
	for f in rules_python_py_runtime_info_freebsd.patch \
	    rules_python_py_executable_freebsd.patch \
	    rules_python_runtime_env_toolchain_freebsd.patch; do \
	    ${MV} ${WRKDIR}/$$f ${WRKSRC}/bazel/$$f; \
	done
# Prepend ${WRKDIR}/bin to action PATH so rules_foreign_cc's generated build_script.sh
# picks up GNU make (gmake) when it calls "make" directly, before /usr/bin/make (BSD make).
	@${MKDIR} ${WRKDIR}/bin
	@${LN} -sf ${GMAKE} ${WRKDIR}/bin/make
# Create SOURCE_VERSION so get_workspace_status skips git (distribution build path).
# Must be a hex string: Bazel's gnu_build_id genrule prefixes it with 0x for --build-id.
	${PRINTF} "pomerium-envoy-%s" "${PORTVERSION}" | sha256 -q > ${WRKSRC}/SOURCE_VERSION
# Workspace status script: .bazelrc sets --workspace_status_command=bazel/bazel_get_workspace_status
# which does not exist in the extracted source.  Override via --workspace_status_command in
# BAZEL_BUILD_OPTS; this script outputs the stable key Bazel needs for stamped builds.
# Generated from files/workspace_status.sh.in via SUB_LIST/SUB_FILES (%%WRKSRC%% substituted).
	@${CHMOD} +x ${WRKDIR}/workspace_status.sh
	@${ECHO_MSG} "===> Setting up Bazel override repositories for system libraries"
	@${MKDIR} ${WRKDIR}/.home ${WRKDIR}/.cache
# platforms: rules_foreign_cc_dependencies() registers @platforms via maybe(http_archive),
# but Bazel 7's embedded @platforms does not appear in existing_rules() so maybe() proceeds
# to fetch it (fails: download disabled).  Override with the real 1.0.0 archive so all
# http_archive registrations see it already defined.
	@${MKDIR} ${WRKDIR}/sys_repos/platforms
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/platforms-1.0.0.tar.gz \
		-C ${WRKDIR}/sys_repos/platforms
# com_github_golang_protobuf: rules_go registers this as an http_archive at v1.5.4 with
# a gazelle patch, but we only vendor the Go module source zip.  Recreate an equivalent
# local repo from the vendored module zip and apply rules_go's BUILD file patch.
	@${MKDIR} ${WRKDIR}/sys_repos/com_github_golang_protobuf
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/v1.5.0.zip \
		-d ${WRKDIR}/sys_repos/com_github_golang_protobuf
	@cd ${WRKDIR}/sys_repos/com_github_golang_protobuf && \
		for path in github.com/golang/protobuf@v1.5.0/*; do \
			${MV} "$$path" .; \
		done
	@${RM} -r ${WRKDIR}/sys_repos/com_github_golang_protobuf/github.com
	@echo 'workspace(name = "com_github_golang_protobuf")' > \
		${WRKDIR}/sys_repos/com_github_golang_protobuf/WORKSPACE
	@bsdtar -xOf ${DISTDIR}/${DIST_SUBDIR}/rules_go-v0.59.0.zip \
		third_party/com_github_golang_protobuf-gazelle.patch \
		> ${WRKDIR}/com_github_golang_protobuf-gazelle.patch
	@cd ${WRKDIR}/sys_repos/com_github_golang_protobuf && \
		${PATCH} -p1 < ${WRKDIR}/com_github_golang_protobuf-gazelle.patch
# com_github_cncf_xds: the embedded envoy_api fetches commit 555b57 which predates
# keep_matching in OnMatch; the pomerium envoy C++ source already uses keep_matching,
# so override with the newer 8bfbf64 commit (already downloaded via GH_TUPLE) that
# includes keep_matching = 3 in xds/type/matcher/v3/matcher.proto.
	@${MKDIR} ${WRKDIR}/sys_repos/com_github_cncf_xds
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/cncf-xds-8bfbf64dc13ee1a570be4fbdcfccbdd8532463f0_GH0.tar.gz \
		--strip-components=1 \
		-C ${WRKDIR}/sys_repos/com_github_cncf_xds
	@echo 'workspace(name = "com_github_cncf_xds")' > \
		${WRKDIR}/sys_repos/com_github_cncf_xds/WORKSPACE
# com_github_iancoleman_strcase: patched nested Envoy requests v0.2.0 via go_repository,
# but the port already vendors v0.3.0.  Override with a tiny local repo exposing //:strcase.
	@${MKDIR} ${WRKDIR}/sys_repos/com_github_iancoleman_strcase
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/v0.3.0.zip \
		-d ${WRKDIR}/sys_repos/com_github_iancoleman_strcase
	@cd ${WRKDIR}/sys_repos/com_github_iancoleman_strcase && \
		for path in github.com/iancoleman/strcase@v0.3.0/*; do \
			${MV} "$$path" .; \
		done
	@${RM} -r ${WRKDIR}/sys_repos/com_github_iancoleman_strcase/github.com
	@echo 'workspace(name = "com_github_iancoleman_strcase")' > \
		${WRKDIR}/sys_repos/com_github_iancoleman_strcase/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_iancoleman_strcase.BUILD.bazel \
		${WRKDIR}/sys_repos/com_github_iancoleman_strcase/BUILD.bazel
# fmt: header-only (FMT_HEADER_ONLY), devel/libfmt
	@${MKDIR} ${WRKDIR}/sys_repos/fmt
	@echo "" > ${WRKDIR}/sys_repos/fmt/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_fmt.BUILD.bazel ${WRKDIR}/sys_repos/fmt/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include ${WRKDIR}/sys_repos/fmt/include
# tclap: header-only, devel/tclap12
	@${MKDIR} ${WRKDIR}/sys_repos/tclap
	@echo "" > ${WRKDIR}/sys_repos/tclap/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_tclap.BUILD.bazel ${WRKDIR}/sys_repos/tclap/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include ${WRKDIR}/sys_repos/tclap/include
# nlohmann-json: header-only, devel/nlohmann-json
	@${MKDIR} ${WRKDIR}/sys_repos/nlohmann-json
	@echo "" > ${WRKDIR}/sys_repos/nlohmann-json/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_nlohmann-json.BUILD.bazel \
		${WRKDIR}/sys_repos/nlohmann-json/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include ${WRKDIR}/sys_repos/nlohmann-json/include
# spdlog: header-only from Bazel's perspective, devel/spdlog
	@${MKDIR} ${WRKDIR}/sys_repos/spdlog
	@echo "" > ${WRKDIR}/sys_repos/spdlog/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_spdlog.BUILD.bazel ${WRKDIR}/sys_repos/spdlog/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include ${WRKDIR}/sys_repos/spdlog/include
# xxhash: static lib, devel/xxhash
	@${MKDIR} ${WRKDIR}/sys_repos/xxhash
	@echo "" > ${WRKDIR}/sys_repos/xxhash/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_xxhash.BUILD.bazel ${WRKDIR}/sys_repos/xxhash/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/xxhash.h ${WRKDIR}/sys_repos/xxhash/xxhash.h
	${LN} -sf ${LOCALBASE}/include/xxh3.h ${WRKDIR}/sys_repos/xxhash/xxh3.h
	${LN} -sf ${LOCALBASE}/lib/libxxhash.so ${WRKDIR}/sys_repos/xxhash/libxxhash.so
# c-ares: shared lib, dns/c-ares
	@${MKDIR} ${WRKDIR}/sys_repos/c-ares
	@echo "" > ${WRKDIR}/sys_repos/c-ares/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_c-ares.BUILD.bazel ${WRKDIR}/sys_repos/c-ares/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/ares.h ${WRKDIR}/sys_repos/c-ares/ares.h
	${LN} -sf ${LOCALBASE}/include/ares_build.h ${WRKDIR}/sys_repos/c-ares/ares_build.h
	${LN} -sf ${LOCALBASE}/include/ares_dns.h ${WRKDIR}/sys_repos/c-ares/ares_dns.h
	${LN} -sf ${LOCALBASE}/include/ares_dns_record.h ${WRKDIR}/sys_repos/c-ares/ares_dns_record.h
	${LN} -sf ${LOCALBASE}/include/ares_nameser.h ${WRKDIR}/sys_repos/c-ares/ares_nameser.h
	${LN} -sf ${LOCALBASE}/include/ares_version.h ${WRKDIR}/sys_repos/c-ares/ares_version.h
	${LN} -sf ${LOCALBASE}/lib/libcares.so ${WRKDIR}/sys_repos/c-ares/libcares.so
# yaml-cpp: shared lib, devel/yaml-cpp
	@${MKDIR} ${WRKDIR}/sys_repos/yaml-cpp
	@echo "" > ${WRKDIR}/sys_repos/yaml-cpp/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_yaml-cpp.BUILD.bazel ${WRKDIR}/sys_repos/yaml-cpp/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/yaml-cpp ${WRKDIR}/sys_repos/yaml-cpp/yaml-cpp
	${LN} -sf ${LOCALBASE}/lib/libyaml-cpp.so ${WRKDIR}/sys_repos/yaml-cpp/libyaml-cpp.so
# re2: shared lib, devel/re2
	@${MKDIR} ${WRKDIR}/sys_repos/re2
	@echo "" > ${WRKDIR}/sys_repos/re2/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_re2.BUILD.bazel ${WRKDIR}/sys_repos/re2/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/re2 ${WRKDIR}/sys_repos/re2/re2
	${LN} -sf ${LOCALBASE}/lib/libre2.so ${WRKDIR}/sys_repos/re2/libre2.so
# zstd: static lib, archivers/zstd
	@${MKDIR} ${WRKDIR}/sys_repos/zstd
	@echo "" > ${WRKDIR}/sys_repos/zstd/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_zstd.BUILD.bazel ${WRKDIR}/sys_repos/zstd/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/zstd.h ${WRKDIR}/sys_repos/zstd/zstd.h
	${LN} -sf ${LOCALBASE}/include/zstd_errors.h ${WRKDIR}/sys_repos/zstd/zstd_errors.h
	${LN} -sf ${LOCALBASE}/include/zdict.h ${WRKDIR}/sys_repos/zstd/zdict.h
	${LN} -sf ${LOCALBASE}/lib/libzstd.so ${WRKDIR}/sys_repos/zstd/libzstd.so
# brotli: shared libs, archivers/brotli
	@${MKDIR} ${WRKDIR}/sys_repos/brotli
	@echo "" > ${WRKDIR}/sys_repos/brotli/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_brotli.BUILD.bazel ${WRKDIR}/sys_repos/brotli/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/brotli ${WRKDIR}/sys_repos/brotli/brotli
	${LN} -sf ${LOCALBASE}/lib/libbrotlicommon.so ${WRKDIR}/sys_repos/brotli/libbrotlicommon.so
	${LN} -sf ${LOCALBASE}/lib/libbrotlidec.so ${WRKDIR}/sys_repos/brotli/libbrotlidec.so
	${LN} -sf ${LOCALBASE}/lib/libbrotlienc.so ${WRKDIR}/sys_repos/brotli/libbrotlienc.so
# flatbuffers: headers only, devel/flatbuffers (only header-only APIs are used)
	@${MKDIR} ${WRKDIR}/sys_repos/flatbuffers
	@echo "" > ${WRKDIR}/sys_repos/flatbuffers/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_flatbuffers.BUILD.bazel \
		${WRKDIR}/sys_repos/flatbuffers/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/flatbuffers ${WRKDIR}/sys_repos/flatbuffers/flatbuffers
# zlib: static lib from FreeBSD base system (/usr/lib/libz.a)
	@${MKDIR} ${WRKDIR}/sys_repos/zlib/zlib/include
	@echo "" > ${WRKDIR}/sys_repos/zlib/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_zlib.BUILD.bazel ${WRKDIR}/sys_repos/zlib/BUILD.bazel
	${LN} -sf ${ZLIBBASE}/include/zlib.h ${WRKDIR}/sys_repos/zlib/zlib/include/zlib.h
	${LN} -sf ${ZLIBBASE}/include/zconf.h ${WRKDIR}/sys_repos/zlib/zlib/include/zconf.h
	${LN} -sf ${ZLIBBASE}/lib/libz.so ${WRKDIR}/sys_repos/zlib/libz.so
# nghttp2: shared lib, www/nghttp2
	@${MKDIR} ${WRKDIR}/sys_repos/nghttp2/include/nghttp2
	@echo "" > ${WRKDIR}/sys_repos/nghttp2/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_nghttp2.BUILD.bazel ${WRKDIR}/sys_repos/nghttp2/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/nghttp2/nghttp2.h \
		${WRKDIR}/sys_repos/nghttp2/include/nghttp2/nghttp2.h
	${LN} -sf ${LOCALBASE}/include/nghttp2/nghttp2ver.h \
		${WRKDIR}/sys_repos/nghttp2/include/nghttp2/nghttp2ver.h
	${LN} -sf ${LOCALBASE}/lib/libnghttp2.so ${WRKDIR}/sys_repos/nghttp2/libnghttp2.so
# libmaxminddb: shared lib, net/libmaxminddb
	@${MKDIR} ${WRKDIR}/sys_repos/libmaxminddb/include
	@echo "" > ${WRKDIR}/sys_repos/libmaxminddb/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_libmaxminddb.BUILD.bazel ${WRKDIR}/sys_repos/libmaxminddb/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/maxminddb.h \
		${WRKDIR}/sys_repos/libmaxminddb/include/maxminddb.h
	${LN} -sf ${LOCALBASE}/include/maxminddb_config.h \
		${WRKDIR}/sys_repos/libmaxminddb/include/maxminddb_config.h
	${LN} -sf ${LOCALBASE}/lib/libmaxminddb.so ${WRKDIR}/sys_repos/libmaxminddb/libmaxminddb.so
# hyperscan: override always so Bazel never fetches the source archive.
# On amd64: real system library from devel/hyperscan (exact version match 5.4.2).
# On other arches: empty stub (hyperscan targets are linux/freebsd_x86_64-only).
	@${MKDIR} ${WRKDIR}/sys_repos/hyperscan/include
	@echo "" > ${WRKDIR}/sys_repos/hyperscan/WORKSPACE
.if ${ARCH} == amd64
	${CP} ${FILESDIR}/sys_repos_hyperscan.BUILD.bazel \
		${WRKDIR}/sys_repos/hyperscan/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/hs ${WRKDIR}/sys_repos/hyperscan/include/hs
	${LN} -sf ${LOCALBASE}/lib/libhs.a ${WRKDIR}/sys_repos/hyperscan/libhs.a
.else
	@echo "" > ${WRKDIR}/sys_repos/hyperscan/BUILD.bazel
.endif
# vectorscan: override always so Bazel never fetches the source archive.
# On aarch64: real system library from devel/vectorscan.
# On other arches: empty stub (vectorscan targets are linux/freebsd_aarch64-only).
	@${MKDIR} ${WRKDIR}/sys_repos/vectorscan/include
	@echo "" > ${WRKDIR}/sys_repos/vectorscan/WORKSPACE
.if ${ARCH} == aarch64
	${CP} ${FILESDIR}/sys_repos_vectorscan.BUILD.bazel \
		${WRKDIR}/sys_repos/vectorscan/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/hs ${WRKDIR}/sys_repos/vectorscan/include/hs
	${LN} -sf ${LOCALBASE}/lib/libhs.a ${WRKDIR}/sys_repos/vectorscan/libhs.a
.else
	@echo "" > ${WRKDIR}/sys_repos/vectorscan/BUILD.bazel
.endif
# build_bazel_rules_apple stub: grpc_build_system.bzl loads ios.bzl/ios_test_runner.bzl
# unconditionally; we provide no-op stubs since Apple targets are not built on FreeBSD
	@${MKDIR} ${WRKDIR}/sys_repos/apple_stub/apple/testing/default_runner
	@echo 'workspace(name = "build_bazel_rules_apple")' > \
		${WRKDIR}/sys_repos/apple_stub/WORKSPACE
	@echo '# Apple stub' > ${WRKDIR}/sys_repos/apple_stub/BUILD
	@echo '# Apple stub' > ${WRKDIR}/sys_repos/apple_stub/apple/BUILD
	@echo '# Apple stub' > ${WRKDIR}/sys_repos/apple_stub/apple/testing/BUILD
	@echo '# Apple stub' > \
		${WRKDIR}/sys_repos/apple_stub/apple/testing/default_runner/BUILD
	@echo 'def ios_unit_test(**kwargs): pass' > \
		${WRKDIR}/sys_repos/apple_stub/apple/ios.bzl
	@echo 'def ios_test_runner(**kwargs): pass' > \
		${WRKDIR}/sys_repos/apple_stub/apple/testing/default_runner/ios_test_runner.bzl
	@echo 'def apple_rules_dependencies(**kwargs): pass' > \
		${WRKDIR}/sys_repos/apple_stub/apple/repositories.bzl
# base_pip3 stub: envoy's v8.patch rewrites @v8_python_deps -> @base_pip3 in v8/BUILD.bazel.
# v8/BUILD.bazel loads @base_pip3//:requirements.bzl at package load time (blocking @v8//
# evaluation even for C++ targets). Provide a stub so the load succeeds. The requirement()
# function returns a stub py_library; jinja2 is the only package referenced.
	@${MKDIR} ${WRKDIR}/sys_repos/base_pip3
	@echo 'workspace(name = "base_pip3")' > ${WRKDIR}/sys_repos/base_pip3/WORKSPACE
	@echo 'py_library(name = "jinja2", srcs = [], visibility = ["//visibility:public"])' > \
		${WRKDIR}/sys_repos/base_pip3/BUILD.bazel
	@echo 'def install_deps(): pass' > \
		${WRKDIR}/sys_repos/base_pip3/requirements.bzl
	@echo 'def requirement(name): return "@base_pip3//:" + name' >> \
		${WRKDIR}/sys_repos/base_pip3/requirements.bzl
# emsdk stub: dependency_imports.bzl loads emscripten_deps.bzl/toolchains.bzl;
# repositories_extra.bzl loads deps.bzl. Provide no-op stubs — WASM not built on FreeBSD.
	@${MKDIR} ${WRKDIR}/sys_repos/emsdk
	@echo "" > ${WRKDIR}/sys_repos/emsdk/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/emsdk/BUILD.bazel
	@echo 'def emscripten_deps(**kwargs): pass' > ${WRKDIR}/sys_repos/emsdk/emscripten_deps.bzl
	@echo 'def register_emscripten_toolchains(**kwargs): pass' > ${WRKDIR}/sys_repos/emsdk/toolchains.bzl
	@echo 'def deps(**kwargs): pass' > ${WRKDIR}/sys_repos/emsdk/deps.bzl
# proxy_wasm_rust_sdk stub: dependency_imports.bzl loads bazel/dependencies.bzl.
	@${MKDIR} ${WRKDIR}/sys_repos/proxy_wasm_rust_sdk/bazel
	@echo "" > ${WRKDIR}/sys_repos/proxy_wasm_rust_sdk/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/proxy_wasm_rust_sdk/BUILD.bazel
	@echo "" > ${WRKDIR}/sys_repos/proxy_wasm_rust_sdk/bazel/BUILD.bazel
	@echo 'def proxy_wasm_rust_sdk_dependencies(**kwargs): pass' > \
		${WRKDIR}/sys_repos/proxy_wasm_rust_sdk/bazel/dependencies.bzl
# rules_fuzzing stub: test_only; shares v0.6.0.tar.gz basename with cpp2sky causing
# a distdir collision (last-write-wins overwrites the symlink).  Stub it out so Bazel
# never fetches it and cpp2sky retains the v0.6.0.tar.gz distdir entry.
	@${MKDIR} ${WRKDIR}/sys_repos/rules_fuzzing/fuzzing
	@echo 'workspace(name = "rules_fuzzing")' > \
		${WRKDIR}/sys_repos/rules_fuzzing/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/rules_fuzzing/BUILD
	@echo "" > ${WRKDIR}/sys_repos/rules_fuzzing/fuzzing/BUILD
	@echo 'def rules_fuzzing_dependencies(**kwargs): pass' > \
		${WRKDIR}/sys_repos/rules_fuzzing/fuzzing/repositories.bzl
	@echo 'def fuzzing_decoration(**kwargs): pass' > \
		${WRKDIR}/sys_repos/rules_fuzzing/fuzzing/cc_defs.bzl
# rules_buf stub: dependency_imports.bzl loads @rules_buf//buf:repositories.bzl at module
# level; buf binary is provided by the system (devel/buf) so no toolchain download needed.
	@${MKDIR} ${WRKDIR}/sys_repos/rules_buf/buf
	@echo 'workspace(name = "rules_buf")' > ${WRKDIR}/sys_repos/rules_buf/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/rules_buf/BUILD
	@echo "" > ${WRKDIR}/sys_repos/rules_buf/buf/BUILD
	@echo 'def rules_buf_toolchains(**kwargs): pass' > \
		${WRKDIR}/sys_repos/rules_buf/buf/repositories.bzl
# rules_proto stub: io_bazel_rules_go/proto/compiler.bzl loads
# @rules_proto//proto:proto_common.bzl at module level.  The real rules_proto 7.1.0
# proto_common.bzl transitively loads @com_google_protobuf which may not be
# initialised during early loading phase.  Provide a self-contained stub that
# satisfies all load()s without any external deps.
	@${MKDIR} ${WRKDIR}/sys_repos/rules_proto/proto/private/rules
	@echo 'workspace(name = "rules_proto")' > ${WRKDIR}/sys_repos/rules_proto/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/rules_proto/BUILD
	@echo "" > ${WRKDIR}/sys_repos/rules_proto/proto/BUILD
	@echo "" > ${WRKDIR}/sys_repos/rules_proto/proto/private/BUILD
	@echo "" > ${WRKDIR}/sys_repos/rules_proto/proto/private/rules/BUILD
	@echo 'def _use_toolchain(toolchain_type): return []' > \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo 'def _find_toolchain(ctx, legacy_attr, toolchain_type): return None' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo 'def _if_legacy_toolchain(legacy_attr_dict): return legacy_attr_dict' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo 'toolchains = struct(' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo '    use_toolchain = _use_toolchain,' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo '    find_toolchain = _find_toolchain,' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo '    if_legacy_toolchain = _if_legacy_toolchain,' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo ')' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/proto_common.bzl
	@echo 'ProtoInfo = provider("ProtoInfo", fields = ["check_deps_sources", "direct_descriptor_set", "direct_sources", "proto_source_root", "transitive_descriptor_sets", "transitive_imports", "transitive_proto_path", "transitive_sources"])' > \
		${WRKDIR}/sys_repos/rules_proto/proto/defs.bzl
	@echo 'def proto_library(**kwargs): native.proto_library(**kwargs)' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/defs.bzl
	@echo 'def proto_lang_toolchain(**kwargs): native.proto_lang_toolchain(**kwargs)' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/defs.bzl
	@echo 'def proto_toolchain(**kwargs): pass' >> \
		${WRKDIR}/sys_repos/rules_proto/proto/defs.bzl
	@echo 'def proto_descriptor_set(**kwargs): pass' > \
		${WRKDIR}/sys_repos/rules_proto/proto/private/rules/proto_descriptor_set.bzl
# io_bazel_rules_go: extract rules_go 0.59.0 which already fixed the GOEXPERIMENT
# coverageredesign issue and has correct BUILD.bazel files for org_golang_google_protobuf v1.36.x.
	@${MKDIR} ${WRKDIR}/sys_repos/io_bazel_rules_go
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/rules_go-v0.59.0.zip \
		-d ${WRKDIR}/sys_repos/io_bazel_rules_go
# opentelemetry_proto: the data-plane-api's api_dependencies() registers opentelemetry_proto
# with build content using api_cc_py_proto_library(name="trace",...) which creates "trace" and
# "trace_cc_proto" targets.  The envoy source's opentelemetry tracer BUILD directly references
# "@opentelemetry_proto//:trace_proto_cc" (new naming convention).  Override with a local
# directory that provides both old-style aliases and new-style cc_proto_library targets.
# Uses the v1.9.0 archive (from GH_TUPLE) which has all required .proto source files.
	@${MKDIR} ${WRKDIR}/sys_repos/opentelemetry_proto
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/open-telemetry-opentelemetry-proto-v1.9.0_GH0.tar.gz \
		--strip-components=1 \
		-C ${WRKDIR}/sys_repos/opentelemetry_proto
	@echo 'workspace(name = "opentelemetry_proto")' > \
		${WRKDIR}/sys_repos/opentelemetry_proto/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_opentelemetry_proto.BUILD.bazel \
		${WRKDIR}/sys_repos/opentelemetry_proto/BUILD.bazel
# ninja_build_src: rules_foreign_cc_dependencies() registers this via maybe(http_archive)
# with sha256 matching the GitHub releases archive (v1.11.1.tar.gz).  The GH_TUPLE download
# is from codeload.github.com which has a different sha256, so the distdir basename lookup
# fails.  Override with the GH_TUPLE archive so Bazel skips the fetch entirely.
# rules_foreign_cc builds ninja from source for its foreign_cc toolchain; all_srcs must exist.
	@${MKDIR} ${WRKDIR}/sys_repos/ninja_build_src
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/ninja-build-ninja-v1.11.1_GH0.tar.gz \
		--strip-components=1 \
		-C ${WRKDIR}/sys_repos/ninja_build_src
	@echo 'workspace(name = "ninja_build_src")' > \
		${WRKDIR}/sys_repos/ninja_build_src/WORKSPACE
	@echo 'filegroup(name = "all_srcs", srcs = glob(["**"]), visibility = ["//visibility:public"])' > \
		${WRKDIR}/sys_repos/ninja_build_src/BUILD.bazel
# empty_stub: shared stub for Linux/Intel/WASM-specific repos not used on FreeBSD.
	@${MKDIR} ${WRKDIR}/sys_repos/empty_stub
	@echo "" > ${WRKDIR}/sys_repos/empty_stub/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/empty_stub/BUILD.bazel
# libinotify: inotify support for FreeBSD < 1500051; stub (inotify in base) on newer systems.
.if defined(LIBINOTIFY_IS_REAL)
	@${MKDIR} ${WRKDIR}/sys_repos/libinotify/sys
	@echo "" > ${WRKDIR}/sys_repos/libinotify/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_libinotify.BUILD.bazel \
		${WRKDIR}/sys_repos/libinotify/BUILD.bazel
	${LN} -sf ${LOCALBASE}/include/sys/inotify.h \
		${WRKDIR}/sys_repos/libinotify/sys/inotify.h
	${LN} -sf ${LOCALBASE}/lib/libinotify.so \
		${WRKDIR}/sys_repos/libinotify/libinotify.so
.else
	@${MKDIR} ${WRKDIR}/sys_repos/libinotify
	@echo "" > ${WRKDIR}/sys_repos/libinotify/WORKSPACE
	@printf 'cc_library(name = "libinotify", visibility = ["//visibility:public"])\n' \
		> ${WRKDIR}/sys_repos/libinotify/BUILD.bazel
.endif
# python3_11 stub: envoy_toolshed/packages.bzl loads @python3_11//:defs.bzl at module level.
# The toolshed targets Python 3.11 but envoy registers python3_12; stub out 3.11 so the
# module-level load() succeeds. interpreter is only used by pip3 which is also stubbed.
	@${MKDIR} ${WRKDIR}/sys_repos/python3_11
	@echo "" > ${WRKDIR}/sys_repos/python3_11/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/python3_11/BUILD.bazel
	@echo 'interpreter = "@python3_11//:python"' > ${WRKDIR}/sys_repos/python3_11/defs.bzl
# pip3_stub: stubs for pip repos created by pip_parse() in envoy_python_dependencies().
# pip3 = load_packages() result; dev_pip3/fuzzing_pip3 = development tooling; all unused
# for building the static envoy binary. Use same no-op pattern as base_pip3.
	@${MKDIR} ${WRKDIR}/sys_repos/pip3_stub
	@echo "" > ${WRKDIR}/sys_repos/pip3_stub/WORKSPACE
	@echo 'py_library(name = "jinja2", srcs = [], visibility = ["//visibility:public"])' > \
		${WRKDIR}/sys_repos/pip3_stub/BUILD.bazel
	@echo 'def install_deps(): pass' > ${WRKDIR}/sys_repos/pip3_stub/requirements.bzl
	@echo 'def requirement(name): return "@pip3_stub//:" + name' >> \
		${WRKDIR}/sys_repos/pip3_stub/requirements.bzl
# com_google_absl: the pomerium SSH wire extension enables -Wimplicit-int-conversion which triggers
# a truncation warning in absl's civil_time_detail.h on FreeBSD where int_fast8_t=int but
# int_least8_t=signed char.  Override with a patched copy that adds static_casts.
	@${LN} -sf ${WRKDIR}/abseil-cpp-20250814.1 ${WRKDIR}/sys_repos/com_google_absl
	@echo 'workspace(name = "com_google_absl")' > \
		${WRKDIR}/sys_repos/com_google_absl/WORKSPACE
	@${REINPLACE_CMD} -e \
		's|: y(year), m(month), d(day), hh(hour), mm(minute), ss(second) {}|: y(year), m(static_cast<std::int_least8_t>(month)), d(static_cast<std::int_least8_t>(day)), hh(static_cast<std::int_least8_t>(hour)), mm(static_cast<std::int_least8_t>(minute)), ss(static_cast<std::int_least8_t>(second)) {}|' \
		${WRKDIR}/sys_repos/com_google_absl/absl/time/internal/cctz/include/cctz/civil_time_detail.h
# com_google_googleapis: data-plane-api's api_dependencies() registers this via external_http_archive
# with commit 114a745b (sha256 9b4e0d0a). The GH_TUPLE archive fd52b5754b is a compatible newer
# version. Use --override_repository to bypass the distdir fetch entirely.
	@${MKDIR} ${WRKDIR}/sys_repos/com_google_googleapis
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/googleapis-googleapis-fd52b5754b2b268bc3a22a10f29844f206abb327_GH0.tar.gz \
		--strip-components=1 \
		-C ${WRKDIR}/sys_repos/com_google_googleapis
	@echo 'workspace(name = "com_google_googleapis")' > \
		${WRKDIR}/sys_repos/com_google_googleapis/WORKSPACE
# org_golang_google_protobuf: the patched nested Envoy repo still refers to an older module
# version, but the vendored v1.36.10 module zip contains the required source tree and is
# sufficient for the packages this build imports. Override it locally from that module zip.
	@${MKDIR} ${WRKDIR}/sys_repos/org_golang_google_protobuf
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/v1.36.10.zip \
		-d ${WRKDIR}/sys_repos/org_golang_google_protobuf
	@cd ${WRKDIR}/sys_repos/org_golang_google_protobuf && \
		for path in google.golang.org/protobuf@v1.36.10/*; do \
			${MV} "$$path" .; \
		done
	@${RM} -r ${WRKDIR}/sys_repos/org_golang_google_protobuf/google.golang.org
	@echo 'workspace(name = "org_golang_google_protobuf")' > \
		${WRKDIR}/sys_repos/org_golang_google_protobuf/WORKSPACE
	@bsdtar -xOf ${DISTDIR}/${DIST_SUBDIR}/rules_go-v0.59.0.zip \
		third_party/org_golang_google_protobuf-gazelle.patch \
		> ${WRKDIR}/org_golang_google_protobuf-gazelle.patch
	@cd ${WRKDIR}/sys_repos/org_golang_google_protobuf && \
		${PATCH} -p1 < ${WRKDIR}/org_golang_google_protobuf-gazelle.patch
# v1.36.10 replaced version-split *_go1XX.go files with unified files and removed weak.go.
# The gazelle patch references stale filenames; replace or delete as appropriate.
	@${FIND} ${WRKDIR}/sys_repos/org_golang_google_protobuf -name "BUILD.bazel" \
		-exec ${SED} -i '' \
		-e 's|"strings_unsafe_go120\.go"|"strings_unsafe.go"|' \
		-e 's|"value_unsafe_go120\.go"|"value_unsafe.go"|' \
		-e '/"weak\.go"/d' \
		-e '/_go1[0-9][0-9]*\.go/d' \
		{} +
# presence.go was added after v1.36.3 (when rules_go 0.59.0 was cut); add it to filedesc srcs.
	@${REINPLACE_CMD} -e 's|"placeholder\.go",|"placeholder.go",\n        "presence.go",|' \
		${WRKDIR}/sys_repos/org_golang_google_protobuf/internal/filedesc/BUILD.bazel
# org_golang_x_text: patched nested Envoy still refers to v0.3.3, but the port vendors
# v0.21.0.  Override locally with the specific packages needed by afero's build directives.
	@${MKDIR} ${WRKDIR}/sys_repos/org_golang_x_text
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/v0.21.0.zip \
		-d ${WRKDIR}/sys_repos/org_golang_x_text
	@cd ${WRKDIR}/sys_repos/org_golang_x_text && \
		for path in golang.org/x/text@v0.21.0/*; do \
			${MV} "$$path" .; \
		done
	@${RM} -r ${WRKDIR}/sys_repos/org_golang_x_text/golang.org
	@echo 'workspace(name = "org_golang_x_text")' > \
		${WRKDIR}/sys_repos/org_golang_x_text/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_org_golang_x_text_transform.BUILD.bazel \
		${WRKDIR}/sys_repos/org_golang_x_text/transform/BUILD.bazel
	${CP} ${FILESDIR}/sys_repos_org_golang_x_text_runes.BUILD.bazel \
		${WRKDIR}/sys_repos/org_golang_x_text/runes/BUILD.bazel
	${CP} ${FILESDIR}/sys_repos_org_golang_x_text_unicode_norm.BUILD.bazel \
		${WRKDIR}/sys_repos/org_golang_x_text/unicode/norm/BUILD.bazel
# prometheus_metrics_model: embedded envoy_api's api_dependencies() registers this with
# custom build_file_content. Override it with a local extracted tree and equivalent
# BUILD file so Bazel does not try to fetch the repository.
	@${MKDIR} ${WRKDIR}/sys_repos/prometheus_metrics_model
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/prometheus-client_model-v0.6.2_GH0.tar.gz \
		--strip-components=1 \
		-C ${WRKDIR}/sys_repos/prometheus_metrics_model
	@echo 'workspace(name = "prometheus_metrics_model")' > \
		${WRKDIR}/sys_repos/prometheus_metrics_model/WORKSPACE
	${CP} ${FILESDIR}/sys_repos_prometheus_metrics_model.BUILD.bazel \
		${WRKDIR}/sys_repos/prometheus_metrics_model/BUILD.bazel
# envoy_toolshed stub: the real toolshed v0.3.3 has coverage/grcov/ and compile/ packages
# but Bazel 7 fails to recognise them as sub-packages (no-package error at load time).
# Also, packages.bzl in v0.3.3 loads @python3_11 at module level, creating a cycle because
# envoy registers python3_12, not python3_11.  Provide a minimal stub with no-op versions
# of all symbols loaded by the envoy source.
	@${MKDIR} ${WRKDIR}/sys_repos/envoy_toolshed/compile
	@${MKDIR} ${WRKDIR}/sys_repos/envoy_toolshed/coverage/grcov
	@${MKDIR} ${WRKDIR}/sys_repos/envoy_toolshed/dependency
	@echo 'workspace(name = "envoy_toolshed")' > \
		${WRKDIR}/sys_repos/envoy_toolshed/WORKSPACE
	@echo "" > ${WRKDIR}/sys_repos/envoy_toolshed/BUILD
	@echo 'def json_data(**kwargs): pass' > \
		${WRKDIR}/sys_repos/envoy_toolshed/macros.bzl
	@echo 'def load_packages(**kwargs): pass' > \
		${WRKDIR}/sys_repos/envoy_toolshed/packages.bzl
	@echo "" > ${WRKDIR}/sys_repos/envoy_toolshed/compile/BUILD
	@echo 'def setup_sanitizer_libs(**kwargs): pass' > \
		${WRKDIR}/sys_repos/envoy_toolshed/compile/sanitizer_libs.bzl
	@echo "" > ${WRKDIR}/sys_repos/envoy_toolshed/coverage/BUILD
	@echo "" > ${WRKDIR}/sys_repos/envoy_toolshed/coverage/grcov/BUILD
	@echo 'def grcov_repository(**kwargs): pass' > \
		${WRKDIR}/sys_repos/envoy_toolshed/coverage/grcov/grcov_repository.bzl
	@echo "" > ${WRKDIR}/sys_repos/envoy_toolshed/dependency/BUILD
	@echo 'def updater(**kwargs): pass' > \
		${WRKDIR}/sys_repos/envoy_toolshed/dependency/macros.bzl
	@${ECHO_MSG} "===> Setting up Go module proxy for offline go_repository builds"
	@${MKDIR} ${WRKDIR}/goproxy
# proxy.golang.org-format zips: extract go.mod, create .info and list, symlink .zip
	@for entry in \
	    "google.golang.org/grpc v1.68.0 v1.68.0.zip" \
	    "golang.org/x/net v0.34.0 v0.34.0.zip" \
	    "golang.org/x/text v0.21.0 v0.21.0.zip" \
	    "google.golang.org/protobuf v1.36.10 v1.36.10.zip" \
	    "github.com/cncf/xds/go v0.0.0-20251110193048-8bfbf64dc13e v0.0.0-20251110193048-8bfbf64dc13e.zip" \
	    "cel.dev/expr v0.25.1 v0.25.1.zip" \
	    "github.com/spf13/afero v1.10.0 v1.10.0.zip" \
	    "github.com/lyft/protoc-gen-star/v2 v2.0.4-0.20230330145011-496ad1ac90a4 v2.0.4-0.20230330145011-496ad1ac90a4.zip" \
	    "github.com/iancoleman/strcase v0.3.0 v0.3.0.zip" \
	    "github.com/planetscale/vtprotobuf v0.6.1-0.20240409071808-615f978279ca v0.6.1-0.20240409071808-615f978279ca.zip" \
	    "github.com/golang/protobuf v1.5.0 v1.5.0.zip" \
	    "github.com/alecthomas/jsonschema v0.0.0-20210918223802-a1d3f4b43d7b v0.0.0-20210918223802-a1d3f4b43d7b.zip" \
	    "github.com/davecgh/go-spew v1.1.1 v1.1.1.zip" \
	    "github.com/fatih/camelcase v1.0.0 v1.0.0.zip" \
	    "github.com/google/go-cmp v0.5.5 v0.5.5.zip" \
	    "github.com/iancoleman/orderedmap v0.2.0 v0.2.0.zip" \
	    "github.com/sirupsen/logrus v1.4.2 v1.4.2.zip" \
	    "github.com/stretchr/objx v0.1.1 v0.1.1.zip" \
	    "github.com/stretchr/testify v1.6.1 v1.6.1.zip" \
	    "github.com/xeipuuv/gojsonpointer v0.0.0-20190809123943-df4f5c81cb3b v0.0.0-20190809123943-df4f5c81cb3b.zip" \
	    "github.com/xeipuuv/gojsonreference v0.0.0-20180127040603-bd5ef7bd5415 v0.0.0-20180127040603-bd5ef7bd5415.zip" \
	    "github.com/xeipuuv/gojsonschema v1.2.0 v1.2.0.zip" \
	    "gopkg.in/check.v1 v1.0.0-20180628173108-788fd7840127 v1.0.0-20180628173108-788fd7840127.zip" \
	    "gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c v3.0.0-20200313102051-9f266ea9e77c.zip" \
	    "golang.org/x/lint v0.0.0-20210508222113-6edffad5e616 v0.0.0-20210508222113-6edffad5e616.zip" \
	    "golang.org/x/mod v0.9.0 v0.9.0.zip" \
	    "golang.org/x/sys v0.7.0 v0.7.0.zip" \
	    "golang.org/x/xerrors v0.0.0-20191204190536-9bdfabe68543 v0.0.0-20191204190536-9bdfabe68543.zip" \
	; do \
	    set -- $$entry; modpath=$$1; ver=$$2; zipf=$$3; \
	    d="${WRKDIR}/goproxy/$${modpath}/@v"; \
	    ${MKDIR} "$${d}"; \
	    if ! ${UNZIP_CMD} -p "${DISTDIR}/${DIST_SUBDIR}/$${zipf}" "$${modpath}@$${ver}/go.mod" > "$${d}/$${ver}.mod"; then \
	        ${PRINTF} 'module %s\n' "$${modpath}" > "$${d}/$${ver}.mod"; \
	    fi; \
	    ${PRINTF} '{"Version":"%s","Time":"2020-01-01T00:00:00Z"}\n' "$${ver}" > "$${d}/$${ver}.info"; \
	    ${PRINTF} '%s\n' "$${ver}" > "$${d}/list"; \
	    ${LN} -sf "${DISTDIR}/${DIST_SUBDIR}/$${zipf}" "$${d}/$${ver}.zip"; \
	done
# genproto/googleapis/{api,rpc}: create proxy-format zips from GitHub archive
# The GitHub archive contains the same git tree as the Go module proxy serves;
# nested module subdirectories must be excluded per the Go module zip spec.
	@GENVER="v0.0.0-20251029180050-ab9386a59fda"; \
	GENSRCPFX="go-genproto-ab9386a59fda5527e1fb6eb1f7d4b052283f7934"; \
	tmpdir=$$(mktemp -d); \
	${UNZIP_CMD} -q "${DISTDIR}/${DIST_SUBDIR}/ab9386a59fda.zip" -d "$${tmpdir}"; \
	for submod in api rpc; do \
	    modpath="google.golang.org/genproto/googleapis/$${submod}"; \
	    srcdir="$${tmpdir}/$${GENSRCPFX}/googleapis/$${submod}"; \
	    dstprefix="$${modpath}@$${GENVER}"; \
	    dstdir="$${tmpdir}/$${dstprefix}"; \
	    ${MKDIR} "$${dstdir}"; \
	    ( cd "$${srcdir}" && find . -type f ) | sort | while IFS= read -r f; do \
	        rel="$${f#./}"; \
	        case "$${submod}:$${rel}" in \
	            api:apikeys/*|api:servicecontrol/*|api:servicemanagement/*|api:serviceusage/*) \
	                continue ;; \
	        esac; \
	        ${MKDIR} "$$(dirname "$${dstdir}/$${rel}")"; \
	        cp "$${srcdir}/$${rel}" "$${dstdir}/$${rel}"; \
	    done; \
	    proxyd="${WRKDIR}/goproxy/$${modpath}/@v"; \
	    ${MKDIR} "$${proxyd}"; \
	    ( cd "$${tmpdir}" && find "$${dstprefix}" -type f | sort | zip -q "$${proxyd}/$${GENVER}.zip" -@ ); \
	    cp "$${dstdir}/go.mod" "$${proxyd}/$${GENVER}.mod"; \
		    ${PRINTF} '{"Version":"%s","Time":"2025-10-29T11:00:00Z"}\n' "$${GENVER}" > "$${proxyd}/$${GENVER}.info"; \
		    ${PRINTF} '%s\n' "$${GENVER}" > "$${proxyd}/list"; \
	done; \
	rm -rf "$${tmpdir}"
# protoc-gen-validate Go module: create proxy-format zip from GitHub tar.gz;
# exclude the tests/ nested module subdirectory.
	@PGV_VER="v1.3.0"; \
	PGV_MOD="github.com/envoyproxy/protoc-gen-validate"; \
	PGV_SRCPFX="protoc-gen-validate-1.3.0"; \
	tmpdir=$$(mktemp -d); \
	tar xzf "${DISTDIR}/${DIST_SUBDIR}/v1.3.0.tar.gz" -C "$${tmpdir}"; \
	srcdir="$${tmpdir}/$${PGV_SRCPFX}"; \
	dstprefix="$${PGV_MOD}@$${PGV_VER}"; \
	dstdir="$${tmpdir}/$${dstprefix}"; \
	${MKDIR} "$${dstdir}"; \
	( cd "$${srcdir}" && find . -type f ) | sort | while IFS= read -r f; do \
	    rel="$${f#./}"; \
	    case "$${rel}" in tests/*) continue ;; esac; \
	    ${MKDIR} "$$(dirname "$${dstdir}/$${rel}")"; \
	    cp "$${srcdir}/$${rel}" "$${dstdir}/$${rel}"; \
	done; \
	proxyd="${WRKDIR}/goproxy/$${PGV_MOD}/@v"; \
	${MKDIR} "$${proxyd}"; \
	( cd "$${tmpdir}" && find "$${dstprefix}" -type f | sort | zip -q "$${proxyd}/$${PGV_VER}.zip" -@ ); \
	cp "$${dstdir}/go.mod" "$${proxyd}/$${PGV_VER}.mod"; \
		${PRINTF} '{"Version":"%s","Time":"2023-01-01T00:00:00Z"}\n' "$${PGV_VER}" > "$${proxyd}/$${PGV_VER}.info"; \
		${PRINTF} '%s\n' "$${PGV_VER}" > "$${proxyd}/list"; \
	rm -rf "$${tmpdir}"
	@${ECHO_MSG} "===> Setting up Bazel distdir from distfiles"
	@${MKDIR} ${WRKDIR}/bazel-distdir
	@for f in ${DISTDIR}/${DIST_SUBDIR}/*; do \
	    [ -f "$$f" ] || continue; \
	    ${LN} -sf "$$f" ${WRKDIR}/bazel-distdir/$$(basename "$$f"); \
	done
# @envoy_api http_archive URL basename is <commit>.tar.gz; GH_TUPLE names it with a prefix.
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/envoyproxy-data-plane-api-${ENVOY_API_COMMIT}_GH0.tar.gz \
	    ${WRKDIR}/bazel-distdir/${ENVOY_API_COMMIT}.tar.gz
# Embedded envoy_api dependencies: link exact upstream basenames expected by bazel/repositories.bzl.
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/bazel-skylib-1.7.1.tar.gz \
	    ${WRKDIR}/bazel-distdir/bazel-skylib-1.7.1.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/rules_jvm_external-6.1.tar.gz \
	    ${WRKDIR}/bazel-distdir/rules_jvm_external-6.1.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/v1.0.4.zip \
	    ${WRKDIR}/bazel-distdir/v1.0.4.zip
# Embedded envoy_api dependency: com_google_googleapis is fetched as <commit>.tar.gz.
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/114a745b2841a044e98cdbb19358ed29fcf4a5f1.tar.gz \
	    ${WRKDIR}/bazel-distdir/114a745b2841a044e98cdbb19358ed29fcf4a5f1.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/v0.4.1.tar.gz \
	    ${WRKDIR}/bazel-distdir/v0.4.1.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/v0.6.1.tar.gz \
	    ${WRKDIR}/bazel-distdir/v0.6.1.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/5.3.0-21.7.tar.gz \
	    ${WRKDIR}/bazel-distdir/5.3.0-21.7.tar.gz
# Embedded envoy_api dependency: com_github_openzipkin_zipkinapi is fetched as 1.0.0.tar.gz.
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/openzipkin-zipkin-api-1.0.0_GH0.tar.gz \
	    ${WRKDIR}/bazel-distdir/1.0.0.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/buf-Linux-x86_64.tar.gz \
	    ${WRKDIR}/bazel-distdir/buf-Linux-x86_64.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/7680e4998426e62b6896995ff73d4d91cc5fb13c.zip \
	    ${WRKDIR}/bazel-distdir/7680e4998426e62b6896995ff73d4d91cc5fb13c.zip
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/v0.15.0.tar.gz \
	    ${WRKDIR}/bazel-distdir/v0.15.0.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/rules_proto_grpc-4.6.0.tar.gz \
	    ${WRKDIR}/bazel-distdir/rules_proto_grpc-4.6.0.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/bazel-v0.1.3.tar.gz \
	    ${WRKDIR}/bazel-distdir/bazel-v0.1.3.tar.gz
# Patched dep: com_github_google_tcmalloc bumped by patches/envoy/0002-bump-dependencies.patch.
# The auto-detection loop reads the unpatched repository_locations.bzl and won't find the new
# sha, so we create the symlink explicitly here.
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/google-tcmalloc-0c3faab546c22d67e11327c6c6c7c34c1707c5db_GH0.tar.gz \
	    ${WRKDIR}/bazel-distdir/0c3faab546c22d67e11327c6c6c7c34c1707c5db.tar.gz
	@for locations in ${WRKSRC}/bazel/repository_locations.bzl \
	    ${WRKSRC}/api/bazel/repository_locations.bzl; do \
	    [ -f "$$locations" ] || continue; \
	    ${AWK} '\
	        /^[A-Z0-9_]+ = "/ { \
	            split($$0, parts, " = "); \
	            split($$0, fields, "\""); \
	            consts[parts[1]] = fields[2]; \
	            next; \
	        } \
		        index($$0, "version = \"") { \
		            split($$0, fields, "\""); \
		            version = fields[2]; \
		            next; \
		        } \
		        index($$0, "version = ") && index($$0, "\"") == 0 { \
		            split($$0, parts, " = "); \
		            symbol = parts[2]; \
		            sub(/,.*/, "", symbol); \
	            version = consts[symbol]; \
	            next; \
	        } \
	        /sha256 = "/ { \
	            split($$0, fields, "\""); \
	            sha = fields[2]; \
	            next; \
	        } \
	        /urls = \[/ { \
	            if (sha != "") { \
	                split($$0, fields, "\""); \
	                url = fields[2]; \
	                gsub(/\{version\}/, version, url); \
	                sub(/^.*\//, "", url); \
	                print sha " " url; \
	                sha = ""; \
	                version = ""; \
	            } \
	        }' "$$locations" | while read -r sha name; do \
	            [ -n "$$sha" ] || continue; \
	            src=$$(${AWK} -v sha="$$sha" '\
	                $$1 == "SHA256" && index($$0, sha) { \
	                    sub(/^SHA256 \(/, ""); \
	                    sub(/\).*/, ""); \
	                    print; \
	                    exit; \
	                }' ${.CURDIR}/distinfo); \
	            [ -n "$$src" ] || continue; \
	            ${LN} -sf ${DISTDIR}/$$src ${WRKDIR}/bazel-distdir/$$name; \
	        done; \
	done
	@for spec in \
	    "${DISTDIR}/${DIST_SUBDIR}/${ENVOY_SRC_COMMIT}.zip|envoy-${ENVOY_SRC_COMMIT}/bazel/repository_locations.bzl" \
	    "${DISTDIR}/${DIST_SUBDIR}/envoyproxy-data-plane-api-${ENVOY_API_COMMIT}_GH0.tar.gz|data-plane-api-${ENVOY_API_COMMIT}/bazel/repository_locations.bzl"; do \
	    archive=$${spec%%|*}; \
	    member=$${spec#*|}; \
	    [ -f "$$archive" ] || continue; \
	    ${TAR} -xOf "$$archive" "$$member" 2>/dev/null | ${AWK} '\
	        /^[A-Z0-9_]+ = "/ { \
	            split($$0, parts, " = "); \
	            split($$0, fields, "\""); \
	            consts[parts[1]] = fields[2]; \
	            next; \
	        } \
	        index($$0, "version = \"") { \
	            split($$0, fields, "\""); \
	            version = fields[2]; \
	            next; \
	        } \
	        index($$0, "version = ") && index($$0, "\"") == 0 { \
	            split($$0, parts, " = "); \
	            symbol = parts[2]; \
	            sub(/,.*/, "", symbol); \
	            version = consts[symbol]; \
	            next; \
	        } \
	        /sha256 = "/ { \
	            split($$0, fields, "\""); \
	            sha = fields[2]; \
	            next; \
	        } \
	        /urls = \[/ { \
	            if (sha != "") { \
	                split($$0, fields, "\""); \
	                url = fields[2]; \
	                gsub(/\{version\}/, version, url); \
	                sub(/^.*\//, "", url); \
	                print sha " " url; \
	                sha = ""; \
	                version = ""; \
	            } \
	        }' | while read -r sha name; do \
	            [ -n "$$sha" ] || continue; \
	            src=$$(${AWK} -v sha="$$sha" '\
	                $$1 == "SHA256" && index($$0, sha) { \
	                    sub(/^SHA256 \(/, ""); \
	                    sub(/\).*/, ""); \
	                    print; \
	                    exit; \
	                }' ${.CURDIR}/distinfo); \
	            [ -n "$$src" ] || continue; \
	            ${LN} -sf ${DISTDIR}/$$src ${WRKDIR}/bazel-distdir/$$name; \
	        done; \
	done

do-build:
	cd ${WRKSRC} && ${SETENV} ${BAZEL_ENV} ${LOCALBASE}/bin/bazel \
		${BAZEL_STARTUP_OPTS} \
		build \
		${BAZEL_BUILD_OPTS} \
		--repo_env=GOROOT=$$(${GO_CMD} env GOROOT) \
		//:envoy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bazel-bin/envoy \
		${STAGEDIR}${PREFIX}/libexec/pomerium-envoy

.include <bsd.port.mk>
