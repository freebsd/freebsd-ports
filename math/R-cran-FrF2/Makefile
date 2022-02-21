# Created by: Pedro Giffuni

PORTNAME=	FrF2
DISTVERSION=	2.2-2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
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
