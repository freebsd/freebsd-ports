# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RgoogleMaps
PORTVERSION=	1.2.0.5
PORTREVISION=	1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Overlays on Google map tiles in R

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-png>0:${PORTSDIR}/graphics/R-cran-png \
		R-cran-RJSONIO>0:${PORTSDIR}/converters/R-cran-RJSONIO

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
