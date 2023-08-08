PORTNAME=	units
DISTVERSION=	0.8-2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measurement Units for R Vectors
WWW=		https://cran.r-project.org/web/packages/units/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-Rcpp>=0.12.10:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libudunits2.so:science/udunits
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
