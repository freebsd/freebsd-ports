PORTNAME=	deno
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.5
CATEGORIES=	www

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Secure JavaScript and TypeScript runtime
WWW=		https://deno.com/runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	cargo:warning=c/freebsd.c:31:10: error: conflicting types for 'get_cpu_speed'

BUILD_DEPENDS=	gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo cpe gmake gnome llvm:min=16,build ninja:build pkgconfig:build python:3.9+,build

USE_GITHUB=	yes
GH_ACCOUNT=	denoland

USE_GNOME=	glib20

CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO="false" \
		CLANG_BASE_PATH=/usr \
		GN=${PREFIX}/bin/gn \
		NINJA=${NINJA_CMD} \
		V8_FROM_SOURCE=1 \
		RUSTC_BOOTSTRAP=yes \
		GN_ARGS="clang_use_chrome_plugins=false \
		fatal_linker_warnings=false \
		is_clang=true \
		use_custom_libcxx=false \
		use_sysroot=false \
		use_udev=false \
		use_glib=false"

PLIST_FILES=	bin/${PORTNAME} \
		bin/denort

BINARY_ALIAS=	python3=${PYTHON_CMD}

DENO_CORE_ICUDATA_V=	0.74.0
DENO_TS_V=		0.20.2
V8_CARGO_V=		135.0.0

V8_DISTDIR=	${CARGO_VENDOR_DIR}/v8-${V8_CARGO_V}
V8_BPGO_DIR=	${V8_DISTDIR}/v8/tools/builtins-pgo

CARGO_INSTALL=	no

WITHOUT_LTO=	yes

post-patch:
	${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" \
		${WRKSRC}/cli/task_runner.rs \
		${WRKSRC}/cli/tools/jupyter/install.rs \
		${WRKSRC}/ext/os/lib.rs
	${REINPLACE_CMD} "s|WRKDIR|${WRKDIR}|" \
		${WRKSRC}/tests/util/server/src/lib.rs

	${MKDIR} ${V8_BPGO_DIR}/arm64.profile ${V8_BPGO_DIR}/x64.profile

	${CP} ${WRKSRC}/ext/napi/generated_symbol_exports_list_linux.def \
		${WRKSRC}/ext/napi/generated_symbol_exports_list_freebsd.def

	${MKDIR} ${V8_DISTDIR}/third_party/icu/common
	${CP} ${CARGO_VENDOR_DIR}/deno_core_icudata-${DENO_CORE_ICUDATA_V}/src/icudtl.dat \
		${V8_DISTDIR}/third_party/icu/common/

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/deno ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/denort ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
