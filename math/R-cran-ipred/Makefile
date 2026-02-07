PORTNAME=	ipred
DISTVERSION=	0.9-15
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Improved Predictors
WWW=		https://cran.r-project.org/web/packages/ipred/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-prodlim>0:math/R-cran-prodlim
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-mlbench>0:devel/R-cran-mlbench \
		R-cran-TH.data>0:devel/R-cran-TH.data

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
