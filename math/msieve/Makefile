# New ports collection makefile for:	msieve
# Date created:		2007-01-02
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	msieve
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.boo.net/~jasonp/ \
		http://mirror.roe.ch/dist/msieve/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	daniel@roe.ch
COMMENT=	Fast factorization of big integers using MPQS and GNFS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST_FILES=	bin/msieve lib/libmsieve.a include/msieve/msieve.h \
		include/msieve/mp.h include/msieve/util.h
PLIST_DIRS=	include/msieve
PORTDOCS=	Changes Readme Readme.nfs Readme.qs

OPTIONS=	OCFLAGS "Enable optimized CFLAGS" On \
		GNFS "General Number Field Sieve support" On

.include <bsd.port.pre.mk>

# Does not build with GCC 4.2
.if ${OSVERSION} >= 700042
USE_GCC=	3.4
.endif

.if !defined(WITHOUT_OCFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.if !defined(WITHOUT_GNFS)
LIB_DEPENDS+=	gsl.10:${PORTSDIR}/math/gsl
ALLTGT_SUFX=	_nfs
.endif

ALLTGT=		generic
.if ${ARCH} == "i386"
ALLTGT=		x86
.endif
.if ${ARCH} == "amd64"
ALLTGT=		x86_64
.endif
ALL_TARGET=	${ALLTGT}${ALLTGT_SUFX}

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
