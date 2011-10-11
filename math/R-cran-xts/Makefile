# New ports collection makefile for:	R-cran-xts
# Date created:		2011-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xts
DISTVERSION=	0.8-2
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Extensible Time Series

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-zoo>=1.7.2:${PORTSDIR}/math/R-cran-zoo

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
