PORTNAME=	deno
DISTVERSIONPREFIX=	v
DISTVERSION=	1.39.0
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

USES=		cargo compiler:c++20-lang cpe gmake gnome ninja:build pkgconfig:build python:3.9+,build

USE_GITHUB=	yes
GH_ACCOUNT=	denoland

USE_GNOME=	glib20

V8_VERS=	0.82.0

CARGO_ENV+=	CLANG_BASE_PATH=/usr \
		GN=${PREFIX}/bin/gn \
		NINJA=${NINJA_CMD} \
		V8_FROM_SOURCE=1

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

CARGO_INSTALL=	no

.include <bsd.port.pre.mk>
.if ${COMPILER_VERSION} != 160
LLVM_DEFAULT=		16
BUILD_DEPENDS+=		clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
			cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
			c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
			ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
			nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
			ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
.else
BINARY_ALIAS+=		ar=/usr/bin/llvm-ar \
			nm=/usr/bin/llvm-nm
.endif

post-patch:
	${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/cargo-crates/v8-${V8_VERS}/buildtools/third_party/libc++/BUILD.gn
	${MKDIR} ${WRKSRC}/cargo-crates/v8-${V8_VERS}/v8/tools/builtins-pgo/arm64.profile
	${MKDIR} ${WRKSRC}/cargo-crates/v8-${V8_VERS}/v8/tools/builtins-pgo/x64.profile

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/deno ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.post.mk>
