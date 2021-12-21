PORTNAME=	zig
DISTVERSION=	0.9.0
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${DISTVERSION}/ \
		https://ziglang.org/builds/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Language designed for robustness, optimality, and maintainability

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet supported

BUILD_DEPENDS=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}

CONFLICTS=	zig

USES=		cmake compiler:c++11-lang localbase:ldflags tar:xz

OPTIONS_DEFINE=		STATIC
OPTIONS_DEFAULT=	STATIC

STATIC_DESC=	sets ZIG_STATIC to avoid 800MiB LLVM dependencies

STATIC_RUN_DEPENDS_OFF=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}
STATIC_CMAKE_BOOL=	CMAKE_SKIP_INSTALL_RPATH ZIG_STATIC
STATIC_LDFLAGS=		-llzma -lm -lmd -lxml2 -lz

_LLVM_VER=	13
_ZIG_BIN=	${STAGEDIR}${PREFIX}/bin/zig

post-configure-STATIC-on:
	@${REINPLACE_CMD} 's/-Wl,-Bdynamic//' ${BUILD_WRKSRC}/build.ninja

post-build:
# Produce the experimental std lib documentation.
	${MKDIR}  ${WRKDIR}/cache ${WRKDIR}/doc
	${WRKDIR}/.build/zig test ${WRKSRC}/lib/std/std.zig \
		--cache-dir ${WRKDIR}/cache \
		--global-cache-dir ${WRKDIR}/cache \
		--zig-lib-dir ${WRKSRC}/lib \
		-femit-docs=${WRKDIR}/doc \
		-fno-emit-bin
	${RM} ${WRKSRC}/lib/zig/std/zig-cache

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/std
# langref cannot be generated until after install target has run
	(cd ${WRKSRC} && ${_ZIG_BIN} run \
		./doc/docgen.zig -- ${_ZIG_BIN} \
		./doc/langref.html.in ${STAGEDIR}${DOCSDIR}/langref.html \
		&& ${RM} ${STAGEDIR}/lib/zig/std/zig-cache)
	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' ${STAGEDIR}${DOCSDIR}/langref.html
.for f in data.js main.js index.html
	${INSTALL_MAN} ${WRKDIR}/doc/${f} ${STAGEDIR}${DOCSDIR}/std/
.endfor

.include <bsd.port.mk>
