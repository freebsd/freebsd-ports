# New ports collection makefile for:	R-cran-DCluster
# Date created:		2011-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DCluster
DISTVERSION=	0.2-3
PORTREVISION=	1
CATEGORIES=	science
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Functions for the detection of spatial clusters of diseases

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-spdep>0:${PORTSDIR}/math/R-cran-spdep

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
