PORTNAME=	e1071
DISTVERSION=	1.7-14
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Misc Functions of the Department of Statistics (e1071), TU Wien
WWW=		https://cran.r-project.org/web/packages/e1071/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-proxy>0:math/R-cran-proxy
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-mlbench>0:devel/R-cran-mlbench \
		R-cran-randomForest>0:devel/R-cran-randomForest \
		R-cran-xtable>0:textproc/R-cran-xtable

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
