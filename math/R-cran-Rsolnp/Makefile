# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	Rsolnp
DISTVERSION=	1.16
PORTREVISION=	4
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	General Non-Linear Optimization

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-truncnorm>0:math/R-cran-truncnorm

BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
