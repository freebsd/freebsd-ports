PORTNAME=	terra
DISTVERSION=	1.5-17
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Spatiall Data Analysis

LICENSE=	GPLv3+

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj
CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles sqlite:3

.include <bsd.port.mk>
