PORTNAME=	terra
DISTVERSION=	1.8-70
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Spatiall Data Analysis
WWW=		https://cran.r-project.org/package=terra

LICENSE=	GPLv3+

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj
CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-deldir>0:math/R-cran-deldir \
		R-cran-ncdf4>0:math/R-cran-ncdf4

USES=		cran:auto-plist,compiles sqlite:3

.include <bsd.port.mk>
