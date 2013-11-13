# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ChangeAnomalyDetection
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Change Anomaly Detection

LICENSE=	BSD

RUN_DEPENDS=	R-cran-TTR>0:${PORTSDIR}/finance/R-cran-TTR \
		R-cran-forecast>0:${PORTSDIR}/math/R-cran-forecast

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
