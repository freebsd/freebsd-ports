PORTNAME=	terra
DISTVERSION=	1.7-65
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Spatiall Data Analysis
WWW=		https://cran.r-project.org/web/packages/terra/

LICENSE=	GPLv3+

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj
CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-ncdf4>0:math/R-cran-ncdf4

USES=		compiler:c++17-lang cran:auto-plist,compiles sqlite:3

.include <bsd.port.mk>
