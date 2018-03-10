# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	readr
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Read Rectangular Text Data

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-Rcpp>=0.12.0.5:devel/R-cran-Rcpp \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-hms>0:devel/R-cran-hms \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-BH>0:devel/R-cran-BH
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
