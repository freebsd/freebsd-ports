PORTNAME=	units
DISTVERSION=	0.8-5
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Measurement Units for R Vectors
WWW=		https://cran.r-project.org/web/packages/units/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-Rcpp>=0.12.10:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libudunits2.so:science/udunits
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat
# Tests fails: https://github.com/r-quantities/units/issues/354

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
