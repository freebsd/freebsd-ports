# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	lcalc
PORTVERSION=	1.23
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

USES=		gmake localbase tar:bz2

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes

MAKE_ENV=	MAKE=${GMAKE} STAGEDIR=${STAGEDIR}

.include <bsd.port.mk>
