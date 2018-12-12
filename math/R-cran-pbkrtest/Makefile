# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pbkrtest
DISTVERSION=	0.4-7
PORTREVISION=	2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Parametric bootstrap and Kenward-Roger-based methods for mixed model comparison

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-lme4>=1.1.10:math/R-cran-lme4
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
