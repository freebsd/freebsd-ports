# Created by: Jukka A. Ukkonen <jau@iki.fi>
# $FreeBSD$

PORTNAME=	Rmpfr
DISTVERSION=	0.6-1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R wrapper for the mpfr multiple precision library

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-gmp>=0.5.8:math/R-cran-gmp
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
