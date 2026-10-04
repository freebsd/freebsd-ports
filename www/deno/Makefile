PORTNAME=	deno
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.7
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure JavaScript and TypeScript runtime
WWW=		https://deno.com/runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	cargo:warning=c/freebsd.c:31:10: error: conflicting types for 'get_cpu_speed'

BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli \
		gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdeflate.so:archivers/libdeflate \
		libffi.so:devel/libffi \
		liblcms2.so:graphics/lcms2 \
		libsqlite3.so:databases/sqlite3 \
		libzstd.so:archivers/zstd

USES=		cargo cpe gmake llvm:min=21,build localbase:ldflags ninja:build \
		pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	denoland
GH_TUPLE=	denoland:deno_lsp_benchdata:a787434:denolsp/tests/bench/testdata/lsp_benchdata \
		denoland:node_test:f287abd:nodetest/tests/node_compat/runner/suite \
		denoland:std:9c5b710:denostd/tests/util/std \
		web-platform-tests:wpt:c937f9d271eb35913c3b5b0635fa7fd5f8c88eec:webp/tests/wpt/suite
USE_LDCONFIG=	yes

CARGO_INSTALL=	no
CARGO_ENV+=	V8_FROM_SOURCE=1 \
		GN=${PREFIX}/bin/gn \
		NINJA=${NINJA_CMD} \
		CLANG_BASE_PATH=/usr \
		LCMS2_INCLUDE_DIR="${LOCALBASE}/include" \
		LCMS2_LIB_DIR="${LOCALBASE}/lib" \
		LIBSQLITE3_SYS_USE_PKG_CONFIG=1 \
		CARGO_PROFILE_RELEASE_LTO="false" \
		GN_ARGS="${V8_GN_ARGS}"

V8_GN_ARGS=	clang_use_chrome_plugins=false \
		extra_cppflags=\"-idirafter ${LOCALBASE}/include\" \
		extra_ldflags=\"-L${LOCALBASE}/lib\" \
		fatal_linker_warnings=false \
		is_clang=true \
		use_custom_libcxx=true \
		use_custom_libunwind=true \
		use_udev=true \
		use_sysroot=false \
		use_glib=false \
		v8_enable_cet_ibt=true

WITHOUT_LTO=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/${PORTNAME} \
		bin/denort \
		lib/libdenort.so

DENO_CORE_ICUDATA_V=	0.77.0
V8_CARGO_V=		150.4.0

V8_DISTDIR=		${CARGO_VENDOR_DIR}/v8-${V8_CARGO_V}
V8_BPGO_DIR=		${V8_DISTDIR}/v8/tools/builtins-pgo
ICUDATA_DIR=		${CARGO_VENDOR_DIR}/deno_core_icudata-${DENO_CORE_ICUDATA_V}/src
TEMPORAL_CAPI_DIR=	${CARGO_VENDOR_DIR}/${CARGO_CRATES:Mtemporal_capi-[0-9]*}
TEMPORAL_CAPI_LIB=	${WRKDIR}/libtemporal_capi.a

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
PATCH_DEPENDS+=	${LOCALBASE}/sbin/icupkg:devel/icu
V8_GN_ARGS+=	host_byteorder=\"big\"
ICUDATA_MAJOR=	${DENO_CORE_ICUDATA_V:R:E}
.endif

post-patch:
	${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/cli/task_runner.rs \
		${WRKSRC}/ext/os/lib.rs
	${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/tests/unit_node/process_test.ts
	${REINPLACE_CMD} "s|%%LLVM_PREFIX%%|${LLVM_PREFIX}|g" \
		${WRKSRC}/cargo-crates/v8-${V8_CARGO_V}/build/toolchain/gcc_toolchain.gni
	${REINPLACE_CMD} -e "s|%%TEMPORAL_CAPI_DIR%%|${TEMPORAL_CAPI_DIR}|g" \
		-e "s|%%TEMPORAL_CAPI_LIB%%|${TEMPORAL_CAPI_LIB}|g" \
		${V8_DISTDIR}/third_party/rust/temporal_capi/BUILD.gn
	${REINPLACE_CMD} "s|linux|freebsd|g" \
		${WRKSRC}/tests/ffi/testdata/ffi_callback_errors.ts \
		${WRKSRC}/tests/ffi/testdata/test.js \
		${WRKSRC}/tests/ffi/testdata/bench.js \
		${WRKSRC}/tests/ffi/testdata/event_loop_integration.ts \
		${WRKSRC}/tests/ffi/testdata/thread_safe_test_worker.js \
		${WRKSRC}/tests/ffi/testdata/thread_safe_test.js \
		${WRKSRC}/tests/integration/cache_tests.rs \
		${WRKSRC}/tests/napi/common.js \
		${WRKSRC}/tests/unit/build_test.ts \
		${WRKSRC}/tests/unit/dir_test.ts \
		${WRKSRC}/tests/specs/mod.rs

	${MKDIR} ${V8_BPGO_DIR}/arm64.profile ${V8_BPGO_DIR}/x64.profile

	${CP} ${WRKSRC}/ext/napi/generated_symbol_exports_list_linux.def \
		${WRKSRC}/ext/napi/generated_symbol_exports_list_freebsd.def

	${MKDIR} ${V8_DISTDIR}/third_party/icu/common
.if ${ARCH} == powerpc64
	${CP} ${ICUDATA_DIR}/icudtl.dat ${WRKDIR}/icudt${ICUDATA_MAJOR}l.dat
	${LOCALBASE}/sbin/icupkg -tb --ignore-deps \
		${WRKDIR}/icudt${ICUDATA_MAJOR}l.dat ${WRKDIR}/icudt${ICUDATA_MAJOR}b.dat
	${CP} ${WRKDIR}/icudt${ICUDATA_MAJOR}b.dat \
		${V8_DISTDIR}/third_party/icu/common/icudtb.dat
.else
	${CP} ${ICUDATA_DIR}/icudtl.dat ${V8_DISTDIR}/third_party/icu/common/
.endif

# V8 links mksnapshot itself and needs the Temporal symbols at that point
pre-build:
	@${CARGO_CARGO_RUN} rustc \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS} \
		--package temporal_capi \
		--lib --crate-type staticlib
	${CP} ${CARGO_TARGET_DIR}/*/libtemporal_capi.a ${TEMPORAL_CAPI_LIB}

do-install:
	${INSTALL_PROGRAM} \
		${CARGO_TARGET_DIR}/*/deno \
		${CARGO_TARGET_DIR}/*/denort ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libdenort.so ${STAGEDIR}${PREFIX}/lib

# do not pass RUST_BACKTRACE=1 to cargo test as some tests fails if it's there
do-test:
	(cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CARGO_ENV:S/RUST_BACKTRACE=1//g} \
			${CARGO} test -vv ${CARGO_BUILD_ARGS})

.include <bsd.port.mk>
