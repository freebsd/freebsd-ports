PORTNAME=	deno
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.6
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure JavaScript and TypeScript runtime
WWW=		https://deno.com/runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	cargo:warning=c/freebsd.c:31:10: error: conflicting types for 'get_cpu_speed'

BUILD_DEPENDS=	gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libffi.so:devel/libffi \
		liblcms2.so:graphics/lcms2 \
		libzstd.so:archivers/zstd

USES=		cargo cpe gmake gnome llvm:min=21,build ninja:build pkgconfig:build python:build

USE_GITHUB=	yes
GH_ACCOUNT=	denoland
GH_TUPLE=	denoland:deno_lsp_benchdata:a787434:denolsp/cli/bench/testdata/lsp_benchdata \
		denoland:node_test:8846b53:nodetest/tests/node_compat/runner/suite \
		denoland:std:1f032bb7:denostd/tests/util/std \
		web-platform-tests:wpt:e78446e:webp/tests/wpt/suite

USE_GNOME=	glib20

CARGO_ENV+=	V8_FROM_SOURCE=1 \
		GN=${PREFIX}/bin/gn \
		NINJA=${NINJA_CMD} \
		CLANG_BASE_PATH=/usr \
		LCMS2_INCLUDE_DIR="${LOCALBASE}/include" \
		LCMS2_LIB_DIR="${LOCALBASE}/lib" \
		CARGO_PROFILE_RELEASE_LTO="false" \
		GN_ARGS="clang_use_chrome_plugins=false \
		extra_cppflags=\"-idirafter ${LOCALBASE}/include -idirafter ${X11BASE}/include\" \
		extra_ldflags=\"-L${LOCALBASE}/lib -L${X11BASE}/lib\" \
		fatal_linker_warnings=false \
		is_clang=true \
		use_custom_libcxx=true \
		use_custom_libunwind=true \
		use_libcxx_modules=false \
		use_udev=true \
		use_sysroot=false \
		use_glib=false \
		v8_enable_cet_ibt=true"

RUSTFLAGS+=	"-L${LOCALBASE}/lib"

PLIST_FILES=	bin/${PORTNAME} \
		bin/denort

BINARY_ALIAS=	python3=${PYTHON_CMD}

DENO_CORE_ICUDATA_V=	0.74.0
V8_CARGO_V=		142.2.0

V8_DISTDIR=	${CARGO_VENDOR_DIR}/v8-${V8_CARGO_V}
V8_BPGO_DIR=	${V8_DISTDIR}/v8/tools/builtins-pgo

CARGO_INSTALL=	no

WITHOUT_LTO=	yes

post-patch:
	${REINPLACE_CMD} "s|${PREFIX}|${PREFIX}|" \
		${WRKSRC}/cli/task_runner.rs \
		${WRKSRC}/cli/tools/jupyter/install.rs \
		${WRKSRC}/ext/os/lib.rs \
		${WRKSRC}/tests/unit_node/process_test.ts
	${REINPLACE_CMD} "s|WRKDIR|${WRKDIR}|" \
		${WRKSRC}/tests/util/server/src/lib.rs
	${REINPLACE_CMD} "s|linux|freebsd|g" \
		${WRKSRC}/tests/ffi/tests/ffi_callback_errors.ts \
		${WRKSRC}/tests/ffi/tests/test.js \
		${WRKSRC}/tests/ffi/tests/bench.js \
		${WRKSRC}/tests/ffi/tests/event_loop_integration.ts \
		${WRKSRC}/tests/ffi/tests/thread_safe_test_worker.js \
		${WRKSRC}/tests/ffi/tests/thread_safe_test.js \
		${WRKSRC}/tests/integration/cache_tests.rs \
		${WRKSRC}/tests/napi/common.js \
		${WRKSRC}/tests/unit/build_test.ts \
		${WRKSRC}/tests/unit/dir_test.ts \
		${WRKSRC}/tests/specs/mod.rs

	${MKDIR} ${V8_BPGO_DIR}/arm64.profile ${V8_BPGO_DIR}/x64.profile

	${CP} ${WRKSRC}/ext/napi/generated_symbol_exports_list_linux.def \
		${WRKSRC}/ext/napi/generated_symbol_exports_list_freebsd.def

	${MKDIR} ${V8_DISTDIR}/third_party/icu/common
	${CP} ${CARGO_VENDOR_DIR}/deno_core_icudata-${DENO_CORE_ICUDATA_V}/src/icudtl.dat \
		${V8_DISTDIR}/third_party/icu/common/

# do not pass RUST_BACKTRACE=1 to cargo test as some tests fails if it's there
do-test:
	cd ${WRKSRC} ; \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CARGO_ENV:S/RUST_BACKTRACE=1//g} ${CARGO} test -vv ${CARGO_BUILD_ARGS}

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/deno ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/denort ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
