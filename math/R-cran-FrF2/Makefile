# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	FrF2
DISTVERSION=	1.7-3
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Statistical Methods for Quality Science

LICENSE=	GPLv2+

BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

CRAN_DEPENDS=	R-cran-DoE.base>0:math/R-cran-DoE.base		\
		R-cran-igraph>0:math/R-cran-igraph		\
		R-cran-scatterplot3d>0:math/R-cran-scatterplot3d \
		R-cran-sfsmisc>0:devel/R-cran-sfsmisc		\
		R-cran-BsMD>0:math/R-cran-BsMD

.include <bsd.port.mk>
