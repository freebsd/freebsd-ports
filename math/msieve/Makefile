# New ports collection makefile for:	msieve
# Date created:		2007-01-02
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	msieve
PORTVERSION=	1.50
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	\
	${PORTNAME}/${PORTNAME}/${PORTNAME:C/^m/M/}%20v${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}src

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Fast factorization of big integers using MPQS and GNFS

BUILD_DEPENDS=	${LOCALBASE}/lib/libecm.a:${PORTSDIR}/math/gmp-ecm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" ECM=1

HEADERS=	mp.h msieve.h util.h
PLIST_FILES=	bin/msieve lib/libmsieve.a ${HEADERS:S|^|include/msieve/|}
PLIST_DIRS=	include/msieve
PORTDOCS=	Changes Readme Readme.nfs Readme.qs

OPTIONS=	OCFLAGS "Enable optimized CFLAGS" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OCFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -DNDEBUG
.endif

.if ${OSVERSION} >= 700042 && ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${ARCH} == "i386"
ALL_TARGET=	x86
.elif ${ARCH} == "amd64"
ALL_TARGET=	x86_64
.else
ALL_TARGET=	generic
.endif

post-patch:
	@${REINPLACE_CMD} -e "\|^CC =|d" -e "\|^OPT_FLAGS =|d" \
		-e "\|^CFLAGS =|s|=|+=|" ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/msieve ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/msieve
	@(cd ${WRKSRC}/include; ${INSTALL_DATA} ${HEADERS} ${PREFIX}/include/msieve)
	@${INSTALL_DATA} ${WRKSRC}/libmsieve.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

regression-test test check: build
	@(cd ${WRKSRC}; ./msieve -q -d 1 2385734365243128176756453434347656453122245767798)

.include <bsd.port.post.mk>
