# Created by: Jukka A. Ukkonen <jau@iki.fi>
# $FreeBSD$

PORTNAME=	Rmpfr
DISTVERSION=	0.6-0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R wrapper for the mpfr multiple precision library

LICENSE=	GPLv2+

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	R-cran-gmp>=0.5.8:math/R-cran-gmp

USES=	cran:auto-plist

.include <bsd.port.mk>
