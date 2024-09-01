PORTNAME=	geometry
DISTVERSION=	0.5.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Mesh Generation and Surface Tesselation
WWW=		https://cran.r-project.org/web/packages/geometry/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-linprog>0:math/R-cran-linprog \
		R-cran-lpSolve>0:math/R-cran-lpSolve \
		R-cran-magic>0:math/R-cran-magic \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-RcppProgress>0:devel/R-cran-RcppProgress
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
