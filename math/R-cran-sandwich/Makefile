# New ports collection makefile for:	R-cran-sandwich
# Date created:		2011-09-23
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sandwich
DISTVERSION=	2.2-8
PORTREVISION=	1
CATEGORIES=	math
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Robust Covariance Matrix Estimators

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-zoo>0:${PORTSDIR}/math/R-cran-zoo

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
