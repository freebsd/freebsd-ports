# New ports collection makefile for:	msieve
# Date created:		2007-01-02
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	msieve
PORTVERSION=	1.34
CATEGORIES=	math
MASTER_SITES=	http://www.boo.net/~jasonp/ \
		http://mirror.roe.ch/dist/msieve/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	daniel@roe.ch
COMMENT=	Fast factorization of big integers using MPQS and GNFS

BUILD_DEPENDS=	${LOCALBASE}/lib/libecm.a:${PORTSDIR}/math/gmp-ecm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		ECM=1

PLIST_FILES=	bin/msieve lib/libmsieve.a include/msieve/msieve.h \
		include/msieve/mp.h include/msieve/util.h
PLIST_DIRS=	include/msieve
PORTDOCS=	Changes Readme Readme.nfs Readme.qs

OPTIONS=	OCFLAGS "Enable optimized CFLAGS" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OCFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -D_FILE_OFFSET_BITS=64
.else
CFLAGS+=	-D_FILE_OFFSET_BITS=64
.endif

# Does not build with GCC 4.2
.if ${OSVERSION} >= 700042
USE_GCC=	3.4
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64-7
.endif
.endif

ALL_TARGET=	generic
.if ${ARCH} == "i386"
ALL_TARGET=	x86
.endif
.if ${ARCH} == "amd64"
ALL_TARGET=	x86_64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msieve ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/msieve
	${INSTALL_DATA} ${WRKSRC}/include/msieve.h ${PREFIX}/include/msieve
	${INSTALL_DATA} ${WRKSRC}/include/mp.h ${PREFIX}/include/msieve
	${INSTALL_DATA} ${WRKSRC}/include/util.h ${PREFIX}/include/msieve
	${INSTALL_DATA} ${WRKSRC}/libmsieve.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
