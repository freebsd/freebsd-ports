# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forecast
PORTVERSION=	4.8
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Forecasting functions for time series and linear models

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-tseries>0:${PORTSDIR}/finance/R-cran-tseries \
		R-cran-fracdiff>0:${PORTSDIR}/math/R-cran-fracdiff \
		R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo \
		R-cran-Rcpp>=0.9.10:${PORTSDIR}/devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>=0.2.35:${PORTSDIR}/math/R-cran-RcppArmadillo \
		R-cran-colorspace>0:${PORTSDIR}/graphics/R-cran-colorspace

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
