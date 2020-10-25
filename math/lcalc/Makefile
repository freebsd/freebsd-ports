# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	lcalc
PORTVERSION=	1.23
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/misc/sage/spkg/upstream/lcalc/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	L-function c++ class library and the CLI program lcalc

LICENSE=	GPLv2+

LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libpari.so:math/pari

#USE_GITHUB=	yes
#GH_ACCOUNT=	agrawroh
#GH_PROJECT=	l-calc
#GH_TAGNAME=	4c57471

USES=		compiler:c++11-lang gmake localbase tar:bz2

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes

MAKE_ENV=	MAKE=${GMAKE} STAGEDIR=${STAGEDIR}

post-stage:
	cd ${STAGEDIR}${PREFIX}/lib && ${MV} libLfunction.so libLfunction.so.0
	${LN} -sf libLfunction.so.0 ${STAGEDIR}${PREFIX}/lib/libLfunction.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
