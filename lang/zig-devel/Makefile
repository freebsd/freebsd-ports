PORTNAME=	zig
DISTVERSION=	g20210824
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${DISTVERSION}/ \
		https://ziglang.org/builds/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Language designed for robustness, optimality, and maintainability

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet supported

BUILD_DEPENDS=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}

USES=		cmake compiler:c++11-lang localbase:ldflags tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	ziglang
GH_PROJECT=	zig
GH_TAGNAME=	9e3ec9893

CONFLICTS=	zig

OPTIONS_DEFINE=		STATIC
OPTIONS_DEFAULT=	STATIC

CMAKE_ARGS+=	-DZIG_VERSION="0.9.0-dev.850+9e3ec9893"

STATIC_DESC=	sets ZIG_STATIC to avoid 800MiB LLVM dependencies

STATIC_RUN_DEPENDS_OFF=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}
STATIC_CMAKE_BOOL=	CMAKE_SKIP_INSTALL_RPATH ZIG_STATIC
STATIC_LDFLAGS=		-lz -lm -lmd -llzma -L/usr/lib

_LLVM_VER=	12
_ZIG_BIN=	${STAGEDIR}${PREFIX}/bin/zig

post-configure-STATIC-on:
	@${REINPLACE_CMD} 's/-Wl,-Bdynamic//' ${BUILD_WRKSRC}/build.ninja

post-build:
	${MKDIR}  ${WRKDIR}/cache ${WRKDIR}/doc
	${RM} ${WRKSRC}/lib/zig/std/zig-cache

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/std
	# langref cannot be generated until after install target has run
	(cd ${WRKSRC} && ${_ZIG_BIN} run \
		./doc/docgen.zig -- ${_ZIG_BIN} \
		./doc/langref.html.in ${STAGEDIR}${DOCSDIR}/langref.html \
		&& ${RM} ${STAGEDIR}/lib/zig/std/zig-cache)
	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' ${STAGEDIR}${DOCSDIR}/langref.html

.include <bsd.port.mk>
