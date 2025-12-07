PORTNAME=	sf
DISTVERSION=	1.0-21
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simple Features for R
WWW=		https://cran.r-project.org/web/packages/sf/

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-classInt>=0.4.1:devel/R-cran-classInt \
		R-cran-DBI>=0.8:databases/R-cran-DBI \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-Rcpp>=0.12.18:devel/R-cran-Rcpp \
		R-cran-s2>=1.1.0:graphics/R-cran-s2 \
		R-cran-units>=0.7.0:math/R-cran-units
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libproj.so:graphics/proj
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles pkgconfig

CONFIGURE_ARGS+=	"--with-proj-api=yes"

.include <bsd.port.mk>
