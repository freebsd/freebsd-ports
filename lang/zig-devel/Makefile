PORTNAME=	zig
DISTVERSION=	0.12.0-dev.1879+e19219fa0
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${DISTVERSION}/ \
		https://ziglang.org/builds/
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PATCH_SITES=	https://github.com/ziglang/${PORTNAME}/commit/

MAINTAINER=	bsd@orsolic.org
COMMENT=	Language designed for robustness, optimality, and maintainability, latest git version
WWW=		https://ziglang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet supported

BUILD_DEPENDS=	icu>=71:devel/icu \
		libxml2>=2.0:textproc/libxml2 \
		llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}

LIB_DEPENDS=	liblzma.so:archivers/lzma \
		libzstd.so:archivers/zstd
USES=		cmake compiler:c++11-lang localbase:ldflags tar:xz
CMAKE_ARGS+=	-DZIG_TARGET_MCPU=baseline # ensure we run everywhere
CMAKE_ON=	THREADS_PREFER_PTHREAD_FLAG

CONFLICTS_INSTALL=	zig zig0*

_LLVM_VER=		17
OPTIONS_DEFINE=		DOCS STATIC
OPTIONS_DEFAULT=	STATIC

STATIC_DESC=	sets ZIG_STATIC to avoid 800MiB LLVM runtime dependency

STATIC_RUN_DEPENDS_OFF=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}
STATIC_CMAKE_BOOL=	ZIG_STATIC
STATIC_LDFLAGS=		-licudata -licuuc -llzma -lm -lmd -lxml2 -lz -lzstd

_ZIG_BIN=	${STAGEDIR}${PREFIX}/bin/zig

post-patch:
	@${REINPLACE_CMD} 's|"-Dversion-string=$${RESOLVED_ZIG_VERSION}"|"-Dversion-string=${DISTVERSION}"|g' ${WRKSRC}/CMakeLists.txt

post-configure-STATIC-on:
	@${REINPLACE_CMD} 's/-Wl,-Bdynamic//' \
		${BUILD_WRKSRC}/build.ninja

post-build:
	@${RM} -rf ${STAGEDIR}/wrkdirs

post-install:
	@${RM} -rf ${WRKDIR}/.build

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/std
.for f in commonmark.js index.html main.js ziglexer.js
	${INSTALL_MAN} ${WRKSRC}/lib/docs/${f} \
		${STAGEDIR}${DOCSDIR}/${f}
.endfor

do-test:
	${MKDIR} ${WRKDIR}/cache
	(cd ${WRKSRC} && \
		${_ZIG_BIN} build test-behavior --cache-dir ${WRKDIR}/cache \
		--global-cache-dir ${WRKDIR}/cache --zig-lib-dir ${WRKSRC}/lib)

.include <bsd.port.mk>
