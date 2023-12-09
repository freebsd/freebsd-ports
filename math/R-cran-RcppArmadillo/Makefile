PORTNAME=	RcppArmadillo
DISTVERSION=	0.12.6.6.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Rcpp integration for Armadillo templated linear algebra library
WWW=		https://cran.r-project.org/web/packages/RcppArmadillo/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
