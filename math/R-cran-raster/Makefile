PORTNAME=	raster
DISTVERSION=	3.4-13
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Geographic Data Analysis and Modeling

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-sp>=1.4.1:math/R-cran-sp \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
