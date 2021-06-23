# Created by: Wen Heping <wen@FreeBSD.org>

PORTNAME=	Amelia
DISTVERSION=	1.8.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Program for Missing Data

LICENSE=	GPLv2+

BUILD_DEPENDS=	R-cran-Rcpp>=0.11:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>=0:math/R-cran-RcppArmadillo
RUN_DEPENDS=	R-cran-Rcpp>=0.11:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>=0:math/R-cran-RcppArmadillo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
