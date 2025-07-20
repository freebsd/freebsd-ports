PORTNAME=	Rmpfr
DISTVERSION=	1.1-1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R wrapper for the mpfr multiple precision library
WWW=		https://cran.r-project.org/web/packages/Rmpfr/

LICENSE=	GPLv2+

NOT_FOR_ARCHS=	i386

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	R-cran-gmp>=0.6.1:math/R-cran-gmp

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
