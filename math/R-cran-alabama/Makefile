# Created by: Devin Teske <dteske@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alabama
DISTVERSION=	2015.3-1
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Constrained Nonlinear Optimization

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-numDeriv>0:math/R-cran-numDeriv
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
