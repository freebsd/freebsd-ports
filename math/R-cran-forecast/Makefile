# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forecast
PORTVERSION=	6.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Forecasting functions for time series and linear models

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-timeDate>0:${PORTSDIR}/finance/R-cran-timeDate \
		R-cran-tseries>0:${PORTSDIR}/finance/R-cran-tseries \
		R-cran-fracdiff>0:${PORTSDIR}/math/R-cran-fracdiff \
		R-cran-Rcpp>=0.11.0:${PORTSDIR}/devel/R-cran-Rcpp \
		R-cran-colorspace>0:${PORTSDIR}/graphics/R-cran-colorspace \
		R-cran-RcppArmadillo>=0.2.35:${PORTSDIR}/math/R-cran-RcppArmadillo

USES=	cran:auto-plist

.include <bsd.port.mk>
