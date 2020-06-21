# $FreeBSD$

PORTNAME=	isoband
PORTVERSION=	0.2.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Generate Isolines and Isobands from Regularly Spaced Elevation Grids

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles compiler:c++11-lang

.include <bsd.port.mk>
