# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	etm
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Empirical Transition Matrix

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-Rcpp>=0.11.4:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>0:math/R-cran-RcppArmadillo
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
