# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forecast
PORTVERSION=	7.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Forecasting functions for time series and linear models

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-zoo>0:math/R-cran-zoo \
		R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-tseries>0:finance/R-cran-tseries \
		R-cran-fracdiff>0:math/R-cran-fracdiff \
		R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-colorspace>0:graphics/R-cran-colorspace \
		R-cran-ggplot2>=2.0.0:graphics/R-cran-ggplot2 \
		R-cran-RcppArmadillo>=0.2.35:math/R-cran-RcppArmadillo

USES=	cran:auto-plist

.include <bsd.port.mk>
