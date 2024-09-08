PORTNAME=	deno
DISTVERSIONPREFIX=	v
DISTVERSION=	1.46.2
CATEGORIES=	www

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Secure JavaScript and TypeScript runtime
WWW=		https://github.com/denoland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	cargo:warning=c/freebsd.c:31:10: error: conflicting types for 'get_cpu_speed'

BUILD_DEPENDS=	gn:devel/gn \
		libunwind>0:devel/libunwind \
		protoc:devel/protobuf
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libonig.so:devel/oniguruma

USES=		cargo cpe gmake gnome llvm:min=16,build ninja:build pkgconfig:build python:3.9+,build

USE_GITHUB=	yes
GH_ACCOUNT=	denoland

USE_GNOME=	glib20

V8_VERS=	0.105.0

CARGO_ENV+=	CLANG_BASE_PATH=/usr \
		GN=${PREFIX}/bin/gn \
		NINJA=${NINJA_CMD} \
		V8_FROM_SOURCE=1 \
		RUSTC_BOOTSTRAP=yes \
		GN_ARGS="clang_use_chrome_plugins=false \
                fatal_linker_warnings=false \
		icu_use_data_file=false \
                is_clang=true \
                treat_warnings_as_errors=false \
                use_custom_libcxx=false \
                use_custom_libunwind=true \
                use_lld=true \
                use_sysroot=false \
                use_system_libjpeg=true \
                use_udev=false"

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

CARGO_INSTALL=	no

post-patch:
	${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/cargo-crates/v8-${V8_VERS}/buildtools/third_party/libc++/BUILD.gn
	${MKDIR} ${WRKSRC}/cargo-crates/v8-${V8_VERS}/v8/tools/builtins-pgo/arm64.profile
	${MKDIR} ${WRKSRC}/cargo-crates/v8-${V8_VERS}/v8/tools/builtins-pgo/x64.profile

	${MKDIR} ${WRKSRC}/cargo-crates/v8-${V8_VERS}/third_party/icu/common
	${CP} ${WRKSRC}/cargo-crates/deno_core_icudata-0.0.73/src/icudtl.dat ${WRKSRC}/cargo-crates/v8-${V8_VERS}/third_party/icu/common/

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/deno ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
