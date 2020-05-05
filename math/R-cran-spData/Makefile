# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spData
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Datasets for Spatial Analysis

LICENSE=	CC0-1.0

CRAN_DEPENDS=	R-cran-sp>0:math/R-cran-sp \
		R-cran-raster>0:math/R-cran-raster
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
