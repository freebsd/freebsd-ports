PORTNAME=	conquer
PORTVERSION=	1.0.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Convolution-Type Smoothed Quantile Regression

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-Rcpp>=1.0.3:devel/R-cran-Rcpp \
		R-cran-matrixStats>0:math/R-cran-matrixStats \
		R-cran-RcppArmadillo>=0.9.850.1.0:math/R-cran-RcppArmadillo
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
