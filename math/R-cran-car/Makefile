# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	car
DISTVERSION=	2.1-2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Companion to Applied Regression for R

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-pbkrtest>=0.3.2:math/R-cran-pbkrtest \
		R-cran-quantreg>0:math/R-cran-quantreg
TEST_DEPENDS=	R-cran-lmtest>=0.9.26:finance/R-cran-lmtest \
		R-cran-sandwich>0:math/R-cran-sandwich

USES=	cran

.include <bsd.port.mk>
