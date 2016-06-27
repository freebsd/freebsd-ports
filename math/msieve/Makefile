# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	msieve
PORTVERSION=	1.51
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME:C/^m/M/}%20v${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast factorization of big integers using MPQS and GNFS

BUILD_DEPENDS=	${LOCALBASE}/lib/libecm.a:math/gmp-ecm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake
MAKE_ENV=	ECM=1

HEADERS=	mp.h msieve.h util.h
PLIST_FILES=	bin/msieve lib/libmsieve.a ${HEADERS:S|^|include/msieve/|}
PORTDOCS=	Changes Readme Readme.nfs Readme.qs

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.if defined(WITHOUT_DEBUG) || !defined(WITH_DEBUG)
CFLAGS+=	-fomit-frame-pointer -DNDEBUG
.endif
.endif

.if ${MACHINE_CPU:Mathlon}
CFLAGS+=	-DHAS_AMD_MMX
.endif

.if ${MACHINE_CPU:Msse}
CFLAGS+=	-DHAS_SSE
.endif

.if ${MACHINE_CPU:Msse2}
CFLAGS+=	-DHAS_SSE2
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e '/(^(CC|OPT_FLAGS) =|-DNDEBUG|svnversion|-ldl)/d' \
		-e '/^CFLAGS =/s/=/+=/' \
		-e 's@-Ignfs/poly/stage1@& -I${LOCALBASE}/include@' \
		-e 's@-lecm@-L${LOCALBASE}/lib &@' \
		-e 's/-lpthread/-pthread/' \
		-e 's/-DHAS_SSE2//' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/msieve ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/msieve
	@cd ${WRKSRC}/include; ${INSTALL_DATA} ${HEADERS} ${STAGEDIR}${PREFIX}/include/msieve
	@${INSTALL_DATA} ${WRKSRC}/libmsieve.a ${STAGEDIR}${PREFIX}/lib
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

regression-test test check: build
	@cd ${WRKSRC}; \
	./msieve -q -d 1 2385734365243128176756453434347656453122245767798

.include <bsd.port.mk>
