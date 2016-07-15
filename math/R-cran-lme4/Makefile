# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lme4
DISTVERSION=	1.1-12
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Linear mixed-effects models using Eigen and S4

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-minqa>=1.1.15:math/R-cran-minqa \
		R-cran-nloptr>=1.0.4:math/R-cran-nloptr \
		R-cran-Rcpp>=0.10.5:devel/R-cran-Rcpp \
		R-cran-RcppEigen>0:math/R-cran-RcppEigen

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
