PORTNAME=	raster
DISTVERSION=	3.6-23
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Geographic Data Analysis and Modeling
WWW=		https://cran.r-project.org/web/packages/raster/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-sp>=1.4.5:math/R-cran-sp \
		R-cran-terra>=1.7.29:math/R-cran-terra
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
