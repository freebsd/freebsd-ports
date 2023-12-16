PORTNAME=	zig
DISTVERSION=	0.10.1
PORTREVISION?=	3
CATEGORIES=	lang
MASTER_SITES=	https://ziglang.org/download/${DISTVERSION}/ \
		https://ziglang.org/builds/
# fetch prebuilt platform-independent docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		zig-freebsd-x86_64-${DISTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/ziglang/${PORTNAME}/commit/

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Language designed for robustness, optimality, and maintainability
WWW=		https://ziglang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet supported

BUILD_DEPENDS=	icu>=71:devel/icu \
		llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}

LIB_DEPENDS=	liblzma.so:archivers/lzma \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++11-lang localbase:ldflags tar:xz
CMAKE_ON=	THREADS_PREFER_PTHREAD_FLAG
CMAKE_ARGS+=	-DZIG_TARGET_MCPU=baseline # ensure we run everywhere

OPTIONS_DEFINE=		DOCS STATIC
OPTIONS_DEFAULT=	DOCS

STATIC_DESC=	sets ZIG_STATIC to avoid 800MiB LLVM runtime dependency

STATIC_RUN_DEPENDS_OFF=	llvm${_LLVM_VER}>=0:devel/llvm${_LLVM_VER}
STATIC_CMAKE_BOOL=	CMAKE_SKIP_INSTALL_RPATH ZIG_STATIC
STATIC_LDFLAGS=		-licudata -licuuc -llzma -lm -lmd -lxml2 -lz -lzstd

_LLVM_VER=	15
_ZIG_BIN=	${STAGEDIR}${PREFIX}/bin/zig

post-configure-STATIC-on:
	@${REINPLACE_CMD} 's/-Wl,-Bdynamic//' \
		${BUILD_WRKSRC}/build.ninja

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/std
.for f in langref.html std/data.js std/main.js std/index.html
	${INSTALL_MAN} ${WRKDIR}/zig-freebsd-x86_64-${DISTVERSION}/doc/${f} \
		${STAGEDIR}${DOCSDIR}/${f}
.endfor

do-test:
	mkdir ${WRKDIR}/cache
	(cd ${WRKSRC} && \
		${_ZIG_BIN} build test-behavior --cache-dir ${WRKDIR}/cache \
		--global-cache-dir ${WRKDIR}/cache --zig-lib-dir ${WRKSRC}/lib)

.include <bsd.port.mk>
