# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Amelia
DISTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Program for Missing Data

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	R-cran-Rcpp>=0.11:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>=0:math/R-cran-RcppArmadillo
RUN_DEPENDS=	R-cran-Rcpp>=0.11:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>=0:math/R-cran-RcppArmadillo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
