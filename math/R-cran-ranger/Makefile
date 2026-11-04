PORTNAME=	ranger
DISTVERSION=	0.18.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	Fast implementation of random forests
WWW=		https://imbs-hl.github.io/ranger/

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-Rcpp>=0.11.2:devel/R-cran-Rcpp \
		R-cran-RcppEigen>0:math/R-cran-RcppEigen
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
