PORTNAME=	spData
PORTVERSION=	2.3.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Datasets for Spatial Analysis
WWW=		https://cran.r-project.org/web/packages/spData/

LICENSE=	CC0-1.0

CRAN_DEPENDS=	R-cran-sp>0:math/R-cran-sp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
