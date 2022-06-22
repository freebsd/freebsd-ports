# Created by: Pedro Giffuni

PORTNAME=	FrF2
DISTVERSION=	2.2-3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Statistical Methods for Quality Science

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-BsMD>0:math/R-cran-BsMD \
		R-cran-DoE.base>0:math/R-cran-DoE.base \
		R-cran-igraph>0:math/R-cran-igraph \
		R-cran-scatterplot3d>0:math/R-cran-scatterplot3d \
		R-cran-sfsmisc>0:devel/R-cran-sfsmisc
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
