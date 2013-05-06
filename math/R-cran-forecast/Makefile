# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	forecast
PORTVERSION=	4.03
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Forecasting functions for time series and linear models

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-fracdiff>0:${PORTSDIR}/math/R-cran-fracdiff \
		R-cran-RcppArmadillo>=0.2.35:${PORTSDIR}/math/R-cran-RcppArmadillo

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
