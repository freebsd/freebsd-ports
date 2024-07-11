PORTNAME=	xts
DISTVERSION=	0.14.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extensible Time Series
WWW=		https://cran.r-project.org/web/packages/xts/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-zoo>=1.7.12:math/R-cran-zoo
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
