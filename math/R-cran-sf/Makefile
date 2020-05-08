# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sf
DISTVERSION=	0.9-3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple Features for R

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-classInt>=0.4.1:devel/R-cran-classInt \
		R-cran-DBI>=0.8:databases/R-cran-DBI \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-Rcpp>=0.12.18:devel/R-cran-Rcpp \
		R-cran-units>=0.6.0:math/R-cran-units
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles pkgconfig

CONFIGURE_ARGS+=	"--with-proj-api=yes"

.include <bsd.port.mk>
